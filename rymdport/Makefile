PORTNAME=	rymdport
DISTVERSIONPREFIX=v
DISTVERSION=	3.6.0
CATEGORIES=	net-im

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Cross-platform application for easy encrypted file, \
		folder, and text sharing between devices.
WWW=		https://rymdport.github.io/

LICENSE=	GPLv3

USES=		go:1.22 desktop-file-utils
USE_XORG=	x11 xau xcb xdmcp
USE_GL=		gl
USE_GITHUB=	yes
GH_ACCOUNT=	jacalz

PLIST_FILES=	bin/rymdport \
		share/applications/io.github.jacalz.rymdport.desktop \
		share/icons/hicolor/icon-128.png \
		share/icons/hicolor/icon-16.png \
		share/icons/hicolor/icon-24.png \
		share/icons/hicolor/icon-256.png \
		share/icons/hicolor/icon-32.png \
		share/icons/hicolor/icon-48.png \
		share/icons/hicolor/icon-512.png \
		share/icons/hicolor/icon-64.png

do-build:
	@cd ${WRKSRC} && ${GO_CMD} mod vendor && ${GO_CMD} build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/internal/assets/unix/io.github.jacalz.${PORTNAME}.desktop \
		${STAGEDIR}${DESKTOPDIR}
.for s in 16 24 32 48 64 128 256 512
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/
	${INSTALL_DATA} ${WRKSRC}/internal/assets/icons/icon-${s}.png \
                ${STAGEDIR}${PREFIX}/share/icons/hicolor/
.endfor

.include <bsd.port.mk>
