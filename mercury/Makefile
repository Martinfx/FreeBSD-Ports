PORTNAME=	Mercury
DISTVERSION=	v.123.0.1
CATEGORIES=	www wayland
MASTER_SITES=	https://download.cdn.mozilla.net/pub/firefox/releases/125.0.1/source/:source1
DISTFILES=      firefox-125.0.1.source${EXTRACT_SUFX}:source1
DIST_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Custom version of firefox mercury
WWW=		https://thorium.rocks/mercury

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	nspr>=4.32:devel/nspr \
		nss>=3.95:security/nss \
		icu>=73.1:devel/icu \
		libevent>=2.1.8:devel/libevent \
		harfbuzz>=8.3.0:print/harfbuzz \
		graphite2>=1.3.14:graphics/graphite2 \
		png>=1.6.39:graphics/png \
		dav1d>=1.0.0:multimedia/dav1d \
		libvpx>=1.13.0:multimedia/libvpx \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		v4l_compat>0:multimedia/v4l_compat \
		autoconf2.13:devel/autoconf2.13 \
		nasm:devel/nasm \
		yasm:devel/yasm \
		zip:archivers/zip \
		rust-cbindgen>=0.26.0:devel/rust-cbindgen \
		${RUST_DEFAULT}>=1.77.0:lang/${RUST_DEFAULT} \
		node:www/node

#.include "${.CURDIR}/../../www/firefox/Makefile.options"

.include <bsd.port.options.mk>
.if ${ARCH} != powerpc64
BUILD_DEPENDS+=	${LOCALBASE}/share/wasi-sysroot/lib/wasm32-wasi/libc++abi.a:devel/wasi-libcxx${LLVM_VERSION} \
		${LOCALBASE}/share/wasi-sysroot/lib/wasm32-wasi/libc.a:devel/wasi-libc \
		wasi-compiler-rt${LLVM_VERSION}>0:devel/wasi-compiler-rt${LLVM_VERSION}
.endif

USE_GECKO=	gecko
USE_MOZILLA=	-sqlite
WRKSRC=		${WRKDIR}/firefox-125.0.1

USE_GITHUB=	yes
GH_ACCOUNT=	Alex313031

CFLAGS_powerpc64le=	-DSQLITE_BYTEORDER=1234
# work around bindgen not finding ICU, e.g.
# dist/include/mozilla/intl/ICU4CGlue.h:8:10: fatal error: 'unicode/uenum.h' file not found, err: true
CONFIGURE_ENV+=	BINDGEN_CFLAGS="-I${LOCALBASE}/include"
CONFIGURE_ENV+=	MOZ_REQUIRE_SIGNING=""
MOZ_EXPORT+=	MOZ_TELEMETRY_REPORTING="" \
		MOZILLA_OFFICIAL="1" \
		MOZ_OFFICIAL_BRANDING="1" \
		MOZ_APP_DISPLAYNAME="Mercury" \
		MOZ_APP_NAME="mercury"

MOZ_OPTIONs=	--enable-application=browser \
		--allow-addon-sideload \
		--disable-crashreporter \
		--disable-debug \
		--disable-default-browser-agent \
		--disable-tests \
		--disable-updater \
		--enable-hardening \
		--enable-optimize \
		--enable-release \
		--enable-rust-simd \
		--with-app-name=mercury \
		--with-branding=browser/branding/mercury \
		--with-unsigned-addon-scopes=app,system \
		--with-l10n-base=$PWD/browser/locales/l10n \
		--enable-bootstrap \
		MOZ_CRASHREPORTER=0 \
		MOZ_DATA_REPORTING=0 \
		MOZ_SERVICES_HEALTHREPORT=0

MOZ_OPTIONS+=   --with-libclang-path="${LLVM_PREFIX:S/${PREFIX}/${LOCALBASE}/}/lib"


FIREFOX_ICON_SRC=	${PREFIX}/lib/${MOZILLA}/browser/chrome/icons/default/default48.png
FIREFOX_DESKTOP=	${MOZSRC}/taskcluster/docker/firefox-snap/firefox.desktop

.if ${ARCH} == powerpc64
CFLAGS+=	-DHWY_COMPILE_ONLY_SCALAR
MOZ_OPTIONS+=	--without-wasm-sandboxed-libraries
.else

BUILD_DEPENDS+=	${LOCALBASE}/share/wasi-sysroot/lib/wasm32-wasi/libc++abi.a:devel/wasi-libcxx${LLVM_VERSION} \
		${LOCALBASE}/share/wasi-sysroot/lib/wasm32-wasi/libc.a:devel/wasi-libc \
		wasi-compiler-rt${LLVM_VERSION}>0:devel/wasi-compiler-rt${LLVM_VERSION}
MOZ_OPTIONS+=	--with-wasi-sysroot=${LOCALBASE}/share/wasi-sysroot
.endif

pre-patch:
	${CP} -R -v ${WRKDIR}/${PORTNAME}-${DISTVERSION}/app/ ${WRKSRC}/browser/app
	${CP} -R -v ${WRKDIR}/${PORTNAME}-${DISTVERSION}/browser/ ${WRKSRC}/browser
	${CP} -R -v ${WRKDIR}/${PORTNAME}-${DISTVERSION}/devtools/ ${WRKSRC}/devtools
	${CP} -R -v ${WRKDIR}/${PORTNAME}-${DISTVERSION}/ipc/ ${WRKSRC}/ipc
	${CP} -R -v ${WRKDIR}/${PORTNAME}-${DISTVERSION}/moz.build ${WRKSRC}
	${CP} -R -v ${WRKDIR}/${PORTNAME}-${DISTVERSION}/netwerk ${WRKSRC}/netwerk
	${CP} -R -v ${WRKDIR}/${PORTNAME}-${DISTVERSION}/other-licenses ${WRKSRC}/other-licenses
	${MKDIR} -p -v ${WRKSRC}/policies
	${CP} -R -v ${WRKDIR}/${PORTNAME}-${DISTVERSION}/policies ${WRKSRC}/policies
	${CP} -R -v ${WRKDIR}/${PORTNAME}-${DISTVERSION}/toolkit ${WRKSRC}/toolkit
	${CP} -R -v ${WRKDIR}/${PORTNAME}-${DISTVERSION}/testing ${WRKSRC}/testing
	${CP} -v ${WRKDIR}/${PORTNAME}-${DISTVERSION}/mozconfigs/mozconfig ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/browser/app/nsBrowserApp.cpp

post-install:
	${CP} ${FIREFOX_DESKTOP} ${STAGEDIR}${PREFIX}/share/applications/librewolf.desktop
	${REINPLACE_CMD} -e 's|Firefox|Librewolf|g' ${STAGEDIR}${PREFIX}/share/applications/librewolf.desktop
	${REINPLACE_CMD} -e 's|firefox|librewolf|g' ${STAGEDIR}${PREFIX}/share/applications/librewolf.desktop
	${REINPLACE_CMD} -e 's|Icon=.*|Icon=${FIREFOX_ICON_SRC}|g' ${STAGEDIR}${PREFIX}/share/applications/librewolf.desktop

.include <bsd.port.mk>
