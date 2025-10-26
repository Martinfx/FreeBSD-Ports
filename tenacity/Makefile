PORTNAME=	tenacity
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4
DISTVERSIONSUFFIX=	-alpha1
CATEGORIES=	multimedia

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Tenacity is an easy-to-use multi-track audio editor and recorde.
WWW=		https://tenacityaudio.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	expat>0:textproc/expat2 \
		ffmpeg>0:multimedia/ffmpeg \
		flac>0:audio/flac \
		glib>0:devel/glib20 \
		lame>0:audio/lame \
		libid3tag>0:audio/libid3tag \
		libmatroska>0:multimedia/libmatroska \
		libsndfile>0:audio/libsndfile \
		libsoxr>0:audio/libsoxr \
		libzip>0:archivers/libzip \
		lilv>0:audio/lilv \
		lv2>0:audio/lv2 \
		mpg123>0:audio/mpg123 \
		nasm>=0:devel/nasm \
		opus>0:audio/opus \
		opusfile>0:audio/opusfile \
		portaudio>0:audio/portaudio \
		portmidi>0:audio/portmidi \
		rapidjson>0:devel/rapidjson \
		soundtouch>0:audio/soundtouch \
		suil>0:audio/suil \
		twolame>0:audio/twolame \
		vamp-plugin-sdk>0:audio/vamp-plugin-sdk \
		wavpack>0:audio/wavpack \
		wx32-gtk3>0:x11-toolkits/wxgtk32 \
		zam-plugins-lv2>0:audio/zam-plugins-lv2

LIB_DEPENDS+=	libatk-1.0.so:accessibility/at-spi2-core \
		libexpat.so:textproc/expat2 \
		libharfbuzz.so:print/harfbuzz \
		liblilv-0.so:audio/lilv \
		libportaudio.so:audio/portaudio \
		libsndfile.so:audio/libsndfile \
		libSoundTouch.so:audio/soundtouch \
		libsoxr.so:audio/libsoxr \
		libsuil-0.so:audio/suil \
		libvamp-hostsdk.so:audio/vamp-plugin-sdk \
		libwx_baseu-3.2.so:x11-toolkits/wxgtk32 \
		libwx_baseu_net-3.2.so:x11-toolkits/wxgtk32 \
		libwx_gtk3u_core-3.2.so:x11-toolkits/wxgtk32 \
		libwx_gtk3u_html-3.2.so:x11-toolkits/wxgtk32 \
		libwx_gtk3u_qa-3.2.so:x11-toolkits/wxgtk32
USES=		cmake gettext-runtime localbase pkgconfig python sqlite
USE_GNOME=	cairo gdkpixbuf glib20 gtk30 pango

USE_GITHUB=	yes
GH_ACCOUNT=	tenacityteam
GH_PROJECT=	tenacity
GH_TUPLE+=	Martinfx:libnyquist:a76cd38:libnyquist/lib-src/libnyquist

CMAKE_OFF=	LIBNYQUIST_BUILD_EXAMPLE
CFLAGS+=	-fPIC

.include <bsd.port.options.mk>

OPTIONS_DEFINE=		AVX AVX2 AVX512 SSE4
OPTIONS_DEFAULT=	SSE4

SSE4_DESC=	Prefer SSE4 fallback (no AVX*)
AVX_DESC=	Enable AVX (x86_64 only)
AVX2_DESC=	Enable AVX2 (x86_64 only)
AVX512_DESC=	Enable AVX512 (x86_64 only)

.if ${ARCH} != amd64
OPTIONS_EXCLUDE+=	AVX AVX2 AVX512 SSE4
.endif

CMAKE_ARGS+=	-DAVX2=OFF \
		-DAVX512=OFF \
		-DAVX=OFF

.if ${ARCH} == amd64
.if ${PORT_OPTIONS:MAVX512}
CMAKE_ARGS+=	-DAVX2=OFF \
		-DAVX512=ON \
		-DAVX=OFF
.elif ${PORT_OPTIONS:MAVX2}
CMAKE_ARGS+=	-DAVX2=ON \
		-DAVX512=OFF \
		-DAVX=OFF
.elif ${PORT_OPTIONS:MAVX}
CMAKE_ARGS+=	-DAVX2=OFF \
		-DAVX512=OFF \
		-DAVX=ON
.elif ${PORT_OPTIONS:MSSE4}
CMAKE_ARGS+=	-DAVX2=OFF \
		-DAVX512=OFF \
		-DAVX=OFF
.else
.endif
.endif

.include <bsd.port.mk>
