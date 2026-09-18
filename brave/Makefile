PORTNAME=	brave
DISTVERSIONPREFIX=	v
DISTVERSION=	1.87.131
CATEGORIES=	www
MASTER_SITES=	https://commondatastorage.googleapis.com/chromium-browser-official/:chromium
DISTFILES=	chromium-${CHROME_VERSION}-lite.tar.xz:chromium

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Brave web browser based on Chromium
WWW=		https://brave.com/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/src/brave/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	the Chromium build is only supported on amd64 and aarch64

# Chromium release the pinned brave-core revision is built against, see
# "config.projects.chrome.tag" in src/brave/package.json.
CHROME_VERSION=	144.0.7559.31

# This port builds natively: depot_tools, gclient, cipd, siso and reclient are
# not used at all.  Everything is taken from the official Chromium release
# tarball (which, unlike a git checkout, already contains all DEPS-managed
# third-party code), from brave-core and from the ports tree.  The parts that
# gclient would normally fetch for brave-core are listed in GH_TUPLE below and
# match the "deps" section of src/brave/DEPS.

USE_GITHUB=	yes
GH_ACCOUNT=	brave
GH_PROJECT=	brave-browser
GH_TUPLE=	brave:brave-core:eebca352d681b19d6bdc0d8eed3fc7d26f0ada04:core/src/brave \
		brave:python-patch:d8880110be6554686bc08261766538c2926d4e82:pypatch/src/brave/vendor/python-patch \
		brave-intl:bat-native-tweetnacl:8b424ccf29957fe01c88c36076fd32006a357887:tweetnacl/src/brave/vendor/bat-native-tweetnacl \
		brave:gn-project-generators:b76e14b162aa0ce40f11920ec94bfc12da29e5d0:gnprojgen/src/brave/vendor/gn-project-generators \
		brave:web-discovery-project:17d6581e06c4cfbc476f5da0c9bb61bd1520617f:wdp/src/brave/vendor/web-discovery-project \
		brave-intl:bat-native-bip39wally-core:0d3a8713a2b388d2156fe49a70ef3f7cdb44b190:bip39wally/src/brave/third_party/bip39wally-core-native \
		chfast:ethash:e4a15c3d76dc09392c7efd3e30d84ee3b871e9ce:ethash/src/brave/third_party/ethash/src \
		bitcoin:bitcoin:8105bce5b384c72cf08b25b7c5343622754e7337:bitcoincore/src/brave/third_party/bitcoin-core/src \
		P-H-C:phc-winner-argon2:62358ba2123abd17fccf2a108a301d4b52c01a7c:argon2/src/brave/third_party/argon2/src \
		brave:playlist-component:673d40f017a1559bb685a15cf608ad1d4a94f8fb:playlist/src/brave/third_party/playlist_component/src \
		brave-intl:futures-retry:2aaaafbc3d394661534d4dbd14159d164243c20e:futuresretry/src/brave/third_party/rust/futures_retry/v0_5/crate \
		brave:librustzcash:127aacc83dc9ed12fc38c3c7f5b52f7f51011e4d:librustzcash/src/brave/components/brave_wallet/browser/zcash/rust/librustzcash/src

