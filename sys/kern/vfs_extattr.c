/*-
 * SPDX-License-Identifier: BSD-2-Clause-FreeBSD
 *
 * Copyright (c) 1999-2001 Robert N. M. Watson
 * All rights reserved.
 *
 * This software was developed by Robert Watson for the TrustedBSD Project.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <sys/cdefs.h>
__FBSDID("$FreeBSD$");

#include <sys/param.h>
#include <sys/systm.h>
#include <sys/capsicum.h>
#include <sys/lock.h>
#include <sys/mount.h>
#include <sys/mutex.h>
#include <sys/sysproto.h>
#include <sys/syscallsubr.h>
#include <sys/fcntl.h>
#include <sys/namei.h>
#include <sys/filedesc.h>
#include <sys/limits.h>
#include <sys/vnode.h>
#include <sys/proc.h>
#include <sys/extattr.h>

#include <security/audit/audit.h>
#include <security/mac/mac_framework.h>

/*
 * Syscall to push extended attribute configuration information into the VFS.
 * Accepts a path, which it converts to a mountpoint, as well as a command
 * (int cmd), and attribute name and misc data.
 *
 * Currently this is used only by UFS1 extended attributes.
 */
#ifndef _SYS_SYSPROTO_H_
struct extattrctl_args {
	const char *path;
	int cmd;
	const char *filename;
	int attrnamespace;
	const char *attrname;
};
#endif
int
sys_extattrctl(struct thread *td, struct extattrctl_args *uap)
{

	return (kern_extattrctl(td, __USER_CAP_STR(uap->path), uap->cmd,
	    __USER_CAP_STR(uap->filename), uap->attrnamespace,
	    __USER_CAP_STR(uap->attrname)));
}

int
kern_extattrctl(struct thread *td, const char * __capability path, int cmd,
    const char * __capability filename, int attrnamespace,
    const char * __capability uattrname)
{

	struct vnode *filename_vp;
	struct nameidata nd;
	struct mount *mp, *mp_writable;
	char attrname[EXTATTR_MAXNAMELEN];
	int error;

	AUDIT_ARG_CMD(cmd);
	AUDIT_ARG_VALUE(attrnamespace);
	/*
	 * uattrname is not always defined.  We check again later when we
	 * invoke the VFS call so as to pass in NULL there if needed.
	 */
	if (uattrname != NULL) {
		error = copyinstr_c(uattrname, &attrname[0],
		    EXTATTR_MAXNAMELEN, NULL);
		if (error)
			return (error);
	}
	AUDIT_ARG_TEXT(attrname);

	mp = NULL;
	filename_vp = NULL;
	if (filename != NULL) {
		NDINIT_C(&nd, LOOKUP, FOLLOW | AUDITVNODE2,
		    UIO_USERSPACE, filename, td);
		error = namei(&nd);
		if (error)
			return (error);
		filename_vp = nd.ni_vp;
		NDFREE(&nd, NDF_NO_VP_RELE);
	}

	/* path is always defined. */
	NDINIT_C(&nd, LOOKUP, FOLLOW | LOCKLEAF | AUDITVNODE1,
	    UIO_USERSPACE, path, td);
	error = namei(&nd);
	if (error)
		goto out;
	mp = nd.ni_vp->v_mount;
	error = vfs_busy(mp, 0);
	if (error) {
		NDFREE(&nd, 0);
		mp = NULL;
		goto out;
	}
	VOP_UNLOCK(nd.ni_vp, 0);
	error = vn_start_write(nd.ni_vp, &mp_writable, V_WAIT | PCATCH);
	NDFREE(&nd, NDF_NO_VP_UNLOCK);
	if (error)
		goto out;
	if (filename_vp != NULL) {
		/*
		 * filename is not always defined.  If it is,
		 * grab a vnode lock, which VFS_EXTATTRCTL() will
		 * later release.
		 */
		error = vn_lock(filename_vp, LK_EXCLUSIVE);
		if (error) {
			vn_finished_write(mp_writable);
			goto out;
		}
	}

	error = VFS_EXTATTRCTL(mp, cmd, filename_vp, attrnamespace,
	    uattrname != NULL ? attrname : NULL);

	vn_finished_write(mp_writable);
out:
	if (mp != NULL)
		vfs_unbusy(mp);

	/*
	 * VFS_EXTATTRCTL will have unlocked, but not de-ref'd, filename_vp,
	 * so vrele it if it is defined.
	 */
	if (filename_vp != NULL)
		vrele(filename_vp);
	return (error);
}

