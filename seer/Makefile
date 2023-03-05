PORTNAME=	seer
DISTVERSIONPREFIX=	v
DISTVERSION=	1.14

CATEGORIES=	devel

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Seer - a gui frontend to gdb
WWW=		https://github.com/epasveer/seer

LICENSE=	GPLv3

RUN_DEPENDS=	gdb:devel/gdb

USES=		compiler:c++17-lang cmake gl qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	epasveer
GH_PROJECT=	seer
USE_GL=		gl
USE_QT=		core gui charts network printsupport widgets buildtools
WRKSRC_SUBDIR=	src
post-patch:
	@${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/SeerGdbWidget.cpp ${WRKSRC}/SeerMainWindow.cpp
pre-install:
.for s in 32 64 128 256 512
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps
	${INSTALL_DATA} ${WRKSRC}/resources/seergdb_${s}x${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps/
.endfor
	${INSTALL_DATA} ${WRKSRC}/resources/seergdb.desktop \
		${STAGEDIR}${DESKTOPDIR}

.include <bsd.port.mk>
