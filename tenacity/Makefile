PORTNAME=	tenacity
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4-alpha1-332
DISTVERSIONSUFFIX=	-gea6a9f50c
CATEGORIES=	multimedia audio

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Easy-to-use multi-track audio editor and recorder
WWW=		https://tenacityaudio.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	rapidjson>0:devel/rapidjson
LIB_DEPENDS=	libatk-1.0.so:accessibility/at-spi2-core \
		libexpat.so:textproc/expat2 \
		libharfbuzz.so:print/harfbuzz \
		libmp3lame.so:audio/lame \
		libportaudio.so:audio/portaudio \
		libsndfile.so:audio/libsndfile \
		libSoundTouch.so:audio/soundtouch \
		libsoxr.so:audio/libsoxr \
		libzip.so:archivers/libzip

USES=		cmake compiler:c++17-lang desktop-file-utils gettext-runtime \
		gnome localbase pkgconfig shared-mime-info sqlite
USE_GITHUB=	yes
GH_ACCOUNT=	tenacityteam
GH_TUPLE=	portsmf:portsmf:239:portsmf/lib-src/portsmf \
		tenacityteam:libnyquist:aaf654f:libnyquist/lib-src/libnyquist
USE_GNOME=	cairo gdkpixbuf glib20 gtk30 pango
USE_WX=		3.2
WX_COMPS=	wx

CMAKE_ARGS=	-DTENACITY_REV_LONG:STRING=ea6a9f50c3ec95d9e129a6d404c7c3f83480be25
# SoundTouch cannot be disabled: ChangeTempo fails to build without it
CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_Git \
		CMAKE_DISABLE_FIND_PACKAGE_Python3 SOUNDTOUCH
CMAKE_OFF=	PCH SBSMS VCPKG

PORTDOCS=	README.md

OPTIONS_DEFINE=		DOCS FFMPEG FLAC ID3TAG LADSPA LV2 MATROSKA MIDI \
			MPG123 NLS NYQUIST OPUS TWOLAME VAMP VORBIS VST WAVPACK
OPTIONS_DEFINE_amd64=	AVX AVX2 AVX512
OPTIONS_DEFAULT=	FFMPEG FLAC ID3TAG LADSPA LV2 MATROSKA MIDI MPG123 \
			NYQUIST OPUS SWH TWOLAME VAMP VORBIS VST WAVPACK ZAM
OPTIONS_GROUP=		PLUGINS
OPTIONS_GROUP_PLUGINS=	CALF CAPS CMT DRAGONFLY LSP MDA NOISEREPELLENT SWH \
			TAP X42 ZAM
OPTIONS_EXCLUDE_i386=	X42
OPTIONS_EXCLUDE_powerpc=	LSP
OPTIONS_EXCLUDE_riscv64=	LSP
OPTIONS_SUB=		yes

AVX_DESC=		Use AVX instructions instead of SSE4
AVX2_DESC=		Use AVX2 instructions instead of SSE4 or AVX
AVX512_DESC=		Use AVX512 instructions instead of SSE4 or AVX2
FFMPEG_DESC=		FFmpeg import/export support (loaded at runtime)
ID3TAG_DESC=		ID3 tag support for MP3 files
LADSPA_DESC=		LADSPA plugin hosting
LV2_DESC=		LV2 plugin hosting
MATROSKA_DESC=		Matroska (MKA/MKV) container support
MIDI_DESC=		MIDI support (note tracks, MIDI import/export)
MPG123_DESC=		MP3 import support via mpg123
NYQUIST_DESC=		Nyquist effects and scripting support
TWOLAME_DESC=		MP2 export support via TwoLAME
VAMP_DESC=		Vamp analysis plugin hosting
VST_DESC=		VST (version 2) plugin hosting

PLUGINS_DESC=		Bundled third-party effect plugins
CALF_DESC=		Calf Studio Gear (LV2)
CAPS_DESC=		C* Audio Plugin Suite (LADSPA)
CMT_DESC=		Computer Music Toolkit (LADSPA)
DRAGONFLY_DESC=		Dragonfly reverbs (LV2)
LSP_DESC=		Linux Studio Plugins (LV2)
MDA_DESC=		MDA plugins (LV2)
NOISEREPELLENT_DESC=	Noise Repellent noise reduction (LV2)
SWH_DESC=		Steve Harris' plugins (LADSPA)
TAP_DESC=		Tom's Audio Processing plugins (LADSPA)
X42_DESC=		x42 plugin collection (LV2)
ZAM_DESC=		ZamAudio plugins (LV2 and LADSPA)

AVX_CMAKE_BOOL=		AVX
AVX2_CMAKE_BOOL=	AVX2
AVX512_CMAKE_BOOL=	AVX512

