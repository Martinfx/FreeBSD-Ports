PORTNAME=	rymdport
DISTVERSIONPREFIX=v
DISTVERSION=	3.6.0
MASTER_SITES=	https://github.com/Jacalz/rymdport/releases/download/v3.6.0/
DISTFILES=	rymdport-v3.6.0-freebsd-${ARCH:S/amd64/amd64/:S/arm64/arm64/}${EXTRACT_SUFX}
EXTRACT_SUFX=	.tar.xz

CATEGORIES=	net-im

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Cross-platform application for easy encrypted file, \
		folder, and text sharing between devices.

LICENSE=	GPLv3
NO_BUILD=	yes
ONLY_FOR_ARCH=	amd64 arm64

PLIST_FILES=	bin/rymdport \
		share/applications/Rymdport.desktop \
		share/pixmaps/Rymdport.png

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/usr/local/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/usr/local/share/applications/Rymdport.desktop \
		${STAGEDIR}${DESKTOPDIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKDIR}/usr/local/share/pixmaps/Rymdport.png \
                ${STAGEDIR}${PREFIX}/share/pixmaps
.include <bsd.port.mk>
