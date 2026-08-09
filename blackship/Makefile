PORTNAME=	blackship
DISTVERSIONPREFIX=v
DISTVERSION=	0.1.6
CATEGORIES=	sysutils

MAINTAINER=	freebsd@seuros.com
COMMENT=	FreeBSD jail manager with state machine control
WWW=		https://github.com/seuros/blackship

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	seuros
GH_TAGNAME=	fae2c2d

CARGO_CRATES=	adler2-2.0.1 \
		allocator-api2-0.2.21 \
		anstream-1.0.0 \
		anstyle-1.0.14 \
		anstyle-parse-1.0.0 \
		anstyle-query-1.1.5 \
		anstyle-wincon-3.0.11 \
		base64-0.22.1 \
		bitflags-1.3.2 \
		bitflags-2.13.0 \
		block-buffer-0.12.1 \
		breaker-machines-0.15.0 \
		byteorder-1.5.0 \
		bytes-1.12.1 \
		cc-1.2.67 \
		cfg-if-1.0.4 \
		cfg_aliases-0.2.1 \
		chacha20-0.10.1 \
		chrono-machines-0.4.0 \
		clap-4.6.1 \
		clap_builder-4.6.0 \
		clap_complete-4.6.7 \
		clap_derive-4.6.1 \
		clap_lex-1.1.0 \
		colorchoice-1.0.5 \
		const-oid-0.10.2 \
		cpufeatures-0.3.0 \
		crc32fast-1.5.0 \
		crypto-common-0.2.2 \
		defmt-1.1.1 \
		defmt-macros-1.1.1 \
		defmt-parser-1.0.0 \
		digest-0.11.3 \
		equivalent-1.0.2 \
		errno-0.3.14 \
		filetime-0.2.29 \
		find-msvc-tools-0.1.9 \
		fixedbitset-0.5.7 \
		flate2-1.1.9 \
		foldhash-0.1.5 \
		getrandom-0.2.17 \
		getrandom-0.4.3 \
		hashbrown-0.15.5 \
		hashbrown-0.17.1 \
		heck-0.5.0 \
		hex-0.4.3 \
		http-1.4.2 \
		httparse-1.10.1 \
		hybrid-array-0.4.13 \
		indexmap-2.14.0 \
		ipnet-2.12.0 \
		is_terminal_polyfill-1.70.2 \
		itoa-1.0.18 \
		jiff-0.2.32 \
		jiff-static-0.2.32 \
		jiff-tzdb-0.1.8 \
		jiff-tzdb-platform-0.1.3 \
		jobserver-0.1.35 \
		libc-0.2.186 \
		linux-raw-sys-0.12.1 \
		log-0.4.33 \
		lzma-sys-0.1.20 \
		memchr-2.8.3 \
		miniz_oxide-0.8.9 \
		mio-1.2.2 \
		nix-0.31.3 \
		nom-8.0.0 \
		once_cell-1.21.4 \
		once_cell_polyfill-1.70.2 \
		percent-encoding-2.3.2 \
		petgraph-0.8.3 \
		pin-project-lite-0.2.17 \
		pkg-config-0.3.33 \
		portable-atomic-1.13.1 \
		portable-atomic-util-0.2.7 \
		proc-macro2-1.0.106 \
		quote-1.0.46 \
		r-efi-6.0.0 \
		rand-0.10.2 \
		rand_core-0.10.1 \
		ring-0.17.14 \
		rustix-1.1.4 \
		rustls-0.23.42 \
		rustls-pki-types-1.15.0 \
		rustls-webpki-0.103.13 \
		serde-1.0.228 \
		serde_core-1.0.228 \
		serde_derive-1.0.228 \
		serde_json-1.0.150 \
		serde_spanned-1.1.1 \
		sha2-0.11.0 \
		shlex-2.0.1 \
		signal-hook-registry-1.4.8 \
		simd-adler32-0.3.10 \
		socket2-0.6.5 \
		spin-0.12.2 \
		state-machines-0.20.1 \
		state-machines-core-0.9.0 \
		state-machines-macro-0.21.0 \
		strsim-0.11.1 \
		subtle-2.6.1 \
		syn-2.0.118 \
		tar-0.4.46 \
		thiserror-2.0.18 \
		thiserror-impl-2.0.18 \
		throttle-machines-0.2.0 \
		tokio-1.52.3 \
		tokio-macros-2.7.0 \
		toml-1.1.3+spec-1.1.0 \
		toml_datetime-1.1.1+spec-1.1.0 \
		toml_parser-1.1.2+spec-1.1.0 \
		toml_writer-1.1.2+spec-1.1.0 \
		typenum-1.20.1 \
		unicode-ident-1.0.24 \
		untrusted-0.9.0 \
		ureq-3.3.0 \
		ureq-proto-0.6.0 \
		utf8-zero-0.8.1 \
		utf8parse-0.2.2 \
		wasi-0.11.1+wasi-snapshot-preview1 \
		webpki-roots-1.0.8 \
		windows-link-0.2.1 \
		windows-sys-0.52.0 \
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
		winnow-1.0.4 \
		xattr-1.6.1 \
		xz2-0.1.7 \
		zeroize-1.9.0 \
		zmij-1.0.23 \
		zstd-0.13.3 \
		zstd-safe-7.2.4 \
		zstd-sys-2.0.16+zstd.1.5.7


SUB_FILES=	pkg-message
SUB_LIST=	ETCDIR=${ETCDIR}

PLIST_FILES=	bin/blackship \
		"@sample ${ETCDIR}/blackship.toml.sample"

PLIST_DIRS=	${ETCDIR}

USE_RC_SUBR=	blackship_warden

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/blackship
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${FILESDIR}/blackship.toml.sample ${STAGEDIR}${ETCDIR}/

.include <bsd.port.mk>
