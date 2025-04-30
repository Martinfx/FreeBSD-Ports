PORTNAME=	mullvad-browser
DISTVERSION=	14.5.1
CATEGORIES=	www net security wayland
MASTER_SITES=	TOR \
		LOCAL/vvd \
		LOCAL/vvd:source1 \
		https://build-sources.tbb.torproject.org/:source1 \
		LOCAL/jsm:source2 \
		LOCAL/vvd:source2 \
		LOCAL/vvd:source3 \
		https://secure.informaction.com/%SUBDIR%/:source3
MASTER_SITE_SUBDIR=	mullvadbrowser/${DISTVERSION}/:DEFAULT \
			download/releases/:source3
DISTNAME=	src-firefox-mullvad-browser-128.10.0esr-14.5-1-build2
NOSCRIPT=	noscript-12.1.1.xpi
DISTFILES=	${DISTNAME}.tar.xz \
		manual_268702.zip:source1 \
		fonts-3--4348e1.tar.zst:source2 \
		${NOSCRIPT}:source3

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Mullvad Browser for FreeBSD
WWW=		https://mullvad.net/en/browser

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	nspr>=4.32:devel/nspr \
		nss>=3.101:security/nss \
		icu>=73.1,1:devel/icu \
		libevent>=2.1.8:devel/libevent \
		harfbuzz>=8.5.0:print/harfbuzz \
		graphite2>=1.3.14:graphics/graphite2 \
		png>=1.6.43:graphics/png \
		dav1d>=1.0.0:multimedia/dav1d \
		libvpx>=1.14:multimedia/libvpx \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		v4l_compat>0:multimedia/v4l_compat \
		autoconf2.13:devel/autoconf2.13 \
		nasm:devel/nasm \
		yasm:devel/yasm
RUN_DEPENDS=	tor:security/tor \
		obfs4proxy:security/obfs4proxy-tor \
		snowflake-client:security/snowflake-tor

USES=		compiler:c++11-lib libtool localbase:ldflags perl5 pkgconfig \
		python shebangfix tar:xz
USE_GECKO=	gecko
USE_GITHUB=	nodefault
TAG_L10N=	fcd0300e8478d1ec4d1c097a073ddb8e1e0351e3
GH_TUPLE=	mozilla-l10n:firefox-l10n:${TAG_L10N}:ffl10n
USE_GITLAB=	nodefault
GL_SITE=	https://gitlab.torproject.org/
GL_ACCOUNT=	tpo
GL_PROJECT=	translation:basebrowser translation:torbrowser
TAG_BASE=	86442427facf038d5706644221de7e2fb733550b
TAG_TOR=	2c0b448503d52c3b512d1e7a55ccc78ac19db146
GL_TAGNAME=	${TAG_BASE}:basebrowser ${TAG_TOR}:torbrowser
USE_MOZILLA=	-sqlite

LOCALES=	ar ca cs da de el es-ES fa fi fr ga-IE he hu id is it ja ka ko \
		lt mk ms my nb-NO nl pl pt-BR ro ru sq sv-SE th tr uk vi zh-CN \
		zh-TW
CONFIGURE_ENV+=	BINDGEN_CFLAGS="-I${LOCALBASE}/include" \
		MOZ_CHROME_MULTILOCALE="${LOCALES}"

MAKE_ENV+=	LOCALES="${LOCALES}"

CFLAGS_powerpc64le=	-DSQLITE_BYTEORDER=1234
SSP_UNSAFE=		yes

BUNDLE_LIBS=	yes
SUB_FILES=	fonts.conf mullvad-browser.desktop torrc-defaults