/*-
 * Set a named extended attribute on a file or directory
 *
 * Arguments: unlocked vnode "vp", attribute namespace "attrnamespace",
 *            kernelspace string pointer "attrname", userspace buffer
 *            pointer "data", buffer length "nbytes", thread "td".
 * Returns: 0 on success, an error number otherwise
 * Locks: none
 * References: vp must be a valid reference for the duration of the call
 */
static int
extattr_set_vp(struct vnode *vp, int attrnamespace, const char *attrname,
    void * __capability data, size_t nbytes, struct thread *td)
{
	struct mount *mp;
	struct uio auio;
	kiovec_t aiov;
	ssize_t cnt;
	int error;

	if (nbytes > IOSIZE_MAX)
		return (EINVAL);

	error = vn_start_write(vp, &mp, V_WAIT | PCATCH);
	if (error)
		return (error);
	vn_lock(vp, LK_EXCLUSIVE | LK_RETRY);

	IOVEC_INIT_C(&aiov, data, nbytes);
	auio.uio_iov = &aiov;
	auio.uio_iovcnt = 1;
	auio.uio_offset = 0;
	auio.uio_resid = nbytes;
	auio.uio_rw = UIO_WRITE;
	auio.uio_segflg = UIO_USERSPACE;
	auio.uio_td = td;
	cnt = nbytes;

#ifdef MAC
	error = mac_vnode_check_setextattr(td->td_ucred, vp, attrnamespace,
	    attrname);
	if (error)
		goto done;
#endif

	error = VOP_SETEXTATTR(vp, attrnamespace, attrname, &auio,
	    td->td_ucred, td);
	cnt -= auio.uio_resid;
	td->td_retval[0] = cnt;

#ifdef MAC
done:
#endif
	VOP_UNLOCK(vp, 0);
	vn_finished_write(mp);
	return (error);
}

#ifndef _SYS_SYSPROTO_H_
struct extattr_set_fd_args {
	int fd;
	int attrnamespace;
	const char *attrname;
	void *data;
	size_t nbytes;
};
#endif
int
sys_extattr_set_fd(struct thread *td, struct extattr_set_fd_args *uap)
{

	return (kern_extattr_set_fd(td, uap->fd, uap->attrnamespace,
	    __USER_CAP_STR(uap->attrname), __USER_CAP(uap->data, uap->nbytes),
	    uap->nbytes));
}

int
kern_extattr_set_fd(struct thread *td, int fd, int attrnamespace,
    const char * __capability uattrname, void * __capability data,
    size_t nbytes)
{
	struct file *fp;
	char attrname[EXTATTR_MAXNAMELEN];
	cap_rights_t rights;
	int error;

	AUDIT_ARG_FD(fd);
	AUDIT_ARG_VALUE(attrnamespace);
	error = copyinstr_c(uattrname, &attrname[0], EXTATTR_MAXNAMELEN, NULL);
	if (error)
		return (error);
	AUDIT_ARG_TEXT(attrname);

	error = getvnode(td, fd,
	    cap_rights_init(&rights, CAP_EXTATTR_SET), &fp);
	if (error)
		return (error);

	error = extattr_set_vp(fp->f_vnode, attrnamespace,
	    attrname, data, nbytes, td);
	fdrop(fp, td);

	return (error);
}

#ifndef _SYS_SYSPROTO_H_
struct extattr_set_file_args {
	const char *path;
	int attrnamespace;
	const char *attrname;
	void *data;
	size_t nbytes;
};
#endif
int
sys_extattr_set_file(struct thread *td, struct extattr_set_file_args *uap)
{

	return (kern_extattr_set_path(td, __USER_CAP_STR(uap->path),
	    uap->attrnamespace, __USER_CAP_STR(uap->attrname),
	    __USER_CAP(uap->data, uap->nbytes), uap->nbytes, FOLLOW));
}

