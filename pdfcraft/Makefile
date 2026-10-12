PORTNAME=	pdfcraft
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.0
CATEGORIES=	print graphics

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	PDF workbench: read, comment, fill, sign, organize and protect PDFs
WWW=		https://getartcraft.com/apps/pdfcraft \
		https://github.com/storytold/pdfcraft

LICENSE=	APACHE20 MIT OFL11
LICENSE_COMB=	multi
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT
LICENSE_FILE_OFL11=	${WRKSRC}/assets/fonts/OFL-Inter.txt

# winit, wgpu, x11rb and xkbcommon-dl dlopen() the display, input and
# graphics libraries at run time, nothing links against them.  File
# dialogs go through the XDG desktop portal (rfd's xdg-portal backend).
RUN_DEPENDS=	${LOCALBASE}/lib/libEGL.so:graphics/libglvnd \
		${LOCALBASE}/lib/libvulkan.so:graphics/vulkan-loader \
		${LOCALBASE}/lib/libwayland-client.so:graphics/wayland \
		${LOCALBASE}/lib/libX11.so:x11/libX11 \
		${LOCALBASE}/lib/libXcursor.so:x11/libXcursor \
		${LOCALBASE}/lib/libXi.so:x11/libXi \
		${LOCALBASE}/lib/libxcb.so:x11/libxcb \
		${LOCALBASE}/lib/libxkbcommon.so:x11/libxkbcommon \
		xdg-desktop-portal-gtk>0:x11/xdg-desktop-portal-gtk \
		xdg-open:devel/xdg-utils

USES=		cargo desktop-file-utils shared-mime-info
USE_GITHUB=	yes
GH_ACCOUNT=	storytold

