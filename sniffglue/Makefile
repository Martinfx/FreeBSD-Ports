PORTNAMES=	sniffglue
DISTVERSIONPREFIX= v
DISTVERSION=    0.13.1
CATEGORIES=	devel


MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Secure multithreaded packet sniffer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=     kpcyrd

do-build:
	@${CARGO_CARGO_RUN} cbuild \
		--verbose \
		--verbose \
		${CARGO_BUILD_ARGS}

.include <bsd.port.mk>
