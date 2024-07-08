PORTNAME=	physx5
DISTVERSIONPREFIX=106-physx-
DISTVERSION=	5.4.0
CATEGORIES=	devel
MASTER_SITES=	http://bootstrap.packman.nvidia.com/:packman
DISTFILES=	packman-common@7.23.1.zip:packman

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	NVIDIA PhysX SDK
WWW=		https://developer.nvidia.com/physx-sdk

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md
#LICENSE_PERMS=  dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

BUILD_DEPENDS=	bash:shells/bash

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	NVIDIA-Omniverse
GH_PROJECT=	PhysX
GH_TAGNAME=	f07ba77

BINARY_ALIAS+=	python3=${PYTHON_CMD}

#do-extract:
#	unzip ${DISTDIR}/packman-common@7.23.1.zip -d /root/.cache/packman/packman-common/7.23.1/

do-build:
	${MKDIR} -p .cache/packman/packman-common/7.23.1/
	unzip ${DISTDIR}/packman-common@7.23.1.zip -d /root/.cache/packman/packman-common/7.23.1
	@cd ${WRKSRC}/physx && ${BASH} ./generate_projects.sh
	@cd ${WRKSRC}/physx/compiler/freebsd-release && gmake


.include <bsd.port.mk>
