PORTNAME=	iaito
PORTVERSION=	5.9.0
CATEGORIES=	x11

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Official QT frontend of radare2
WWW=		https://github.com/radareorg/iaito

LICENSE=	GPLv3

BUILD_DEPENDS=	radare2>0:devel/radare2

LIB_DEPENDS=	libr_core.so:devel/radare2 \
		libcapstone.so:devel/capstone \
		libr_config.so:devel/radare2 \
		libr_debug.so:devel/radare2 \
		libr_bin.so:devel/radare2 \
		libr_lang.so:devel/radare2 \
		libr_anal.so:devel/radare2 \
		libr_bp.so:devel/radare2 \
		libr_egg.so:devel/radare2 \
		libr_asm.so:devel/radare2 \
		libr_flag.so:devel/radare2 \
		libr_cons.so:devel/radare2 \
		libr_reg.so:devel/radare2 \
		libr_search.so:devel/radare2 \
		libr_syscall.so:devel/radare2 \
		libr_socket.so:devel/radare2 \
		libr_fs.so:devel/radare2 \
		libr_util.so:devel/radare2 \
		libr_io.so:devel/radare2 \
		libr_magic.so:devel/radare2 \
		libr_crypto.so:devel/radare2 \
		libr_arch.so:devel/radare2 \
		libr_esil.so:devel/radare2 \
		libGL.so:graphics/libglvnd \

USES=		gmake ssl qt:5 pkgconfig qmake:no_configure
USE_QT=		svg widgets gui network core linguisttools buildtools
USE_GL=		gl
MAKE_ENV=	QMAKE_FLAGS="PREFIX=${STAGEDIR}${PREFIX}"\
		DESTDIR=${STAGEDIR}${PREFIX}
GNU_CONFIGURE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	radareorg
GH_PROJECT=	iaito

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/src/org.radare.${PORTNAME}.desktop \
			${STAGEDIR}${DESKTOPDIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/src/img/org.radare.iaito.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${MKDIR} ${STAGEDIR}${PREFIX}/share/metainfo
	${INSTALL_DATA} ${WRKSRC}/src/org.radare.iaito.appdata.xml \
		${STAGEDIR}${PREFIX}/share/metainfo

.include <bsd.port.mk>
