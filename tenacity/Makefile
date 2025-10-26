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
		gtk3>0:x11-toolkits/gtk30 \
		lame>0:audio/lame \
		libid3tag>0:audio/libid3tag \
		libsndfile>0:audio/libsndfile \
		libsoxr>0:audio/libsoxr \
		libzip>0:archivers/libzip \
		libmatroska>0:multimedia/libmatroska \
		lilv>0:audio/lilv \
		lv2>0:audio/lv2 \
		mpg123>0:audio/mpg123 \
		opus>0:audio/opus \
		opusfile>0:audio/opusfile \
		portaudio>0:audio/portaudio \
		portmidi>0:audio/portmidi \
		rapidjson>0:devel/rapidjson \
		soundtouch>0:audio/soundtouch \
		sqlite3>0:databases/sqlite3 \
		suil>0:audio/suil \
		twolame>0:audio/twolame \
		vamp-plugin-sdk>0:audio/vamp-plugin-sdk \
		wavpack>0:audio/wavpack \
		wx32-gtk3>0:x11-toolkits/wxgtk32 \
		zam-plugins-lv2>0:audio/zam-plugins-lv2

USES=		cmake python localbase

USE_GITHUB=	yes
GH_ACCOUNT=	tenacityteam
GH_PROJECT=	tenacity
GH_TUPLE+=	Martinfx:libnyquist:a76cd38:libnyquist/lib-src/libnyquist

CMAKE_OFF=	LIBNYQUIST_BUILD_EXAMPLE
CFLAGS+=	-fPIC

.include <bsd.port.mk>
