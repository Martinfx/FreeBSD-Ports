PORTNAME=	brave
DISTVERSIONPREFIX=	v
DISTVERSION=	1.94.120
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
# "config.projects.chrome.tag" in src/brave/package.json.  Brave 1.94.120 is
# the release that comes closest to the Chromium in www/chromium (152.0.7977.75
# there, .76 here), so that port's FreeBSD patches apply to this tree as well.
CHROME_VERSION=	152.0.7977.76

# The FreeBSD patches for the Chromium tree in files/ are the ones from
# www/chromium 152.0.7977.75, rewritten for the src/ prefix this port unpacks
# Chromium into.
#
# This port builds natively: depot_tools, gclient, cipd, siso and reclient are
# not used at all.  Everything is taken from the official Chromium release
# tarball (which, unlike a git checkout, already contains all DEPS-managed
# third-party code), from brave-core and from the ports tree.  The parts that
# gclient would normally fetch for brave-core are listed in GH_TUPLE below and
# match the "deps" section of src/brave/DEPS.

USE_GITHUB=	yes
GH_ACCOUNT=	brave
GH_PROJECT=	brave-browser
GH_TUPLE=	brave:brave-core:v${DISTVERSION}:core/src/brave \
		brave-intl:bat-native-tweetnacl:8b424ccf29957fe01c88c36076fd32006a357887:tweetnacl/src/brave/vendor/bat-native-tweetnacl \
		brave:gn-project-generators:b76e14b162aa0ce40f11920ec94bfc12da29e5d0:gnprojgen/src/brave/vendor/gn-project-generators \
		brave:web-discovery-project:ae82a1b7510f4035d13df47b87a1a7fe5b6471ac:wdp/src/brave/vendor/web-discovery-project \
		brave-intl:bat-native-bip39wally-core:547a7810333d821e29b8f55126aba031aa0d5fcd:bip39wally/src/brave/third_party/bip39wally-core-native \
		chfast:ethash:e4a15c3d76dc09392c7efd3e30d84ee3b871e9ce:ethash/src/brave/third_party/ethash/src \
		bitcoin:bitcoin:8105bce5b384c72cf08b25b7c5343622754e7337:bitcoincore/src/brave/third_party/bitcoin-core/src \
		P-H-C:phc-winner-argon2:62358ba2123abd17fccf2a108a301d4b52c01a7c:argon2/src/brave/third_party/argon2/src \
		brave:playlist-component:673d40f017a1559bb685a15cf608ad1d4a94f8fb:playlist/src/brave/third_party/playlist_component/src \
		brave-intl:futures-retry:2aaaafbc3d394661534d4dbd14159d164243c20e:futuresretry/src/brave/third_party/rust/futures_retry/v0_5/crate \
		brave:librustzcash:f01f50d64214278552edbe4a34b9049244ce03c1:librustzcash/src/brave/components/brave_wallet/browser/zcash/rust/librustzcash/src \
		rollup:rollup:v4.60.4:rollup/src/rollup \
		evanw:esbuild:v${_ESBUILD_VERSION:sh}:esbuild/src/esbuild

# Chromium builds devtools-frontend with rollup and esbuild.  Neither ships a
# FreeBSD binary, so the rollup native binding is built from source (like
# www/chromium does, hence the shared Makefile.crates) and esbuild is taken
# from ports.
_ESBUILD_VERSION=	${MAKE} -C ${PORTSDIR}/devel/esbuild -V DISTVERSION

BUILD_DEPENDS=	bash:shells/bash \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ply>0:devel/py-ply@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}html5lib>0:www/py-html5lib@${PY_FLAVOR} \
		bindgen:devel/rust-bindgen-cli \
		esbuild:devel/esbuild \
		gperf:devel/gperf \
		flock:sysutils/flock \
		corepack>0:www/corepack \
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

USES=		bison cargo compiler:c++20-lang cpe desktop-file-utils gl gmake \
		gnome go:no_targets iconv:wchar_t jpeg localbase:ldflags ninja \
		nodejs:24,build perl5 pkgconfig python:build shebangfix tar:xz \
		xorg

CARGO_CARGOTOML=	${WRKSRC}/src/rollup/rust/Cargo.toml
CARGO_CARGOLOCK=	${WRKSRC}/src/rollup/rust/Cargo.lock
CARGO_TARGET_DIR=	${WRKSRC}/src/rollup/rust/target
CARGO_INSTALL=		No
CARGO_BUILD=		No
CARGO_TEST=		No

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

# Brave overrides Chromium sources through chromium_src/, which only works when
# the compiler is invoked through redirect_cc as a cc_wrapper.  Without siso
# (which is fetched with CIPD and does not exist for FreeBSD) redirect_cc has to
# be built first, into its own output directory.
REDIRECT_CC_DIR=	${BUILD_WRKSRC}/out/redirect_cc

