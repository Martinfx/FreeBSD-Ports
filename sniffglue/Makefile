PORTNAMES=	sniffglue
DISTVERSIONPREFIX= v
DISTVERSION=    0.13.1
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

do-build:
#	cd ${WRKSRC} && cargo build --release --verbose
	@${CARGO_CARGO_RUN} cbuild \
		--verbose \
		${CARGO_BUILD_ARGS}

.include <bsd.port.mk>