#ifndef _SYS_SYSPROTO_H_
struct extattr_set_link_args {
	const char *path;
	int attrnamespace;
	const char *attrname;
	void *data;
	size_t nbytes;
};
#endif
int
sys_extattr_set_link(struct thread *td, struct extattr_set_link_args *uap)
{

	return (kern_extattr_set_path(td, __USER_CAP_STR(uap->path),
	    uap->attrnamespace,
	    __USER_CAP_STR(uap->attrname),
	    __USER_CAP(uap->data, uap->nbytes), uap->nbytes,
	    NOFOLLOW));
}

int
kern_extattr_set_path(struct thread *td,
    const char * __capability path, int attrnamespace,
    const char * __capability uattrname, void * __capability data,
    size_t nbytes, int follow)
{
	struct nameidata nd;
	char attrname[EXTATTR_MAXNAMELEN];
	int error;

	AUDIT_ARG_VALUE(attrnamespace);
	error = copyinstr_c(uattrname, &attrname[0], EXTATTR_MAXNAMELEN, NULL);
	if (error)
		return (error);
	AUDIT_ARG_TEXT(attrname);

	NDINIT_C(&nd, LOOKUP, follow | AUDITVNODE1, UIO_USERSPACE, path, td);
	error = namei(&nd);
	if (error)
		return (error);
	NDFREE(&nd, NDF_ONLY_PNBUF);

	error = extattr_set_vp(nd.ni_vp, attrnamespace, attrname, data,
	    nbytes, td);

	vrele(nd.ni_vp);
	return (error);
}

/*-
 * Get a named extended attribute on a file or directory
 *
 * Arguments: unlocked vnode "vp", attribute namespace "attrnamespace",
 *            kernelspace string pointer "attrname", userspace buffer
 *            pointer "data", buffer length "nbytes", thread "td".
 * Returns: 0 on success, an error number otherwise
 * Locks: none
 * References: vp must be a valid reference for the duration of the call
 */
static int
extattr_get_vp(struct vnode *vp, int attrnamespace, const char *attrname,
    void * __capability data, size_t nbytes, struct thread *td)
{
	struct uio auio, *auiop;
	kiovec_t aiov;
	ssize_t cnt;
	size_t size, *sizep;
	int error;

	if (nbytes > IOSIZE_MAX)
		return (EINVAL);

	vn_lock(vp, LK_SHARED | LK_RETRY);

	/*
	 * Slightly unusual semantics: if the user provides a NULL data
	 * pointer, they don't want to receive the data, just the maximum
	 * read length.
	 */
	auiop = NULL;
	sizep = NULL;
	cnt = 0;
	if (data != NULL) {
		IOVEC_INIT_C(&aiov, data, nbytes);
		auio.uio_iov = &aiov;
		auio.uio_iovcnt = 1;
		auio.uio_offset = 0;
		auio.uio_resid = nbytes;
		auio.uio_rw = UIO_READ;
		auio.uio_segflg = UIO_USERSPACE;
		auio.uio_td = td;
		auiop = &auio;
		cnt = nbytes;
	} else
		sizep = &size;

#ifdef MAC
	error = mac_vnode_check_getextattr(td->td_ucred, vp, attrnamespace,
	    attrname);
	if (error)
		goto done;
#endif

	error = VOP_GETEXTATTR(vp, attrnamespace, attrname, auiop, sizep,
	    td->td_ucred, td);

	if (auiop != NULL) {
		cnt -= auio.uio_resid;
		td->td_retval[0] = cnt;
	} else
		td->td_retval[0] = size;
#ifdef MAC
done:
#endif
	VOP_UNLOCK(vp, 0);
	return (error);
}

