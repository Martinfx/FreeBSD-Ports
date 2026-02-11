PORTNAME=	kleidiai
DISTVERSIONPREFIX=v
DISTVERSION=	1.21.0
CATEGORIES=	devel

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	KleidiAI is an open-source library that provides optimized performance-critical routines.
WWW=		https://github.com/ARM-software/kleidiai

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSES/Apache-2.0.txt

ONLY_FOR_ARCHS=	aarch64

TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	ARM-software
GH_PROJECT=	kleidiai

do-test:
	@cd ${BUILD_WRKSRC} && \
	${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DKLEIDIAI_BUILD_TESTS=ON ${CMAKE_SOURCE_PATH} && \
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
	ctest -C ${CMAKE_BUILD_TYPE} --verbose --output-on-failure


.include <bsd.port.mk>