FFMPEG_RUN_DEPENDS=	ffmpeg>=6:multimedia/ffmpeg
FFMPEG_CMAKE_BOOL=	FFMPEG

FLAC_LIB_DEPENDS=	libFLAC++.so:audio/flac
FLAC_CMAKE_BOOL=	FLAC

ID3TAG_LIB_DEPENDS=	libid3tag.so:audio/libid3tag
ID3TAG_CMAKE_BOOL=	ID3TAG

LADSPA_CMAKE_BOOL=	LADSPA

LV2_BUILD_DEPENDS=	lv2>0:audio/lv2
LV2_LIB_DEPENDS=	liblilv-0.so:audio/lilv \
			libsuil-0.so:audio/suil
LV2_CMAKE_BOOL=		LV2

MATROSKA_LIB_DEPENDS=	libebml.so:textproc/libebml \
			libmatroska.so:multimedia/libmatroska
MATROSKA_CMAKE_BOOL=	MATROSKA

# PortSMF (lib-src/portsmf) is built statically, it is not in the ports tree
MIDI_LIB_DEPENDS=	libportmidi.so:audio/portmidi
MIDI_CMAKE_BOOL=	MIDI

MPG123_LIB_DEPENDS=	libmpg123.so:audio/mpg123
MPG123_CMAKE_BOOL=	MP3_DECODING

NLS_USES=		gettext-tools
NLS_CMAKE_OFF=		-DCMAKE_DISABLE_FIND_PACKAGE_Gettext:BOOL=ON

NYQUIST_CMAKE_BOOL=	NYQUIST

OPUS_IMPLIES=		VORBIS
OPUS_LIB_DEPENDS=	libopus.so:audio/opus \
			libopusfile.so:audio/opusfile
OPUS_CMAKE_BOOL=	OPUS

TWOLAME_LIB_DEPENDS=	libtwolame.so:audio/twolame
TWOLAME_CMAKE_BOOL=	MP2

VAMP_LIB_DEPENDS=	libvamp-hostsdk.so:audio/vamp-plugin-sdk
VAMP_CMAKE_BOOL=	VAMP

VORBIS_LIB_DEPENDS=	libogg.so:audio/libogg \
			libvorbis.so:audio/libvorbis
VORBIS_CMAKE_BOOL=	OGG VORBIS

VST_CMAKE_BOOL=		VST2

WAVPACK_LIB_DEPENDS=	libwavpack.so:audio/wavpack
WAVPACK_CMAKE_BOOL=	WAVPACK

CALF_IMPLIES=		LV2
CALF_RUN_DEPENDS=	calf-lv2>0:audio/calf-lv2
CAPS_IMPLIES=		LADSPA
CAPS_RUN_DEPENDS=	caps-plugins>0:audio/caps-plugins
CMT_IMPLIES=		LADSPA
CMT_RUN_DEPENDS=	cmt>0:audio/cmt
DRAGONFLY_IMPLIES=	LV2
DRAGONFLY_RUN_DEPENDS=	dragonfly-reverb>0:audio/dragonfly-reverb-lv2
LSP_IMPLIES=		LV2
LSP_RUN_DEPENDS=	lsp-plugins-lv2>0:audio/lsp-plugins-lv2
MDA_IMPLIES=		LV2
MDA_RUN_DEPENDS=	mda-lv2>0:audio/mda-lv2
NOISEREPELLENT_IMPLIES=	LV2
NOISEREPELLENT_RUN_DEPENDS=	noise-repellent-lv2>0:audio/noise-repellent-lv2
SWH_IMPLIES=		LADSPA
SWH_RUN_DEPENDS=	swhplugins>0:audio/swhplugins
TAP_IMPLIES=		LADSPA
TAP_RUN_DEPENDS=	tap-plugins>0:audio/tap-plugins
X42_IMPLIES=		LV2
X42_RUN_DEPENDS=	x42-plugins-lv2>0:audio/x42-plugins-lv2
ZAM_IMPLIES=		LV2
ZAM_RUN_DEPENDS=	zam-plugins-lv2>0:audio/zam-plugins-lv2

.include <bsd.port.options.mk>

.if ${ARCH} == i386
# pffft uses SSE intrinsics unconditionally
CFLAGS+=	-msse2
CXXFLAGS+=	-msse2
.endif

post-install:
# libnyquist is linked statically into lib-nyquist-effects
	@${RM} ${STAGEDIR}${PREFIX}/lib/libnyquist.a
	@${RM} ${STAGEDIR}${DOCSDIR}/LICENSE.txt

post-install-DOCS-off:
	@${RM} -r ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
