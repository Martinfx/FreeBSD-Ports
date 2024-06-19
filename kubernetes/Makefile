PORTNAME=	kubernetes
DISTVERSIONPREFIX=v
DISTVERSION=	1.30.2
CATEGORIES=	devel

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Production-Grade Container Scheduling and Management.
WWW=		kubernetes.io

LICENSE=	APACHE20
LICENSE_FILE=   ${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash>0:shells/bash \
		coreutils>0:sysutils/coreutils \
		go122>0:lang/go122

USES=		gmake
USE_GITHUB=     yes
GH_ACCOUNT=     kubernetes
GH_PROJECT=     kubernetes

GO_CMD=		${LOCALBASE}/bin/go/go122

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/_output/local/go/bin ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