CARGO_CRATES=	accesskit-0.24.1 \
		accesskit_atspi_common-0.18.1 \
		accesskit_consumer-0.35.0 \
		accesskit_consumer-0.36.0 \
		accesskit_consumer-0.38.0 \
		accesskit_macos-0.26.3 \
		accesskit_unix-0.21.1 \
		accesskit_windows-0.32.1 \
		accesskit_winit-0.32.2 \
		adler2-2.0.1 \
		aes-0.9.3 \
		ahash-0.8.12 \
		aligned-vec-0.6.4 \
		alloc-no-stdlib-2.0.4 \
		alloc-stdlib-0.2.4 \
		allocator-api2-0.2.21 \
		android-activity-0.6.1 \
		android-properties-0.2.2 \
		android_system_properties-0.1.6 \
		anyhow-1.0.104 \
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
		aws-lc-rs-1.18.1 \
		aws-lc-sys-0.45.0 \
		base16ct-1.0.0 \
		base64-0.22.1 \
		base64-0.23.1 \
		base64ct-1.8.3 \
		bit-set-0.8.0 \
		bit-set-0.10.0 \
		bit-vec-0.8.0 \
		bit-vec-0.9.1 \
		bitflags-1.3.2 \
		bitflags-2.13.2 \
		block-buffer-0.12.1 \
		block-padding-0.4.2 \
		block2-0.5.1 \
		block2-0.6.2 \
		blocking-1.7.0 \
		boa_ast-0.22.0 \
		boa_engine-0.22.0 \
		boa_gc-0.22.0 \
		boa_interner-0.22.0 \
		boa_macros-0.22.0 \
		boa_parser-0.22.0 \
		boa_string-0.22.0 \
		bp256-0.14.0 \
		bp384-0.14.0 \
		brotli-8.0.4 \
		brotli-decompressor-5.0.3 \
		bumpalo-3.20.3 \
		bytemuck-1.25.2 \
		bytemuck_derive-1.12.1 \
		byteorder-lite-0.1.0 \
		bytes-1.12.1 \
		calloop-0.13.0 \
		calloop-0.14.4 \
		calloop-wayland-source-0.3.0 \
		calloop-wayland-source-0.4.1 \
		cbc-0.2.1 \
		cc-1.5.1 \
		cfg-if-1.0.5 \
		cfg_aliases-0.2.2 \
		cgl-0.3.2 \
		chacha20-0.10.2 \
		chrono-0.4.45 \
		cipher-0.5.2 \
		clipboard-win-5.4.1 \
		cmake-0.1.58 \
		cmov-0.5.4 \
		codespan-reporting-0.13.1 \
		color-0.3.3 \
		color_quant-1.1.0 \
		combine-4.6.8 \
		concurrent-queue-2.5.0 \
		const-oid-0.10.2 \
		core-foundation-0.9.4 \
		core-foundation-0.10.1 \
		core-foundation-sys-0.8.7 \
		core-graphics-0.23.2 \
		core-graphics-types-0.1.3 \
		core_detect-1.0.0 \
		cow-utils-0.1.3 \
		cpubits-0.1.1 \
		cpufeatures-0.3.1 \
		crc32fast-1.5.2 \
		crossbeam-deque-0.8.8 \
		crossbeam-epoch-0.9.21 \
		crossbeam-utils-0.8.23 \
		crunchy-0.2.4 \
		crypto-bigint-0.7.5 \
		crypto-common-0.2.2 \
		crypto-primes-0.7.2 \
		ctutils-0.4.2 \
		cursor-icon-1.2.0 \
		curve25519-dalek-5.0.0 \
		curve25519-dalek-derive-0.1.1 \
		dashmap-6.2.1 \
		data-url-0.3.2 \
		der-0.8.2 \
		deranged-0.5.8 \
		des-0.9.0 \
		digest-0.11.3 \
		dispatch-0.2.0 \
		dispatch2-0.3.1 \
		displaydoc-0.2.7 \
		dlib-0.5.3 \
		document-features-0.2.12 \
		downcast-rs-1.2.1 \
		dpi-0.1.2 \
		dunce-1.0.5 \
		dynify-0.1.2 \
		dynify-macros-0.1.2 \
		ecb-0.2.1 \
		ecdsa-0.17.0 \
		ecolor-0.36.2 \
		ed25519-3.0.0 \
		ed25519-dalek-3.0.0 \
		eframe-0.36.2 \
		egui-0.36.2 \
		egui-winit-0.36.2 \
		egui_extras-0.36.2 \
		egui_glow-0.36.2 \
		egui_kittest-0.36.2 \
		either-1.18.0 \
		elliptic-curve-0.14.1 \
		emath-0.36.2 \
		encoding_rs-0.8.42 \
		endi-1.1.1 \
		enum-map-2.7.3 \
		enum-map-derive-0.17.0 \
		enumflags2-0.7.12 \
		enumflags2_derive-0.7.12 \
		enumn-0.1.14 \
		epaint-0.36.2 \
		epaint_default_fonts-0.36.2 \
		equator-0.4.2 \
		equator-macro-0.4.2 \
		equivalent-1.0.2 \
		errno-0.3.14 \
		error-code-3.4.0 \
		euclid-0.22.14 \
		event-listener-5.4.2 \
		event-listener-strategy-0.5.4 \
		fast-float2-0.2.4 \
		fastrand-2.5.0 \
		fax-0.2.7 \
		fdeflate-0.3.7 \
		fearless_simd-0.4.1 \
		ff-0.14.0 \
		fiat-crypto-0.3.0 \
		find-msvc-tools-0.1.14 \
		fixedbitset-0.5.7 \
		flatbuffers-24.12.23 \
		flate2-1.1.10 \
		float-cmp-0.9.0 \
		fmv-macos-events-0.1.0 \
		fnv-1.0.7 \
		foldhash-0.2.0 \
		font-types-0.11.3 \
		font-types-0.12.5 \
		foreign-types-0.5.0 \
		foreign-types-macros-0.2.4 \
		foreign-types-shared-0.3.1 \
		form_urlencoded-1.2.2 \
		fs_extra-1.3.0 \
		futures-concurrency-7.7.1 \
		futures-core-0.3.34 \
		futures-io-0.3.34 \
		futures-lite-2.6.1 \
		futures-macro-0.3.34 \
		futures-task-0.3.34 \
		futures-util-0.3.34 \
		gethostname-1.1.0 \
		getrandom-0.2.17 \
		getrandom-0.3.4 \
		getrandom-0.4.3 \
		gif-0.14.2 \
		gl_generator-0.14.0 \
		glifo-0.1.1 \
		glifo-0.2.0 \
		glow-0.17.0 \
		glutin-0.32.3 \
		glutin-winit-0.5.0 \
		glutin_egl_sys-0.7.1 \
		glutin_glx_sys-0.6.1 \
		glutin_wgl_sys-0.6.1 \
		gpu-allocator-0.28.0 \
		group-0.14.0 \
		guillotiere-0.7.0 \
		half-2.7.1 \
		harfrust-0.12.0 \
		hashbrown-0.14.5 \
		hashbrown-0.16.1 \
		hashbrown-0.17.1 \
		hayro-ccitt-0.3.0 \
		hayro-cmap-0.1.0 \
		hayro-jpeg2000-0.3.5 \
		hayro-postscript-0.1.0 \
		heck-0.5.0 \
		hermit-abi-0.5.3 \
		hex-0.4.3 \
		hmac-0.13.0 \
		http-1.5.0 \
		httparse-1.10.1 \
		hybrid-array-0.4.15 \
		iana-time-zone-0.1.65 \
		iana-time-zone-haiku-0.1.2 \
		icu_collections-2.3.0 \
		icu_locale_core-2.3.0 \
		icu_normalizer-2.3.0 \
		icu_normalizer_data-2.3.0 \
		icu_properties-2.3.0 \
		icu_properties_data-2.3.0 \
		icu_provider-2.3.1 \
		idna-1.1.0 \
		idna_adapter-1.2.2 \
		image-0.25.10 \
		imagesize-0.13.0 \
		indexmap-2.14.2 \
		inout-0.2.2 \
		intrusive-collections-0.10.3 \
		itertools-0.15.0 \
		itoa-1.0.18 \
		jni-0.22.4 \
		jni-macros-0.22.4 \
		jni-sys-0.3.1 \
		jni-sys-0.4.1 \
		jni-sys-macros-0.4.1 \
		jobserver-0.1.35 \
		js-sys-0.3.106 \
		keccak-0.2.2 \
		khronos-egl-6.0.0 \
		khronos_api-3.1.0 \
		kittest-0.4.0 \
		kurbo-0.11.3 \
		kurbo-0.13.1 \
		libc-0.2.189 \
		libloading-0.8.9 \
		libm-0.2.16 \
		libredox-0.1.25 \
		linebender_resource_handle-0.1.1 \
		linux-raw-sys-0.4.15 \
		linux-raw-sys-0.12.1 \
		litemap-0.8.3 \
		litrs-1.0.0 \
		lock_api-0.4.14 \
		log-0.4.34 \
		md-5-0.11.0 \
		memchr-2.8.3 \
		memmap2-0.9.11 \
		memoffset-0.9.1 \
		miniz_oxide-0.8.9 \
		miniz_oxide-0.9.1 \
		moxcms-0.8.1 \
		multiversion_no_op-1.0.0 \
		naga-30.0.1 \
		naga-types-30.0.1 \
		ndk-0.9.0 \
		ndk-context-0.1.1 \
		ndk-sys-0.6.0+11769913 \
		nohash-hasher-0.2.0 \
		nom-8.0.0 \
		num-bigint-0.5.1 \
		num-conv-0.2.2 \
		num-integer-0.1.47 \
		num-traits-0.2.19 \
		num_cpus-1.17.0 \
		num_enum-0.7.6 \
		num_enum_derive-0.7.6 \
		num_threads-0.1.7 \
		objc-sys-0.3.5 \
		objc2-0.5.2 \
		objc2-0.6.4 \
		objc2-app-kit-0.2.2 \
		objc2-app-kit-0.3.2 \
		objc2-cloud-kit-0.2.2 \
		objc2-contacts-0.2.2 \
		objc2-core-data-0.2.2 \
		objc2-core-foundation-0.3.2 \
		objc2-core-graphics-0.3.2 \
		objc2-core-image-0.2.2 \
		objc2-core-location-0.2.2 \
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
		ocrs-0.13.1 \
		once_cell-1.21.4 \
		oneshot-0.2.1 \
		openssl-probe-0.2.1 \
		orbclient-0.3.55 \
		ordered-float-5.5.0 \
		ordered-stream-0.2.0 \
		p256-0.14.0 \
		p384-0.14.0 \
		p521-0.14.0 \
		parking-2.2.1 \
		parking_lot-0.12.5 \
		parking_lot_core-0.9.12 \
		pastey-0.2.3 \
		pbkdf2-0.13.0 \
		pem-rfc7468-1.0.0 \
		peniko-0.6.1 \
		percent-encoding-2.3.2 \
		phf-0.13.1 \
		phf-0.14.0 \
		phf_generator-0.13.1 \
		phf_generator-0.14.0 \
		phf_macros-0.13.1 \
		phf_macros-0.14.0 \
		phf_shared-0.13.1 \
		phf_shared-0.14.0 \
		pic-scale-0.7.12 \
		pico-args-0.5.0 \
		pin-project-1.1.13 \
		pin-project-internal-1.1.13 \
		pin-project-lite-0.2.17 \
		piper-0.2.5 \
		pkcs1-0.8.0-rc.4 \
		pkcs8-0.11.0 \
		pkg-config-0.3.34 \
		plain-0.2.3 \
		png-0.17.16 \
		png-0.18.1 \
		polling-3.11.0 \
		pollster-0.4.0 \
		pollster-1.0.1 \
		polycool-0.4.0 \
		portable-atomic-1.15.0 \
		portable-atomic-util-0.2.8 \
		potential_utf-0.1.6 \
		powerfmt-0.2.0 \
		ppv-lite86-0.2.21 \
		presser-0.3.1 \
		primefield-0.14.0 \
		primeorder-0.14.0 \
		proc-macro-crate-3.5.0 \
		proc-macro2-1.0.107 \
		profiling-1.0.18 \
		proptest-1.11.0 \
		pxfm-0.1.30 \
		quick-error-1.2.3 \
		quick-error-2.0.1 \
		quick-xml-0.41.0 \
		quote-1.0.47 \
		r-efi-5.3.0 \
		r-efi-6.0.0 \
		rand-0.9.5 \
		rand-0.10.3 \
		rand_chacha-0.9.0 \
		rand_core-0.9.5 \
		rand_core-0.10.1 \
		rand_xorshift-0.4.0 \
		range-alloc-0.1.5 \
		rangemap-1.8.0 \
		raw-window-handle-0.6.2 \
		raw-window-metal-1.1.0 \
		rayon-1.12.0 \
		rayon-core-1.13.0 \
		rc2-0.9.0 \
		read-fonts-0.39.2 \
		read-fonts-0.41.0 \
		read-fonts-0.44.0 \
		redox_syscall-0.4.1 \
		redox_syscall-0.5.18 \
		redox_syscall-0.9.4 \
		regex-syntax-0.8.11 \
		regress-0.12.0 \
		renderdoc-sys-1.1.0 \
		resvg-0.45.1 \
		rfc6979-0.6.0 \
		rfd-0.17.2 \
		rgb-0.8.53 \
		ring-0.17.14 \
		ripemd-0.2.0 \
		ron-0.12.2 \
		roxmltree-0.20.0 \
		rsa-0.10.0-rc.18 \
		rten-0.26.0 \
		rten-base-0.26.0 \
		rten-gemm-0.26.0 \
		rten-imageproc-0.26.0 \
		rten-model-file-0.26.0 \
		rten-parallel-0.26.0 \
		rten-shape-inference-0.26.0 \
		rten-simd-0.26.0 \
		rten-tensor-0.26.0 \
		rten-vecmath-0.26.0 \
		rustc-hash-1.1.0 \
		rustc-hash-2.1.3 \
		rustc_version-0.4.1 \
		rustix-0.38.44 \
		rustix-1.1.5 \
		rustls-0.23.45 \
		rustls-cng-0.7.1 \
		rustls-native-certs-0.8.4 \
		rustls-pki-types-1.15.1 \
		rustls-webpki-0.103.15 \
		rustversion-1.0.23 \
		rusty-fork-0.3.1 \
		ryu-js-1.0.3 \
		same-file-1.0.6 \
		schannel-0.1.29 \
		scoped-tls-1.0.1 \
		scopeguard-1.2.0 \
		sec1-0.8.1 \
		security-framework-3.7.0 \
		security-framework-sys-2.17.0 \
		self_cell-1.3.0 \
		semver-1.0.28 \
		serde-1.0.229 \
		serde_core-1.0.229 \
		serde_derive-1.0.229 \
		serde_json-1.0.151 \
		serde_repr-0.1.21 \
		serde_spanned-1.1.1 \
		serdect-0.4.3 \
		sha1-0.11.0 \
		sha2-0.11.0 \
		sha3-0.12.0 \
		shlex-2.0.1 \
		signal-hook-registry-1.4.8 \
		signature-3.0.0 \
		simd-adler32-0.3.10 \
		simd_cesu8-1.2.0 \
		simdutf8-0.1.5 \
		simplecss-0.2.2 \
		siphasher-1.0.4 \
		skrifa-0.42.1 \
		skrifa-0.44.0 \
		skrifa-0.47.0 \
		slab-0.4.12 \
		slotmap-1.1.1 \
		small_btree-0.1.0 \
		smallvec-1.16.2 \
		smithay-client-toolkit-0.19.2 \
		smithay-client-toolkit-0.20.0 \
		smithay-clipboard-0.7.3 \
		smol_str-0.2.2 \
		spirv-0.4.0+sdk-1.4.341.0 \
		spki-0.8.0 \
		sponge-cursor-0.1.0 \
		stable_deref_trait-1.2.1 \
		static_assertions-1.1.0 \
		strict-num-0.1.1 \
		stringprep-0.1.5 \
		strum-0.28.0 \
		strum_macros-0.28.0 \
		subtle-2.6.1 \
		svgtypes-0.15.3 \
		syn-2.0.119 \
		syn-3.0.6 \
		synstructure-0.14.0 \
		sys-locale-0.3.2 \
		tag_ptr-0.1.0 \
		tap-1.0.1 \
		tempfile-3.27.0 \
		termcolor-1.4.1 \
		thin-vec-0.2.20 \
		thiserror-1.0.69 \
		thiserror-2.0.21 \
		thiserror-impl-1.0.69 \
		thiserror-impl-2.0.21 \
		tiff-0.11.3 \
		time-0.3.55 \
		time-core-0.1.9 \
		time-macros-0.2.32 \
		tiny-skia-0.11.4 \
		tiny-skia-path-0.11.4 \
		tinystr-0.8.4 \
		tinyvec-1.13.3 \
		tokio-1.53.1 \
		toml-1.1.6+spec-1.1.0 \
		toml_datetime-1.1.1+spec-1.1.0 \
		toml_edit-0.25.15+spec-1.1.0 \
		toml_parser-1.1.3+spec-1.1.0 \
		toml_writer-1.1.2+spec-1.1.0 \
		tracing-0.1.44 \
		tracing-attributes-0.1.31 \
		tracing-core-0.1.36 \
		type-map-0.5.1 \
		typeid-1.0.3 \
		typenum-1.20.1 \
		uds_windows-1.2.1 \
		unarray-0.1.4 \
		unicode-bidi-0.3.18 \
		unicode-general-category-1.1.0 \
		unicode-ident-1.0.26 \
		unicode-normalization-0.1.25 \
		unicode-properties-0.1.4 \
		unicode-segmentation-1.13.3 \
		unicode-width-0.2.2 \
		untrusted-0.9.0 \
		ureq-3.4.2 \
		ureq-proto-0.6.4 \
		url-2.5.8 \
		usvg-0.45.1 \
		utf16_iter-1.0.5 \
		utf8-zero-0.8.1 \
		utf8_iter-1.0.4 \
		uuid-1.26.1 \
		vello_common-0.0.8 \
		vello_common-0.0.9 \
		vello_common-0.1.0 \
		vello_cpu-0.0.8 \
		vello_cpu-0.1.0 \
		version_check-0.9.5 \
		wait-timeout-0.2.1 \
		walkdir-2.5.0 \
		wasi-0.11.1+wasi-snapshot-preview1 \
		wasip2-1.0.4+wasi-0.2.12 \
		wasm-bindgen-0.2.129 \
		wasm-bindgen-futures-0.4.79 \
		wasm-bindgen-macro-0.2.129 \
		wasm-bindgen-macro-support-0.2.129 \
		wasm-bindgen-shared-0.2.129 \
		wayland-backend-0.3.17 \
		wayland-client-0.31.15 \
		wayland-csd-frame-0.3.0 \
		wayland-cursor-0.31.14 \
		wayland-protocols-0.32.13 \
		wayland-protocols-experimental-20250721.0.1 \
		wayland-protocols-misc-0.3.12 \
		wayland-protocols-plasma-0.3.12 \
		wayland-protocols-wlr-0.3.12 \
		wayland-scanner-0.31.11 \
		wayland-sys-0.31.11 \
		web-sys-0.3.106 \
		web-time-1.1.0 \
		webbrowser-1.2.4 \
		weezl-0.1.12 \
		weezl-0.2.1 \
		wgpu-30.0.1 \
		wgpu-core-30.0.1 \
		wgpu-core-deps-apple-30.0.1 \
		wgpu-core-deps-emscripten-30.0.1 \
		wgpu-core-deps-wasm-30.0.1 \
		wgpu-core-deps-windows-linux-android-30.0.1 \
		wgpu-hal-30.0.1 \
		wgpu-naga-bridge-30.0.1 \
		wgpu-types-30.0.1 \
		winapi-util-0.1.11 \
		windows-0.62.2 \
		windows-collections-0.3.2 \
		windows-core-0.62.2 \
		windows-future-0.3.2 \
		windows-implement-0.60.2 \
		windows-interface-0.59.3 \
		windows-link-0.2.1 \
		windows-numerics-0.3.1 \
		windows-result-0.4.1 \
		windows-strings-0.5.1 \
		windows-sys-0.52.0 \
		windows-sys-0.59.0 \
		windows-sys-0.60.2 \
		windows-sys-0.61.2 \
		windows-targets-0.52.6 \
		windows-targets-0.53.5 \
		windows-threading-0.2.1 \
		windows_aarch64_gnullvm-0.52.6 \
		windows_aarch64_gnullvm-0.53.1 \
		windows_aarch64_msvc-0.52.6 \
		windows_aarch64_msvc-0.53.1 \
		windows_i686_gnu-0.52.6 \
		windows_i686_gnu-0.53.1 \
		windows_i686_gnullvm-0.52.6 \
		windows_i686_gnullvm-0.53.1 \
		windows_i686_msvc-0.52.6 \
		windows_i686_msvc-0.53.1 \
		windows_x86_64_gnu-0.52.6 \
		windows_x86_64_gnu-0.53.1 \
		windows_x86_64_gnullvm-0.52.6 \
		windows_x86_64_gnullvm-0.53.1 \
		windows_x86_64_msvc-0.52.6 \
		windows_x86_64_msvc-0.53.1 \
		winnow-1.0.4 \
		winresource-0.1.31 \
		winsafe-0.0.29 \
		wit-bindgen-0.57.1 \
		wnaf-0.14.1 \
		write16-1.0.0 \
		writeable-0.6.4 \
		x11-dl-2.21.0 \
		x11rb-0.13.2 \
		x11rb-protocol-0.13.2 \
		xcursor-0.3.11 \
		xkbcommon-dl-0.4.2 \
		xkeysym-0.2.1 \
		xml-rs-0.8.29 \
		xmlwriter-0.1.0 \
		yoke-0.8.3 \
		yoke-derive-0.8.4 \
		zbus-5.19.0 \
		zbus-lockstep-0.5.2 \
		zbus-lockstep-macros-0.5.2 \
		zbus_macros-5.19.0 \
		zbus_names-4.3.4 \
		zbus_xml-5.2.1 \
		zcheapstr-1.1.0 \
		zerocopy-0.8.59 \
		zerocopy-derive-0.8.59 \
		zerofrom-0.1.8 \
		zerofrom-derive-0.1.8 \
		zeroize-1.9.0 \
		zerotrie-0.2.5 \
		zerovec-0.11.8 \
		zerovec-derive-0.11.6 \
		zlib-rs-0.6.8 \
		zmij-1.0.23 \
		zune-core-0.5.3 \
		zune-jpeg-0.5.15 \
		zvariant-5.15.0 \
		zvariant_derive-5.15.0 \
		zvariant_utils-4.2.0

