# $FreeBSD$

PORTNAME=	wps-office
DISTVERSION=	11.1.0.10161
CATEGORIES=	linux editors
MASTER_SITES=	https://wdl1.pcfg.cache.wpscdn.com/wpsdl/wpsoffice/download/linux/10161/ #wps-office-11.1.0.10161.XA-1.x86_64.rpm
DISTNAME=	${PORTNAME}-${PORTVERSION}.XA-1.x86_64

MAINTAINER=	maintainer@email.com
COMMENT=	Kingsoft WPS Office free for linux

LICENSE=	commercial
LICENSE_NAME=	EULA
LICENSE_TEXT=	${RESTRICTED}
LICENSE_PERMS=	no-auto-accept no-dist-mirror no-dist-sell no-pkg-mirror no-pkg-sell

RESTRICTED=	Source recipient must acknowledge license. \
		Reproduction or redistribution prohibited. \
		See https://www.wps.com/eula

USES=		linux:c7 shebangfix desktop-file-utils
USE_LINUX=	xorglibs png pulseaudio-libs

SHEBANG_FILES= 	usr/bin/et \
		usr/bin/wpspdf \
		usr/bin/wps \
		usr/bin/wpp

ONLY_FOR_ARCHS= amd64

EXTRACT_SUFX=   .rpm
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PLIST_SUB=	LINUXBASE=${LINUXBASE}

WPS_BINS=	et wpp wps wpspdf

do-install:

.for s in 16 20 24 32 40 48 60 64 72 80 96 128 256
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps
	${INSTALL_DATA} ${WRKSRC}/usr/share/icons/hicolor/${s}x${s}/mimetypes/*.png \
	${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps/
.endfor

.for d in et pdf prometheus wpp wps
	${INSTALL_DATA} ${WRKSRC}/opt/kingsoft/${PORTNAME}/desktops/${PORTNAME}-${d}.desktop \
		${STAGEDIR}${DESKTOPDIR}
.endfor
	${MKDIR} ${STAGEDIR}${LINUXBASE}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} opt ${STAGEDIR}${LINUXBASE})
	${CHMOD} +x ${STAGEDIR}${LINUXBASE}/opt/kingsoft/wps-office/office6/wp*

.for WPS_BINARY in ${WPS_BINS}
	${INSTALL_SCRIPT} ${WRKSRC}/usr/bin/${WPS_BINARY} ${STAGEDIR}${PREFIX}/bin
.endfor

.include <bsd.port.mk>
