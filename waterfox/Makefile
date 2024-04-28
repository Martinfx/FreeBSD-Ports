PORTNAME=	waterfox
DISTVERSION=	G6.0.13
CATEGORIES=	www

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Distilled fork of Firefox

BUILD_DEPENDS=	icu>=73.1:devel/icu \
		libevent>=2.1.8:devel/libevent \
                harfbuzz>=8.3.0:print/harfbuzz \
                graphite2>=1.3.14:graphics/graphite2 \
                png>=1.6.39:graphics/png \
                dav1d>=1.0.0:multimedia/dav1d \
                libvpx>=1.14.0:multimedia/libvpx \
                ${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
                v4l_compat>0:multimedia/v4l_compat \
                autoconf2.13:devel/autoconf2.13 \
                nasm:devel/nasm \
                yasm:devel/yasm \
                zip:archivers/zip

USE_GITHUB=	yes
GH_ACCOUNT=	MrAlex94
GH_PROJECT=	Waterfox

USE_GECKO=	gecko
#MOZ_PKGCONFIG_FILES=	# empty
#USE_MOZILLA=	-soundtouch
#MOZILLA_NAME=	Waterfox

WATERFOX_ICON=		${MOZILLA}.png
WATERFOX_ICON_SRC=	${PREFIX}/lib/${MOZILLA}/browser/chrome/icons/default/default256.png
WATERFOX_DESKTOP=	${MOZSRC}/taskcluster/docker/firefox-snap/firefox.desktop
MOZ_OPTIONS=	--enable-application=browser \
		--with-app-name=${MOZILLA} \
		--with-app-basename=${MOZILLA_NAME} \
		--with-distribution-id=org.${MOZILLA}project

#OPTIONS_DEFAULT=	BUNDLED_CAIRO

#.include "${.CURDIR}/../../www/firefox/Makefile.options"

# Inconsistent fallback order (libcubeb vs. audio_device)
#SNDIO_PREVENTS=		${OPTIONS_MULTI_AUDIO:NSNDIO}

post-patch:
	@${REINPLACE_CMD} -e 's/%u/%U/' -e '/X-MultipleArgs/d' \
		-e 's/firefox/${MOZILLA}/' \
		-e 's/Firefox/${MOZILLA_NAME}/' \
		${WATERFOX_DESKTOP}
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/browser/app/nsBrowserApp.cpp

pre-configure:
	(cd ${WRKSRC} && ${LOCALBASE}/bin/autoconf-2.13)
	(cd ${WRKSRC}/js/src/ && ${LOCALBASE}/bin/autoconf-2.13)

post-install:
	${INSTALL_DATA} ${WATERFOX_DESKTOP} \
		${STAGEDIR}${PREFIX}/share/applications/${MOZILLA}.desktop
	${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps
	${LN} -sf ${WATERFOX_ICON_SRC} ${STAGEDIR}${PREFIX}/share/pixmaps/${WATERFOX_ICON}

.include <bsd.port.mk>
