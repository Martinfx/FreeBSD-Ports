PORTNAME=	concat
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.7
CATEGORIES=	multimedia
MASTER_SITES=	https://gitlab.com/libeigen/eigen/-/archive/${EIGEN_VERSION}/:eigen
DISTFILES=	eigen-${EIGEN_VERSION}.tar.gz:eigen

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Video editor with auto-captions, text to speech and cutouts
WWW=		https://concatenate.pages.dev/ \
		https://github.com/jub0t/Concat

LICENSE=	AGPLv3+
LICENSE_FILE=	${WRKSRC}/../LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	upstream supports only 64-bit x86 and ARM; needs misc/onnxruntime and Skia

BUILD_DEPENDS=	gn:devel/gn
LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libavcodec.so:multimedia/ffmpeg \
		libexpat.so:textproc/expat2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libonnxruntime.so:misc/onnxruntime \
		libpng16.so:graphics/png
# winit, wgpu, glutin, softbuffer, x11rb and xkbcommon-dl dlopen() the
# display, input and graphics libraries at run time, nothing links
# against them.  File dialogs go through the XDG desktop portal (rfd's
# xdg-portal backend).
RUN_DEPENDS=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:audio/alsa-plugins \
		${LOCALBASE}/lib/libEGL.so:graphics/libglvnd \
		${LOCALBASE}/lib/libvulkan.so:graphics/vulkan-loader \
		${LOCALBASE}/lib/libwayland-client.so:graphics/wayland \
		${LOCALBASE}/lib/libX11.so:x11/libX11 \
		${LOCALBASE}/lib/libXcursor.so:x11/libXcursor \
		${LOCALBASE}/lib/libXi.so:x11/libXi \
		${LOCALBASE}/lib/libxcb.so:x11/libxcb \
		${LOCALBASE}/lib/libxkbcommon.so:x11/libxkbcommon \
		xdg-desktop-portal-gtk>0:x11/xdg-desktop-portal-gtk \
		xdg-open:devel/xdg-utils

USES=		cargo compiler:c++20-lang desktop-file-utils jpeg \
		llvm:build,noexport localbase:ldflags ninja:build pkgconfig \
		python:build ssl
USE_GITHUB=	yes
GH_ACCOUNT=	jub0t
GH_PROJECT=	Concat
# Skia at the revision the skia-bindings crate wants
# (package.metadata.skia in its Cargo.toml), with the one dependency
# Skia's DEPS lists that is not taken from the system for this build:
# the Vulkan Memory Allocator.  Then sherpa-onnx (text to speech) and
# the sources its CMake build would otherwise download, at the versions
# its cmake/*.cmake files name.
GH_TUPLE=	rust-skia:skia:m153-0.101.2:skia \
		GPUOpen-LibrariesAndSDKs:VulkanMemoryAllocator:eb744ea7a2b17040121b4bbb4d6f9e8a77e3cae7:vma \
		k2-fsa:sherpa-onnx:v1.13.7:sherpa \
		csukuangfj:espeak-ng:ed530aa113046142eb5115cf2fc9157854d0ffe1:espeak \
		csukuangfj:hclust-cpp:2026-02-25:hclust \
		csukuangfj:kaldi-native-fbank:v1.22.3:kfbank \
		csukuangfj:openfst:v1.8.5-2026-07-09:openfst \
		csukuangfj:piper-phonemize:f3ff95afc03640bc1399e113e83361192a2fafb4:piper \
		k2-fsa:kaldi-decoder:v0.3.0:kdecoder \
		k2-fsa:kaldifst:v1.8.0:kaldifst \
		mborgerding:kissfft:febd4caeed32e33ad8b2e0bb5ea77542c40f18ec:kissfft \
		nlohmann:json:v3.12.0:json \
		pkufool:simple-sentencepiece:v0.7:ssp

WRKSRC_SUBDIR=	src