# The workspace also holds the web front end and xtask: build only the
# desktop application and the command line tool, and install them from
# the target directory instead of running cargo install once per crate.
CARGO_BUILD_ARGS=	--package pdfcraft --package pdfcraft-cli
CARGO_INSTALL=	no

# Digital signatures use aws-lc-rs.  Always build the bundled AWS-LC (with
# cc, no cmake needed) instead of linking whatever AWS-LC or OpenSSL
# installation aws-lc-sys happens to detect on the build host.
CARGO_ENV+=	AWS_LC_SYS_USE_SYSTEM=0

# The LTO the framework enables for cargo ports also sets panic=abort, but
# PdfCraft relies on unwinding: opening a damaged document and running an
# engine command happen under catch_unwind, so that a panic is reported as
# an error instead of taking the application, and the unsaved document,
# down with it.  LTO_UNSAFE adds -C lto=no to RUSTFLAGS, so also turn off
# the workspace's own thin LTO: otherwise cargo builds the dependencies as
# LLVM bitcode only and the bitcode reaches the base system linker, whose
# LLVM cannot read it.
LTO_UNSAFE=	yes
CARGO_ENV+=	CARGO_PROFILE_RELEASE_LTO=false

# The OCR models are not archives.
EXTRACT_ONLY=	${_DISTFILES:N*.rten}