#ifndef _SYS_SYSPROTO_H_
struct extattr_get_fd_args {
	int fd;
	int attrnamespace;
	const char *attrname;
	void *data;
	size_t nbytes;
};
#endif
int
sys_extattr_get_fd(struct thread *td, struct extattr_get_fd_args *uap)
{

	return (kern_extattr_get_fd(td, uap->fd, uap->attrnamespace,
	    __USER_CAP_STR(uap->attrname),
	    __USER_CAP(uap->data, uap->nbytes), uap->nbytes));
}

int
kern_extattr_get_fd(struct thread *td, int fd, int attrnamespace,
    const char * __capability uattrname, void * __capability data,
    size_t nbytes)
{
	struct file *fp;
	char attrname[EXTATTR_MAXNAMELEN];
	cap_rights_t rights;
	int error;

	AUDIT_ARG_FD(fd);
	AUDIT_ARG_VALUE(attrnamespace);
	error = copyinstr_c(uattrname, &attrname[0], EXTATTR_MAXNAMELEN, NULL);
	if (error)
		return (error);
	AUDIT_ARG_TEXT(attrname);

	error = getvnode(td, fd,
	    cap_rights_init(&rights, CAP_EXTATTR_GET), &fp);
	if (error)
		return (error);

	error = extattr_get_vp(fp->f_vnode, attrnamespace,
	    attrname, data, nbytes, td);

	fdrop(fp, td);
	return (error);
}

#ifndef _SYS_SYSPROTO_H_
struct extattr_get_file_args {
	const char *path;
	int attrnamespace;
	const char *attrname;
	void *data;
	size_t nbytes;
};
#endif
int
sys_extattr_get_file(struct thread *td, struct extattr_get_file_args *uap)
{
	return (kern_extattr_get_path(td, __USER_CAP_STR(uap->path),
	    uap->attrnamespace, __USER_CAP_STR(uap->attrname),
	    __USER_CAP(uap->data, uap->nbytes), uap->nbytes, FOLLOW));
}

#ifndef _SYS_SYSPROTO_H_
struct extattr_get_link_args {
	const char *path;
	int attrnamespace;
	const char *attrname;
	void *data;
	size_t nbytes;
};
#endif
int
sys_extattr_get_link(struct thread *td, struct extattr_get_link_args *uap)
{
	return (kern_extattr_get_path(td, __USER_CAP_STR(uap->path),
	    uap->attrnamespace, __USER_CAP_STR(uap->attrname),
	    __USER_CAP(uap->data, uap->nbytes), uap->nbytes, NOFOLLOW));
}

int
kern_extattr_get_path(struct thread *td, const char * __capability path,
    int attrnamespace, const char * __capability uattrname,
    void * __capability data, size_t nbytes, int follow)
{
	struct nameidata nd;
	char attrname[EXTATTR_MAXNAMELEN];
	int error;

	AUDIT_ARG_VALUE(attrnamespace);
	error = copyinstr_c(uattrname, &attrname[0], EXTATTR_MAXNAMELEN, NULL);
	if (error)
		return (error);
	AUDIT_ARG_TEXT(attrname);

	NDINIT_C(&nd, LOOKUP, follow | AUDITVNODE1, UIO_USERSPACE, path, td);
	error = namei(&nd);
	if (error)
		return (error);
	NDFREE(&nd, NDF_ONLY_PNBUF);

	error = extattr_get_vp(nd.ni_vp, attrnamespace, attrname, data,
	    nbytes, td);

	vrele(nd.ni_vp);
	return (error);
}

/*
 * extattr_delete_vp(): Delete a named extended attribute on a file or
 *                      directory
 *
 * Arguments: unlocked vnode "vp", attribute namespace "attrnamespace",
 *            kernelspace string pointer "attrname", proc "p"
 * Returns: 0 on success, an error number otherwise
 * Locks: none
 * References: vp must be a valid reference for the duration of the call
 */
static int
extattr_delete_vp(struct vnode *vp, int attrnamespace, const char *attrname,
    struct thread *td)
{
	struct mount *mp;
	int error;

	error = vn_start_write(vp, &mp, V_WAIT | PCATCH);
	if (error)
		return (error);
	vn_lock(vp, LK_EXCLUSIVE | LK_RETRY);

#ifdef MAC
	error = mac_vnode_check_deleteextattr(td->td_ucred, vp, attrnamespace,
	    attrname);
	if (error)
		goto done;
#endif

