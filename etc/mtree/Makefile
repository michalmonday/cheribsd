.include <src.opts.mk>

.include <bsd.compat.pre.mk>

PACKAGE=	mtree

# NOTE: BSD.debug.dist is unconditionally installed for developer ease-of-use.
FILES=	\
	BSD.debug.dist \
	BSD.include.dist \
	BSD.root.dist \
	${_BSD.c18n.dist} \
	${_BSD.libcompats.dist} \
	${_BSD.sendmail.dist} \
	${_BSD.tests.dist} \
	BSD.usr.dist \
	BSD.var.dist

.if ${MACHINE_ABI:Mpurecap}
_BSD.c18n.dist=		BSD.c18n.dist
.endif
.for LIBCOMPAT libcompat in ${_ALL_LIBCOMPATS_libcompats}
.if ${MK_LIB${LIBCOMPAT}} != "no"
_BSD.libcompats.dist+=	BSD.lib${libcompat}.dist
.if exists(${.CURDIR}/BSD.pkg${libcompat}.dist) && \
    ${MK_PKGBOOTSTRAP} != "no"
_BSD.libcompats.dist+=	BSD.pkg${libcompat}.dist
.endif
.endif
.endfor
.if ${MK_SENDMAIL} != "no"
_BSD.sendmail.dist=	BSD.sendmail.dist
.endif
.if ${MK_TESTS} != "no"
_BSD.tests.dist=	BSD.tests.dist
.endif

NO_OBJ=
FILESDIR= /etc/mtree

.include <bsd.prog.mk>