BUILD_DEPENDS=	bash:shells/bash \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ply>0:devel/py-ply@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}html5lib>0:www/py-html5lib@${PY_FLAVOR} \
		bindgen:devel/rust-bindgen-cli \
		gperf:devel/gperf \
		flock:sysutils/flock \
		npm:www/npm \
		rustc:lang/rust \
		xcb-proto>0:x11/xcb-proto \
		${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat \
		${LOCALBASE}/share/usbids/usb.ids:misc/usbids \
		${LOCALBASE}/libdata/pkgconfig/dri.pc:graphics/mesa-libs

LIB_DEPENDS=	libatk-bridge-2.0.so:accessibility/at-spi2-core \
		libatspi.so:accessibility/at-spi2-core \
		libspeechd.so:accessibility/speech-dispatcher \
		libFLAC.so:audio/flac \
		libopus.so:audio/opus \
		libspeex.so:audio/speex \
		libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libepoll-shim.so:devel/libepoll-shim \
		libevent.so:devel/libevent \
		libffi.so:devel/libffi \
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
		libdav1d.so:multimedia/dav1d \
		libopenh264.so:multimedia/openh264 \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libharfbuzz-icu.so:print/harfbuzz-icu \
		libgcrypt.so:security/libgcrypt \
		libsecret-1.so:security/libsecret \
		libnss3.so:security/nss \
		libexpat.so:textproc/expat2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libwayland-client.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon \
		libxshmfence.so:x11/libxshmfence

RUN_DEPENDS=	xdg-open:devel/xdg-utils \
		noto-basic>0:x11-fonts/noto-basic

USES=		bison compiler:c++20-lang cpe desktop-file-utils gl gmake gnome \
		iconv:wchar_t jpeg localbase:ldflags ninja nodejs:24,build \
		perl5 pkgconfig python:build shebangfix tar:xz xorg

CPE_VENDOR=	brave
CPE_PRODUCT=	brave
USE_GL=		gbm gl
USE_GNOME=	atk dconf gdkpixbuf glib20 gtk30 libxml2 libxslt
USE_LDCONFIG=	${DATADIR}
USE_PERL5=	build
USE_XORG=	x11 xcb xcomposite xcursor xext xdamage xfixes xi \
		xorgproto xrandr xrender xscrnsaver xtst

SHEBANG_FILES=	src/brave/script/*.py

# Everything below out/ is driven by ninja from the Chromium source root.
BUILD_WRKSRC=		${WRKSRC}/src
CONFIGURE_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=		${WRKSRC}/src
MAKE_ARGS=	-C out/${BUILDTYPE}
ALL_TARGET=	brave

BINARY_ALIAS=	python3=${PYTHON_CMD}

BRAVE_VERSION_MAJOR=	${DISTVERSION:R:R}
BRAVE_VERSION_MINOR=	${DISTVERSION:R:E}
BRAVE_VERSION_BUILD=	${DISTVERSION:E}

GN=		${BUILD_WRKSRC}/out/${BUILDTYPE}/gn
GN_BOOTSTRAP_FLAGS=	--no-clean --no-rebuild --skip-generate-buildfiles

# FreeBSD support for the Chromium tree itself lives in www/chromium, it is not
# duplicated here.  Point CHROMIUM_FREEBSD_PATCHDIR at the files/ directory of a
# www/chromium port for the very same Chromium release; anything else will fail
# to apply.
CHROMIUM_FREEBSD_PATCHDIR?=	${PORTSDIR}/www/chromium/files

# Brave overrides Chromium sources through chromium_src/, which only works when
# the compiler is invoked through redirect_cc as a cc_wrapper.  Without siso
# (which is fetched with CIPD and does not exist for FreeBSD) redirect_cc has to
# be built first, into its own output directory.
REDIRECT_CC_DIR=	${BUILD_WRKSRC}/out/redirect_cc

GN_ARGS+=	import("//brave/build/args/brave_defaults.gni") \
		import("//brave/build/args/blink_platform_defaults.gni") \
		import("//brave/build/args/desktop_defaults.gni") \
		target_os="freebsd" \
		target_cpu="${GN_CPU}" \
		brave_channel="" \
		brave_version_major="${BRAVE_VERSION_MAJOR}" \
		brave_version_minor="${BRAVE_VERSION_MINOR}" \
		brave_version_build="${BRAVE_VERSION_BUILD}" \
		chrome_version_string="${CHROME_VERSION}" \
		cc_wrapper="${REDIRECT_CC_DIR}/redirect_cc" \
		clang_use_chrome_plugins=false \
		chrome_pgo_phase=0 \
		enable_backup_ref_ptr_support=false \
		enable_cdm_host_verification=false \
		enable_hangout_services_extension=false \
		enable_nacl=false \
		enable_remoting=false \
		enable_updater=false \
		enable_update_notifications=false \
		enable_widevine=false \
		fatal_linker_warnings=false \
		icu_use_data_file=false \
		is_clang=true \
		is_component_build=false \
		is_official_build=false \
		optimize_webui=true \
		skip_signing=true \
		toolkit_views=true \
		treat_warnings_as_errors=false \
		use_allocator_shim=false \
		use_aura=true \
		use_custom_libcxx=true \
		use_custom_libunwind=true \
		use_lld=true \
		use_partition_alloc=true \
		use_partition_alloc_as_malloc=false \
		use_qt5=false \
		use_qt6=false \
		use_reclient=false \
		use_remoteexec=false \
		use_siso=false \
		use_sysroot=false \
		use_system_freetype=false \
		use_system_harfbuzz=true \
		use_system_libffi=true \
		use_system_libjpeg=true \
		use_udev=false \
		extra_cxxflags="${CXXFLAGS} -I${LOCALBASE}/include/libepoll-shim" \
		extra_ldflags="${LDFLAGS}" \
		ffmpeg_branding="${FFMPEG_BRAND}"

# redirect_cc is a small host tool, it must not be wrapped by itself.
GN_REDIRECT_CC_ARGS=	import("//brave/tools/redirect_cc/args.gni") \
			target_os="freebsd" \
			target_cpu="${GN_CPU}" \
			clang_use_chrome_plugins=false \
			is_clang=true \
			treat_warnings_as_errors=false \
			use_reclient=false \
			use_remoteexec=false \
			use_siso=false \
			use_sysroot=false

OPTIONS_DEFINE=		CODECS DEBUG LTO
OPTIONS_DEFAULT=	CODECS ALSA PULSEAUDIO SNDIO
OPTIONS_EXCLUDE_aarch64=LTO
OPTIONS_GROUP=		AUDIO
OPTIONS_GROUP_AUDIO=	ALSA PULSEAUDIO SNDIO
OPTIONS_SUB=		yes
CODECS_DESC=		Compile and enable patented codecs like H.264

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_VARS=		GN_ARGS+=use_alsa=true
ALSA_VARS_OFF=		GN_ARGS+=use_alsa=false

CODECS_VARS=		GN_ARGS+=proprietary_codecs=true \
			FFMPEG_BRAND="Chrome"
CODECS_VARS_OFF=	GN_ARGS+=proprietary_codecs=false \
			FFMPEG_BRAND="Chromium"

DEBUG_VARS=		BUILDTYPE=Debug \
			GN_BOOTSTRAP_FLAGS+=--debug \
			GN_ARGS+=is_debug=true \
			GN_ARGS+=symbol_level=1 \
			WANTSPACE="100 GB" \
			WANTMEM="32 GB"
DEBUG_VARS_OFF=		BUILDTYPE=Release \
			GN_ARGS+=is_debug=false \
			GN_ARGS+=symbol_level=0 \
			GN_ARGS+=blink_symbol_level=0 \
			WANTSPACE="60 GB" \
			WANTMEM="16 GB"

LTO_VARS=		GN_ARGS+=use_thin_lto=true \
			GN_ARGS+=thin_lto_enable_optimizations=true
LTO_VARS_OFF=		GN_ARGS+=use_thin_lto=false

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_VARS=	GN_ARGS+=use_pulseaudio=true
PULSEAUDIO_VARS_OFF=	GN_ARGS+=use_pulseaudio=false

SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_VARS=		GN_ARGS+=use_sndio=true
SNDIO_VARS_OFF=		GN_ARGS+=use_sndio=false

SUB_FILES=	brave brave-browser.desktop
SUB_LIST=	COMMENT="${COMMENT}"

.include <bsd.port.options.mk>
.include <bsd.port.pre.mk>

LLVM_DEFAULT=	21
BUILD_DEPENDS+=	clang${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT}
BINARY_ALIAS+=	cpp=${LOCALBASE}/bin/clang-cpp${LLVM_DEFAULT} \
		cc=${LOCALBASE}/bin/clang${LLVM_DEFAULT} \
		c++=${LOCALBASE}/bin/clang++${LLVM_DEFAULT} \
		ar=${LOCALBASE}/bin/llvm-ar${LLVM_DEFAULT} \
		nm=${LOCALBASE}/bin/llvm-nm${LLVM_DEFAULT} \
		ld=${LOCALBASE}/bin/ld.lld${LLVM_DEFAULT}

.if ${ARCH} == aarch64
GN_CPU=		arm64
FFMPEG_TARGET=	arm64
# swiftshader/lib/{libEGL.so,libGLESv2.so} is x86 only
PLIST_SUB+=	NOT_AARCH64="@comment "
.else
BUILD_DEPENDS+=	nasm:devel/nasm
GN_CPU=		x64
FFMPEG_TARGET=	x64
PLIST_SUB+=	NOT_AARCH64=""
.endif

FFMPEG_BDIR=	${BUILD_WRKSRC}/third_party/ffmpeg/build.${FFMPEG_TARGET}.freebsd/${FFMPEG_BRAND}
FFMPEG_CDIR=	${BUILD_WRKSRC}/third_party/ffmpeg/chromium/config/${FFMPEG_BRAND}/freebsd/${FFMPEG_TARGET}

.if !exists(${CHROMIUM_FREEBSD_PATCHDIR}/patch-BUILD.gn)
IGNORE=		needs the FreeBSD patches for the Chromium tree: set \
		CHROMIUM_FREEBSD_PATCHDIR to the files/ directory of a \
		www/chromium port for Chromium ${CHROME_VERSION}
.endif

MAKE_ENV+=	C_INCLUDE_PATH=${LOCALBASE}/include \
		CPLUS_INCLUDE_PATH=${LOCALBASE}/include \
		RUSTC_BOOTSTRAP=1
CONFIGURE_ENV+=	${MAKE_ENV}

GN_ARGS+=	enable_rust=true \
		rust_sysroot_absolute="${LOCALBASE}"

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "To build ${PORTNAME}, you should have at least:"
	@${ECHO_MSG} "- ${WANTMEM} of memory"
	@${ECHO_MSG} "- ${WANTSPACE} of free disk space"
	@${ECHO_MSG}

# The official Chromium tarball is unpacked next to brave-core, which gclient
# would otherwise check out as src/brave.  ${FIND} is used instead of a glob so
# that the dotfiles in the Chromium root (.gn above all) are moved as well.
post-extract:
	@${MKDIR} ${WRKSRC}/src
	@cd ${WRKDIR}/chromium-${CHROME_VERSION} && ${FIND} . -mindepth 1 \
		-maxdepth 1 -exec ${MV} {} ${WRKSRC}/src/ \;
	@${RMDIR} ${WRKDIR}/chromium-${CHROME_VERSION}

# Order matters: brave-core carries its own patches for the Chromium tree and
# they are written against pristine Chromium, so they have to go in before the
# FreeBSD ones.
post-patch:
	@${ECHO_MSG} "===>  Applying brave-core patches to the Chromium tree"
	@cd ${WRKSRC}/src/brave/patches && for _d in . v8 third_party/catapult \
	    third_party/devtools-frontend/src \
	    third_party/search_engines_data/resources; do \
		[ -d "$${_d}" ] || continue; \
		if [ "$${_d}" = "." ]; then _t=${WRKSRC}/src; \
		else _t=${WRKSRC}/src/$${_d}; fi; \
		for _p in $${_d}/*.patch; do \
			[ -f "$${_p}" ] || continue; \
			${PATCH} -s -d "$${_t}" -p1 \
			    -i ${WRKSRC}/src/brave/patches/$${_p} || exit 1; \
		done; \
	done
	@${ECHO_MSG} "===>  Applying FreeBSD patches to the Chromium tree"
	@for _p in ${CHROMIUM_FREEBSD_PATCHDIR}/patch-*; do \
		${PATCH} -s -d ${WRKSRC}/src -p0 -i "$${_p}" || exit 1; \
	done

pre-configure:
	cd ${BUILD_WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${PYTHON_CMD} \
		./build/linux/unbundle/replace_gn_files.py --system-libraries \
		dav1d flac fontconfig harfbuzz libdrm libpng \
		libusb libwebp libxml libxslt openh264 opus || ${FALSE}
	# Chromium ships an unreleased FFmpeg, so its config has to be generated
	cd ${BUILD_WRKSRC}/media/ffmpeg && \
		${PYTHON_CMD} scripts/build_ffmpeg.py freebsd ${FFMPEG_TARGET} \
		--config-only --branding=${FFMPEG_BRAND}
	cd ${FFMPEG_BDIR} && ${GMAKE} ffversion.h
	${MKDIR} ${FFMPEG_CDIR}
.for _e in config.h config.asm config_components.asm config_components.h \
	libavcodec libavformat libavutil
	-${CP} -pR ${FFMPEG_BDIR}/${_e} ${FFMPEG_CDIR}
.endfor
	@${REINPLACE_CMD} -e 's|$${LOCALBASE}|${LOCALBASE}|;s|$${MODCLANG_VERSION}|${LLVM_DEFAULT}|' \
		${BUILD_WRKSRC}/build/linux/strip_binary.gni \
		${BUILD_WRKSRC}/build/rust/rust_bindgen.gni \
		${BUILD_WRKSRC}/build/rust/rust_bindgen_generator.gni
	# The webpack based parts of the Brave UI are built out of node_modules.
	# This is the only step that still wants network access, so it is skipped
	# when the modules have been staged into the work directory beforehand.
	@if [ ! -d ${WRKSRC}/src/brave/node_modules ]; then \
		cd ${WRKSRC}/src/brave && ${SETENV} ${CONFIGURE_ENV} \
		    ${LOCALBASE}/bin/npm install --ignore-scripts --no-audit \
		    --no-fund; \
	fi

do-configure:
	# gn itself is built from the Chromium tree, no prebuilt binary is fetched
	cd ${BUILD_WRKSRC} && ${SETENV} ${CONFIGURE_ENV} CC=${CC} CXX=${CXX} \
		LD=${CXX} READELF=${READELF} AR=${AR} NM=${NM} ${PYTHON_CMD} \
		./tools/gn/bootstrap/bootstrap.py ${GN_BOOTSTRAP_FLAGS}

	# Dependencies Chromium normally expects below third_party/
	@${MKDIR} ${BUILD_WRKSRC}/third_party/node/freebsd/node-freebsd/bin
	${LN} -sf ${LOCALBASE}/bin/node \
		${BUILD_WRKSRC}/third_party/node/freebsd/node-freebsd/bin/node
	@${MKDIR} ${BUILD_WRKSRC}/third_party/rust-toolchain/bin
	${LN} -sf ${LOCALBASE}/bin/rustc \
		${BUILD_WRKSRC}/third_party/rust-toolchain/bin/rustc
	${LN} -sf ${LOCALBASE}/bin/gperf \
		${BUILD_WRKSRC}/third_party/gperf/cipd/bin/gperf
	@${MKDIR} ${BUILD_WRKSRC}/buildtools/freebsd
	${LN} -sf ${BUILD_WRKSRC}/buildtools/linux64/clang-format \
		${BUILD_WRKSRC}/buildtools/freebsd
	${LN} -sf ${GN} ${BUILD_WRKSRC}/buildtools/freebsd
	${LN} -sf /usr/bin/strip ${BUILD_WRKSRC}/buildtools/freebsd/strip

	# chromium_src/ overrides only take effect through redirect_cc
	cd ${BUILD_WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${GN} gen \
		--root-target=//brave/tools/redirect_cc \
		--args='${GN_REDIRECT_CC_ARGS}' out/redirect_cc
	cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${NINJA_CMD} -C out/redirect_cc \
		brave/tools/redirect_cc

	cd ${BUILD_WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${GN} gen \
		--args='${GN_ARGS}' out/${BUILDTYPE}

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/out/${BUILDTYPE}/brave \
		${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/out/${BUILDTYPE}/*.pak ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/out/${BUILDTYPE}/*.bin ${STAGEDIR}${DATADIR}
	cd ${BUILD_WRKSRC}/out/${BUILDTYPE} && \
		${COPYTREE_SHARE} "locales resources" ${STAGEDIR}${DATADIR}
.for _f in libEGL.so libGLESv2.so libVkICD_mock_icd.so
	${INSTALL_LIB} ${BUILD_WRKSRC}/out/${BUILDTYPE}/${_f} ${STAGEDIR}${DATADIR}
.endfor
	${INSTALL_LIB} ${BUILD_WRKSRC}/out/${BUILDTYPE}/libvulkan.so.1 \
		${STAGEDIR}${DATADIR}/libvulkan.so
.if ${ARCH} != aarch64
	${INSTALL_LIB} ${BUILD_WRKSRC}/out/${BUILDTYPE}/libvk_swiftshader.so \
		${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/out/${BUILDTYPE}/vk_swiftshader_icd.json \
		${STAGEDIR}${DATADIR}
.endif
.for _s in 24 48 64 128 256
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${_s}x${_s}/apps
	${INSTALL_DATA} \
		${WRKSRC}/src/brave/app/theme/brave/product_logo_${_s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${_s}x${_s}/apps/brave.png
.endfor
	${INSTALL_SCRIPT} ${WRKDIR}/brave ${STAGEDIR}${PREFIX}/bin/brave
	@${MKDIR} ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKDIR}/brave-browser.desktop ${STAGEDIR}${DESKTOPDIR}

.include <bsd.port.post.mk>