	error = VOP_DELETEEXTATTR(vp, attrnamespace, attrname, td->td_ucred,
	    td);
	if (error == EOPNOTSUPP)
		error = VOP_SETEXTATTR(vp, attrnamespace, attrname, NULL,
		    td->td_ucred, td);
#ifdef MAC
done:
#endif
	VOP_UNLOCK(vp, 0);
	vn_finished_write(mp);
	return (error);
}

#ifndef _SYS_SYSPROTO_H_
struct extattr_delete_fd_args {
	int fd;
	int attrnamespace;
	const char *attrname;
};
#endif
int
sys_extattr_delete_fd(struct thread *td, struct extattr_delete_fd_args *uap)
{

	return (kern_extattr_delete_fd(td, uap->fd, uap->attrnamespace,
	    __USER_CAP_STR(uap->attrname)));
}

int
kern_extattr_delete_fd(struct thread *td, int fd, int attrnamespace,
    const char * __capability uattrname)
{
	struct file *fp;
	char attrname[EXTATTR_MAXNAMELEN];
	cap_rights_t rights;
	int error;

	AUDIT_ARG_FD(fd);
	AUDIT_ARG_VALUE(attrnamespace);
	error = copyinstr_c(uattrname, &attrname[0], EXTATTR_MAXNAMELEN, NULL);
	if (error)
		return (error);
	AUDIT_ARG_TEXT(attrname);

	error = getvnode(td, fd,
	    cap_rights_init(&rights, CAP_EXTATTR_DELETE), &fp);
	if (error)
		return (error);

	error = extattr_delete_vp(fp->f_vnode, attrnamespace,
	    attrname, td);
	fdrop(fp, td);
	return (error);
}

#ifndef _SYS_SYSPROTO_H_
struct extattr_delete_file_args {
	const char *path;
	int attrnamespace;
	const char *attrname;
};
#endif
int
sys_extattr_delete_file(struct thread *td, struct extattr_delete_file_args *uap)
{

	return (kern_extattr_delete_path(td, __USER_CAP_STR(uap->path),
	    uap->attrnamespace, __USER_CAP_STR(uap->attrname), FOLLOW));
}

#ifndef _SYS_SYSPROTO_H_
struct extattr_delete_link_args {
	const char *path;
	int attrnamespace;
	const char *attrname;
};
#endif
int
sys_extattr_delete_link(struct thread *td, struct extattr_delete_link_args *uap)
{

	return (kern_extattr_delete_path(td, __USER_CAP_STR(uap->path),
	    uap->attrnamespace, __USER_CAP_STR(uap->attrname), NOFOLLOW));
}

int
kern_extattr_delete_path(struct thread *td, const char * __capability path,
    int attrnamespace, const char * __capability uattrname, int follow)
{
	struct nameidata nd;
	char attrname[EXTATTR_MAXNAMELEN];
	int error;

	AUDIT_ARG_VALUE(attrnamespace);
	error = copyinstr_c(uattrname, &attrname[0], EXTATTR_MAXNAMELEN, NULL);
	if (error)
		return(error);
	AUDIT_ARG_TEXT(attrname);

	NDINIT_C(&nd, LOOKUP, follow | AUDITVNODE1, UIO_USERSPACE, path, td);
	error = namei(&nd);
	if (error)
		return(error);
	NDFREE(&nd, NDF_ONLY_PNBUF);

	error = extattr_delete_vp(nd.ni_vp, attrnamespace, attrname, td);
	vrele(nd.ni_vp);
	return(error);
}

/*-
 * Retrieve a list of extended attributes on a file or directory.
 *
 * Arguments: unlocked vnode "vp", attribute namespace 'attrnamespace",
 *            userspace buffer pointer "data", buffer length "nbytes",
 *            thread "td".
 * Returns: 0 on success, an error number otherwise
 * Locks: none
 * References: vp must be a valid reference for the duration of the call
 */