APP_ID=		ai.storyteller.pdfcraft
# Release date of ${DISTVERSION}, for the AppStream metadata.
RELEASE_DATE=	2026-10-10
ICON_SIZES=	16 24 32 48 64 128 256 512

PORTDOCS=	README.md

OPTIONS_DEFINE=		CRAFTFONTS DOCS OCR
OPTIONS_DEFAULT=	CRAFTFONTS OCR
OPTIONS_SUB=		yes

CRAFTFONTS_DESC=	Embed the Japanese and Arabic craft-fonts
OCR_DESC=		Text recognition (Scan & OCR) with the ocrs models

# The commit upstream's release builds embed.
CRAFTFONTS_GH_TUPLE=	storytold:craft-fonts:8dcdacd5153e64560d109541a47d806f26f048c0:fonts
CRAFTFONTS_MAKE_ENV=	CRAFT_FONTS_DIR=${WRKSRC_fonts} \
			CRAFT_FONTS_REQUIRED=1

# The models upstream's release packages ship (ATTRIBUTION.toml, "kind =
# model"); the application looks for them in ${DATADIR}/models.  The
# files are not versioned upstream, so keep them in a subdirectory.
OCR_MASTER_SITES=	https://ocrs-models.s3-accelerate.amazonaws.com/text-detection.rten?dummy=/:ocrdet \
			https://ocrs-models.s3-accelerate.amazonaws.com/text-recognition.rten?dummy=/:ocrrec
