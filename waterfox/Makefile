PORTNAME=	waterfox
DISTVERSION=	G6.0.13
CATEGORIES=	www

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Distilled fork of Firefox
WWW=		https://www.waterfox.net/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	nspr>=4.32:devel/nspr \
		nss>=3.95:security/nss \
		icu>=74.2:devel/icu \
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
		zip:archivers/zip

LIB_DEPENDS=	libdav1d.so:multimedia/dav1d \
		libaom.so:multimedia/aom \
		libharfbuzz.so:print/harfbuzz

USE_GITHUB=	yes
GH_ACCOUNT=	MrAlex94
GH_PROJECT=	Waterfox

.include <bsd.port.options.mk>

.if ${ARCH} != powerpc64
BUILD_DEPENDS+=	${LOCALBASE}/share/wasi-sysroot/lib/wasm32-wasi/libc++abi.a:devel/wasi-libcxx${LLVM_VERSION} \
		${LOCALBASE}/share/wasi-sysroot/lib/wasm32-wasi/libc.a:devel/wasi-libc \
		wasi-compiler-rt${LLVM_VERSION}>0:devel/wasi-compiler-rt${LLVM_VERSION}
.endif

USE_GECKO=	gecko
USE_MOZILLA=    -sqlite

CFLAGS_powerpc64le=     -DSQLITE_BYTEORDER=1234
# work around bindgen not finding ICU, e.g.
# dist/include/mozilla/intl/ICU4CGlue.h:8:10: fatal error: 'unicode/uenum.h' file not found, err: true
CONFIGURE_ENV+= BINDGEN_CFLAGS="-I${LOCALBASE}/include"
CONFIGURE_ENV+= MOZ_REQUIRE_SIGNING=""
MOZ_EXPORT+=    MOZ_TELEMETRY_REPORTING="" \
                MOZILLA_OFFICIAL="1" \
                MOZ_OFFICIAL_BRANDING="1" \
                MOZ_APP_DISPLAYNAME="Waterfox" \
                MOZ_APP_NAME="waterfox"

MOZ_OPTION+=    --enable-application=browser \
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
                --with-app-name=waterfox \
                --with-branding=browser/branding/waterfox \
                --with-unsigned-addon-scopes=app,system \
                --with-l10n-base=$PWD/browser/locales/l10n \
                --enable-bootstrap \
                --without-system-icu \
                MOZ_CRASHREPORTER=0 \
                MOZ_DATA_REPORTING=0 \
                MOZ_SERVICES_HEALTHREPORT=0

BINARY_ALIAS+=	python3=${PYTHON_CMD}

MOZILLA_NAME=	Waterfox
USE_GECKO=	gecko

WATERFOX_ICON=		${MOZILLA}.png
WATERFOX_ICON_SRC=	${PREFIX}/lib/${MOZILLA}/browser/chrome/icons/default/default256.png
WATERFOX_DESKTOP=	${MOZSRC}/taskcluster/docker/firefox-snap/firefox.desktop

.if ${ARCH} == powerpc64
CFLAGS+=	-DHWY_COMPILE_ONLY_SCALAR
MOZ_OPTIONS+=	--without-wasm-sandboxed-libraries
.else
BUILD_DEPENDS+=	${LOCALBASE}/share/wasi-sysroot/lib/wasm32-wasi/libc++abi.a:devel/wasi-libcxx${LLVM_VERSION} \
		${LOCALBASE}/share/wasi-sysroot/lib/wasm32-wasi/libc.a:devel/wasi-libc \
		wasi-compiler-rt${LLVM_VERSION}>0:devel/wasi-compiler-rt${LLVM_VERSION}
MOZ_OPTIONS+=	--with-wasi-sysroot=${LOCALBASE}/share/wasi-sysroot
.endif

.include "${.CURDIR}/../../www/firefox/Makefile.options"

post-patch:
	@${REINPLACE_CMD} -e 's/%u/%U/' -e '/X-MultipleArgs/d' \
		-e 's/firefox/${MOZILLA}/' \
		-e 's/Firefox/${MOZILLA_NAME}/' \
		${WATERFOX_DESKTOP}
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/browser/app/nsBrowserApp.cpp
	@${RM} ${WRKSRC}/.mozconfig

post-install:
	${INSTALL_DATA} ${WATERFOX_DESKTOP} \
		${STAGEDIR}${PREFIX}/share/applications/${MOZILLA}.desktop
	${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps
	${LN} -sf ${WATERFOX_ICON_SRC} ${STAGEDIR}${PREFIX}/share/pixmaps/${WATERFOX_ICON}

.include <bsd.port.mk>