CARGO_CRATES=	ab_glyph-0.2.32 \
		ab_glyph_rasterizer-0.1.10 \
		accesskit-0.24.1 \
		accesskit_atspi_common-0.19.1 \
		accesskit_consumer-0.38.0 \
		accesskit_ios-0.1.2 \
		accesskit_macos-0.26.3 \
		accesskit_unix-0.22.1 \
		accesskit_windows-0.34.0 \
		accesskit_winit-0.33.2 \
		adler2-2.0.1 \
		aes-0.8.4 \
		ahash-0.8.12 \
		aho-corasick-1.1.5 \
		allocator-api2-0.2.21 \
		alsa-0.9.1 \
		alsa-sys-0.3.1 \
		android-activity-0.5.2 \
		android-activity-0.6.1 \
		android-build-0.1.4 \
		android-properties-0.2.2 \
		android_log-sys-0.3.2 \
		android_logger-0.15.1 \
		android_system_properties-0.1.6 \
		annotate-snippets-0.12.16 \
		anstream-1.0.0 \
		anstyle-1.0.14 \
		anstyle-parse-1.0.0 \
		anstyle-query-1.1.5 \
		anstyle-wincon-3.0.11 \
		anyhow-1.0.104 \
		arbitrary-1.4.2 \
		arboard-3.6.1 \
		arrayref-0.3.9 \
		arrayvec-0.7.8 \
		as-raw-xcb-connection-1.0.1 \
		ash-0.38.0+1.3.281 \
		async-broadcast-0.7.2 \
		async-channel-2.5.0 \
		async-executor-1.14.0 \
		async-io-2.6.0 \
		async-lock-3.4.2 \
		async-process-2.5.0 \
		async-recursion-1.1.1 \
		async-signal-0.2.14 \
		async-task-4.7.1 \
		async-trait-0.1.92 \
		atomic-waker-1.1.2 \
		atspi-0.29.0 \
		atspi-common-0.13.0 \
		atspi-proxies-0.13.0 \
		autocfg-1.5.1 \
		axum-0.8.9 \
		axum-core-0.5.6 \
		base64-0.13.1 \
		base64-0.22.1 \
		base64-0.23.1 \
		base64ct-1.8.3 \
		beef-0.5.2 \
		bincode-2.0.1 \
		bindgen-0.72.1 \
		bit-set-0.8.0 \
		bit-set-0.10.0 \
		bit-vec-0.8.0 \
		bit-vec-0.9.1 \
		bitflags-1.3.2 \
		bitflags-2.13.1 \
		block-buffer-0.10.4 \
		block2-0.5.1 \
		block2-0.6.2 \
		blocking-1.7.0 \
		borsh-1.8.1 \
		bstr-1.13.1 \
		bumpalo-3.20.3 \
		by_address-1.2.1 \
		bytemuck-1.25.2 \
		bytemuck_derive-1.12.0 \
		byteorder-1.5.0 \
		byteorder-lite-0.1.0 \
		bytes-1.12.1 \
		bzip2-0.4.4 \
		bzip2-0.5.2 \
		bzip2-0.6.1 \
		bzip2-sys-0.1.13+1.0.8 \
		calloop-0.13.0 \
		calloop-0.14.4 \
		calloop-wayland-source-0.3.0 \
		castaway-0.2.4 \
		cc-1.4.4 \
		cesu8-1.1.0 \
		cexpr-0.6.0 \
		cfg-if-1.0.4 \
		cfg_aliases-0.2.2 \
		cgl-0.3.2 \
		chrono-0.4.45 \
		cipher-0.4.4 \
		clang-2.1.0 \
		clang-sys-1.9.1 \
		clap-4.6.6 \
		clap_builder-4.6.6 \
		clap_derive-4.6.4 \
		clap_lex-1.1.0 \
		clipboard-win-5.4.1 \
		clru-0.6.3 \
		cmake-0.1.58 \
		codespan-reporting-0.13.1 \
		color_quant-1.1.0 \
		colorchoice-1.0.5 \
		combine-4.6.8 \
		compact_str-0.9.1 \
		concurrent-queue-2.5.0 \
		const-field-offset-0.2.1 \
		const-field-offset-macro-0.2.1 \
		constant_time_eq-0.3.1 \
		convert_case-0.10.0 \
		core-foundation-0.9.4 \
		core-foundation-0.10.1 \
		core-foundation-sys-0.8.7 \
		core-graphics-0.23.2 \
		core-graphics-types-0.1.3 \
		core_maths-0.1.1 \
		coreaudio-rs-0.13.0 \
		countme-3.0.1 \
		cpal-0.16.0 \
		cpufeatures-0.2.17 \
		crc-3.4.0 \
		crc-catalog-2.5.0 \
		crc32fast-1.5.1 \
		critical-section-1.2.0 \
		crossbeam-channel-0.5.16 \
		crossbeam-deque-0.8.7 \
		crossbeam-epoch-0.9.20 \
		crossbeam-utils-0.8.22 \
		crunchy-0.2.4 \
		crypto-common-0.1.7 \
		ctor-0.10.1 \
		cursor-icon-1.2.0 \
		daachorse-3.0.3 \
		darling-0.20.11 \
		darling_core-0.20.11 \
		darling_macro-0.20.11 \
		dary_heap-0.3.9 \
		dasp_sample-0.11.0 \
		data-url-0.3.2 \
		deflate64-0.1.12 \
		der-0.8.2 \
		deranged-0.5.8 \
		derive_arbitrary-1.4.2 \
		derive_builder-0.20.2 \
		derive_builder_core-0.20.2 \
		derive_builder_macro-0.20.2 \
		derive_more-2.1.1 \
		derive_more-impl-2.1.1 \
		digest-0.10.7 \
		dirs-6.0.0 \
		dirs-sys-0.5.0 \
		dispatch-0.2.0 \
		dispatch2-0.3.1 \
		displaydoc-0.2.7 \
		dlib-0.5.3 \
		document-features-0.2.12 \
		downcast-rs-1.2.1 \
		dpi-0.1.2 \
		drm-0.14.1 \
		drm-0.15.0 \
		drm-ffi-0.9.1 \
		drm-fourcc-2.2.0 \
		drm-sys-0.8.1 \
		dtor-0.8.1 \
		either-1.18.0 \
		endi-1.1.1 \
		enumflags2-0.7.12 \
		enumflags2_derive-0.7.12 \
		env_filter-0.1.4 \
		equivalent-1.0.2 \
		errno-0.3.14 \
		error-code-3.4.0 \
		esaxx-rs-0.1.10 \
		euclid-0.22.14 \
		event-listener-5.4.2 \
		event-listener-strategy-0.5.4 \
		fancy-regex-0.17.0 \
		fastrand-2.5.0 \
		fdeflate-0.3.7 \
		femtovg-0.27.0 \
		ffmpeg-sys-the-third-6.0.0+ffmpeg-9.0 \
		ffmpeg-the-third-6.0.0+ffmpeg-9.0 \
		field-offset-0.3.6 \
		filetime-0.2.29 \
		find-msvc-tools-0.1.11 \
		fixed_decimal-0.7.2 \
		fixedbitset-0.5.7 \
		flate2-1.1.10 \
		float-cmp-0.9.0 \
		fnv-1.0.7 \
		foldhash-0.1.5 \
		foldhash-0.2.0 \
		font-types-0.12.4 \
		fontconfig-parser-0.5.8 \
		fontdb-0.23.0 \
		fontdb-0.24.0 \
		fontique-0.11.1 \
		foreign-types-0.3.2 \
		foreign-types-0.5.0 \
		foreign-types-macros-0.2.4 \
		foreign-types-shared-0.1.1 \
		foreign-types-shared-0.3.1 \
		form_urlencoded-1.2.2 \
		fs_extra-1.3.0 \
		futures-0.3.34 \
		futures-channel-0.3.34 \
		futures-core-0.3.34 \
		futures-executor-0.3.34 \
		futures-io-0.3.34 \
		futures-lite-2.6.1 \
		futures-macro-0.3.34 \
		futures-sink-0.3.34 \
		futures-task-0.3.34 \
		futures-util-0.3.34 \
		gbm-0.18.0 \
		gbm-sys-0.4.0 \
		generic-array-0.14.7 \
		gethostname-1.1.0 \
		getrandom-0.2.17 \
		getrandom-0.3.4 \
		getrandom-0.4.3 \
		gif-0.14.2 \
		gl_generator-0.14.0 \
		glob-0.3.4 \
		glow-0.17.0 \
		glow-0.18.0 \
		glutin-0.32.3 \
		glutin-winit-0.5.0 \
		glutin_egl_sys-0.7.1 \
		glutin_glx_sys-0.6.1 \
		glutin_wgl_sys-0.6.1 \
		gpu-allocator-0.28.0 \
		grid-1.0.1 \
		h2-0.4.19 \
		half-2.7.1 \
		harfrust-0.12.0 \
		hashbrown-0.14.5 \
		hashbrown-0.15.5 \
		hashbrown-0.16.1 \
		hashbrown-0.17.1 \
		heck-0.5.0 \
		hermit-abi-0.3.9 \
		hermit-abi-0.5.3 \
		hex-0.4.3 \
		hmac-0.12.1 \
		hmac-sha256-1.1.14 \
		htmlparser-0.2.1 \
		http-1.5.0 \
		http-body-1.1.0 \
		http-body-util-0.1.5 \
		httparse-1.10.1 \
		httpdate-1.0.3 \
		hyper-1.11.1 \
		hyper-timeout-0.5.2 \
		hyper-util-0.1.20 \
		i-slint-backend-android-activity-1.18.1 \
		i-slint-backend-linuxkms-1.18.1 \
		i-slint-backend-selector-1.18.1 \
		i-slint-backend-testing-1.18.1 \
		i-slint-backend-winit-1.18.1 \
		i-slint-common-1.18.1 \
		i-slint-compiler-1.18.1 \
		i-slint-core-1.18.1 \
		i-slint-core-macros-1.18.1 \
		i-slint-renderer-femtovg-1.18.1 \
		i-slint-renderer-software-1.18.1 \
		iana-time-zone-0.1.65 \
		iana-time-zone-haiku-0.1.2 \
		icu_collections-2.3.0 \
		icu_decimal-2.3.0 \
		icu_decimal_data-2.3.0 \
		icu_locale_core-2.3.0 \
		icu_locale_fallback-2.3.0 \
		icu_locale_fallback_data-2.3.0 \
		icu_normalizer-2.3.0 \
		icu_normalizer_data-2.3.0 \
		icu_plurals-2.3.0 \
		icu_plurals_data-2.3.0 \
		icu_properties-2.3.0 \
		icu_properties_data-2.3.0 \
		icu_provider-2.3.1 \
		icu_segmenter-2.3.0 \
		icu_segmenter_data-2.3.0 \
		ident_case-1.0.1 \
		idna-1.1.0 \
		idna_adapter-1.2.2 \
		image-0.25.10 \
		image-webp-0.2.4 \
		imagesize-0.15.0 \
		imgref-1.12.3 \
		indexmap-2.14.0 \
		inout-0.1.4 \
		input-0.10.0 \
		input-sys-1.19.0 \
		io-lifetimes-1.0.11 \
		is_terminal_polyfill-1.70.2 \
		itertools-0.13.0 \
		itertools-0.14.0 \
		itertools-0.15.0 \
		itoa-1.0.18 \
		jni-0.21.1 \
		jni-0.22.4 \
		jni-macros-0.22.4 \
		jni-sys-0.3.1 \
		jni-sys-0.4.1 \
		jni-sys-macros-0.4.1 \
		jobserver-0.1.35 \
		js-sys-0.3.104 \
		keyboard-types-0.7.0 \
		khronos-egl-6.0.0 \
		khronos_api-3.1.0 \
		ksni-0.3.6 \
		kurbo-0.13.1 \
		lazy_static-1.5.0 \
		libbz2-rs-sys-0.2.5 \
		libc-0.2.189 \
		libloading-0.8.9 \
		libm-0.2.16 \
		libredox-0.1.23 \
		libseat-0.2.4 \
		libseat-sys-0.2.0 \
		libudev-sys-0.1.4 \
		linebender_resource_handle-0.1.1 \
		linux-raw-sys-0.4.15 \
		linux-raw-sys-0.9.4 \
		linux-raw-sys-0.12.1 \
		litemap-0.8.3 \
		litrs-1.0.0 \
		lock_api-0.4.14 \
		log-0.4.34 \
		logos-0.15.1 \
		logos-0.16.1 \
		logos-codegen-0.15.1 \
		logos-codegen-0.16.1 \
		logos-derive-0.15.1 \
		logos-derive-0.16.1 \
		lyon_algorithms-1.0.21 \
		lyon_extra-1.1.0 \
		lyon_geom-1.0.19 \
		lyon_path-1.0.19 \
		lzma-rs-0.3.0 \
		lzma-rust2-0.15.8 \
		lzma-sys-0.1.20 \
		mach2-0.4.3 \
		macro_rules_attribute-0.2.3 \
		macro_rules_attribute-proc_macro-0.2.3 \
		matchit-0.8.4 \
		matrixmultiply-0.3.11 \
		memchr-2.8.3 \
		memmap2-0.9.11 \
		memoffset-0.9.1 \
		miette-7.6.0 \
		miette-derive-7.6.0 \
		mime-0.3.17 \
		minimal-lexical-0.2.1 \
		miniz_oxide-0.8.9 \
		miniz_oxide-0.9.1 \
		mio-1.2.3 \
		monostate-0.1.18 \
		monostate-impl-0.1.18 \
		moxcms-0.8.1 \
		muda-0.19.3 \
		multimap-0.10.1 \
		naga-30.0.1 \
		naga-types-30.0.1 \
		native-tls-0.2.18 \
		natord-1.0.9 \
		ndarray-0.17.2 \
		ndk-0.8.0 \
		ndk-0.9.0 \
		ndk-context-0.1.1 \
		ndk-sys-0.5.0+25.2.9519653 \
		ndk-sys-0.6.0+11769913 \
		nix-0.31.3 \
		nom-7.1.3 \
		nom-8.0.0 \
		normpath-1.5.1 \
		num-complex-0.4.6 \
		num-conv-0.2.2 \
		num-derive-0.4.2 \
		num-integer-0.1.47 \
		num-traits-0.2.19 \
		num_enum-0.7.6 \
		num_enum_derive-0.7.6 \
		objc-sys-0.3.5 \
		objc2-0.5.2 \
		objc2-0.6.4 \
		objc2-app-kit-0.2.2 \
		objc2-app-kit-0.3.2 \
		objc2-audio-toolbox-0.3.2 \
		objc2-cloud-kit-0.2.2 \
		objc2-contacts-0.2.2 \
		objc2-core-audio-0.3.2 \
		objc2-core-audio-types-0.3.2 \
		objc2-core-data-0.2.2 \
		objc2-core-foundation-0.3.2 \
		objc2-core-graphics-0.3.2 \
		objc2-core-image-0.2.2 \
		objc2-core-location-0.2.2 \
		objc2-core-text-0.3.2 \
		objc2-encode-4.1.0 \
		objc2-foundation-0.2.2 \
		objc2-foundation-0.3.2 \
		objc2-io-surface-0.3.2 \
		objc2-link-presentation-0.2.2 \
		objc2-metal-0.2.2 \
		objc2-metal-0.3.2 \
		objc2-quartz-core-0.2.2 \
		objc2-quartz-core-0.3.2 \
		objc2-symbols-0.2.2 \
		objc2-ui-kit-0.2.2 \
		objc2-ui-kit-0.3.2 \
		objc2-uniform-type-identifiers-0.2.2 \
		objc2-user-notifications-0.2.2 \
		once_cell-1.21.4 \
		once_cell_polyfill-1.70.2 \
		opener-0.8.5 \
		openssl-0.10.81 \
		openssl-macros-0.1.1 \
		openssl-probe-0.2.1 \
		openssl-sys-0.9.117 \
		option-ext-0.2.0 \
		orbclient-0.3.55 \
		ordered-float-5.5.0 \
		ordered-stream-0.2.0 \
		ort-2.0.0-rc.13 \
		ort-sys-2.0.0-rc.13 \
		os_pipe-1.2.3 \
		owned_ttf_parser-0.25.1 \
		parking-2.2.1 \
		parking_lot-0.12.5 \
		parking_lot_core-0.9.12 \
		parlance-0.1.0 \
		parley-0.11.1 \
		parley_data-0.11.1 \
		paste-1.0.15 \
		pastey-0.2.3 \
		pbkdf2-0.12.2 \
		pem-rfc7468-1.0.0 \
		percent-encoding-2.3.2 \
		petgraph-0.8.3 \
		phf-0.13.1 \
		phf_generator-0.13.1 \
		phf_macros-0.13.1 \
		phf_shared-0.13.1 \
		pico-args-0.5.0 \
		pin-project-1.1.13 \
		pin-project-internal-1.1.13 \
		pin-project-lite-0.2.17 \
		pin-utils-0.1.0 \
		pin-weak-1.1.0 \
		piper-0.2.5 \
		pkg-config-0.3.34 \
		plain-0.2.3 \
		png-0.17.16 \
		png-0.18.1 \
		polling-3.11.0 \
		pollster-0.4.0 \
		polycool-0.4.0 \
		portable-atomic-1.15.0 \
		portable-atomic-util-0.2.7 \
		potential_utf-0.1.6 \
		powerfmt-0.2.0 \
		ppv-lite86-0.2.21 \
		presser-0.3.1 \
		prettyplease-0.2.37 \
		proc-macro-crate-3.5.0 \
		proc-macro2-1.0.107 \
		profiling-1.0.18 \
		prost-0.14.4 \
		prost-build-0.14.4 \
		prost-derive-0.14.4 \
		prost-reflect-0.16.5 \
		prost-types-0.14.4 \
		protox-0.9.1 \
		protox-parse-0.9.0 \
		pulldown-cmark-0.13.4 \
		pulldown-cmark-to-cmark-22.0.1 \
		pxfm-0.1.30 \
		quick-error-2.0.1 \
		quick-xml-0.41.0 \
		quote-1.0.47 \
		r-efi-5.3.0 \
		r-efi-6.0.0 \
		rand-0.9.5 \
		rand_chacha-0.9.0 \
		rand_core-0.9.5 \
		range-alloc-0.1.5 \
		raw-window-handle-0.6.2 \
		raw-window-metal-1.1.0 \
		rawpointer-0.2.1 \
		rayon-1.12.0 \
		rayon-cond-0.4.0 \
		rayon-core-1.13.0 \
		read-fonts-0.41.0 \
		redox_syscall-0.4.1 \
		redox_syscall-0.5.18 \
		redox_syscall-0.9.3 \
		redox_users-0.5.3 \
		regex-1.13.1 \
		regex-automata-0.4.18 \
		regex-syntax-0.8.11 \
		renderdoc-sys-1.1.0 \
		resvg-0.48.1 \
		rfd-0.17.2 \
		rgb-0.8.53 \
		ring-0.17.14 \
		rowan-0.17.0 \
		roxmltree-0.20.0 \
		roxmltree-0.21.1 \
		rspolib-0.1.2 \
		rustc-hash-1.1.0 \
		rustc-hash-2.1.3 \
		rustc_version-0.4.1 \
		rustix-0.38.44 \
		rustix-1.1.4 \
		rustls-0.23.45 \
		rustls-pki-types-1.15.1 \
		rustls-webpki-0.103.15 \
		rustversion-1.0.23 \
		rustybuzz-0.20.1 \
		ryu-1.0.23 \
		same-file-1.0.6 \
		schannel-0.1.29 \
		scoped-tls-1.0.1 \
		scoped-tls-hkt-0.1.5 \
		scopeguard-1.2.0 \
		sctk-adwaita-0.10.1 \
		security-framework-3.7.0 \
		security-framework-sys-2.17.0 \
		semver-1.0.28 \
		serde-1.0.229 \
		serde_core-1.0.229 \
		serde_derive-1.0.229 \
		serde_json-1.0.151 \
		serde_repr-0.1.21 \
		serde_spanned-1.1.1 \
		sha1-0.10.7 \
		sha2-0.10.9 \
		sherpa-onnx-1.13.7 \
		sherpa-onnx-sys-1.13.7 \
		shlex-1.3.0 \
		shlex-2.0.1 \
		signal-hook-registry-1.4.8 \
		simd-adler32-0.3.10 \
		simd_cesu8-1.2.0 \
		simdutf8-0.1.5 \
		simplecss-0.2.2 \
		siphasher-1.0.3 \
		skia-bindings-0.153.3 \
		skia-safe-0.153.3 \
		skrifa-0.44.0 \
		slab-0.4.12 \
		slint-1.18.1 \
		slint-build-1.18.1 \
		slint-macros-1.18.1 \
		slotmap-1.1.1 \
		smallvec-1.15.2 \
		smithay-client-toolkit-0.19.2 \
		smol_str-0.2.2 \
		smol_str-0.3.6 \
		snafu-0.8.9 \
		snafu-derive-0.8.9 \
		socket2-0.6.5 \
		socks-0.3.4 \
		softbuffer-0.4.8 \
		spin_on-0.1.1 \
		spirv-0.4.0+sdk-1.4.341.0 \
		spm_precompiled-0.1.4 \
		stable_deref_trait-1.2.1 \
		static_assertions-1.1.0 \
		strict-num-0.1.1 \
		strsim-0.11.1 \
		strum-0.28.0 \
		strum_macros-0.28.0 \
		subtle-2.6.1 \
		svgtypes-0.16.1 \
		swash-0.2.10 \
		syn-2.0.119 \
		syn-3.0.4 \
		sync_wrapper-1.0.2 \
		synstructure-0.13.2 \
		sys-locale-0.3.2 \
		taffy-0.10.1 \
		tar-0.4.46 \
		task-local-0.1.1 \
		tempfile-3.27.0 \
		termcolor-1.4.1 \
		text-size-1.1.1 \
		thiserror-1.0.69 \
		thiserror-2.0.20 \
		thiserror-impl-1.0.69 \
		thiserror-impl-2.0.20 \
		time-0.3.55 \
		time-core-0.1.9 \
		tiny-skia-0.11.4 \
		tiny-skia-0.12.0 \
		tiny-skia-path-0.11.4 \
		tiny-skia-path-0.12.0 \
		tiny-xlib-0.2.5 \
		tinystr-0.8.4 \
		tinyvec-1.12.0 \
		tinyvec_macros-0.1.1 \
		tokenizers-0.23.2 \
		tokio-1.53.1 \
		tokio-macros-2.7.2 \
		tokio-stream-0.1.19 \
		tokio-util-0.7.19 \
		toml-1.1.5+spec-1.1.0 \
		toml_datetime-1.1.1+spec-1.1.0 \
		toml_edit-0.25.13+spec-1.1.0 \
		toml_parser-1.1.3+spec-1.1.0 \
		toml_writer-1.1.2+spec-1.1.0 \
		tonic-0.14.6 \
		tonic-build-0.14.6 \
		tonic-prost-0.14.6 \
		tonic-prost-build-0.14.6 \
		tower-0.5.3 \
		tower-layer-0.3.3 \
		tower-service-0.3.3 \
		tracing-0.1.44 \
		tracing-attributes-0.1.31 \
		tracing-core-0.1.36 \
		tree_magic_mini-3.2.2 \
		try-lock-0.2.5 \
		ttf-parser-0.25.1 \
		typed-index-collections-3.5.0 \
		typenum-1.20.1 \
		udev-0.9.3 \
		uds_windows-1.2.1 \
		unicase-2.9.0 \
		unicode-bidi-0.3.18 \
		unicode-bidi-mirroring-0.4.0 \
		unicode-ccc-0.4.0 \
		unicode-ident-1.0.24 \
		unicode-linebreak-0.1.5 \
		unicode-normalization-alignments-0.1.12 \
		unicode-properties-0.1.4 \
		unicode-script-0.5.8 \
		unicode-segmentation-1.13.3 \
		unicode-vo-0.1.0 \
		unicode-width-0.1.14 \
		unicode-width-0.2.2 \
		unicode-xid-0.2.6 \
		unicode_categories-0.1.1 \
		untrusted-0.9.0 \
		unty-0.0.4 \
		ureq-2.12.1 \
		ureq-3.4.1 \
		ureq-proto-0.6.2 \
		url-2.5.8 \
		usvg-0.48.1 \
		utf8-zero-0.8.1 \
		utf8_iter-1.0.4 \
		utf8parse-0.2.2 \
		uuid-1.26.0 \
		vcpkg-0.2.15 \
		version_check-0.9.5 \
		vtable-0.5.0 \
		vtable-macro-0.5.0 \
		walkdir-2.5.0 \
		want-0.3.1 \
		wasi-0.11.1+wasi-snapshot-preview1 \
		wasip2-1.0.4+wasi-0.2.12 \
		wasm-bindgen-0.2.127 \
		wasm-bindgen-futures-0.4.77 \
		wasm-bindgen-macro-0.2.127 \
		wasm-bindgen-macro-support-0.2.127 \
		wasm-bindgen-shared-0.2.127 \
		wayland-backend-0.3.17 \
		wayland-client-0.31.15 \
		wayland-csd-frame-0.3.0 \
		wayland-cursor-0.31.14 \
		wayland-protocols-0.32.13 \
		wayland-protocols-plasma-0.3.12 \
		wayland-protocols-wlr-0.3.12 \
		wayland-scanner-0.31.11 \
		wayland-sys-0.31.11 \
		web-sys-0.3.104 \
		web-time-1.1.0 \
		webbrowser-1.2.4 \
		webpki-root-certs-1.0.9 \
		webpki-roots-0.26.11 \
		webpki-roots-1.0.9 \
		weezl-0.1.12 \
		wgpu-30.0.1 \
		wgpu-core-30.0.1 \
		wgpu-core-deps-apple-30.0.1 \
		wgpu-core-deps-emscripten-30.0.1 \
		wgpu-core-deps-wasm-30.0.1 \
		wgpu-core-deps-windows-linux-android-30.0.1 \
		wgpu-hal-30.0.1 \
		wgpu-naga-bridge-30.0.1 \
		wgpu-types-30.0.1 \
		whisper-rs-0.16.0 \
		whisper-rs-sys-0.15.0 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.11 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-0.54.0 \
		windows-0.62.2 \
		windows-collections-0.3.2 \
		windows-core-0.54.0 \
		windows-core-0.62.2 \
		windows-future-0.3.2 \
		windows-implement-0.60.2 \
		windows-interface-0.59.3 \
		windows-link-0.2.1 \
		windows-numerics-0.3.1 \
		windows-result-0.1.2 \
		windows-result-0.4.1 \
		windows-strings-0.5.1 \
		windows-sys-0.45.0 \
		windows-sys-0.48.0 \
		windows-sys-0.52.0 \
		windows-sys-0.59.0 \
		windows-sys-0.61.2 \
		windows-targets-0.42.2 \
		windows-targets-0.48.5 \
		windows-targets-0.52.6 \
		windows-threading-0.2.1 \
		windows_aarch64_gnullvm-0.42.2 \
		windows_aarch64_gnullvm-0.48.5 \
		windows_aarch64_gnullvm-0.52.6 \
		windows_aarch64_msvc-0.42.2 \
		windows_aarch64_msvc-0.48.5 \
		windows_aarch64_msvc-0.52.6 \
		windows_i686_gnu-0.42.2 \
		windows_i686_gnu-0.48.5 \
		windows_i686_gnu-0.52.6 \
		windows_i686_gnullvm-0.52.6 \
		windows_i686_msvc-0.42.2 \
		windows_i686_msvc-0.48.5 \
		windows_i686_msvc-0.52.6 \
		windows_x86_64_gnu-0.42.2 \
		windows_x86_64_gnu-0.48.5 \
		windows_x86_64_gnu-0.52.6 \
		windows_x86_64_gnullvm-0.42.2 \
		windows_x86_64_gnullvm-0.48.5 \
		windows_x86_64_gnullvm-0.52.6 \
		windows_x86_64_msvc-0.42.2 \
		windows_x86_64_msvc-0.48.5 \
		windows_x86_64_msvc-0.52.6 \
		winit-0.30.13 \
		winnow-1.0.4 \
		winresource-0.1.31 \
		wit-bindgen-0.57.1 \
		wl-clipboard-rs-0.9.3 \
		write-fonts-0.50.0 \
		writeable-0.6.4 \
		x11-dl-2.21.0 \
		x11rb-0.13.2 \
		x11rb-protocol-0.13.2 \
		xattr-1.6.1 \
		xcursor-0.3.11 \
		xkbcommon-0.9.0 \
		xkbcommon-dl-0.4.2 \
		xkeysym-0.2.1 \
		xml-rs-0.8.29 \
		xmlwriter-0.1.0 \
		xz2-0.1.7 \
		yazi-0.2.1 \
		yeslogic-fontconfig-sys-6.0.1 \
		yoke-0.8.3 \
		yoke-derive-0.8.2 \
		zbus-5.19.0 \
		zbus-lockstep-0.5.2 \
		zbus-lockstep-macros-0.5.2 \
		zbus_macros-5.19.0 \
		zbus_names-4.3.4 \
		zbus_xml-5.2.1 \
		zcheapstr-1.1.0 \
		zeno-0.3.3 \
		zerocopy-0.8.56 \
		zerocopy-derive-0.8.56 \
		zerofrom-0.1.8 \
		zerofrom-derive-0.1.7 \
		zeroize-1.9.0 \
		zeroize_derive-1.5.0 \
		zerotrie-0.2.5 \
		zerovec-0.11.8 \
		zerovec-derive-0.11.6 \
		zip-2.4.2 \
		zlib-rs-0.6.7 \
		zmij-1.0.23 \
		zopfli-0.8.3 \
		zstd-0.13.3 \
		zstd-safe-7.2.4 \
		zstd-sys-2.0.16+zstd.1.5.7 \
		zune-core-0.5.3 \
		zune-jpeg-0.5.15 \
		zvariant-5.15.0 \
		zvariant_derive-5.15.0 \
		zvariant_utils-4.2.0

