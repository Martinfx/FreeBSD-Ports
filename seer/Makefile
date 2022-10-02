PORTNAME=	seer
DISTVERSIONPREFIX=	v
DISTVERSION=	1.11

CATEGORIES=	devel

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Seer - a gui frontend to gdb
WWW=		https://github.com/epasveer/seer

LICENSE=	GPLv3

USES=		compiler:c++17-lang cmake desktop-file-utils gl qt:5 qmake
USE_GITHUB=	yes
GH_ACCOUNT=	epasveer
GH_PROJECT=	seer
USE_GL=		gl
USE_QT=		core gui charts network printsupport widgets buildtools

WRKSRC_SUBDIR=	src

PLIST_FILES=	bin/seergdb

do-install:
.for s in 32 64 128 256 512
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps
	${INSTALL_DATA} ${WRKSRC}/resources/seergdb_${s}x${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps/
.endfor
	${INSTALL_DATA} ${WRKSRC}/resources/seergdb.desktop \
		${STAGEDIR}${DESKTOPDIR}

.include <bsd.port.mk>
