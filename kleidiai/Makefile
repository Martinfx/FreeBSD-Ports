PORTNAME=	kleidiai
DISTVERSIONPREFIX=v
DISTVERSION=	1.14.0
DISTVERSIONSUFFIX=-r2
CATEGORIES=	devel

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	KleidiAI is an open-source library that provides optimized performance-critical routines.
WWW=		https://github.com/ARM-software/kleidiai

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSES/Apache-2.0.txt

BUILD_DEPENDS=	googletest>0:devel/googletest

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	ARM-software
GH_PROJECT=	kleidiai
GH_TAGNAME=	bd2e6ae

CMAKE_OFF=	KLEIDIAI_BUILD_TESTS

.include <bsd.port.mk>