BINARY_ALIAS=	python3=${PYTHON_CMD}

# The workspace also holds the Android activity: build the editor and
# the command line tool, and install both from the target directory
# instead of running cargo install once per crate.
CARGO_BUILD_ARGS=	--package concat --package concat-cli
CARGO_INSTALL=	no

# Skia is built from ${WRKSRC_skia} instead of being downloaded as
# prebuilt binaries, against the system's FreeType, fontconfig, libpng,
# libjpeg-turbo, expat and zlib.  Its GIF decoder (wuffs) is not built.
# skia-bindings learns FreeBSD from files/skia-bindings-freebsd.rs: Skia's
# GN files do not know it, so it is configured as Linux, as graphics/skia
# does.
#
# ONNX Runtime (background removal, Chatterbox voices) is misc/onnxruntime,
# linked dynamically, as upstream does on Linux, instead of a downloaded
# build.  sherpa-onnx is built in pre-build against the same library,
# instead of the prebuilt static libraries the sherpa-onnx-sys crate
# downloads, which bring their own copy of ONNX Runtime.
#
# whisper.cpp (captions) is built by whisper-rs-sys, which hands GGML_*
# variables to its CMake run: build it for the baseline CPU rather than
# the build machine's.  GGML_NATIVE=OFF alone would switch AVX2, FMA and
# F16C on.
MAKE_ENV+=	GGML_AVX=OFF \
		GGML_AVX2=OFF \
		GGML_BMI2=OFF \
		GGML_F16C=OFF \
		GGML_FMA=OFF \
		GGML_NATIVE=OFF \
		GGML_SSE42=OFF \
		LIBCLANG_PATH=${LLVM_PREFIX}/lib \
		ORT_LIB_LOCATION=${LOCALBASE}/lib \
		ORT_PREFER_DYNAMIC_LINK=1 \
		SHERPA_ONNX_LIB_DIR=${SHERPA_STAGEDIR}/lib \
		SKIA_GN_ARGS=skia_use_wuffs=false \
		SKIA_GN_COMMAND=${LOCALBASE}/bin/gn \
		SKIA_NINJA_COMMAND=${LOCALBASE}/bin/${NINJA_CMD} \
		SKIA_SOURCE_DIR=${WRKSRC_skia} \
		SKIA_USE_SYSTEM_LIBRARIES=1

