# $FreeBSD$

PORTNAME=	premake5
DISTVERSIONPREFIX=	v
DISTVERSION=	5.0.0
DISTVERSIONSUFFIX=	-alpha14
CATEGORIES=	devel

MAINTAINER=	maintainer@email.cz
COMMENT=	Build script creation tool

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		gmake
MAKE_ARGS=	CC="${CC}" CXX="${CXX}"

USE_GITHUB=	yes
GH_ACCOUNT=	premake
GH_PROJECT=	premake-core
GH_TAGNAME=	00052e1

PLIST_FILES=	bin/premake5

do-build:
	cd ${WRKSRC} && ${GMAKE} -f Bootstrap.mak bsd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/release/premake5 ${STAGEDIR}${PREFIX}/bin

do-test:
	cd ${WRKSRC}/tests && ./test

.include <bsd.port.mk>
