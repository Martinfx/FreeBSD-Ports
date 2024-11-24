PORTNAME=	podman-desktop
PORTVERSION=	1.14.1
CATEGORIES=	deskutils
MASTER_SITES=	https://github.com/containers/podman-desktop/releases/download/v${PORTVERSION}/

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Graphical tool for developing on containers and Kubernetes
WWW=		https://podman-desktop.io

LICENSE=	APACHE20

ONLY_FOR_ARCHS=	amd64

LIB_DEPENDS=	libicui18n.so:devel/icu \
		libxshmfence.so:x11/libxshmfence \
		libnss3.so:security/nss \
		libsmime3.so:security/nss \
		libnssutil3.so:security/nss \
		libplds4.so:devel/nspr \
		libplc4.so:devel/nspr \
		libnspr4.so:devel/nspr \
		libatk-bridge-2.0.so:accessibility/at-spi2-core \
		libatk-1.0.so:accessibility/at-spi2-core \
		libcups.so:print/cups \
		libdbus-1.so:devel/dbus \
		libepoll-shim.so:devel/libepoll-shim \
		libdrm.so:graphics/libdrm \
		libwayland-client.so:graphics/wayland \
		libharfbuzz.so:print/harfbuzz \
		libevent-2.1.so:devel/libevent \
		libopus.so:audio/opus \
		libopenh264.so:multimedia/openh264 \
		libdav1d.so:multimedia/dav1d \
		libpipewire-0.3.so:multimedia/pipewire \
		libexpat.so:textproc/expat2 \
		libpng16.so:graphics/png \
		libwebpdemux.so:graphics/webp \
		libwebpmux.so:graphics/webp \
		libwebp.so:graphics/webp \
		libharfbuzz-subset.so:print/harfbuzz \
		libfontconfig.so:x11-fonts/fontconfig \
		libxkbcommon.so:x11/libxkbcommon \
		libpci.so:devel/libpci \
		libffi.so:devel/libffi \
		libsndio.so:audio/sndio \
		libFLAC.so:audio/flac \
		libatspi.so:accessibility/at-spi2-core

USES=		desktop-file-utils jpeg electronfix:30 gettext-runtime shared-mime-info
USE_GNOME=	glib20 gdkpixbuf2 gtk30 pango cairo libxml2 libxslt
USE_XORG=	x11 xcb xcomposite xdamage xext xfixes xrender xrand xtst xi
USE_GL=		gl gbm egl

ELECTRONFIX_MAIN_EXECUTABLE=	podman-desktop
SUB_FILES=	podman-desktop
NO_BUILD=	yes

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/podman-desktop \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${PATCHDIR}/podman-desktop.desktop \
		${STAGEDIR}${DESKTOPDIR}/podman-desktop.desktop
	${INSTALL_DATA} ${PATCHDIR}/podman-desktop.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/podman-desktop.png

.include <bsd.port.mk>