EIGEN_VERSION=	5.0.1

SHERPA_BUILDDIR=	${WRKDIR}/sherpa-onnx-build
SHERPA_STAGEDIR=	${WRKDIR}/sherpa-onnx-stage
# The static libraries the sherpa-onnx crate links, built without the
# demo programs and the Python, WebSocket and PortAudio parts.  Each
# FetchContent dependency is pointed at its source directory.
SHERPA_DEPS=	EIGEN:${WRKDIR}/eigen-${EIGEN_VERSION} \
		ESPEAK_NG:${WRKSRC_espeak} \
		HCLUST_CPP:${WRKSRC_hclust} \
		JSON:${WRKSRC_json} \
		KALDI_DECODER:${WRKSRC_kdecoder} \
		KALDI_NATIVE_FBANK:${WRKSRC_kfbank} \
		KALDIFST:${WRKSRC_kaldifst} \
		KISSFFT:${WRKSRC_kissfft} \
		OPENFST:${WRKSRC_openfst} \
		PIPER_PHONEMIZE:${WRKSRC_piper} \
		SIMPLE-SENTENCEPIECE:${WRKSRC_ssp}
SHERPA_CMAKE_ARGS=	-DBUILD_SHARED_LIBS:BOOL=OFF \
			-DCMAKE_BUILD_TYPE:STRING=Release \
			-DCMAKE_INSTALL_PREFIX:PATH=${SHERPA_STAGEDIR} \
			-DFETCHCONTENT_FULLY_DISCONNECTED:BOOL=ON \
			-DSHERPA_ONNX_BUILD_C_API_EXAMPLES:BOOL=OFF \
			-DSHERPA_ONNX_ENABLE_BINARY:BOOL=OFF \
			-DSHERPA_ONNX_ENABLE_C_API:BOOL=ON \
			-DSHERPA_ONNX_ENABLE_PORTAUDIO:BOOL=OFF \
			-DSHERPA_ONNX_ENABLE_PYTHON:BOOL=OFF \
			-DSHERPA_ONNX_ENABLE_TESTS:BOOL=OFF \
			-DSHERPA_ONNX_ENABLE_WEBSOCKET:BOOL=OFF \
			${SHERPA_DEPS:S/^/-DFETCHCONTENT_SOURCE_DIR_/:C/:/:PATH=/}

