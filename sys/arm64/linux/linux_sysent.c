/*
 * System call switch table.
 *
 * DO NOT EDIT-- this file is automatically @generated.
 * $FreeBSD$
 */

#include <sys/param.h>
#include <sys/sysent.h>
#include <sys/sysproto.h>
#include <compat/linux/linux_sysproto.h>
#include <arm64/linux/linux.h>
#include <arm64/linux/linux_proto.h>

#define AS(name) (sizeof(struct name) / sizeof(syscallarg_t))

/* The casts are bogus but will do for now. */
struct sysent linux_sysent[] = {
#define	nosys	linux_nosys
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 0 = linux_io_setup */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 1 = linux_io_destroy */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 2 = linux_io_submit */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 3 = linux_io_cancel */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 4 = linux_io_getevents */
	{ AS(linux_setxattr_args), (sy_call_t *)linux_setxattr, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 5 = linux_setxattr */
	{ AS(linux_lsetxattr_args), (sy_call_t *)linux_lsetxattr, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 6 = linux_lsetxattr */
	{ AS(linux_fsetxattr_args), (sy_call_t *)linux_fsetxattr, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 7 = linux_fsetxattr */
	{ AS(linux_getxattr_args), (sy_call_t *)linux_getxattr, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 8 = linux_getxattr */
	{ AS(linux_lgetxattr_args), (sy_call_t *)linux_lgetxattr, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 9 = linux_lgetxattr */
	{ AS(linux_fgetxattr_args), (sy_call_t *)linux_fgetxattr, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 10 = linux_fgetxattr */
	{ AS(linux_listxattr_args), (sy_call_t *)linux_listxattr, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 11 = linux_listxattr */
	{ AS(linux_llistxattr_args), (sy_call_t *)linux_llistxattr, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 12 = linux_llistxattr */
	{ AS(linux_flistxattr_args), (sy_call_t *)linux_flistxattr, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 13 = linux_flistxattr */
	{ AS(linux_removexattr_args), (sy_call_t *)linux_removexattr, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 14 = linux_removexattr */
	{ AS(linux_lremovexattr_args), (sy_call_t *)linux_lremovexattr, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 15 = linux_lremovexattr */
	{ AS(linux_fremovexattr_args), (sy_call_t *)linux_fremovexattr, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 16 = linux_fremovexattr */
	{ AS(linux_getcwd_args), (sy_call_t *)linux_getcwd, AUE_GETCWD, NULL, 0, 0, 0, SY_THR_STATIC },	/* 17 = linux_getcwd */
	{ 0, (sy_call_t *)linux_lookup_dcookie, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 18 = linux_lookup_dcookie */
	{ AS(linux_eventfd2_args), (sy_call_t *)linux_eventfd2, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 19 = linux_eventfd2 */
	{ AS(linux_epoll_create1_args), (sy_call_t *)linux_epoll_create1, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 20 = linux_epoll_create1 */
	{ AS(linux_epoll_ctl_args), (sy_call_t *)linux_epoll_ctl, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 21 = linux_epoll_ctl */
	{ AS(linux_epoll_pwait_args), (sy_call_t *)linux_epoll_pwait, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 22 = linux_epoll_pwait */
	{ AS(dup_args), (sy_call_t *)sys_dup, AUE_DUP, NULL, 0, 0, 0, SY_THR_STATIC },	/* 23 = dup */
	{ AS(linux_dup3_args), (sy_call_t *)linux_dup3, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 24 = linux_dup3 */
	{ AS(linux_fcntl_args), (sy_call_t *)linux_fcntl, AUE_FCNTL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 25 = linux_fcntl */
	{ AS(linux_inotify_init1_args), (sy_call_t *)linux_inotify_init1, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 26 = linux_inotify_init1 */
	{ 0, (sy_call_t *)linux_inotify_add_watch, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 27 = linux_inotify_add_watch */
	{ 0, (sy_call_t *)linux_inotify_rm_watch, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 28 = linux_inotify_rm_watch */
	{ AS(linux_ioctl_args), (sy_call_t *)linux_ioctl, AUE_IOCTL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 29 = linux_ioctl */
	{ 0, (sy_call_t *)linux_ioprio_set, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 30 = linux_ioprio_set */
	{ 0, (sy_call_t *)linux_ioprio_get, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 31 = linux_ioprio_get */
	{ AS(flock_args), (sy_call_t *)sys_flock, AUE_FLOCK, NULL, 0, 0, 0, SY_THR_STATIC },	/* 32 = flock */
	{ AS(linux_mknodat_args), (sy_call_t *)linux_mknodat, AUE_MKNODAT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 33 = linux_mknodat */
	{ AS(linux_mkdirat_args), (sy_call_t *)linux_mkdirat, AUE_MKDIRAT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 34 = linux_mkdirat */
	{ AS(linux_unlinkat_args), (sy_call_t *)linux_unlinkat, AUE_UNLINKAT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 35 = linux_unlinkat */
	{ AS(linux_symlinkat_args), (sy_call_t *)linux_symlinkat, AUE_SYMLINKAT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 36 = linux_symlinkat */
	{ AS(linux_linkat_args), (sy_call_t *)linux_linkat, AUE_LINKAT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 37 = linux_linkat */
	{ AS(linux_renameat_args), (sy_call_t *)linux_renameat, AUE_RENAMEAT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 38 = linux_renameat */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 39 = linux_umount2 */
	{ AS(linux_mount_args), (sy_call_t *)linux_mount, AUE_MOUNT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 40 = linux_mount */
	{ 0, (sy_call_t *)linux_pivot_root, AUE_PIVOT_ROOT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 41 = linux_pivot_root */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 42 = nfsservctl */
	{ AS(linux_statfs_args), (sy_call_t *)linux_statfs, AUE_STATFS, NULL, 0, 0, 0, SY_THR_STATIC },	/* 43 = linux_statfs */
	{ AS(linux_fstatfs_args), (sy_call_t *)linux_fstatfs, AUE_FSTATFS, NULL, 0, 0, 0, SY_THR_STATIC },	/* 44 = linux_fstatfs */
	{ AS(linux_truncate_args), (sy_call_t *)linux_truncate, AUE_TRUNCATE, NULL, 0, 0, 0, SY_THR_STATIC },	/* 45 = linux_truncate */
	{ AS(linux_ftruncate_args), (sy_call_t *)linux_ftruncate, AUE_FTRUNCATE, NULL, 0, 0, 0, SY_THR_STATIC },	/* 46 = linux_ftruncate */
	{ AS(linux_fallocate_args), (sy_call_t *)linux_fallocate, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 47 = linux_fallocate */
	{ AS(linux_faccessat_args), (sy_call_t *)linux_faccessat, AUE_FACCESSAT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 48 = linux_faccessat */
	{ AS(linux_chdir_args), (sy_call_t *)linux_chdir, AUE_CHDIR, NULL, 0, 0, 0, SY_THR_STATIC },	/* 49 = linux_chdir */
	{ AS(fchdir_args), (sy_call_t *)sys_fchdir, AUE_FCHDIR, NULL, 0, 0, 0, SY_THR_STATIC },	/* 50 = fchdir */
	{ AS(chroot_args), (sy_call_t *)sys_chroot, AUE_CHROOT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 51 = chroot */
	{ AS(fchmod_args), (sy_call_t *)sys_fchmod, AUE_FCHMOD, NULL, 0, 0, 0, SY_THR_STATIC },	/* 52 = fchmod */
	{ AS(linux_fchmodat_args), (sy_call_t *)linux_fchmodat, AUE_FCHMODAT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 53 = linux_fchmodat */
	{ AS(linux_fchownat_args), (sy_call_t *)linux_fchownat, AUE_FCHOWNAT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 54 = linux_fchownat */
	{ AS(fchown_args), (sy_call_t *)sys_fchown, AUE_FCHOWN, NULL, 0, 0, 0, SY_THR_STATIC },	/* 55 = fchown */
	{ AS(linux_openat_args), (sy_call_t *)linux_openat, AUE_OPEN_RWTC, NULL, 0, 0, 0, SY_THR_STATIC },	/* 56 = linux_openat */
	{ AS(close_args), (sy_call_t *)sys_close, AUE_CLOSE, NULL, 0, 0, 0, SY_THR_STATIC },	/* 57 = close */
	{ 0, (sy_call_t *)linux_vhangup, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 58 = linux_vhangup */
	{ AS(linux_pipe2_args), (sy_call_t *)linux_pipe2, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 59 = linux_pipe2 */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 60 = linux_quotactl */
	{ AS(linux_getdents64_args), (sy_call_t *)linux_getdents64, AUE_GETDIRENTRIES, NULL, 0, 0, 0, SY_THR_STATIC },	/* 61 = linux_getdents64 */
	{ AS(linux_lseek_args), (sy_call_t *)linux_lseek, AUE_LSEEK, NULL, 0, 0, 0, SY_THR_STATIC },	/* 62 = linux_lseek */
	{ AS(read_args), (sy_call_t *)sys_read, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 63 = read */
	{ AS(write_args), (sy_call_t *)sys_write, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 64 = write */
	{ AS(readv_args), (sy_call_t *)sys_readv, AUE_READV, NULL, 0, 0, 0, SY_THR_STATIC },	/* 65 = readv */
	{ AS(writev_args), (sy_call_t *)sys_writev, AUE_WRITEV, NULL, 0, 0, 0, SY_THR_STATIC },	/* 66 = writev */
	{ AS(linux_pread_args), (sy_call_t *)linux_pread, AUE_PREAD, NULL, 0, 0, 0, SY_THR_STATIC },	/* 67 = linux_pread */
	{ AS(linux_pwrite_args), (sy_call_t *)linux_pwrite, AUE_PWRITE, NULL, 0, 0, 0, SY_THR_STATIC },	/* 68 = linux_pwrite */
	{ AS(linux_preadv_args), (sy_call_t *)linux_preadv, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 69 = linux_preadv */
	{ AS(linux_pwritev_args), (sy_call_t *)linux_pwritev, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 70 = linux_pwritev */
	{ AS(linux_sendfile_args), (sy_call_t *)linux_sendfile, AUE_SENDFILE, NULL, 0, 0, 0, SY_THR_STATIC },	/* 71 = linux_sendfile */
	{ AS(linux_pselect6_args), (sy_call_t *)linux_pselect6, AUE_SELECT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 72 = linux_pselect6 */
	{ AS(linux_ppoll_args), (sy_call_t *)linux_ppoll, AUE_POLL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 73 = linux_ppoll */
	{ 0, (sy_call_t *)linux_signalfd4, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 74 = linux_signalfd4 */
	{ 0, (sy_call_t *)linux_vmsplice, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 75 = linux_vmsplice */
	{ AS(linux_splice_args), (sy_call_t *)linux_splice, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 76 = linux_splice */
	{ 0, (sy_call_t *)linux_tee, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },		/* 77 = linux_tee */
	{ AS(linux_readlinkat_args), (sy_call_t *)linux_readlinkat, AUE_READLINKAT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 78 = linux_readlinkat */
	{ AS(linux_newfstatat_args), (sy_call_t *)linux_newfstatat, AUE_FSTATAT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 79 = linux_newfstatat */
	{ AS(linux_newfstat_args), (sy_call_t *)linux_newfstat, AUE_FSTAT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 80 = linux_newfstat */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 81 = linux_sync */
	{ AS(fsync_args), (sy_call_t *)sys_fsync, AUE_FSYNC, NULL, 0, 0, 0, SY_THR_STATIC },	/* 82 = fsync */
	{ AS(linux_fdatasync_args), (sy_call_t *)linux_fdatasync, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 83 = linux_fdatasync */
	{ AS(linux_sync_file_range_args), (sy_call_t *)linux_sync_file_range, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 84 = linux_sync_file_range */
	{ AS(linux_timerfd_create_args), (sy_call_t *)linux_timerfd_create, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 85 = linux_timerfd_create */
	{ AS(linux_timerfd_settime_args), (sy_call_t *)linux_timerfd_settime, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 86 = linux_timerfd_settime */
	{ AS(linux_timerfd_gettime_args), (sy_call_t *)linux_timerfd_gettime, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 87 = linux_timerfd_gettime */
	{ AS(linux_utimensat_args), (sy_call_t *)linux_utimensat, AUE_FUTIMESAT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 88 = linux_utimensat */
	{ AS(acct_args), (sy_call_t *)sys_acct, AUE_ACCT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 89 = acct */
	{ AS(linux_capget_args), (sy_call_t *)linux_capget, AUE_CAPGET, NULL, 0, 0, 0, SY_THR_STATIC },	/* 90 = linux_capget */
	{ AS(linux_capset_args), (sy_call_t *)linux_capset, AUE_CAPSET, NULL, 0, 0, 0, SY_THR_STATIC },	/* 91 = linux_capset */
	{ AS(linux_personality_args), (sy_call_t *)linux_personality, AUE_PERSONALITY, NULL, 0, 0, 0, SY_THR_STATIC },	/* 92 = linux_personality */
	{ AS(linux_exit_args), (sy_call_t *)linux_exit, AUE_EXIT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 93 = linux_exit */
	{ AS(linux_exit_group_args), (sy_call_t *)linux_exit_group, AUE_EXIT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 94 = linux_exit_group */
	{ AS(linux_waitid_args), (sy_call_t *)linux_waitid, AUE_WAIT6, NULL, 0, 0, 0, SY_THR_STATIC },	/* 95 = linux_waitid */
	{ AS(linux_set_tid_address_args), (sy_call_t *)linux_set_tid_address, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 96 = linux_set_tid_address */
	{ 0, (sy_call_t *)linux_unshare, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 97 = linux_unshare */
	{ AS(linux_sys_futex_args), (sy_call_t *)linux_sys_futex, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 98 = linux_sys_futex */
	{ AS(linux_set_robust_list_args), (sy_call_t *)linux_set_robust_list, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 99 = linux_set_robust_list */
	{ AS(linux_get_robust_list_args), (sy_call_t *)linux_get_robust_list, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 100 = linux_get_robust_list */
	{ AS(linux_nanosleep_args), (sy_call_t *)linux_nanosleep, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 101 = linux_nanosleep */
	{ AS(linux_getitimer_args), (sy_call_t *)linux_getitimer, AUE_GETITIMER, NULL, 0, 0, 0, SY_THR_STATIC },	/* 102 = linux_getitimer */
	{ AS(linux_setitimer_args), (sy_call_t *)linux_setitimer, AUE_SETITIMER, NULL, 0, 0, 0, SY_THR_STATIC },	/* 103 = linux_setitimer */
	{ 0, (sy_call_t *)linux_kexec_load, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 104 = linux_kexec_load */
	{ 0, (sy_call_t *)linux_init_module, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 105 = linux_init_module */
	{ 0, (sy_call_t *)linux_delete_module, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 106 = linux_delete_module */
	{ AS(linux_timer_create_args), (sy_call_t *)linux_timer_create, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 107 = linux_timer_create */
	{ AS(linux_timer_gettime_args), (sy_call_t *)linux_timer_gettime, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 108 = linux_timer_gettime */
	{ AS(linux_timer_getoverrun_args), (sy_call_t *)linux_timer_getoverrun, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 109 = linux_timer_getoverrun */
	{ AS(linux_timer_settime_args), (sy_call_t *)linux_timer_settime, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 110 = linux_timer_settime */
	{ AS(linux_timer_delete_args), (sy_call_t *)linux_timer_delete, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 111 = linux_timer_delete */
	{ AS(linux_clock_settime_args), (sy_call_t *)linux_clock_settime, AUE_CLOCK_SETTIME, NULL, 0, 0, 0, SY_THR_STATIC },	/* 112 = linux_clock_settime */
	{ AS(linux_clock_gettime_args), (sy_call_t *)linux_clock_gettime, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 113 = linux_clock_gettime */
	{ AS(linux_clock_getres_args), (sy_call_t *)linux_clock_getres, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 114 = linux_clock_getres */
	{ AS(linux_clock_nanosleep_args), (sy_call_t *)linux_clock_nanosleep, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 115 = linux_clock_nanosleep */
	{ AS(linux_syslog_args), (sy_call_t *)linux_syslog, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 116 = linux_syslog */
	{ AS(linux_ptrace_args), (sy_call_t *)linux_ptrace, AUE_PTRACE, NULL, 0, 0, 0, SY_THR_STATIC },	/* 117 = linux_ptrace */
	{ AS(linux_sched_setparam_args), (sy_call_t *)linux_sched_setparam, AUE_SCHED_SETPARAM, NULL, 0, 0, 0, SY_THR_STATIC },	/* 118 = linux_sched_setparam */
	{ AS(linux_sched_setscheduler_args), (sy_call_t *)linux_sched_setscheduler, AUE_SCHED_SETSCHEDULER, NULL, 0, 0, 0, SY_THR_STATIC },	/* 119 = linux_sched_setscheduler */
	{ AS(linux_sched_getscheduler_args), (sy_call_t *)linux_sched_getscheduler, AUE_SCHED_GETSCHEDULER, NULL, 0, 0, 0, SY_THR_STATIC },	/* 120 = linux_sched_getscheduler */
	{ AS(linux_sched_getparam_args), (sy_call_t *)linux_sched_getparam, AUE_SCHED_GETPARAM, NULL, 0, 0, 0, SY_THR_STATIC },	/* 121 = linux_sched_getparam */
	{ AS(linux_sched_setaffinity_args), (sy_call_t *)linux_sched_setaffinity, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 122 = linux_sched_setaffinity */
	{ AS(linux_sched_getaffinity_args), (sy_call_t *)linux_sched_getaffinity, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 123 = linux_sched_getaffinity */
	{ 0, (sy_call_t *)sys_sched_yield, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 124 = sched_yield */
	{ AS(linux_sched_get_priority_max_args), (sy_call_t *)linux_sched_get_priority_max, AUE_SCHED_GET_PRIORITY_MAX, NULL, 0, 0, 0, SY_THR_STATIC },	/* 125 = linux_sched_get_priority_max */
	{ AS(linux_sched_get_priority_min_args), (sy_call_t *)linux_sched_get_priority_min, AUE_SCHED_GET_PRIORITY_MIN, NULL, 0, 0, 0, SY_THR_STATIC },	/* 126 = linux_sched_get_priority_min */
	{ AS(linux_sched_rr_get_interval_args), (sy_call_t *)linux_sched_rr_get_interval, AUE_SCHED_RR_GET_INTERVAL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 127 = linux_sched_rr_get_interval */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 128 = restart_syscall */
	{ AS(linux_kill_args), (sy_call_t *)linux_kill, AUE_KILL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 129 = linux_kill */
	{ AS(linux_tkill_args), (sy_call_t *)linux_tkill, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 130 = linux_tkill */
	{ AS(linux_tgkill_args), (sy_call_t *)linux_tgkill, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 131 = linux_tgkill */
	{ AS(linux_sigaltstack_args), (sy_call_t *)linux_sigaltstack, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 132 = linux_sigaltstack */
	{ AS(linux_rt_sigsuspend_args), (sy_call_t *)linux_rt_sigsuspend, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 133 = linux_rt_sigsuspend */
	{ AS(linux_rt_sigaction_args), (sy_call_t *)linux_rt_sigaction, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 134 = linux_rt_sigaction */
	{ AS(linux_rt_sigprocmask_args), (sy_call_t *)linux_rt_sigprocmask, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 135 = linux_rt_sigprocmask */
	{ AS(linux_rt_sigpending_args), (sy_call_t *)linux_rt_sigpending, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 136 = linux_rt_sigpending */
	{ AS(linux_rt_sigtimedwait_args), (sy_call_t *)linux_rt_sigtimedwait, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 137 = linux_rt_sigtimedwait */
	{ AS(linux_rt_sigqueueinfo_args), (sy_call_t *)linux_rt_sigqueueinfo, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 138 = linux_rt_sigqueueinfo */
	{ AS(linux_rt_sigreturn_args), (sy_call_t *)linux_rt_sigreturn, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 139 = linux_rt_sigreturn */
	{ AS(setpriority_args), (sy_call_t *)sys_setpriority, AUE_SETPRIORITY, NULL, 0, 0, 0, SY_THR_STATIC },	/* 140 = setpriority */
	{ AS(linux_getpriority_args), (sy_call_t *)linux_getpriority, AUE_GETPRIORITY, NULL, 0, 0, 0, SY_THR_STATIC },	/* 141 = linux_getpriority */
	{ AS(linux_reboot_args), (sy_call_t *)linux_reboot, AUE_REBOOT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 142 = linux_reboot */
	{ AS(setregid_args), (sy_call_t *)sys_setregid, AUE_SETREGID, NULL, 0, 0, 0, SY_THR_STATIC },	/* 143 = setregid */
	{ AS(setgid_args), (sy_call_t *)sys_setgid, AUE_SETGID, NULL, 0, 0, 0, SY_THR_STATIC },	/* 144 = setgid */
	{ AS(setreuid_args), (sy_call_t *)sys_setreuid, AUE_SETREUID, NULL, 0, 0, 0, SY_THR_STATIC },	/* 145 = setreuid */
	{ AS(setuid_args), (sy_call_t *)sys_setuid, AUE_SETUID, NULL, 0, 0, 0, SY_THR_STATIC },	/* 146 = setuid */
	{ AS(setresuid_args), (sy_call_t *)sys_setresuid, AUE_SETRESUID, NULL, 0, 0, 0, SY_THR_STATIC },	/* 147 = setresuid */
	{ AS(getresuid_args), (sy_call_t *)sys_getresuid, AUE_GETRESUID, NULL, 0, 0, 0, SY_THR_STATIC },	/* 148 = getresuid */
	{ AS(setresgid_args), (sy_call_t *)sys_setresgid, AUE_SETRESGID, NULL, 0, 0, 0, SY_THR_STATIC },	/* 149 = setresgid */
	{ AS(getresgid_args), (sy_call_t *)sys_getresgid, AUE_GETRESGID, NULL, 0, 0, 0, SY_THR_STATIC },	/* 150 = getresgid */
	{ AS(linux_setfsuid_args), (sy_call_t *)linux_setfsuid, AUE_SETFSUID, NULL, 0, 0, 0, SY_THR_STATIC },	/* 151 = linux_setfsuid */
	{ AS(linux_setfsgid_args), (sy_call_t *)linux_setfsgid, AUE_SETFSGID, NULL, 0, 0, 0, SY_THR_STATIC },	/* 152 = linux_setfsgid */
	{ AS(linux_times_args), (sy_call_t *)linux_times, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 153 = linux_times */
	{ AS(setpgid_args), (sy_call_t *)sys_setpgid, AUE_SETPGRP, NULL, 0, 0, 0, SY_THR_STATIC },	/* 154 = setpgid */
	{ AS(getpgid_args), (sy_call_t *)sys_getpgid, AUE_GETPGID, NULL, 0, 0, 0, SY_THR_STATIC },	/* 155 = getpgid */
	{ AS(linux_getsid_args), (sy_call_t *)linux_getsid, AUE_GETSID, NULL, 0, 0, 0, SY_THR_STATIC },	/* 156 = linux_getsid */
	{ 0, (sy_call_t *)sys_setsid, AUE_SETSID, NULL, 0, 0, 0, SY_THR_STATIC },	/* 157 = setsid */
	{ AS(linux_getgroups_args), (sy_call_t *)linux_getgroups, AUE_GETGROUPS, NULL, 0, 0, 0, SY_THR_STATIC },	/* 158 = linux_getgroups */
	{ AS(linux_setgroups_args), (sy_call_t *)linux_setgroups, AUE_SETGROUPS, NULL, 0, 0, 0, SY_THR_STATIC },	/* 159 = linux_setgroups */
	{ AS(linux_newuname_args), (sy_call_t *)linux_newuname, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 160 = linux_newuname */
	{ AS(linux_sethostname_args), (sy_call_t *)linux_sethostname, AUE_SYSCTL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 161 = linux_sethostname */
	{ AS(linux_setdomainname_args), (sy_call_t *)linux_setdomainname, AUE_SYSCTL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 162 = linux_setdomainname */
	{ AS(linux_getrlimit_args), (sy_call_t *)linux_getrlimit, AUE_GETRLIMIT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 163 = linux_getrlimit */
	{ AS(linux_setrlimit_args), (sy_call_t *)linux_setrlimit, AUE_SETRLIMIT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 164 = linux_setrlimit */
	{ AS(getrusage_args), (sy_call_t *)sys_getrusage, AUE_GETRUSAGE, NULL, 0, 0, 0, SY_THR_STATIC },	/* 165 = getrusage */
	{ AS(umask_args), (sy_call_t *)sys_umask, AUE_UMASK, NULL, 0, 0, 0, SY_THR_STATIC },	/* 166 = umask */
	{ AS(linux_prctl_args), (sy_call_t *)linux_prctl, AUE_PRCTL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 167 = linux_prctl */
	{ AS(linux_getcpu_args), (sy_call_t *)linux_getcpu, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 168 = linux_getcpu */
	{ AS(gettimeofday_args), (sy_call_t *)sys_gettimeofday, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 169 = gettimeofday */
	{ AS(settimeofday_args), (sy_call_t *)sys_settimeofday, AUE_SETTIMEOFDAY, NULL, 0, 0, 0, SY_THR_STATIC },	/* 170 = settimeofday */
	{ 0, (sy_call_t *)linux_adjtimex, AUE_ADJTIME, NULL, 0, 0, 0, SY_THR_STATIC },	/* 171 = linux_adjtimex */
	{ 0, (sy_call_t *)linux_getpid, AUE_GETPID, NULL, 0, 0, 0, SY_THR_STATIC },	/* 172 = linux_getpid */
	{ 0, (sy_call_t *)linux_getppid, AUE_GETPPID, NULL, 0, 0, 0, SY_THR_STATIC },	/* 173 = linux_getppid */
	{ 0, (sy_call_t *)linux_getuid, AUE_GETUID, NULL, 0, 0, 0, SY_THR_STATIC },	/* 174 = linux_getuid */
	{ 0, (sy_call_t *)sys_geteuid, AUE_GETEUID, NULL, 0, 0, 0, SY_THR_STATIC },	/* 175 = geteuid */
	{ 0, (sy_call_t *)linux_getgid, AUE_GETGID, NULL, 0, 0, 0, SY_THR_STATIC },	/* 176 = linux_getgid */
	{ 0, (sy_call_t *)sys_getegid, AUE_GETEGID, NULL, 0, 0, 0, SY_THR_STATIC },	/* 177 = getegid */
	{ 0, (sy_call_t *)linux_gettid, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 178 = linux_gettid */
	{ AS(linux_sysinfo_args), (sy_call_t *)linux_sysinfo, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 179 = linux_sysinfo */
	{ AS(linux_mq_open_args), (sy_call_t *)linux_mq_open, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 180 = linux_mq_open */
	{ AS(linux_mq_unlink_args), (sy_call_t *)linux_mq_unlink, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 181 = linux_mq_unlink */
	{ AS(linux_mq_timedsend_args), (sy_call_t *)linux_mq_timedsend, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 182 = linux_mq_timedsend */
	{ AS(linux_mq_timedreceive_args), (sy_call_t *)linux_mq_timedreceive, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 183 = linux_mq_timedreceive */
	{ AS(linux_mq_notify_args), (sy_call_t *)linux_mq_notify, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 184 = linux_mq_notify */
	{ AS(linux_mq_getsetattr_args), (sy_call_t *)linux_mq_getsetattr, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 185 = linux_mq_getsetattr */
	{ AS(linux_msgget_args), (sy_call_t *)linux_msgget, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 186 = linux_msgget */
	{ AS(linux_msgctl_args), (sy_call_t *)linux_msgctl, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 187 = linux_msgctl */
	{ AS(linux_msgrcv_args), (sy_call_t *)linux_msgrcv, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 188 = linux_msgrcv */
	{ AS(linux_msgsnd_args), (sy_call_t *)linux_msgsnd, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 189 = linux_msgsnd */
	{ AS(linux_semget_args), (sy_call_t *)linux_semget, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 190 = linux_semget */
	{ AS(linux_semctl_args), (sy_call_t *)linux_semctl, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 191 = linux_semctl */
	{ 0, (sy_call_t *)linux_semtimedop, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 192 = linux_semtimedop */
	{ AS(linux_semop_args), (sy_call_t *)linux_semop, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 193 = linux_semop */
	{ AS(linux_shmget_args), (sy_call_t *)linux_shmget, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 194 = linux_shmget */
	{ AS(linux_shmctl_args), (sy_call_t *)linux_shmctl, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 195 = linux_shmctl */
	{ AS(linux_shmat_args), (sy_call_t *)linux_shmat, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 196 = linux_shmat */
	{ AS(linux_shmdt_args), (sy_call_t *)linux_shmdt, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 197 = linux_shmdt */
	{ AS(linux_socket_args), (sy_call_t *)linux_socket, AUE_SOCKET, NULL, 0, 0, 0, SY_THR_STATIC },	/* 198 = linux_socket */
	{ AS(linux_socketpair_args), (sy_call_t *)linux_socketpair, AUE_SOCKETPAIR, NULL, 0, 0, 0, SY_THR_STATIC },	/* 199 = linux_socketpair */
	{ AS(linux_bind_args), (sy_call_t *)linux_bind, AUE_BIND, NULL, 0, 0, 0, SY_THR_STATIC },	/* 200 = linux_bind */
	{ AS(linux_listen_args), (sy_call_t *)linux_listen, AUE_LISTEN, NULL, 0, 0, 0, SY_THR_STATIC },	/* 201 = linux_listen */
	{ AS(linux_accept_args), (sy_call_t *)linux_accept, AUE_ACCEPT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 202 = linux_accept */
	{ AS(linux_connect_args), (sy_call_t *)linux_connect, AUE_CONNECT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 203 = linux_connect */
	{ AS(linux_getsockname_args), (sy_call_t *)linux_getsockname, AUE_GETSOCKNAME, NULL, 0, 0, 0, SY_THR_STATIC },	/* 204 = linux_getsockname */
	{ AS(linux_getpeername_args), (sy_call_t *)linux_getpeername, AUE_GETPEERNAME, NULL, 0, 0, 0, SY_THR_STATIC },	/* 205 = linux_getpeername */
	{ AS(linux_sendto_args), (sy_call_t *)linux_sendto, AUE_SENDTO, NULL, 0, 0, 0, SY_THR_STATIC },	/* 206 = linux_sendto */
	{ AS(linux_recvfrom_args), (sy_call_t *)linux_recvfrom, AUE_RECVFROM, NULL, 0, 0, 0, SY_THR_STATIC },	/* 207 = linux_recvfrom */
	{ AS(linux_setsockopt_args), (sy_call_t *)linux_setsockopt, AUE_SETSOCKOPT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 208 = linux_setsockopt */
	{ AS(linux_getsockopt_args), (sy_call_t *)linux_getsockopt, AUE_GETSOCKOPT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 209 = linux_getsockopt */
	{ AS(linux_shutdown_args), (sy_call_t *)linux_shutdown, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 210 = linux_shutdown */
	{ AS(linux_sendmsg_args), (sy_call_t *)linux_sendmsg, AUE_SENDMSG, NULL, 0, 0, 0, SY_THR_STATIC },	/* 211 = linux_sendmsg */
	{ AS(linux_recvmsg_args), (sy_call_t *)linux_recvmsg, AUE_RECVMSG, NULL, 0, 0, 0, SY_THR_STATIC },	/* 212 = linux_recvmsg */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 213 = linux_readahead */
	{ AS(linux_brk_args), (sy_call_t *)linux_brk, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 214 = linux_brk */
	{ AS(munmap_args), (sy_call_t *)sys_munmap, AUE_MUNMAP, NULL, 0, 0, 0, SY_THR_STATIC },	/* 215 = munmap */
	{ AS(linux_mremap_args), (sy_call_t *)linux_mremap, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 216 = linux_mremap */
	{ 0, (sy_call_t *)linux_add_key, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 217 = linux_add_key */
	{ 0, (sy_call_t *)linux_request_key, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 218 = linux_request_key */
	{ 0, (sy_call_t *)linux_keyctl, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 219 = linux_keyctl */
	{ AS(linux_clone_args), (sy_call_t *)linux_clone, AUE_RFORK, NULL, 0, 0, 0, SY_THR_STATIC },	/* 220 = linux_clone */
	{ AS(linux_execve_args), (sy_call_t *)linux_execve, AUE_EXECVE, NULL, 0, 0, 0, SY_THR_STATIC },	/* 221 = linux_execve */
	{ AS(linux_mmap2_args), (sy_call_t *)linux_mmap2, AUE_MMAP, NULL, 0, 0, 0, SY_THR_STATIC },	/* 222 = linux_mmap2 */
	{ AS(linux_fadvise64_args), (sy_call_t *)linux_fadvise64, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 223 = linux_fadvise64 */
	{ AS(swapon_args), (sy_call_t *)sys_swapon, AUE_SWAPON, NULL, 0, 0, 0, SY_THR_STATIC },	/* 224 = swapon */
	{ 0, (sy_call_t *)linux_swapoff, AUE_SWAPOFF, NULL, 0, 0, 0, SY_THR_STATIC },	/* 225 = linux_swapoff */
	{ AS(linux_mprotect_args), (sy_call_t *)linux_mprotect, AUE_MPROTECT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 226 = linux_mprotect */
	{ AS(linux_msync_args), (sy_call_t *)linux_msync, AUE_MSYNC, NULL, 0, 0, 0, SY_THR_STATIC },	/* 227 = linux_msync */
	{ AS(mlock_args), (sy_call_t *)sys_mlock, AUE_MLOCK, NULL, 0, 0, 0, SY_THR_STATIC },	/* 228 = mlock */
	{ AS(munlock_args), (sy_call_t *)sys_munlock, AUE_MUNLOCK, NULL, 0, 0, 0, SY_THR_STATIC },	/* 229 = munlock */
	{ AS(mlockall_args), (sy_call_t *)sys_mlockall, AUE_MLOCKALL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 230 = mlockall */
	{ 0, (sy_call_t *)sys_munlockall, AUE_MUNLOCKALL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 231 = munlockall */
	{ AS(linux_mincore_args), (sy_call_t *)linux_mincore, AUE_MINCORE, NULL, 0, 0, 0, SY_THR_STATIC },	/* 232 = linux_mincore */
	{ AS(linux_madvise_args), (sy_call_t *)linux_madvise, AUE_MADVISE, NULL, 0, 0, 0, SY_THR_STATIC },	/* 233 = linux_madvise */
	{ 0, (sy_call_t *)linux_remap_file_pages, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 234 = linux_remap_file_pages */
	{ 0, (sy_call_t *)linux_mbind, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 235 = linux_mbind */
	{ 0, (sy_call_t *)linux_get_mempolicy, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 236 = linux_get_mempolicy */
	{ 0, (sy_call_t *)linux_set_mempolicy, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 237 = linux_set_mempolicy */
	{ 0, (sy_call_t *)linux_migrate_pages, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 238 = linux_migrate_pages */
	{ 0, (sy_call_t *)linux_move_pages, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 239 = linux_move_pages */
	{ AS(linux_rt_tgsigqueueinfo_args), (sy_call_t *)linux_rt_tgsigqueueinfo, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 240 = linux_rt_tgsigqueueinfo */
	{ 0, (sy_call_t *)linux_perf_event_open, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 241 = linux_perf_event_open */
	{ AS(linux_accept4_args), (sy_call_t *)linux_accept4, AUE_ACCEPT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 242 = linux_accept4 */
	{ AS(linux_recvmmsg_args), (sy_call_t *)linux_recvmmsg, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 243 = linux_recvmmsg */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 244 = unimpl_md_syscall */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 245 = unimpl_md_syscall */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 246 = unimpl_md_syscall */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 247 = unimpl_md_syscall */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 248 = unimpl_md_syscall */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 249 = unimpl_md_syscall */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 250 = unimpl_md_syscall */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 251 = unimpl_md_syscall */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 252 = unimpl_md_syscall */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 253 = unimpl_md_syscall */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 254 = unimpl_md_syscall */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 255 = unimpl_md_syscall */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 256 = unimpl_md_syscall */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 257 = unimpl_md_syscall */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 258 = unimpl_md_syscall */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 259 = unimpl_md_syscall */
	{ AS(linux_wait4_args), (sy_call_t *)linux_wait4, AUE_WAIT4, NULL, 0, 0, 0, SY_THR_STATIC },	/* 260 = linux_wait4 */
	{ AS(linux_prlimit64_args), (sy_call_t *)linux_prlimit64, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 261 = linux_prlimit64 */
	{ 0, (sy_call_t *)linux_fanotify_init, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 262 = linux_fanotify_init */
	{ 0, (sy_call_t *)linux_fanotify_mark, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 263 = linux_fanotify_mark */
	{ 0, (sy_call_t *)linux_name_to_handle_at, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 264 = linux_name_to_handle_at */
	{ 0, (sy_call_t *)linux_open_by_handle_at, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 265 = linux_open_by_handle_at */
	{ 0, (sy_call_t *)linux_clock_adjtime, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 266 = linux_clock_adjtime */
	{ AS(linux_syncfs_args), (sy_call_t *)linux_syncfs, AUE_SYNC, NULL, 0, 0, 0, SY_THR_STATIC },	/* 267 = linux_syncfs */
	{ AS(linux_setns_args), (sy_call_t *)linux_setns, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 268 = linux_setns */
	{ AS(linux_sendmmsg_args), (sy_call_t *)linux_sendmmsg, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 269 = linux_sendmmsg */
	{ AS(linux_process_vm_readv_args), (sy_call_t *)linux_process_vm_readv, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 270 = linux_process_vm_readv */
	{ AS(linux_process_vm_writev_args), (sy_call_t *)linux_process_vm_writev, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 271 = linux_process_vm_writev */
	{ AS(linux_kcmp_args), (sy_call_t *)linux_kcmp, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 272 = linux_kcmp */
	{ AS(linux_finit_module_args), (sy_call_t *)linux_finit_module, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 273 = linux_finit_module */
	{ AS(linux_sched_setattr_args), (sy_call_t *)linux_sched_setattr, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 274 = linux_sched_setattr */
	{ AS(linux_sched_getattr_args), (sy_call_t *)linux_sched_getattr, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 275 = linux_sched_getattr */
	{ AS(linux_renameat2_args), (sy_call_t *)linux_renameat2, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 276 = linux_renameat2 */
	{ AS(linux_seccomp_args), (sy_call_t *)linux_seccomp, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 277 = linux_seccomp */
	{ AS(linux_getrandom_args), (sy_call_t *)linux_getrandom, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 278 = linux_getrandom */
	{ AS(linux_memfd_create_args), (sy_call_t *)linux_memfd_create, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 279 = linux_memfd_create */
	{ AS(linux_bpf_args), (sy_call_t *)linux_bpf, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 280 = linux_bpf */
	{ AS(linux_execveat_args), (sy_call_t *)linux_execveat, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 281 = linux_execveat */
	{ AS(linux_userfaultfd_args), (sy_call_t *)linux_userfaultfd, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 282 = linux_userfaultfd */
	{ AS(linux_membarrier_args), (sy_call_t *)linux_membarrier, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 283 = linux_membarrier */
	{ AS(linux_mlock2_args), (sy_call_t *)linux_mlock2, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 284 = linux_mlock2 */
	{ AS(linux_copy_file_range_args), (sy_call_t *)linux_copy_file_range, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 285 = linux_copy_file_range */
	{ AS(linux_preadv2_args), (sy_call_t *)linux_preadv2, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 286 = linux_preadv2 */
	{ AS(linux_pwritev2_args), (sy_call_t *)linux_pwritev2, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 287 = linux_pwritev2 */
	{ AS(linux_pkey_mprotect_args), (sy_call_t *)linux_pkey_mprotect, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 288 = linux_pkey_mprotect */
	{ AS(linux_pkey_alloc_args), (sy_call_t *)linux_pkey_alloc, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 289 = linux_pkey_alloc */
	{ AS(linux_pkey_free_args), (sy_call_t *)linux_pkey_free, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 290 = linux_pkey_free */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 291 = nosys */
};
