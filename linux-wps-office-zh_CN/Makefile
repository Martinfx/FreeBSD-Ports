PORTNAME=	wps-office
DISTVERSION=	12.1.2.22570
DISTVERSIONSUFFIX=	-zh_CN
PORTREVISION=	1
CATEGORIES=	chinese editors linux
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}-${PORTVERSION}.AK.preread.sw-1-480058.x86_64
PKGNAMESUFFIX=	-zh_CN
EXTRACT_SUFX=	.rpm

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Complete office suite with PDF editor
WWW=		https://www.wps.cn/

LICENSE=	commercial
LICENSE_NAME=	End User License Agreement
LICENSE_TEXT=	See: https://www.wps.cn/privacy/full_useragreement/
LICENSE_PERMS=	no-auto-accept no-dist-mirror no-dist-sell no-pkg-mirror no-pkg-sell
LICENSE_PERMS=	auto-accept

ONLY_FOR_ARCHS=	amd64

SHEBANG_FILES=	usr/bin/et \
		usr/bin/wpp \
		usr/bin/wps \
		usr/bin/wpspdf

CONFLICTS_INSTALL=	linux-wps-office

USES=		desktop-file-utils linux:rl9 shebangfix ssl
USE_LINUX=	cups-libs gtk3 imageformats-libs libglvnd pulseaudio-libs xorglibs libxslt

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PLIST_SUB=	LINUXBASE=${LINUXBASE}

ICONS_SIZES=	16 24 32 48 64 96 128 256 512
WPS_BINS=	et wpp wps wpspdf
WPS_DESK=	et wpp wps pdf prometheus
INSTALL_TARGET=	install-strip

WPS_URL=	https://wps-linux-personal.wpscdn.cn/wps/download/ep/Linux2023/22571/wps-office-12.1.2.22571.AK.preread.sw-1-480058.x86_64${EXTRACT_SUFX}?t=1757579155&k=a2fbc70c6265749c995c4ae1c16e64b7

do-fetch:
	@if [ ! -f ${DISTDIR}/${DISTFILES} ]; then \
		@${MKDIR} ${DISTDIR} \
		@${ECHO_MSG} "=> Fetching ${DISTNAME}${EXTRACT_SUFX}" \
		${FETCH_CMD} -o ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} "${WPS_URL}"; \
	fi

post-patch:
	${REINPLACE_CMD} -i '' -e 's|/usr/bin|${PREFIX}/bin|' \
		${WPS_DESK:C|(.+)|${WRKSRC}/opt/kingsoft/${PORTNAME}/desktops/${PORTNAME}-\1.desktop|}
	${REINPLACE_CMD} -e 's|gInstallPath=/opt|gInstallPath=${LINUXBASE}/opt|' \
		${WPS_BINS:C|^|${WRKSRC}/usr/bin/|}

do-install:
	${MKDIR} ${ICONS_SIZES:C|([0-9]+)|${STAGEDIR}${PREFIX}/share/icons/hicolor/\1x\1/apps|}
.for s in ${ICONS_SIZES}
	${INSTALL_DATA} ${WRKSRC}/usr/share/icons/hicolor/${s}x${s}/mimetypes/*.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps/
.endfor
	${INSTALL_DATA} \
		${WPS_DESK:C|(.+)|${WRKSRC}/opt/kingsoft/${PORTNAME}/desktops/${PORTNAME}-\1.desktop|} \
		${STAGEDIR}${DESKTOPDIR}
	(cd ${WRKSRC}  && ${COPYTREE_SHARE} opt ${STAGEDIR}${LINUXBASE})
	${INSTALL_SCRIPT} ${WPS_BINS:C|^|${WRKSRC}/usr/bin/|} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