WRKSRC=		${WRKDIR}/${DISTNAME:S/src-//}

MOZ_EXPORT+=	MOZ_TELEMETRY_REPORTING="" \
		MOZILLA_OFFICIAL="1" \
		MOZ_OFFICIAL_BRANDING="1" \
		MOZ_APP_DISPLAYNAME="Mullvad Browser" \
		MOZ_APP_NAME="mullvad-browser" \
		MOZ_CHROME_MULTILOCALE="${LOCALES}"

MOZ_OPTIONS=	--with-base-browser-version=${DISTVERSION} \
		--enable-optimize \
		--enable-bundled-fonts \
		--disable-crashreporter \
		--disable-debug \
		--with-branding=browser/branding/mb-release

.include "${.CURDIR}/../../www/firefox/Makefile.options"

.include <bsd.port.options.mk>

.if ${ARCH} == amd64
MOZ_OPTIONS+=	--enable-rust-simd
.endif
.if ${ARCH} == powerpc64
MOZ_OPTIONS+=	--without-wasm-sandboxed-libraries
.else
BUILD_DEPENDS+=	${LOCALBASE}/share/wasi-sysroot/lib/wasm32-wasi/libc++abi.a:devel/wasi-libcxx${LLVM_VERSION} \
		${LOCALBASE}/share/wasi-sysroot/lib/wasm32-wasi/libc.a:devel/wasi-libc@${LLVM_VERSION} \
		wasi-compiler-rt${LLVM_VERSION}>0:devel/wasi-compiler-rt${LLVM_VERSION}
MOZILLA_PLIST_DIRS=	bin lib share/applications share/pixmaps \
			share/mullvad-browser
MOZ_OPTIONS+=	--with-wasi-sysroot=${LOCALBASE}/share/wasi-sysroot
.endif
post-patch:
	@${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/browser/app/nsBrowserApp.cpp
	${MKDIR} ${WRKSRC}/tmp-manual
	${UNZIP_NATIVE_CMD} -d ${WRKSRC}/tmp-manual ${DISTDIR}/manual_215922.zip
pre-configure:
	@${REINPLACE_CMD} 's|export MOZ_GOOGLE_.*||g' ${WRKSRC}/.mozconfig
	${PYTHON_CMD} ${FILESDIR}/packagemanual.py ${WRKSRC}/tmp-manual/public \
		${WRKSRC}/browser/base/content/manual
post-configure:
	${MKDIR} ${WRKDIR}/.mozbuild/l10n-central
	${CP} -r ${WRKDIR}/firefox-l10n-${TAG_L10N}/* \
		${WRKDIR}/.mozbuild/l10n-central

post-build:
	MOZBUILD_STATE_PATH=${WRKDIR}/.mozbuild AB_CD="multi" MOZ_AUTOMATION="1" \
		PATH="`find ${WRKRDIR}/.mozbuild/srcdirs -name build -type d -print`/bin:${PATH}" \
		${WRKSRC}/mach package-multi-locale --locales ${LOCALES}

.for i in ${LOCALES}
	${CP} ${WRKDIR}/translation-${TAG_BASE}/${i}/base-browser.ftl \
		${WRKDIR}/.mozbuild/l10n-central/${i}/toolkit/toolkit/global/
	${CP} ${WRKDIR}/translation-${TAG_TOR}/${i}/tor-browser.ftl \
		${WRKDIR}/.mozbuild/l10n-central/${i}/toolkit/toolkit/global/
	${MKDIR} ${WRKDIR}/.mozbuild/l10n-central/${i}/browser/branding/mb-release
	${CP} ${WRKDIR}/translation-${TAG_TOR}/${i}/brand.properties \
		${WRKDIR}/.mozbuild/l10n-central/${i}/browser/branding/mb-release
	${MKDIR} ${WRKSRC}/toolkit/torbutton/chrome/locale/${i}/
.for j in brand.properties onionLocation.properties \
	settings.properties torConnect.properties torlauncher.properties
	${CP} ${WRKDIR}/translation-${TAG_TOR}/${i}/${j} \
		${WRKSRC}/toolkit/torbutton/chrome/locale/${i}/
.endfor
	${CP} -r ${WRKDIR}/translation-${TAG_TOR}/${i}/branding \
		${WRKSRC}/toolkit/torbutton/chrome/locale/${i}
.endfor

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/torrc-defaults \
		${STAGEDIR}${DATADIR}/torrc-defaults
	${INSTALL_DATA} ${WRKDIR}/mullvad-browser.desktop \
		${STAGEDIR}${PREFIX}/share/applications/mullvad-browser.desktop
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/mullvad-browser/fontconfig
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/mullvad-browser/fonts
	${INSTALL_DATA} ${WRKDIR}/fonts.conf \
		${STAGEDIR}${PREFIX}/lib/mullvad-browser/fontconfig/fonts.conf
	(cd ${WRKDIR}/fonts && \
		${COPYTREE_SHARE} "*.otf *.ttf" ${STAGEDIR}${PREFIX}/lib/mullvad-browser/fonts)
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/mullvad-browser/distribution/extensions
	${INSTALL_DATA} ${DISTDIR}/${NOSCRIPT} \
		"${STAGEDIR}${PREFIX}/lib/mullvad-browser/distribution/extensions/{73a6fe31-595d-460b-a920-fcc0f8843232}.xpi"

.include <bsd.port.mk>