# Arguments that describe the platform and the toolchain.  Both output
# directories need them: without them the small redirect_cc build falls back to
# the Chromium defaults and pulls in things FreeBSD cannot build, such as the
# allocator shim, whose malloc overrides clash with the declarations in libc.
GN_BASE_ARGS=	target_os="freebsd" \
		target_cpu="${GN_CPU}" \
		clang_use_chrome_plugins=false \
		enable_backup_ref_ptr_support=false \
		enable_rust=true \
		fatal_linker_warnings=false \
		is_clang=true \
		rust_sysroot_absolute="${LOCALBASE}" \
		treat_warnings_as_errors=false \
		use_allocator_shim=false \
		use_custom_libcxx=true \
		use_custom_libunwind=true \
		use_lld=true \
		use_partition_alloc=true \
		use_partition_alloc_as_malloc=false \
		use_reclient=false \
		use_remoteexec=false \
		use_siso=false \
		use_sysroot=false \
		use_udev=false \
		extra_cxxflags="${CXXFLAGS} -I${LOCALBASE}/include/libepoll-shim" \
		extra_ldflags="${LDFLAGS}"

GN_ARGS+=	${GN_BASE_ARGS} \
		import("//brave/build/args/brave_defaults.gni") \
		import("//brave/build/args/blink_platform_defaults.gni") \
		import("//brave/build/args/desktop_defaults.gni") \
		brave_channel="" \
		cc_wrapper="${REDIRECT_CC_DIR}/redirect_cc" \
		chrome_pgo_phase=0 \
		enable_cdm_host_verification=false \
		enable_hangout_services_extension=false \
		enable_remoting=false \
		enable_updater=false \
		enable_update_notifications=false \
		enable_web_discovery=false \
		enable_web_discovery_native=false \
		enable_widevine=false \
		icu_use_data_file=true \
		is_component_build=false \
		is_official_build=false \
		optimize_webui=true \
		skip_signing=true \
		toolkit_views=true \
		use_aura=true \
		use_qt5=false \
		use_qt6=false \
		use_system_freetype=false \
		use_system_harfbuzz=true \
		use_system_libffi=true \
		use_system_libjpeg=true \
		ffmpeg_branding="${FFMPEG_BRAND}"

# redirect_cc is a small host tool, it must not be wrapped by itself.  Its
# rewrapper_buildflags target bakes the path in unconditionally, so it needs a
# non-empty real_rewrapper even with RBE off, exactly like Brave's own build
# driver passes it.
GN_REDIRECT_CC_ARGS=	import("//brave/tools/redirect_cc/args.gni") \
			real_rewrapper="${BUILD_WRKSRC}/buildtools/reclient/rewrapper" \
			${GN_BASE_ARGS}

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

.include "Makefile.crates"

.include <bsd.port.options.mk>
.include <bsd.port.pre.mk>

LLVM_DEFAULT=	22
BUILD_DEPENDS+=	clang${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT}
BINARY_ALIAS+=	cpp=${LOCALBASE}/bin/clang-cpp${LLVM_DEFAULT} \
		cc=${LOCALBASE}/bin/clang${LLVM_DEFAULT} \
		c++=${LOCALBASE}/bin/clang++${LLVM_DEFAULT} \
		ar=${LOCALBASE}/bin/llvm-ar${LLVM_DEFAULT} \
		nm=${LOCALBASE}/bin/llvm-nm${LLVM_DEFAULT} \
		ld=${LOCALBASE}/bin/ld.lld${LLVM_DEFAULT}

.if ${ARCH} == aarch64
GN_CPU=		arm64
RUST_ABI_TARGET=aarch64-unknown-freebsd
FFMPEG_TARGET=	arm64
# swiftshader/lib/{libEGL.so,libGLESv2.so} is x86 only
PLIST_SUB+=	NOT_AARCH64="@comment "
.else
BUILD_DEPENDS+=	nasm:devel/nasm
GN_CPU=		x64
RUST_ABI_TARGET=x86_64-unknown-freebsd
FFMPEG_TARGET=	x64
PLIST_SUB+=	NOT_AARCH64=""
.endif

FFMPEG_BDIR=	${BUILD_WRKSRC}/third_party/ffmpeg/build.${FFMPEG_TARGET}.freebsd/${FFMPEG_BRAND}
FFMPEG_CDIR=	${BUILD_WRKSRC}/third_party/ffmpeg/chromium/config/${FFMPEG_BRAND}/freebsd/${FFMPEG_TARGET}

MAKE_ENV+=	C_INCLUDE_PATH=${LOCALBASE}/include \
		CPLUS_INCLUDE_PATH=${LOCALBASE}/include \
		GOCACHE=${WRKDIR}/go-cache \
		RUSTC_BOOTSTRAP=1
CONFIGURE_ENV+=	${MAKE_ENV}

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

