PORTNAME=	tor-browser
DISTVERSION=	src-firefox-tor-browser-102.4.0esr-12.0-2-build1
CATEGORIES=	www net security
MASTER_SITES=	https://dist.torproject.org/torbrowser/12.0a4/
DISTFILES=	${DISTVERSION}.tar.xz

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Tor Browser for FreeBSD

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	autoconf2.13:devel/autoconf2.13  \
		yasm:devel/yasm \
		zip:archivers/zip \
		wx31-gtk3>=0:x11-toolkits/wxgtk31 \
		freetype2>=0:print/freetype2 \
		dbus-glib>=0:devel/dbus-glib \
		fontconfig>=0:x11-fonts/fontconfig \
		rustc:lang/rust \
		rust-cbindgen>=0:devel/rust-cbindgen \
		node>=0:www/node \
		nasm:devel/nasm
LIB_DEPENDS=	libgconf-2.so:devel/gconf2 \
		libgtk-x11-2.0.so:x11-toolkits/gtk20 \
		libpangocairo-1.0.so:x11-toolkits/pango \
		libpulse.so:audio/pulseaudio \
		libXt.so:x11-toolkits/libXt \
		libIDL-2.so:devel/libIDL \
		libnspr4.so:devel/nspr
RUN_DEPENDS=	tor:security/tor \
		obfs4proxy:security/obfs4proxy-tor

USES=		compiler:c++11-lib libtool gmake \
		perl5 pkgconfig python:3.4+ shebangfix localbase:ldflags

USE_GECKO=	gecko
CONFLICTS_INSTALL= firefox firefox-esr

BUNDLE_LIBS=	yes
MAKEFILE=	${WRKSRC}/client.mk
PLIST_DIRS=	bin lib \
		share/applications share/pixmaps

USE_MOZILLA=	-sqlite
CFLAGS_powerpc64le=	-DSQLITE_BYTEORDER=1234
CONFIGURE_ENV+=	BINDGEN_CFLAGS="-I${LOCALBASE}/include"

MOZ_OPTIONS+= --with-tor-browser-version=12.0-2 \
#		 --enable-tor-browser-data-outside-app-dir \
	         --enable-release \
	         --enable-sandbox \
	         --enable-forkserver \
	         --enable-lto=thin \
	         --with-libclang-path=${LOCALBASE}/lib

DEBUG_CONFIGURE_ARGS+= --enable-debug-symbols \
                       --disable-install-strip
MOZ_MAKE_FLAGS=-j6

WRKSRC=		${WRKDIR}/firefox-tor-browser-102.4.0esr-12.0-2-build1

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc64
MOZ_OPTIONS+=   --disable-webrtc --without-wasm-sandboxed-libraries
.else
BUILD_DEPENDS+= ${LOCALBASE}/share/wasi-sysroot/lib/wasm32-wasi/libc++abi.a:devel/wasi-libcxx \
                ${LOCALBASE}/share/wasi-sysroot/lib/wasm32-wasi/libc.a:devel/wasi-libc \
                ${LOCALBASE}/llvm${LLVM_DEFAULT}/lib/clang/${LLVM_VERSION}/lib/wasi/libclang_rt.builtins-wasm32.a:devel/wasi-compiler-rt${LLVM_DEFAULT}
MOZ_OPTIONS+=   --with-wasi-sysroot=${LOCALBASE}/share/wasi-sysroot
.endif

pre-configure:
	(cd ${WRKSRC} && ${LOCALBASE}/bin/autoconf2.13)
	(cd ${WRKSRC}/js/src/ && ${LOCALBASE}/bin/autoconf2.13)


do-configure:
	(cd ${WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${MAKE_ENV} ${PYTHON_CMD} mach configure ${MOZ_OPTIONS})

do-build:
	(cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${MAKE_ENV} ${PYTHON_CMD} mach build ${MOZ_MAKE_FLAGS} )

do-install:
	(cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${MAKE_ENV} ${PYTHON_CMD} mach install)


.include <bsd.port.mk>
