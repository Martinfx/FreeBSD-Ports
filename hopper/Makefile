PORTNAME=	hopper
PORTVERSION=	1.0.0.20261012
CATEGORIES=	security devel

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Interpretative fuzzer for C libraries without fuzz drivers
WWW=		https://github.com/FuzzAnything/Hopper

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	FreeBSD support is only tested on amd64

RUN_DEPENDS=	bash:shells/bash \
		cargo:lang/rust \
		patchelf:sysutils/patchelf

USES=		cargo cmake:indirect llvm:18,build,run ninja:build shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	Martinfx
GH_PROJECT=	Hopper
GH_TAGNAME=	ec4f7da77e5300b5d37bdd5edb4c8b73a8f4b11d
SHEBANG_FILES=	hopper tools/*.sh

CARGO_CRATES=	addr2line-0.25.1 \
		adler2-2.0.1 \
		aho-corasick-1.1.5 \
		ansi_term-0.12.1 \
		anstream-1.0.0 \
		anstyle-1.0.14 \
		anstyle-parse-1.0.0 \
		anstyle-query-1.1.5 \
		anstyle-wincon-3.0.11 \
		atty-0.2.14 \
		autocfg-1.5.1 \
		backtrace-0.3.76 \
		base64-0.13.1 \
		bindgen-0.65.1 \
		bitflags-1.3.2 \
		bitflags-2.13.2 \
		block2-0.6.2 \
		cc-1.6.0 \
		cexpr-0.6.0 \
		cfg-if-1.0.5 \
		cfg_aliases-0.2.2 \
		clang-sys-1.9.1 \
		clap-4.6.7 \
		clap_builder-4.6.7 \
		clap_derive-4.6.7 \
		clap_lex-1.1.1 \
		color-eyre-0.6.5 \
		colorchoice-1.0.5 \
		ctrlc-3.5.2 \
		dispatch2-0.3.1 \
		downcast-rs-1.2.1 \
		dyn-clone-1.0.20 \
		either-1.19.0 \
		errno-0.3.14 \
		eyre-0.6.14 \
		fastrand-2.5.0 \
		find-msvc-tools-0.1.14 \
		findshlibs-0.10.2 \
		flexi_logger-0.22.6 \
		getrandom-0.2.17 \
		getrandom-0.4.3 \
		gimli-0.26.2 \
		gimli-0.32.3 \
		glob-0.3.4 \
		goblin-0.6.1 \
		heck-0.5.0 \
		hermit-abi-0.1.19 \
		home-0.5.12 \
		indenter-0.3.4 \
		is_terminal_polyfill-1.70.2 \
		itoa-1.0.18 \
		lazy_static-1.5.1 \
		lazycell-1.3.0 \
		libc-0.2.190 \
		libloading-0.8.9 \
		linkme-0.3.37 \
		linkme-impl-0.3.37 \
		linux-raw-sys-0.12.1 \
		linux-raw-sys-0.4.15 \
		log-0.4.34 \
		mach2-0.4.3 \
		memchr-2.8.3 \
		memmap-0.7.0 \
		memoffset-0.9.1 \
		minimal-lexical-0.2.1 \
		miniz_oxide-0.8.9 \
		nix-0.31.3 \
		nom-7.1.3 \
		ntapi-0.3.7 \
		num-0.4.3 \
		num-bigint-0.4.8 \
		num-complex-0.4.6 \
		num-integer-0.1.47 \
		num-iter-0.1.46 \
		num-rational-0.4.2 \
		num-traits-0.2.19 \
		num_threads-0.1.7 \
		objc2-0.6.5 \
		objc2-encode-4.1.0 \
		object-0.28.4 \
		object-0.37.3 \
		once_cell-1.21.4 \
		once_cell_polyfill-1.70.2 \
		owo-colors-4.4.0 \
		paste-1.0.15 \
		peeking_take_while-0.1.2 \
		plain-0.2.3 \
		plthook-0.2.2 \
		ppv-lite86-0.2.21 \
		prettyplease-0.2.37 \
		proc-macro2-1.0.107 \
		quote-1.0.47 \
		r-efi-6.0.0 \
		rand-0.8.8 \
		rand_chacha-0.3.1 \
		rand_core-0.6.4 \
		regex-1.13.1 \
		regex-automata-0.4.18 \
		regex-syntax-0.8.11 \
		region-3.0.2 \
		rustc-demangle-0.1.28 \
		rustc-hash-1.1.0 \
		rustix-0.38.44 \
		rustix-1.1.5 \
		rustversion-1.0.23 \
		scroll-0.11.0 \
		scroll_derive-0.11.1 \
		serde-1.0.229 \
		serde_core-1.0.229 \
		serde_derive-1.0.229 \
		serde_json-1.0.151 \
		shlex-1.3.0 \
		shlex-2.0.1 \
		simplelog-0.12.2 \
		strsim-0.11.1 \
		syn-1.0.109 \
		syn-2.0.119 \
		syn-3.0.6 \
		tempfile-3.27.0 \
		termcolor-1.4.1 \
		thiserror-1.0.69 \
		thiserror-impl-1.0.69 \
		time-0.3.9 \
		time-macros-0.2.4 \
		twoway-0.2.2 \
		uds_windows-1.2.1 \
		unchecked-index-0.2.2 \
		unicode-ident-1.0.26 \
		utf8parse-0.2.2 \
		wait-timeout-0.2.1 \
		wasi-0.11.1+wasi-snapshot-preview1 \
		which-4.4.2 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.11 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-link-0.2.1 \
		windows-sys-0.52.0 \
		windows-sys-0.59.0 \
		windows-sys-0.61.2 \
		windows-targets-0.52.6 \
		windows_aarch64_gnullvm-0.52.6 \
		windows_aarch64_msvc-0.52.6 \
		windows_i686_gnu-0.52.6 \
		windows_i686_gnullvm-0.52.6 \
		windows_i686_msvc-0.52.6 \
		windows_x86_64_gnu-0.52.6 \
		windows_x86_64_gnullvm-0.52.6 \
		windows_x86_64_msvc-0.52.6 \
		zerocopy-0.8.61 \
		zerocopy-derive-0.8.61 \
		zmij-1.0.23

CARGO_BUILD_ARGS=	--package hopper-compiler
CARGO_INSTALL=	no

SUB_FILES=	cargo-config.toml hopper.sh pkg-message

HOPPER_CRATES=	hopper-compiler hopper-core hopper-derive hopper-derive-impl \
		hopper-harness

PLIST_FILES=	bin/hopper \
		bin/hopper-clang \
		bin/hopper-clang++

# Upstream does not ship a lockfile.
post-extract:
	${CP} ${FILESDIR}/Cargo.lock ${WRKSRC}/Cargo.lock

post-build:
	@${MKDIR} ${WRKDIR}/llvm-mode
	cd ${WRKDIR}/llvm-mode && ${SETENV} ${CONFIGURE_ENV} \
		CC="${CC}" CXX="${CXX}" ${CMAKE_BIN} -G Ninja \
		-DCMAKE_BUILD_TYPE=Release \
		-DLLVM_DIR=${LLVM_PREFIX}/lib/cmake/llvm \
		${WRKSRC}/hopper-instrument/llvm-mode
	${CMAKE_BIN} --build ${WRKDIR}/llvm-mode

# hopper-compiler builds a fuzzing harness per library at run time with
# "cargo install", so the package ships the harness sources and the
# vendored crates, and points cargo at them through HOPPER_CARGO_CONFIG.
do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/install ${STAGEDIR}${DATADIR}/tools
	${INSTALL_PROGRAM} \
		${CARGO_TARGET_DIR}/release/hopper-compiler \
		${WRKDIR}/llvm-mode/hopper-clang ${STAGEDIR}${DATADIR}/install
	${INSTALL_LIB} ${WRKDIR}/llvm-mode/libHopperPass.so \
		${STAGEDIR}${DATADIR}/install
	${LN} -s hopper-clang ${STAGEDIR}${DATADIR}/install/hopper-clang++
	${INSTALL_SCRIPT} ${WRKSRC}/hopper ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/tools/*.sh ${STAGEDIR}${DATADIR}/tools
	${INSTALL_DATA} ${WRKSRC}/Cargo.toml ${WRKSRC}/Cargo.lock \
		${WRKDIR}/cargo-config.toml ${STAGEDIR}${DATADIR}
.for c in ${HOPPER_CRATES}
	@${MKDIR} ${STAGEDIR}${DATADIR}/${c}
	cd ${WRKSRC}/${c} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/${c}
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}/vendor
	cd ${CARGO_VENDOR_DIR} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/vendor
	${INSTALL_SCRIPT} ${WRKDIR}/hopper.sh ${STAGEDIR}${PREFIX}/bin/hopper
	${RLN} ${STAGEDIR}${DATADIR}/install/hopper-clang \
		${STAGEDIR}${PREFIX}/bin/hopper-clang
	${RLN} ${STAGEDIR}${DATADIR}/install/hopper-clang \
		${STAGEDIR}${PREFIX}/bin/hopper-clang++

post-install:
	@cd ${STAGEDIR}${PREFIX} && ${FIND} ${DATADIR_REL} -not -type d | \
		${SORT} >> ${TMPPLIST}

.include <bsd.port.mk>