# brave-core carries its own patches for the Chromium tree and they are written
# against pristine Chromium, so they have to go in before the FreeBSD patches
# in files/, which the regular patch phase applies right after this target.
# The layout below patches/ mirrors the Chromium tree.
#
# Roughly fifty of them are for Android and iOS files that the -lite tarball
# does not ship.  None of brave-core's patches creates a file, so a patch whose
# target is missing is one for a platform this port does not build, and it is
# skipped; everything else has to apply.
pre-patch:
	@${ECHO_MSG} "===>  Applying brave-core patches to the Chromium tree"
	@cd ${WRKSRC}/src/brave/patches && ${FIND} . -name '*.patch' | sort | \
	while read _p; do \
		_d=$$(dirname "$${_p}"); \
		_f=$$(${AWK} '/^\+\+\+ b\//{sub(/^\+\+\+ b\//, ""); \
		    sub(/\t.*/, ""); print; exit}' "$${_p}"); \
		[ -f "${WRKSRC}/src/$${_d}/$${_f}" ] || continue; \
		${PATCH} -s -t -d ${WRKSRC}/src/$${_d} -p1 \
		    -i ${WRKSRC}/src/brave/patches/$${_p} || exit 1; \
	done

pre-configure:
	# Chromium picks the Rust standard library out of the sysroot by crate
	# name, and where a crate is present more than once it takes whichever
	# sorts first.  Two toolchains installed side by side therefore end up
	# mixing rlibs from different builds, and since Rust puts a per-build hash
	# into every symbol name, the link fails much later on undefined core
	# symbols.  Say so now instead.
	@_dup=$$(${LS} ${LOCALBASE}/lib/rustlib/${RUST_ABI_TARGET}/lib/*.rlib \
	    2>/dev/null | ${SED} -e 's|.*/lib||' -e 's|-[0-9a-f]*\.rlib$$||' \
	    | ${SORT} | uniq -d | ${TR} '\n' ' '); \
	if [ -n "$${_dup}" ]; then \
		${ECHO_MSG} "===>  More than one rlib per crate in ${LOCALBASE}/lib/rustlib/${RUST_ABI_TARGET}/lib:"; \
		${ECHO_MSG} "      $${_dup}"; \
		${ECHO_MSG} "      Usually these are leftovers from an earlier Rust,"; \
		${ECHO_MSG} "      owned by no package.  Compare the directory against"; \
		${ECHO_MSG} "      pkg info -ql rust and delete what is not listed."; \
		${FALSE}; \
	fi
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
	# Brave keeps the upstream Chromium version in a sidecar and writes its own
	# version into chrome/VERSION; //brave/build/version.gni is generated from
	# the two and imported all over the Brave build files.  Upstream does this
	# from git in a gclient hook, which a ports build has neither of.
	${CP} ${BUILD_WRKSRC}/chrome/VERSION ${BUILD_WRKSRC}/chrome/VERSION.chromium
	@${REINPLACE_CMD} -e 's|^MINOR=.*|MINOR=${BRAVE_VERSION_MAJOR}|' \
		-e 's|^BUILD=.*|BUILD=${BRAVE_VERSION_MINOR}|' \
		-e 's|^PATCH=.*|PATCH=${BRAVE_VERSION_BUILD}|' \
		${BUILD_WRKSRC}/chrome/VERSION
	cd ${WRKSRC}/src/brave && ${SETENV} ${CONFIGURE_ENV} ${PYTHON_CMD} \
		build/util/version.py gen ../chrome/VERSION
	# The webpack based parts of the Brave UI are built out of node_modules;
	# brave-core is a pnpm workspace, which corepack provides.  This is the
	# only step that still wants network access, so it is skipped when the
	# modules have been staged into the work directory beforehand.
	@if [ ! -d ${WRKSRC}/src/brave/node_modules ]; then \
		cd ${WRKSRC}/src/brave && ${SETENV} ${CONFIGURE_ENV} \
		    ${LOCALBASE}/bin/corepack pnpm install --frozen-lockfile \
		    --ignore-scripts; \
	fi

pre-build:
	# The rollup plugin devtools-frontend loads is a native node module
	@${CARGO_CARGO_RUN} build --manifest-path ${CARGO_CARGOTOML} \
		${CARGO_BUILD_ARGS}
	(cd ${BUILD_WRKSRC}/third_party/devtools-frontend/src/node_modules/@rollup && \
		${MKDIR} rollup-freebsd && \
		${CP} ${CARGO_TARGET_DIR}/release/libbindings_napi.so \
			rollup-freebsd/rollup.freebsd.node && \
		${ECHO_CMD} '{ "main": "./rollup.freebsd.node" }' \
			> rollup-freebsd/package.json)

do-configure:
	(cd ${WRKSRC}/src/esbuild && \
		${LOCALBASE}/bin/node scripts/esbuild.js \
		${LOCALBASE}/bin/esbuild --neutral && \
		${RM} -r ${BUILD_WRKSRC}/third_party/devtools-frontend/src/node_modules/esbuild && \
		${LN} -sf ${WRKSRC}/src/esbuild/npm/esbuild \
		${BUILD_WRKSRC}/third_party/devtools-frontend/src/node_modules/esbuild)
	${LN} -sf ${LOCALBASE}/bin/esbuild \
		${BUILD_WRKSRC}/third_party/devtools-frontend/src/third_party/esbuild/esbuild

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
	${INSTALL_DATA} ${BUILD_WRKSRC}/out/${BUILDTYPE}/icudtl.dat ${STAGEDIR}${DATADIR}
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
