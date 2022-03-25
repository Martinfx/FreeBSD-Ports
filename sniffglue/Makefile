PORTNAMES=	sniffglue
DISTVERSIONPREFIX= v
DISTVERSION=    0.15.0
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
	      dns-parser-0.8.0

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
