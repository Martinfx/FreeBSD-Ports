PORTNAME=	libredefender
DISTVERSIONPREFIX=      v
DISTVERSION=    0.6.0
CATEGORIES=     security

MAINTAINER=     freebsd@sysctl.cz
COMMENT=        libredefender is an antivirus

LICENSE=        GPLv2
LICENSE_FILE=   ${WRKSRC}/LICENSE-GPL2

BUILD_DEPENDS=  cargo-cbuild:devel/cargo-c

USES=           cargo
USE_GITHUB=     yes
GH_ACCOUNT=     kpcyrd
GH_PROJECT=     libredefender

CARGO_CRATES=	anyhow-1.0.40 \
		atoi-1.0.0 \
		atty-0.2.14 \
		async-trait-0.1.57 \
		battery-0.7.0 \
		bitflags-1.2.1 \
		chrono-0.4.19 \
		chrono-humanize-0.2.1 \
		clamav-rs-0.5.3 \
		clamav-sys-0.0.3 \
		clamav-sys-0.0.5 \
		colored-2.0.0 \
		config-0.13.0 \
		cfg-if-1.0.0 \
		cfg-if-0.1.0 \
		crossbeam-utils-0.8.11 \
		crossbeam-channel-0.5.1 \
		core-foundation-0.6.3 \
		core-foundation-0.7.0 \
		dirs-4.0.0 \
		dirs-sys-0.3.7 \
		env_logger-0.9.0 \
        	glob-0.3.0 \
        	humantime-2.1.0 \
        	human-size-0.4.1 \
		ioprio-0.2.0 \
		libc-0.2.94 \
		lazycell-1.3.0 \
		lazy_static-1.4.0 \
		log-0.4.14 \
		memchr-2.4.0 \
		mach-0.2.3 \
		mach-0.3.2 \
		pathdiff-0.2.1 \
		time-0.3.14 \
		time-0.1.44 \
		toml-0.5.9 \
		tempfile-3.3.0 \
		notify-rust-4.5.2 \
		num-format-0.4.0 \
		num_cpus-1.13.0 \
		num-traits-0.2.15 \
		num-integer-0.1.45 \
		nix-0.13.0 \
		nix-0.19.1 \
                nix-0.21.2 \
                nix-0.23.1 \
                nom-5.1.2 \
                nom-7.1.1 \
		uom-0.21.1 \
		rand-0.8.3 \
		serde-1.0.125 \
		serde_json-1.0.64\
		structopt-0.3.21\
		v_htmlescape-0.15.0\
		walkdir-2.3.2 \
		winapi-0.3.9 

.include <bsd.port.mk>
