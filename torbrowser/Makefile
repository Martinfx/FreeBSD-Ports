PORTNAME=	tor-browser
DISTVERSION=	102
CATEGORIES=	www wayland
MASTER_SITES=	https://gitweb.torproject.org/tor-browser.git/snapshot/
DISTFILES=	${PORTNAME}-FIREFOX_102_5_0esr_RELEASE.tar.gz

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Web browser based on the browser portion of Mozilla
WWW=		https://www.mozilla.com/firefox

BUILD_DEPENDS=	nspr>=4.32:devel/nspr \
		nss>=3.84:security/nss \
		icu>=71.1:devel/icu \
		libevent>=2.1.8:devel/libevent \
		harfbuzz>=4.4.1:print/harfbuzz \
		graphite2>=1.3.14:graphics/graphite2 \
		png>=1.6.37:graphics/png \
		dav1d>=1.0.0:multimedia/dav1d \
		libvpx>=1.12.0:multimedia/libvpx \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		v4l_compat>0:multimedia/v4l_compat \
		autoconf2.13:devel/autoconf2.13 \
		nasm:devel/nasm \
		yasm:devel/yasm \
		zip:archivers/zip

RUN_DEPENDS=    tor:security/tor
#BUILD_DEPENDS=	wasi-compiler-rt90>0:devel/wasi-compiler-rt90
#BUILD_DEPENDS=  wasi-compiler-rt9-9.0.1>0:devel/wasi-compiler-rt9-9.0.1


USE_GECKO=	gecko
CONFLICTS_INSTALL=	firefox-esr
USE_MOZILLA=	-sqlite
CFLAGS_powerpc64le=	-DSQLITE_BYTEORDER=1234
# work around bindgen not finding ICU, e.g.
# dist/include/mozilla/intl/ICU4CGlue.h:8:10: fatal error: 'unicode/uenum.h' file not found, err: true
CONFIGURE_ENV+=	BINDGEN_CFLAGS="-I${LOCALBASE}/include"
#		WASM_AR=${LOCALBASE}/bin/llvm-ar${LLVM_VERSION} \
#		WASM_CC=${LOCALBASE}/bin/clang${LLVM_VERSION}

CONFIGURE_SCRIPT=      ${WRKSRC}/configure.py
CONFIGURE_ARGS=       --prefix=${PREFIX}
CONFIGURE_WRKSRC=	${WRKSRC}
CONFIGURE_ARGS=       --enable-sandbox
CONFIGURE_ARGS+=      --enable-forkserver
CONFIGURE_ARGS+=      --with-wasi-sysroot=${LOCALBASE}/share/wasi-sysroot
CONFIGURE_ARGS+=      --enable-lto=thin
CONFIGURE_ARGS+=      --with-libclang-path=/usr/local/llvm90/lib/

#LLVM_VERSION=	90
CPP=		clang-cpp90
CC=		clang90
CXX=		clang++90

USES=		python:3.9 compiler:c++20-lang
# helpful when testing beta
WRKSRC=		${WRKDIR}/tor-browser-FIREFOX_102_5_0esr_RELEASE

FIREFOX_ICON=		${MOZILLA}.png
FIREFOX_ICON_SRC=	${PREFIX}/lib/${MOZILLA}/browser/chrome/icons/default/default48.png
#FIREFOX_DESKTOP=	${MOZSRC}/taskcluster/docker/${MOZILLA}-snap/${MOZILLA}.desktop
MOZ_OPTIONS=	--enable-application=browser \
		--enable-official-branding

.include "${.CURDIR}/../../www/firefox/Makefile.options"

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc64
MOZ_OPTIONS+=	--disable-webrtc --without-wasm-sandboxed-libraries
.else
BUILD_DEPENDS+=	${LOCALBASE}/share/wasi-sysroot/lib/wasm32-wasi/libc++abi.a:devel/wasi-libcxx \
		${LOCALBASE}/share/wasi-sysroot/lib/wasm32-wasi/libc.a:devel/wasi-libc \
		${LOCALBASE}/llvm${LLVM_DEFAULT}/lib/clang/13.0.1/lib/wasi/libclang_rt.builtins-wasm32.a:devel/wasi-compiler-rt${LLVM_DEFAULT}
MOZ_OPTIONS+=	--with-wasi-sysroot=${LOCALBASE}/share/wasi-sysroot
.endif

pre-configure:
	${CHMOD} a+x ${CONFIGURE_SCRIPT}

do-configure:
	${MKDIR} ${WRKSRC}/out
#	(cd ${WRKSRC} && ${LOCALBASE}/bin/autoconf2.13)
#	(cd ${WRKSRC}/js/src/ && ${LOCALBASE}/bin/autoconf2.13)

	(cd ${WRKSRC} && ${PYTHON_CMD} ${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS} CC=${CC} CXX=${CXX})
#	mv work/tor-browser-FIREFOX_102_5_0esr_RELEASE ${WRKSRC}

#post-patch:
#	@${REINPLACE_CMD} -e 's/%u/%U/' -e '/X-MultipleArgs/d' \
#		-e '/^Icon/s/=.*/=${FIREFOX_ICON:R}/' \
#		${FIREFOX_DESKTOP}
#	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
#		${WRKSRC}/browser/app/nsBrowserApp.cpp

post-install:
	${INSTALL_DATA} ${FIREFOX_DESKTOP} ${STAGEDIR}${PREFIX}/share/applications/
	${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps
	${LN} -sf ${FIREFOX_ICON_SRC} ${STAGEDIR}${PREFIX}/share/pixmaps/${FIREFOX_ICON}

.include <bsd.port.mk>
