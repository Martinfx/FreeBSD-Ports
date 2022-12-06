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
#RUN_DEPENDS=	tor:security/tor \
#		obfs4proxy:security/obfs4proxy-tor

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
CONFIGURE_ENV+=	BINDGEN_CFLAGS="-I${LOCALBASE}/include" MOZILLA_OFFICIAL=1
#https://gitlab.torproject.org/tpo/applications/tor-browser/-/merge_requests/299/
MOZ_OPTIONS= --with-tor-browser-version=12.0-2 \
# options from browser/config/mozconfigs/base_browser \
	--enable-official-branding \
	--enable-optimize \
	--enable-rust-simd \
	--enable-bundled-fonts \
	--disable-tests \
	--disable-debug \
	--disable-crashreporter \
#Before removing, please notice that WebRTC does not work on mingw (Bug 1393901) \
	--disable-webrtc \
	--disable-parental-controls \
# Let's make sure no preference is enabling either Adobe's or Google's CDM. \
	--disable-eme \
	--enable-proxy-bypass-protection \
# See bugs #30575 and #32418: system policies are harmful either because they \
# could allow proxy bypass, and override a number of other preferences we set \
	--disable-system-policies \

# See bug #41131 \
	--disable-backgroundtasks \
	--enable-base-browser \
# Disable telemetry \
	MOZ_TELEMETRY_REPORTING= \

# from from browser/config/mozconfigs/tor_browser \
	MOZ_APP_DISPLAYNAME="Tor Browser" \
	--with-relative-profile=TorBrowser/Data/Browser \
	--enable-tor-browser-update \
	--enable-verify-mar \
	--with-distribution-id=org.torproject

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


pre-configure:
	(cd ${WRKSRC} && ${LOCALBASE}/bin/autoconf2.13)
	(cd ${WRKSRC}/js/src/ && ${LOCALBASE}/bin/autoconf2.13)


.include <bsd.port.mk>
