PORTNAME=	seastar
DISTVERSION=	20.05.0
CATEGORIES=	devel

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	SeaStar is an event-driven framework allowing you to write non-blocking, asynchronous code.

WWW=		https://seastar.io/
LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

#BUILD_DEPENDS=	dpdk-20.11:net/dpdk-20.11
LIB_DEPENDS=	libcryptopp.so:security/cryptopp \
		libfmt.so:devel/libfmt \
		libhwloc.so.15:devel/hwloc2
USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	scylladb
GH_PROJECT=	seastar
GH_TAGNAME=	5a68003

.include <bsd.port.mk>
