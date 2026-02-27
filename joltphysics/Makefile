PORTNAME=       joltphysics
DISTVERSIONPREFIX=v
DISTVERSION=    5.0.0
CATEGORIES=     devel

MAINTAINER=     freebsd@sysctl.cz
COMMENT=        A multi core friendly rigid body \
                physics and collision detection library.
WWW=		https://jrouwe.github.io/JoltPhysics/

LICENSE=        MIT
LICENSE_FILE=   ${WRKSRC}/LICENSE

USES=           cmake:insource

USE_GITHUB=     yes
GH_ACCOUNT=     jrouwe
GH_PROJECT=     JoltPhysics

CMAKE_ARGS=     -DTARGET_UNIT_TESTS=OFF \
		-DTARGET_HELLO_WORLD=OFF \
		-DTARGET_PERFORMANCE_TEST=OFF

CMAKE_SOURCE_PATH="${WRKSRC}/Build"

do-install:
	${INSTALL_DATA}	${WRKSRC}/Jolt/*.h ${STAGEDIR}${PREFIX}/include/Jolt
	${INSTALL_LIB} ${WRKSRC}/libJolt.a ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
