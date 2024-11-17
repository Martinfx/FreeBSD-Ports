PORTNAME=	zathuradbg
DISTVERSION=	0.2.5-beta
CATEGORIES=	devel

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	An emulation based tool for learning and debugging assembly.
WWW=		https://zathuradbg.github.io/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/boost/regex.hpp:devel/boost-libs \
		capstone>0:devel/capstone \
		keystone>0:devel/keystone \
		nlohmann-json>0:devel/nlohmann-json

LIB_DEPENDS=	libunicorn.so:emulators/unicorn \
		libglfw.so:graphics/glfw

USES=		cmake pkgconfig gl
USE_GCC=	14
USE_GL=		gl glu
USE_GITHUB=	yes
GH_ACCOUNT=	ZathuraDbg
GH_PROJECT=	ZathuraDbg
GH_TAGNAME=	b2de667
GH_TUPLE+=	HACKE-RC:ImGuiColorTextEdit:17b5ae8:imguicolortextedit/vendor/ImGuiColorTextEdit \
		capstone-engine:capstone:e3bc578:capstone/vendor/capstone \
		ocornut:imgui:c71e4e8:imgui/vendor/imgui \
		keystone-engine:keystone:fb92f32:keystone/vendor/keystone \
		Tessil:ordered-map:46adc0e:map/vendor/ordered-map \
		ZathuraDbg:tinyfdialogue:3dc1330:tiny/vendor/tinydialogue \
		unicorn-engine:unicorn:d568885:unicorn/vendor/unicorn \
		gpakosz:whereami:dcb52a0:whereami/vendor/whereami

CMAKE_SOURCE_PATH=	${WRKSRC}/src

.include <bsd.port.mk>
