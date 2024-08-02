PORTNAME=	iaito
PORTVERSION=	5.9.2
CATEGORIES=	x11

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Official QT frontend of radare2
WWW=		https://github.com/radareorg/iaito

LICENSE=	GPLv3

BUILD_DEPENDS=	radare2>0:devel/radare2

LIB_DEPENDS=	libr_core.so:devel/radare2 \
		libcapstone.so:devel/capstone

USES=		desktop-file-utils gmake ssl qt:5 pkgconfig qmake:no_configure

USE_GITHUB=	yes
GH_ACCOUNT=	radareorg
GH_PROJECT=	${PORTNAME}

USE_QT=		buildtools core gui linguisttools network svg widgets
GNU_CONFIGURE=	yes
USE_GL=		gl
MAKE_ENV=	QMAKE_FLAGS="PREFIX=${STAGEDIR}${PREFIX}"\
		DESTDIR=${STAGEDIR}${PREFIX}

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
