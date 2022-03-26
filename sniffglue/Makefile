PORTNAMES=	sniffglue
DISTVERSIONPREFIX= v
DISTVERSION=    0.12.0
CATEGORIES=	devel


MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Secure multithreaded packet sniffer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cargo-cbuild:devel/cargo-c

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT= kpcyrd
GH_PROJECT= sniffglue

CARGO_CRATES= ansi_term-0.12.1 \
	      anyhow-1.0.35 \
	      atty-0.2.14 \
	      base64-0.13.0 \
	      bstr-0.2.17 \
	      dhcp4r-0.2.3 \
	      dirs-next-2.0.0 \
	      dns-parser-0.8.0 \
	      env_logger-0.8.0 \
	      libc-0.2.121 \
	      log-0.4.16 \
	      nix-0.20.0 \
	      nom-7.0.0 \
	      num_cpus-1.13.1 \
	      pcap-sys-0.1.3 \
	      pktparse-0.5.0 \
	      reduce-0.1.4 \
	      serde-1.0.136 \
	      serde_derive-1.0.136 \
	      serde_json-1.0.79 \
	      sha2-0.9.0 \
	      structopt-0.3.26 \
	      tls-parser-0.10.0 \
	      toml-0.5.8 \
	      users-0.11.0 \
	      boxxy-0.11.0 \
	      syscallz-0.15.0 \
	      winapi-0.3.9 \
	      hermit-abi-0.1.6 \
	      lazy_static-1.4.0 \
	      memchr-2.4.1 \
	      regex-automata-0.1.5 \
	      enum-primitive-derive-0.2.2 \
	      num-traits-0.2.14 \
	      cfg-if-1.0.0 \
	      dirs-sys-next-0.1.2 \
	      byteorder-1.4.3 \
	      quick-error-1.0.0 \
	      humantime-2.1.0 \
	      regex-1.5.5 \
	      termcolor-1.1.3 \
	      bitflags-1.3.2 \
	      memoffset-0.6.5 \
	      cc-1.0.73 \
	      minimal-lexical-0.2.1 \
	      pkg-config-0.3.24 \
	      proc-macro2-1.0.36 \
	      quote-1.0.17 \
	      syn-1.0.89 \
	      itoa-1.0.1 \
	      ryu-1.0.9 \
	      digest-0.10.3 \
	      cpufeatures-0.2.2 \
	      clap-2.33.0 \
	      structopt-derive-0.4.18 \
	      enum_primitive-0.1.1 \
	      nom-derive-0.10.0 \
	      phf-0.10.1 \
	      rusticata-macros-4.1.0 \
	      phf_codegen-0.10.0 \
	      bufstream-0.1.4 \
	      errno-0.2.8

do-build:
#	cd ${WRKSRC} && cargo build --release --verbose
	@${CARGO_CARGO_RUN} cbuild \
		--verbose \
		--workspace
		${CARGO_BUILD_ARGS}

do-install:
	@${CARGO_CARGO_RUN} cinstall \
		--verbose \
		--verbose \
		--destdir "${STAGEDIR}" \
		--prefix "${PREFIX}" \
		${CARGO_INSTALL_ARGS}

.include <bsd.port.mk>
