PORTNAME=	spirv-reflect
DISTVERSIONPREFIX=vulkan-sdk-
DISTVERSION=	1.3.283.0
CATEGORIES=	devel

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	SPIRV-Reflect is a lightweight library that provides a C/C++ reflection API.
WWW=		https://github.com/KhronosGroup/spirv-reflect

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	KhronosGroup
GH_PROJECT=	SPIRV-Reflect
GH_TUPLE=	google:googletest:e2239ee:googletest/third_party/googletest

CMAKE_ON=	SPIRV_REFLECT_STATIC_LIB

SPIRV_BINS=	spirv-reflect	spirv-reflect-pp

do-install:
	@cd ${WRKSRC} && cp -v spirv_reflect.h ${STAGEDIR}${PREFIX}/include
	@cd ${WRKDIR}/.build && cp -v libspirv-reflect-static.a ${STAGEDIR}${PREFIX}/lib
.for b in ${SPIRV_BINS}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${b} ${STAGEDIR}${PREFIX}/bin
.endfor

.include <bsd.port.mk>
