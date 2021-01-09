# $FreeBSD$

PORTNAME=	ungoogled-chromium
DISTVERSION=	87.0.4280.88-1
CATEGORIES=	www

MAINTAINER=	maintainer@email.com
COMMENT=	ungoogled chromium

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_PROJECT=	${PORTNAME}
GH_ACCOUNT=	Eloston

#BUILD_DEPENDS=	bash:shells/bash \
#		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
#		${PYTHON_PKGNAMEPREFIX}ply>0:devel/py-ply@${PY_FLAVOR} \

.if !defined(GN_ONLY)
BUILD_DEPENDS+=	gperf:devel/gperf \
		ffmpeg>=3.2.2,1:multimedia/ffmpeg \
		flock:sysutils/flock \
		node:www/node \
		xcb-proto>0:x11/xcb-proto \
		${LOCALBASE}/bin/ar:devel/binutils \
		${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat \
		${LOCALBASE}/share/usbids/usb.ids:misc/usbids \
		${PYTHON_PKGNAMEPREFIX}html5lib>0:www/py-html5lib@${PY_FLAVOR}
.endif

.if !defined(GN_ONLY)
LIB_DEPENDS=	libatk-bridge-2.0.so:accessibility/at-spi2-atk \
		libatspi.so:accessibility/at-spi2-core \
		libspeechd.so:accessibility/speech-dispatcher \
		libsnappy.so:archivers/snappy \
		libFLAC.so:audio/flac \
		libopus.so:audio/opus \
		libspeex.so:audio/speex \
		libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libicuuc.so:devel/icu \
		libjsoncpp.so:devel/jsoncpp \
		libpci.so:devel/libpci \
		libnspr4.so:devel/nspr \
		libre2.so:devel/re2 \
		libcairo.so:graphics/cairo \
		libdrm.so:graphics/libdrm \
		libexif.so:graphics/libexif \
		libpng.so:graphics/png \
		libwebp.so:graphics/webp \
		libavcodec.so:multimedia/ffmpeg \
		libopenh264.so:multimedia/openh264 \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libharfbuzz-icu.so:print/harfbuzz-icu \
		libgcrypt.so:security/libgcrypt \
		libsecret-1.so:security/libsecret \
		libnss3.so:security/nss \
		libexpat.so:textproc/expat2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libxkbcommon.so:x11/libxkbcommon

RUN_DEPENDS=	xdg-open:devel/xdg-utils \
		noto-basic>0:x11-fonts/noto-basic

BROKEN_FreeBSD_11_aarch64=	components/safe_browsing_db/v4_rice.cc:120:18: use of overloaded operator '&' is ambiguous
ONLY_FOR_ARCHS=			aarch64 amd64 i386

.endif

.if defined(GN_ONLY)
USES=		compiler:c++14-lang dos2unix localbase:ldflags ninja pkgconfig \
		python:3.7,build shebangfix tar:xz
.else
USES=		bison cpe desktop-file-utils dos2unix gl gnome jpeg localbase:ldflags \
		ninja perl5 pkgconfig python:3.7,build shebangfix tar:xz xorg
.endif

BINARY_ALIAS=	python=${PYTHON_CMD}
#DOS2UNIX_FILES=	third_party/skia/third_party/vulkanmemoryallocator/include/vk_mem_alloc.h

.if !defined(GN_ONLY)
CPE_VENDOR=	google
CPE_PRODUCT=	chrome
USE_GL=		gbm gl
USE_LDCONFIG=	${DATADIR}
USE_PERL5=	build
USE_XORG=	x11 xcb xcomposite xcursor xext xdamage xfixes xi \
		xorgproto xrandr xrender xscrnsaver xtst
USE_GNOME=	atk dconf glib20 gtk30 libxml2 libxslt
#SHEBANG_FILES=	chrome/tools/build/linux/chrome-wrapper buildtools/linux64/clang-format
ALL_TARGET=	chrome
INSTALLS_ICONS=	yes

.endif

GN_ARGS+=	enable_hangout_services_extension=false \
		enable_mdns=false			\
		enable_mse_mpeg2ts_stream_parser=true	\
		enable_nacl=false					\
		enable_nacl_nonsfi=false				\
		enable_one_click_signin=false				\
		enable_reading_list=false				\
		enable_remoting=false					\
		enable_reporting=false					\
		enable_service_discovery=false				\
		enable_widevine=true					\
		exclude_unwind_tables=true				\
		fieldtrial_testing_like_official_build=true \
		google_api_key=""			\
		google_default_client_id=""		\
		google_default_client_secret=""		\
		optimize_webui=false			\
		safe_browsing_mode=0			\
		treat_warnings_as_errors=false		\
		use_official_google_api_keys=false	\
		use_unofficial_version_number=false	\
		fieldtrial_testing_like_official_build=true \
		is_clang=true				\
		jumbo_file_merge_limit=8 		\
		toolkit_views=true 			\
		treat_warnings_as_errors=false		\
		use_allocator="none" 			\
/		use_allocator_shim=false		\
		use_lld=true 				\
		use_sysroot=false


MAKE_ARGS=      -C out/${BUILDTYPE}
GN_BOOTSTRAP_FLAGS=	--no-clean --no-rebuild --skip-generate-buildfiles

GN_ARGS+=	google_api_key="AIzaSyBsp9n41JLW8jCokwn7vhoaMejDFRd1mp8" \
		google_default_client_id="996322985003.apps.googleusercontent.com" \
				google_default_client_secret="IR1za9-1VK0zZ0f_O8MVFicn"

#if !defined(GN_ONLY)
#SUB_FILES=	chromium-browser.desktop chrome
SUB_LIST+=	COMMENT="${COMMENT}"

OPTIONS_DEFINE=	CODECS CUPS DEBUG DRIVER KERBEROS TEST
CODECS_DESC=	Compile and enable patented codecs like H.264
DRIVER_DESC=	Install chromedriver
OPTIONS_GROUP=		AUDIO
OPTIONS_GROUP_AUDIO=	ALSA PULSEAUDIO SNDIO

OPTIONS_DEFAULT=	CODECS CUPS DRIVER KERBEROS SNDIO
OPTIONS_SUB=		yes

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_RUN_DEPENDS=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:audio/alsa-plugins \
			alsa-lib>=1.1.1_1:audio/alsa-lib
ALSA_VARS=		GN_ARGS+=use_alsa=true
ALSA_VARS_OFF=		GN_ARGS+=use_alsa=false

CODECS_VARS=		GN_ARGS+=ffmpeg_branding="Chrome" \
			GN_ARGS+=proprietary_codecs=true
CODECS_VARS_OFF=	GN_ARGS+=ffmpeg_branding="Chromium" \
			GN_ARGS+=proprietary_codecs=false

CUPS_LIB_DEPENDS=	libcups.so:print/cups
CUPS_VARS=		GN_ARGS+=use_cups=true
CUPS_VARS_OFF=		GN_ARGS+=use_cups=false

DEBUG_VARS=             BUILDTYPE=Debug \
                        GN_ARGS+=is_debug=true \
	                GN_ARGS+=is_component_build=false \
                       GN_ARGS+=symbol_level=1 \
                        GN_BOOTSTRAP_FLAGS+=--debug \
                        WANTSPACE="lots of free disk space (~ 13GB)"

DEBUG_VARS_OFF=         BUILDTYPE=Release \
                        GN_ARGS+=blink_symbol_level=0 \
                        GN_ARGS+=is_debug=false \
                        GN_ARGS+=is_official_build=true \
                        GN_ARGS+=symbol_level=0 \
                        WANTSPACE="a fair amount of free disk space (~ 6.5GB)"

DRIVER_MAKE_ARGS=	chromedriver

KERBEROS_VARS=		GN_ARGS+=use_kerberos=true
KERBEROS_VARS_OFF=	GN_ARGS+=use_kerberos=false

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_VARS=	GN_ARGS+=use_pulseaudio=true
PULSEAUDIO_VARS_OFF=	GN_ARGS+=use_pulseaudio=false

# With SNDIO=on we exclude audio_manager_linux from the build (see
# media/audio/BUILD.gn) and use audio_manager_openbsd which does not
# support falling back to ALSA or PulseAudio.
SNDIO_PREVENTS=		ALSA PULSEAUDIO
SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_VARS=		GN_ARGS+=use_sndio=true
SNDIO_VARS_OFF=		GN_ARGS+=use_sndio=false

#.endif

.include <bsd.port.options.mk>

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "To build Chromium, you should have around 2GB of memory"
	@${ECHO_MSG} "and ${WANTSPACE}."
	@${ECHO_MSG}

post-extract:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${BASH} ${MKDIR}  build/download_cache \
	&& ${PYTHON_CMD} ./ungoogled-chromium/utils/downloads.py retrieve -c build/download_cache -i ungoogled-chromium/downloads.ini \
	&& ${PYTHON_CMD} ./ungoogled-chromium/utils/downloads.py unpack -c build/download_cache -i ungoogled-chromium/downloads.ini -- build/src \
	&& ${PYTHON_CMD} ./ungoogled-chromium/utils/prune_binaries.py build/src ungoogled-chromium/pruning.list \
	&& ${PYTHON_CMD} ./ungoogled-chromium/utils/patches.py apply build/src patches \
	&& ${PYTHON_CMD} ./ungoogled-chromium/utils/domain_substitution.py apply -r ungoogled-chromium/domain_regex.list -f ungoogled-chromium/domain_substitution.list -c ungoogled-chromium/domsubcache.tar.gz build/src

do-configure:
	cd ${WRKSRC}/build/src && ${SETENV} ${CONFIGURE_ENV} CC=${CC} CXX=${CXX} ${PYTHON_CMD} \
	./build/linux/unbundle/replace_gn_files.py --system-libraries \
		ffmpeg flac fontconfig freetype harfbuzz-ng libdrm libpng libwebp libxml libxslt openh264 opus snappy || ${FALSE}

	# We need the site package from xcbgen, which installs as python3.x (really: default version), while the chromium
	# build still needs to use python2.7. It works, because xcbgen can run with both versions, but we want to avoid
	# having the pre-compiled pyc files from 2.7 in the 3.x site packages
	# Remove this as soon as chromium uses python3.x as well
	@${MKDIR} ${WRKDIR}/site-packages/xcbgen
	${CP} ${PYTHONBASE}/lib/python${PYTHON_DEFAULT}/site-packages/xcbgen/*.py \
		${WRKDIR}/site-packages/xcbgen

	# GN generator bootstrapping and generating ninja files
	cd ${WRKSRC}/build/src && ${SETENV} ${CONFIGURE_ENV} CC=${CC} CXX=${CXX} LD=${CXX} \
		READELF=${READELF} AR=${AR} NM=${NM} ${PYTHON_CMD} \
		./tools/gn/bootstrap/bootstrap.py

	cd ${WRKSRC}/build/src && ${SETENV} ${CONFIGURE_ENV} \
		./out/${BUILDTYPE}/gn gen .



.include <bsd.port.mk>
