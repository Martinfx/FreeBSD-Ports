PORTNAME=	tor-browser
DISTVERSION=	src-firefox-tor-browser-102.5.0esr-12.0-1-build4
CATEGORIES=	www net security
MASTER_SITES=	https://dist.torproject.org/torbrowser/12.0a5/
DISTFILES=	${DISTVERSION}.tar.xz

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Tor Browser for FreeBSD

LICENSE=	BSD3CLAUSE

CONFLICTS_INSTALL= firefox firefox-esr

BUILD_DEPENDS=	nspr>=4.32:devel/nspr \
		nss>=3.79.1:security/nss \
		icu>=71.1,1:devel/icu \
		libevent>=2.1.8:devel/libevent \
		harfbuzz>=4.1.0:print/harfbuzz \
		graphite2>=1.3.14:graphics/graphite2 \
		png>=1.6.37:graphics/png \
		dav1d>=1.0.0:multimedia/dav1d \
		libvpx>=1.11.0:multimedia/libvpx \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		v4l_compat>0:multimedia/v4l_compat \
		autoconf2.13:devel/autoconf2.13 \
		nasm:devel/nasm \
		yasm:devel/yasm \
		zip:archivers/zip

LIB_DEPENDS=	libgconf-2.so:devel/gconf2 \
		libgtk-x11-2.0.so:x11-toolkits/gtk20 \
		libpangocairo-1.0.so:x11-toolkits/pango \
		libpulse.so:audio/pulseaudio \
		libXt.so:x11-toolkits/libXt \
		libIDL-2.so:devel/libIDL \
		libnspr4.so:devel/nspr
RUN_DEPENDS=	tor:security/tor \
		obfs4proxy:security/obfs4proxy-tor

USES=		compiler:c++11-lib libtool \
		perl5 pkgconfig python:3.4+ shebangfix localbase:ldflags

USE_GECKO=	gecko

SSP_UNSAFE=	yes

BUNDLE_LIBS=	yes
#MAKEFILE=	${WRKSRC}/client.mk
#PLIST_DIRS=	bin lib \
#		share/applications share/pixmaps

USE_MOZILLA=	-sqlite
CFLAGS_powerpc64le=	-DSQLITE_BYTEORDER=1234
CONFIGURE_ENV+=	BINDGEN_CFLAGS="-I${LOCALBASE}/include"

MOZ_OPTIONS= --with-tor-browser-version=12.0-2 \
#		 --enable-tor-browser-data-outside-app-dir \
	         --enable-release \
	         --enable-sandbox \
	         --enable-forkserver \
	        # --enable-lto=thin \
	         --with-libclang-path=${LOCALBASE}/lib \
	         --with-system-nspr \
		 --with-system-nss  \
		 --enable-optimize \
		 --enable-proxy-bypass-protection \
		 --enable-verify-mar \
		 --enable-js-shell \
		 --enable-rust-simd \
		 --disable-tests \
		 --disable-debug \
		 --disable-crashreporter \
		 --disable-webrtc \
		--disable-crashreporter \
		--disable-tests \
		--disable-debug \
		--disable-crashreporter \
		--disable-webrtc \

#DEBUG_CONFIGURE_ARGS+= --enable-debug-symbols \
#                       --disable-install-strip

WRKSRC=		${WRKDIR}/firefox-tor-browser-102.5.0esr-12.0-1-build4

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc64
MOZ_OPTIONS+=   --disable-webrtc --without-wasm-sandboxed-libraries
.else
BUILD_DEPENDS+= ${LOCALBASE}/share/wasi-sysroot/lib/wasm32-wasi/libc++abi.a:devel/wasi-libcxx \
                ${LOCALBASE}/share/wasi-sysroot/lib/wasm32-wasi/libc.a:devel/wasi-libc \
                ${LOCALBASE}/llvm${LLVM_DEFAULT}/lib/clang/${LLVM_VERSION}/lib/wasi/libclang_rt.builtins-wasm32.a:devel/wasi-compiler-rt${LLVM_DEFAULT}

MOZ_OPTIONS+=   --with-wasi-sysroot=${LOCALBASE}/share/wasi-sysroot
.endif

#post-patch:
	#@rm ${WRKSRC}/.mozconfig

pre-configure:
	#${CP} ${FILESDIR}/mozconfig ${WRKSRC}/.mozconfig
	(cd ${WRKSRC} && ${LOCALBASE}/bin/autoconf2.13)
	(cd ${WRKSRC}/js/src/ && ${LOCALBASE}/bin/autoconf2.13)


#do-configure:
#(cd ${WRKSRC} && \
#		${SETENV} ${CONFIGURE_ENV} ${MAKE_ENV} ${PYTHON_CMD} mach configure ${MOZ_OPTIONS})

#do-build:
#(cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${MAKE_ENV} ${PYTHON_CMD} mach build )

#do-install:
#(cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${MAKE_ENV} ${PYTHON_CMD} mach install)


.include <bsd.port.mk>
