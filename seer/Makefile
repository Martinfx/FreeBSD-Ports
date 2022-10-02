PORTNAME=	seer
DISTVERSIONPREFIX=	v
DISTVERSION=	1.11

CATEGORIES=	devel

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Seer - a gui frontend to gdb

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++17-lang cmake desktop-file-utils gl qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	epasveer
GH_PROJECT=	seer
USE_GL=		gl
USE_QT=		core gui charts network printsupport widgets

CMAKE_ARGS+=	${CMAKE_SOURCE_DIR}/${WRKSRC}/src

PLIST_FILES=	bin/seergdb

do-install:
.for s in 32 64 128 256 512
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/seergdb_${s}x${s}
	${INSTALL_DATA} ${WRKSRC}/src/resources/seergdb_${s}x${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/seergdb_${s}x${s}
.endfor
	${INSTALL_DATA} ${WRKSRC}/src/resources/seergdb.desktop \
		${STAGEDIR}${DESKTOPDIR}

.include <bsd.port.mk>
