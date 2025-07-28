PORTNAME=	zathuradbg
DISTVERSION=	1.0
CATEGORIES=	devel

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	An emulation based tool for learning and debugging assembly.
WWW=		https://zathuradbg.github.io/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/boost/regex.hpp:devel/boost-libs \
		capstone>0:devel/capstone \
		keystone>0:devel/keystone \
		nlohmann-json>0:devel/nlohmann-json \
		icicle-cpp>=g20250728:devel/icicle-cpp

LIB_DEPENDS=	libunicorn.so:emulators/unicorn \
		libglfw.so:graphics/glfw

USES=		cmake pkgconfig
USE_GL=		gl glu
USE_GITHUB=	yes
GH_ACCOUNT=	ZathuraDbg
GH_PROJECT=	ZathuraDbg

CMAKE_SOURCE_PATH=	${WRKSRC}/src

.include <bsd.port.mk>