static int
extattr_list_vp(struct vnode *vp, int attrnamespace, void * __capability data,
    size_t nbytes, struct thread *td)
{
	struct uio auio, *auiop;
	size_t size, *sizep;
	kiovec_t aiov;
	ssize_t cnt;
	int error;

	if (nbytes > IOSIZE_MAX)
		return (EINVAL);

	vn_lock(vp, LK_EXCLUSIVE | LK_RETRY);

	auiop = NULL;
	sizep = NULL;
	cnt = 0;
	if (data != NULL) {
		IOVEC_INIT_C(&aiov, data, nbytes);
		auio.uio_iov = &aiov;
		auio.uio_iovcnt = 1;
		auio.uio_offset = 0;
		auio.uio_resid = nbytes;
		auio.uio_rw = UIO_READ;
		auio.uio_segflg = UIO_USERSPACE;
		auio.uio_td = td;
		auiop = &auio;
		cnt = nbytes;
	} else
		sizep = &size;

#ifdef MAC
	error = mac_vnode_check_listextattr(td->td_ucred, vp, attrnamespace);
	if (error)
		goto done;
#endif

	error = VOP_LISTEXTATTR(vp, attrnamespace, auiop, sizep,
	    td->td_ucred, td);

	if (auiop != NULL) {
		cnt -= auio.uio_resid;
		td->td_retval[0] = cnt;
	} else
		td->td_retval[0] = size;
#ifdef MAC
done:
#endif
	VOP_UNLOCK(vp, 0);
	return (error);
}


#ifndef _SYS_SYSPROTO_H_
struct extattr_list_fd_args {
	int fd;
	int attrnamespace;
	void *data;
	size_t nbytes;
};
#endif
int
sys_extattr_list_fd(struct thread *td, struct extattr_list_fd_args *uap)
{

	return (kern_extattr_list_fd(td, uap->fd, uap->attrnamespace,
	    __USER_CAP(uap->data, uap->nbytes), uap->nbytes));
}

int
kern_extattr_list_fd(struct thread *td, int fd, int attrnamespace,
    void * __capability data, size_t nbytes)
{
	struct file *fp;
	cap_rights_t rights;
	int error;

	AUDIT_ARG_FD(fd);
	AUDIT_ARG_VALUE(attrnamespace);
	error = getvnode(td, fd,
	    cap_rights_init(&rights, CAP_EXTATTR_LIST), &fp);
	if (error)
		return (error);

	error = extattr_list_vp(fp->f_vnode, attrnamespace, data, nbytes, td);

	fdrop(fp, td);
	return (error);
}

#ifndef _SYS_SYSPROTO_H_
struct extattr_list_file_args {
	const char *path;
	int attrnamespace;
	void *data;
	size_t nbytes;
}
#endif
int
sys_extattr_list_file(struct thread *td, struct extattr_list_file_args *uap)
{

	return (kern_extattr_list_path(td, __USER_CAP_STR(uap->path),
	    uap->attrnamespace, __USER_CAP(uap->data, uap->nbytes),
	    uap->nbytes, FOLLOW));
}

#ifndef _SYS_SYSPROTO_H_
struct extattr_list_link_args {
	const char *path;
	int attrnamespace;
	void *data;
	size_t nbytes;
};
#endif
int
sys_extattr_list_link(struct thread *td, struct extattr_list_link_args *uap)
{

	return (kern_extattr_list_path(td, __USER_CAP_STR(uap->path),
	    uap->attrnamespace, __USER_CAP(uap->data, uap->nbytes),
	    uap->nbytes, NOFOLLOW));
}

int
kern_extattr_list_path(struct thread *td, const char * __capability path,
    int attrnamespace, void * __capability data, size_t nbytes, int follow)
{
	struct nameidata nd;
	int error;

	AUDIT_ARG_VALUE(attrnamespace);
	NDINIT_C(&nd, LOOKUP, follow | AUDITVNODE1, UIO_USERSPACE, path, td);
	error = namei(&nd);
	if (error)
		return (error);
	NDFREE(&nd, NDF_ONLY_PNBUF);

	error = extattr_list_vp(nd.ni_vp, attrnamespace, data, nbytes, td);

	vrele(nd.ni_vp);
	return (error);
}
