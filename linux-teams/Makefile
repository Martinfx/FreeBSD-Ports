PORTNAME=	teams-for-linux
DISTVERSIONPREFIX=	v
DISTVERSION=	2.6.11
CATEGORIES=	net-im linux
MASTER_SITES=	https://github.com/IsmaelMartinez/teams-for-linux/releases/download/v${DISTVERSION}/
DISTNAME=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX_${ARCH}}

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Unofficial Microsoft Teams for Linux client
WWW=		https://github.com/IsmaelMartinez/teams-for-linux

LICENSE=	GPLv3

USES=		desktop-file-utils linux:rl9 shared-mime-info
USE_LINUX=	alsalib alsa-plugins-oss alsa-plugins-pulseaudio at-spi2-atk \
		ca-certificates cairo cups-libs curl dbuslibs dri expat \
		ffmpeg-libs gnupg gstreamer1-libav gtk3 libxkbcommon \
		nspr nss p11-kit pango sqlite3 wget xorglibs

ONLY_FOR_ARCHS=	aarch64 amd64
INSTALLS_ICONS=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PLIST_SUB=	LINUXBASE=${LINUXBASE}

EXTRACT_SUFX?=		.rpm
EXTRACT_SUFX_amd64?=	.x86_64
EXTRACT_SUFX_aarch64?=	.aarch64

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/${PORTNAME}.in ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.for s in 16 24 32 48 64 96 128 256 512 1024
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps
	${INSTALL_DATA} ${WRKSRC}/usr/share/icons/hicolor/${s}x${s}/apps/*.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps/
.endfor

	${INSTALL_DATA} ${WRKSRC}/usr/share/applications/${PORTNAME}.desktop \
			${STAGEDIR}${DESKTOPDIR}
	${MKDIR} ${STAGEDIR}${LINUXBASE}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} opt ${STAGEDIR}${LINUXBASE})
	${CHMOD} +x ${STAGEDIR}${LINUXBASE}/opt/teams-for-linux/${PORTNAME}

.include <bsd.port.mk>