ICON_SIZES=	16 32 64 128 256 512

PLIST_FILES=	bin/concat \
		bin/concat-cli \
		share/applications/concat.desktop \
		${ICON_SIZES:@s@share/icons/hicolor/${s}x${s}/apps/concat.png@}

post-extract:
	@${MKDIR} ${WRKSRC_skia}/third_party/externals
	@${LN} -s ${WRKSRC_vma} \
		${WRKSRC_skia}/third_party/externals/vulkanmemoryallocator

post-patch:
	@${CP} ${FILESDIR}/skia-bindings-freebsd.rs \
		${CARGO_VENDOR_DIR}/skia-bindings-0.153.3/build_support/platform/freebsd.rs

pre-build:
	@${MKDIR} ${SHERPA_BUILDDIR}
	cd ${SHERPA_BUILDDIR} && ${SETENVI} ${WRK_ENV} ${MAKE_ENV} \
		${LOCALBASE}/bin/cmake -G Ninja ${SHERPA_CMAKE_ARGS} \
		${WRKSRC_sherpa}
	cd ${SHERPA_BUILDDIR} && ${SETENVI} ${WRK_ENV} ${MAKE_ENV} \
		${NINJA_CMD} -j${MAKE_JOBS_NUMBER} install

do-install:
.for b in concat concat-cli
	${INSTALL_PROGRAM} ${CARGO_TARGET_DIR}/${WITH_DEBUG:Ddebug:Urelease}/${b} \
		${STAGEDIR}${PREFIX}/bin
.endfor
	@${MKDIR} ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${FILESDIR}/concat.desktop ${STAGEDIR}${DESKTOPDIR}
.for s in ${ICON_SIZES}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps
	${INSTALL_DATA} ${WRKSRC}/../assets/icons/concat_logo_${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps/concat.png
.endfor

.include <bsd.port.mk>
