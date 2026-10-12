PORTNAME=	vivaldi
DISTVERSION=	8.2.4133
CATEGORIES=	www
MASTER_SITES=	https://source.vivaldi.com/ \
		${LINUX_BINS_SITE}:linuxbins
DISTNAME=	${PORTNAME}-source_${DISTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${LINUX_BINS_DIST}:linuxbins

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Vivaldi web browser based on Chromium
WWW=		https://vivaldi.com/

LICENSE=	BSD3CLAUSE LGPL21 MPL11
LICENSE_COMB=	multi
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	the UI is taken from the amd64 Linux package

# The Vivaldi UI (resources/vivaldi) is not part of the source tarball, it is
# only shipped in the official Linux packages (vivapp/ in the source tree has
# just the manifest).  It is taken from the Linux .deb together with the
# product icons and packed into a distfile of its own, the same way the Node
# modules are for www/brave, so that the build needs no network.  The tarball
# has to be regenerated for every version, see gen-linux-bins, and uploaded to
# LINUX_BINS_SITE.  LINUX_DISTVERSION is the full version of the Linux release
# the source tarball belongs to; its last component is passed to the build as
# GLOBAL_BUILDNUM, so that the browser reports the same version as the UI.
LINUX_DISTVERSION=	${DISTVERSION}.84
LINUX_DEB=		${PORTNAME}-stable_${LINUX_DISTVERSION}-1_amd64.deb
LINUX_DEB_SITE?=	https://downloads.vivaldi.com/stable/
LINUX_BINS_DIST=	${PORTNAME}-linux-bins-${LINUX_DISTVERSION}.tar.xz
LINUX_BINS_SITE?=	https://github.com/Martinfx/FreeBSD-Ports/releases/download/${PORTNAME}-${LINUX_DISTVERSION}/
LINUX_BINS_WRKSRC=	${WRKDIR}/${PORTNAME}-linux-bins-${LINUX_DISTVERSION}

# Vivaldi 8.2 is based on Chromium 152.0.7977.  The FreeBSD patches in files/
# are the ones of www/chromium 152.0.7977.75 with the paths moved below
# chromium/, where the Vivaldi source tree keeps Chromium.
WRKSRC=		${WRKDIR}/${PORTNAME}-source
CHROMIUM_WRKSRC=	${WRKSRC}/chromium

USE_GITHUB=	nodefault
GH_TUPLE=	rollup:rollup:v4.60.4:rollup/rollup \
		evanw:esbuild:v${_ESBUILD_VERSION:sh}:esbuild/esbuild

_ESBUILD_VERSION=	${MAKE} -C ${PORTSDIR}/devel/esbuild -V DISTVERSION

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat \
		${LOCALBASE}/include/va/va.h:multimedia/libva \
		${LOCALBASE}/libdata/pkgconfig/dri.pc:graphics/mesa-libs \
		${LOCALBASE}/share/usbids/usb.ids:misc/usbids \
		${PYTHON_PKGNAMEPREFIX}html5lib>0:www/py-html5lib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ply>0:devel/py-ply@${PY_FLAVOR} \
		bash:shells/bash \
		bindgen:devel/rust-bindgen-cli \
		esbuild:devel/esbuild \
		flock:sysutils/flock \
		gperf:devel/gperf \
		nasm:devel/nasm \
		rustc:lang/rust \
		xcb-proto>0:x11/xcb-proto

LIB_DEPENDS=	libatk-bridge-2.0.so:accessibility/at-spi2-core \
		libatspi.so:accessibility/at-spi2-core \
		libcairo.so:graphics/cairo \
		libdav1d.so:multimedia/dav1d \
		libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libdrm.so:graphics/libdrm \
		libepoll-shim.so:devel/libepoll-shim \
		libevent.so:devel/libevent \
		libexif.so:graphics/libexif \
		libexpat.so:textproc/expat2 \
		libffi.so:devel/libffi \
		libFLAC.so:audio/flac \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgcrypt.so:security/libgcrypt \
		libharfbuzz-icu.so:print/harfbuzz-icu \
		libharfbuzz.so:print/harfbuzz \
		libicuuc.so:devel/icu \
		libjsoncpp.so:devel/jsoncpp \
		libnspr4.so:devel/nspr \
		libnss3.so:security/nss \
		libopenh264.so:multimedia/openh264 \
		libopus.so:audio/opus \
		libpci.so:devel/libpci \
		libpng.so:graphics/png \
		libre2.so:devel/re2 \
		libsecret-1.so:security/libsecret \
		libspeechd.so:accessibility/speech-dispatcher \
		libspeex.so:audio/speex \
		libwayland-client.so:graphics/wayland \
		libwebp.so:graphics/webp \
		libxkbcommon.so:x11/libxkbcommon \
		libxshmfence.so:x11/libxshmfence

RUN_DEPENDS=	noto-basic>0:x11-fonts/noto-basic \
		xdg-open:devel/xdg-utils

USES=		bison cargo cmake:indirect compiler:c++20-lang cpe \
		desktop-file-utils gl gmake gnome go:no_targets iconv:wchar_t \
		jpeg localbase:ldflags ninja nodejs:build perl5 pkgconfig \
		python:build shebangfix tar:xz xorg

CARGO_CARGOTOML=	${WRKSRC}/rollup/rust/Cargo.toml
CARGO_CARGOLOCK=	${WRKSRC}/rollup/rust/Cargo.lock
CARGO_TARGET_DIR=	${WRKSRC}/rollup/rust/target
CARGO_INSTALL=		No
CARGO_BUILD=		No
CARGO_TEST=		No
# MAKE_ENV carries DESTDIR=${STAGEDIR}; the cmake install run by the
# libmimalloc-sys2 build script honours it and would drop its OUT_DIR
# (headers, libmimalloc.a, cmake/pkgconfig files) into the stage directory.
CARGO_ENV+=		DESTDIR=

CPE_VENDOR=	vivaldi
CPE_PRODUCT=	vivaldi
USE_GL=		gbm gl
USE_GNOME=	atk dconf gdkpixbuf glib20 gtk30 libxml2 libxslt
USE_LDCONFIG=	${DATADIR}
USE_PERL5=	build
USE_XORG=	x11 xcb xcomposite xcursor xdamage xext xfixes xi xorgproto \
		xrandr xrender xscrnsaver xtst
SHEBANG_FILES=	chromium/chrome/tools/build/linux/chrome-wrapper

# The out directory is in the Vivaldi root, see .gn there.  The vivaldi
# target is a group around //chrome, so the browser is out/Release/chrome.
BUILDTYPE=	Release
MAKE_ARGS=	-C out/${BUILDTYPE}
ALL_TARGET=	vivaldi

BINARY_ALIAS=	python3=${PYTHON_CMD}

# Run "./build/bin/gn args out/${BUILDTYPE} --list" for all variables.
# The first block matches www/chromium.  Vivaldi patches FFmpeg for the
# proprietary codecs and asserts on ffmpeg_branding == "Chrome", so the
# codecs cannot be turned off.  The .gn of Vivaldi defaults to a component
# build, which is not what gets installed.
GN_ARGS+=	clang_use_chrome_plugins=false \
		enable_backup_ref_ptr_support=false \
		enable_hangout_services_extension=true \
		enable_remoting=false \
		enable_widevine=true \
		fatal_linker_warnings=false \
		icu_use_data_file=false \
		is_clang=true \
		optimize_webui=true \
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
		use_sysroot=false \
		use_system_freetype=false \
		use_system_harfbuzz=true \
		use_system_libffi=true \
		use_system_libjpeg=true \
		use_udev=false \
		extra_cxxflags="${CXXFLAGS} -I${LOCALBASE}/include/libepoll-shim" \
		extra_ldflags="${LDFLAGS}" \
		ffmpeg_branding="Chrome" \
		proprietary_codecs=true
GN_ARGS+=	GLOBAL_BUILDNUM="${LINUX_DISTVERSION:E}" \
		blink_symbol_level=0 \
		chrome_pgo_phase=0 \
		enable_precompiled_headers=false \
		is_component_build=false \
		is_debug=false \
		is_official_build=true \
		symbol_level=0 \
		target_cpu="x64" \
		vivaldi_disable_widevine_verification=true

SUB_FILES=	vivaldi vivaldi.desktop
SUB_LIST+=	COMMENT="${COMMENT}"

OPTIONS_DEFINE=		CUPS KERBEROS LTO PIPEWIRE WIDEVINE
OPTIONS_DEFAULT=	ALSA CUPS KERBEROS PIPEWIRE PULSEAUDIO SNDIO
OPTIONS_GROUP=		AUDIO
OPTIONS_GROUP_AUDIO=	ALSA PULSEAUDIO SNDIO
PIPEWIRE_DESC=		Screen capture via PipeWire
WIDEVINE_DESC=		Depend on foreign-cdm to enable playback of DRM content

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_RUN_DEPENDS=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:audio/alsa-plugins
ALSA_VARS=		GN_ARGS+=use_alsa=true
ALSA_VARS_OFF=		GN_ARGS+=use_alsa=false

CUPS_LIB_DEPENDS=	libcups.so:print/cups
CUPS_VARS=		GN_ARGS+=use_cups=true
CUPS_VARS_OFF=		GN_ARGS+=use_cups=false

# SPNEGO and Negotiate authentication.  Chromium loads the GSSAPI library at
# run time, so the one in the base system serves and there is nothing to
# depend on.
KERBEROS_VARS=		GN_ARGS+=use_kerberos=true
KERBEROS_VARS_OFF=	GN_ARGS+=use_kerberos=false

LTO_VARS=		GN_ARGS+=thin_lto_enable_optimizations=true \
			GN_ARGS+=use_thin_lto=true
LTO_VARS_OFF=		GN_ARGS+=use_thin_lto=false

PIPEWIRE_LIB_DEPENDS=	libpipewire-0.3.so:multimedia/pipewire
PIPEWIRE_VARS=		GN_ARGS+=rtc_link_pipewire=true \
			GN_ARGS+=rtc_use_pipewire=true
PIPEWIRE_VARS_OFF=	GN_ARGS+=rtc_link_pipewire=false \
			GN_ARGS+=rtc_use_pipewire=false

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_VARS=	GN_ARGS+=use_pulseaudio=true
PULSEAUDIO_VARS_OFF=	GN_ARGS+=use_pulseaudio=false

SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_VARS=		GN_ARGS+=use_sndio=true
SNDIO_VARS_OFF=		GN_ARGS+=use_sndio=false

WIDEVINE_RUN_DEPENDS=	foreign-cdm>0:www/foreign-cdm

.include "Makefile.crates"

.include <bsd.port.options.mk>
.include <bsd.port.pre.mk>

LLVM_DEFAULT=	22
BUILD_DEPENDS+=	clang${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT}
BINARY_ALIAS+=	ar=${LOCALBASE}/bin/llvm-ar${LLVM_DEFAULT} \
		c++=${LOCALBASE}/bin/clang++${LLVM_DEFAULT} \
		cc=${LOCALBASE}/bin/clang${LLVM_DEFAULT} \
		cpp=${LOCALBASE}/bin/clang-cpp${LLVM_DEFAULT} \
		ld=${LOCALBASE}/bin/ld.lld${LLVM_DEFAULT} \
		nm=${LOCALBASE}/bin/llvm-nm${LLVM_DEFAULT}

FFMPEG_TARGET=	x64
FFMPEG_BDIR=	${CHROMIUM_WRKSRC}/third_party/ffmpeg/build.${FFMPEG_TARGET}.freebsd/Chrome
FFMPEG_CDIR=	${CHROMIUM_WRKSRC}/third_party/ffmpeg/chromium/config/Chrome/freebsd/${FFMPEG_TARGET}

_ROLLUP_FREEBSD=	${CHROMIUM_WRKSRC}/third_party/devtools-frontend/src/node_modules/@rollup/rollup-freebsd

# scripts/rungn.py builds gn from thirdparty/gn and keeps it here.
GN=		${WRKSRC}/build/bin/gn

# The work directory may be inside a git checkout (of the ports tree), which
# the version scripts of the build must not take for the Chromium one.
MAKE_ENV+=	C_INCLUDE_PATH=${LOCALBASE}/include \
		CPLUS_INCLUDE_PATH=${LOCALBASE}/include \
		GIT_CEILING_DIRECTORIES=${WRKDIR} \
		GOCACHE=${WRKDIR}/go-cache \
		RUSTC_BOOTSTRAP=1
CONFIGURE_ENV+=	${MAKE_ENV}

GN_ARGS+=	enable_rust=true \
		rust_sysroot_absolute="${LOCALBASE}"

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "To build ${PORTNAME}, you should have at least:"
	@${ECHO_MSG} "- 16 GB of memory"
	@${ECHO_MSG} "- 60 GB of free disk space"
	@${ECHO_MSG} "- 1.5 million free inodes"
	@${ECHO_MSG}

pre-configure:
	cd ${CHROMIUM_WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${PYTHON_CMD} \
		./build/linux/unbundle/replace_gn_files.py --system-libraries \
		dav1d flac fontconfig harfbuzz libdrm libpng \
		libusb libwebp libxml libxslt openh264 opus || ${FALSE}
# Chromium ships an unreleased FFmpeg, so its config has to be generated
	cd ${CHROMIUM_WRKSRC}/media/ffmpeg && \
		${PYTHON_CMD} scripts/build_ffmpeg.py freebsd ${FFMPEG_TARGET} \
		--config-only --branding=Chrome
	cd ${FFMPEG_BDIR} && ${GMAKE} ffversion.h
	${MKDIR} ${FFMPEG_CDIR}
.for _e in config.h config.asm config_components.asm config_components.h \
	libavcodec libavformat libavutil
	-${CP} -pR ${FFMPEG_BDIR}/${_e} ${FFMPEG_CDIR}
.endfor
	@${REINPLACE_CMD} -e 's|$${LOCALBASE}|${LOCALBASE}|;s|$${MODCLANG_VERSION}|${LLVM_DEFAULT}|' \
		${CHROMIUM_WRKSRC}/build/linux/strip_binary.gni \
		${CHROMIUM_WRKSRC}/build/rust/rust_bindgen.gni \
		${CHROMIUM_WRKSRC}/build/rust/rust_bindgen_generator.gni

pre-build:
# The rollup plugin devtools-frontend loads is a native node module
	@${CARGO_CARGO_RUN} build --manifest-path ${CARGO_CARGOTOML} \
		${CARGO_BUILD_ARGS}
	@${MKDIR} ${_ROLLUP_FREEBSD}
	${CP} ${CARGO_TARGET_DIR}/release/libbindings_napi.so \
		${_ROLLUP_FREEBSD}/rollup.freebsd.node
	${ECHO_CMD} '{ "main": "./rollup.freebsd.node" }' \
		> ${_ROLLUP_FREEBSD}/package.json

do-configure:
	(cd ${WRKSRC}/esbuild && \
		${LOCALBASE}/bin/node scripts/esbuild.js \
		${LOCALBASE}/bin/esbuild --neutral && \
		${RM} -r ${CHROMIUM_WRKSRC}/third_party/devtools-frontend/src/node_modules/esbuild && \
		${LN} -sf ${WRKSRC}/esbuild/npm/esbuild \
		${CHROMIUM_WRKSRC}/third_party/devtools-frontend/src/node_modules/esbuild)
# The Vivaldi tarball has no devtools-frontend/src/third_party/esbuild at all
	@${MKDIR} ${CHROMIUM_WRKSRC}/third_party/devtools-frontend/src/third_party/esbuild
	${LN} -sf ${LOCALBASE}/bin/esbuild \
		${CHROMIUM_WRKSRC}/third_party/devtools-frontend/src/third_party/esbuild/esbuild

# Dependencies Chromium normally expects below third_party/
	@${MKDIR} ${CHROMIUM_WRKSRC}/third_party/node/freebsd/node-freebsd/bin
	${LN} -sf ${LOCALBASE}/bin/node \
		${CHROMIUM_WRKSRC}/third_party/node/freebsd/node-freebsd/bin/node
	@${MKDIR} ${CHROMIUM_WRKSRC}/third_party/rust-toolchain/bin
	${LN} -sf ${LOCALBASE}/bin/rustc \
		${CHROMIUM_WRKSRC}/third_party/rust-toolchain/bin/rustc
	@${MKDIR} ${CHROMIUM_WRKSRC}/third_party/gperf/cipd/bin
	${LN} -sf ${LOCALBASE}/bin/gperf \
		${CHROMIUM_WRKSRC}/third_party/gperf/cipd/bin/gperf

# gclient writes gclient_args.gni from DEPS, but the Vivaldi tarball comes
# without it.  generate_location_tags is off as in Vivaldi's own builds.
	${PYTHON_CMD} ${FILESDIR}/gclient_args.py ${CHROMIUM_WRKSRC}/DEPS \
		${CHROMIUM_WRKSRC}/build/config/gclient_args.gni \
		generate_location_tags=false
	@${CAT} ${CHROMIUM_WRKSRC}/build/config/gclient_args.gni

# The lastchange hooks of gclient write LASTCHANGE and the GPU lists, Skia
# and Dawn versions from git; the tarball has none of them.
	${PYTHON_CMD} ${FILESDIR}/lastchange_files.py ${CHROMIUM_WRKSRC}
	@${CAT} ${CHROMIUM_WRKSRC}/build/util/LASTCHANGE

# rungn.py bootstraps gn from thirdparty/gn (into ${GN}) and generates the
# ninja files.
	@${MKDIR} ${CHROMIUM_WRKSRC}/buildtools/freebsd
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} CC=${CC} CXX=${CXX} \
		LD=${CXX} AR=${AR} ${PYTHON_CMD} ./scripts/rungn.py \
		gen --args='${GN_ARGS}' out/${BUILDTYPE}
	${LN} -sf ${CHROMIUM_WRKSRC}/buildtools/linux64/clang-format \
		${CHROMIUM_WRKSRC}/buildtools/freebsd
	${LN} -sf ${GN} ${CHROMIUM_WRKSRC}/buildtools/freebsd
	${LN} -sf /usr/bin/strip ${CHROMIUM_WRKSRC}/buildtools/freebsd/strip

# Builds the LINUX_BINS_DIST distfile from the official Linux package.  Only
# the UI and the product icons are taken, the Linux executables and libraries
# are of no use here.  Upload ${WRKDIR}/${LINUX_BINS_DIST} to LINUX_BINS_SITE
# and run "make makesum".
gen-linux-bins:
	@${RM} -r ${WRKDIR}/linux-deb ${LINUX_BINS_WRKSRC}
	@${MKDIR} ${WRKDIR}/linux-deb ${LINUX_BINS_WRKSRC}/resources
	@${ECHO_MSG} "===>  Fetching ${LINUX_DEB}"
	@cd ${WRKDIR}/linux-deb && \
		${FETCH_BINARY} ${FETCH_ARGS} -o ${LINUX_DEB} ${LINUX_DEB_SITE}${LINUX_DEB}
	@${ECHO_MSG} "===>  Extracting the UI from ${LINUX_DEB}"
	@cd ${WRKDIR}/linux-deb && ${TAR} -xf ${LINUX_DEB} && \
		${MKDIR} data && ${TAR} -xf data.tar.* -C data
	@if [ ! -d ${WRKDIR}/linux-deb/data/opt/vivaldi/resources/vivaldi ]; then \
		${ECHO_MSG} "===>  No opt/vivaldi/resources/vivaldi in ${LINUX_DEB}"; \
		${FALSE}; \
	fi
	@${MV} ${WRKDIR}/linux-deb/data/opt/vivaldi/resources/vivaldi \
		${LINUX_BINS_WRKSRC}/resources/
	@${MV} ${WRKDIR}/linux-deb/data/opt/vivaldi/product_logo_*.png \
		${LINUX_BINS_WRKSRC}/
	@${ECHO_MSG} "===>  Packing ${LINUX_BINS_DIST}"
	@cd ${WRKDIR} && ${TAR} -c -J -f ${WRKDIR}/${LINUX_BINS_DIST} \
		${LINUX_BINS_WRKSRC:T}
	@${RM} -r ${WRKDIR}/linux-deb
	@${ECHO_MSG} "===>  ${WRKDIR}/${LINUX_BINS_DIST}"

# The UI from the Linux package goes next to the browser, as on Linux, so that
# running it from the build directory works as well.
post-build:
	@${MKDIR} ${WRKSRC}/out/${BUILDTYPE}/resources
	@${RM} -r ${WRKSRC}/out/${BUILDTYPE}/resources/vivaldi
	cd ${LINUX_BINS_WRKSRC}/resources && \
		${COPYTREE_SHARE} vivaldi ${WRKSRC}/out/${BUILDTYPE}/resources

# Laid out like /opt/vivaldi of the Linux package: the browser is vivaldi-bin
# and the UI is in resources/vivaldi next to it (copied there by post-build).
do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/out/${BUILDTYPE}/chrome \
		${STAGEDIR}${DATADIR}/vivaldi-bin
	${INSTALL_DATA} ${WRKSRC}/out/${BUILDTYPE}/*.pak ${STAGEDIR}${DATADIR}
.for f in snapshot_blob.bin v8_context_snapshot.bin
	${INSTALL_DATA} ${WRKSRC}/out/${BUILDTYPE}/${f} ${STAGEDIR}${DATADIR}
.endfor
	cd ${WRKSRC}/out/${BUILDTYPE} && \
		${COPYTREE_SHARE} "locales resources" ${STAGEDIR}${DATADIR}
# ANGLE, EGL, Vk, SwiftShader and the FFmpeg that Vivaldi builds as a
# component on Linux
.for f in libEGL.so libGLESv2.so libVkICD_mock_icd.so libvk_swiftshader.so
	${INSTALL_LIB} ${WRKSRC}/out/${BUILDTYPE}/${f} ${STAGEDIR}${DATADIR}
.endfor
	${INSTALL_LIB} ${WRKSRC}/out/${BUILDTYPE}/libvulkan.so.1 \
		${STAGEDIR}${DATADIR}/libvulkan.so
	${INSTALL_DATA} ${WRKSRC}/out/${BUILDTYPE}/vk_swiftshader_icd.json \
		${STAGEDIR}${DATADIR}
	if [ -f ${WRKSRC}/out/${BUILDTYPE}/libffmpeg.so ]; then \
		${INSTALL_LIB} ${WRKSRC}/out/${BUILDTYPE}/libffmpeg.so \
			${STAGEDIR}${DATADIR}; \
	fi
	${INSTALL_SCRIPT} ${CHROMIUM_WRKSRC}/chrome/tools/build/linux/chrome-wrapper \
		${STAGEDIR}${DATADIR}
.for s in 16 24 32 48 64 128 256
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps
	${INSTALL_DATA} ${LINUX_BINS_WRKSRC}/product_logo_${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps/vivaldi.png
.endfor
	${INSTALL_SCRIPT} ${WRKDIR}/vivaldi ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKDIR}/vivaldi.desktop ${STAGEDIR}${DESKTOPDIR}

.include <bsd.port.post.mk>