OCR_DISTFILES=		ocrs-models/text-detection.rten:ocrdet \
			ocrs-models/text-recognition.rten:ocrrec
OCR_VARS=		LICENSE+=CC-BY-SA-4.0

do-install:
.for b in pdfcraft pdfcraft-cli
	${INSTALL_PROGRAM} ${CARGO_TARGET_DIR}/${WITH_DEBUG:Ddebug:Urelease}/${b} \
		${STAGEDIR}${PREFIX}/bin
.endfor
	@${MKDIR} ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/packaging/linux/${APP_ID}.desktop \
		${STAGEDIR}${DESKTOPDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/mime/packages
	${INSTALL_DATA} ${WRKSRC}/packaging/linux/${APP_ID}.mime.xml \
		${STAGEDIR}${PREFIX}/share/mime/packages/${APP_ID}.xml
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/metainfo
	${SED} -e 's|@VERSION@|${DISTVERSION}|g' \
		-e 's|@DATE@|${RELEASE_DATE}|g' \
		${WRKSRC}/packaging/linux/${APP_ID}.metainfo.xml.in > \
		${STAGEDIR}${PREFIX}/share/metainfo/${APP_ID}.metainfo.xml
.for s in ${ICON_SIZES}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps
	${INSTALL_DATA} ${WRKSRC}/assets/app-icon/hicolor/${s}x${s}/apps/${APP_ID}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/assets/app-icon/hicolor/scalable/apps/${APP_ID}.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
# The attribution and notice files carry the third-party licence notices.
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ATTRIBUTION.md ${WRKSRC}/NOTICE \
		${STAGEDIR}${DOCSDIR}

post-install-DOCS-on:
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install-OCR-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}/models
	${INSTALL_DATA} ${DISTDIR}/ocrs-models/text-detection.rten \
		${DISTDIR}/ocrs-models/text-recognition.rten \
		${STAGEDIR}${DATADIR}/models

.include <bsd.port.mk>
