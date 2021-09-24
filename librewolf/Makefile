# $FreeBSD: $

PORTNAME=	firefox
DISTVERSION=	88.0.1
CATEGORIES=	www
MASTER_SITES=	MOZILLA/firefox/releases/${DISTVERSION}/source \
		MOZILLA/firefox/candidates/${DISTVERSION}-candidates/build3/source
DISTFILES=	firefox-${DISTVERSION}.source${EXTRACT_SUFX}

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Web browser based on the browser portion of Mozilla

BUILD_DEPENDS=	nspr>=4.26:devel/nspr \
		nss>=3.58:security/nss \
		icu>=67.1,1:devel/icu \
		libevent>=2.1.8:devel/libevent \
		harfbuzz>=2.6.8:print/harfbuzz \
		graphite2>=1.3.14:graphics/graphite2 \
		png>=1.6.35:graphics/png \
		libvpx>=1.8.2:multimedia/libvpx \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		v4l_compat>0:multimedia/v4l_compat \
		autoconf-2.13:devel/autoconf213 \
		nasm:devel/nasm \
		yasm:devel/yasm \
		zip:archivers/zip

USE_GECKO=	gecko
CONFLICTS_INSTALL=	firefox-esr firefox
USE_MOZILLA=	-sqlite
CFLAGS_powerpc64le=	-DSQLITE_BYTEORDER=1234

USES=		tar:xz

FIREFOX_ICON=		${MOZILLA}.png
FIREFOX_ICON_SRC=	${PREFIX}/lib/${MOZILLA}/browser/chrome/icons/default/default48.png
FIREFOX_DESKTOP=	${MOZSRC}/taskcluster/docker/${MOZILLA}-snap/${MOZILLA}.desktop
MOZ_OPTIONS=		--enable-application=browser \
			--enable-release \
			--enable-rust-simd \
			--with-app-name=librewolf \
			--with-app-basename=LibreWolf \
			--with-branding=browser/branding/librewolf \
			--with-distribution-id=io.gitlab.librewolf-community \
			--with-unsigned-addon-scopes=app,system \
			--allow-addon-sideload \
			--with-system-nspr \
			--with-system-nss \
			--disable-tests \
            		--disable-debug \
            		--disable-crashreporter \
           	 	--disable-updater \
           		--disable-webrtc \
			MOZ_CRASHREPORTER=0 \
			MOZ_DATA_REPORTING=0
#			MOZ_TELEMETRY_REPORTING=1

EXTRA_PATCHES+=	${FILESDIR}/extra-patch-browser_base_content_aboutDialog.xhtml \
		${FILESDIR)/extra-patch-modules_libpref_init_StaticPrefList.yaml \
		${FILESDIR)/extra-patch-browser_confvars.sh \
		${FILESDIR}/extra-patch-browser_base_content_browser-context.inc \
		${FILESDIR}/extra-patch-browser_components_urlbar_UrlbarInput.jsm \
		${FILESDIR}/extra-patch-browser_themes_shared_urlbar-searchbar.inc.css \
		${FILESDIR}/extra-patch-browser_themes_shared_urlbarView.inc.css \
		${FILESDIR}/extra-patch-browser_components_privatebrowsing_content_aboutPrivateBrowsing.html
post-patch:
	@${REINPLACE_CMD} -e 's/%u/%U/' -e '/X-MultipleArgs/d' \
		-e '/^Icon/s/=.*/=${FIREFOX_ICON:R}/' \
		${FIREFOX_DESKTOP}
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/browser/app/nsBrowserApp.cpp

	# Disable pocket
	${SED} -e "s/'pocket'/#'pocket'/g" ${WRKSRC}/browser/components/moz.build
	
	${SED} -e 's#SaveToPocket.init();#// SaveToPocket.init();#g' \
		 ${WRKSRC}/browser/components/BrowserGlue.jsm

pre-configure:
	(cd ${WRKSRC} && ${LOCALBASE}/bin/autoconf-2.13)
	(cd ${WRKSRC}/js/src/ && ${LOCALBASE}/bin/autoconf-2.13)

post-install:
	${INSTALL_DATA} ${FIREFOX_DESKTOP} ${STAGEDIR}${PREFIX}/share/applications/
	${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps
	${LN} -sf ${FIREFOX_ICON_SRC} ${STAGEDIR}${PREFIX}/share/pixmaps/${FIREFOX_ICON}

.include <bsd.port.mk>
