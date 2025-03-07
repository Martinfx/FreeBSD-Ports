PORTNAME=	materialx
DISTVERSIONPREFIX=v
DISTVERSION=	1.39.3-rc1
CATEGORIES=	graphics

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	MaterialX is an open standard for the exchange \
		of rich material and look-development content \
		across applications and renderers.
WWW=		http://www.materialx.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	openshadinglanguage>0:graphics/openshadinglanguage \
		openimageio>0:graphics/openimageio \
		libglvnd>0:graphics/libglvnd
LIB_DEPENDS=	libOpenImageIO.so:graphics/openimageio \
		libOpenImageIO_Util.so:graphics/openimageio \
		libImath-3_1.so:math/Imath

USES=		cmake localbase python:3.11+ gl
USE_GL=		gl opengl
USE_XORG=	x11 xt ice sm
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	AcademySoftwareFoundation
GH_PROJECT=	MaterialX
GH_TUPLE=	mitsuba-renderer:nanogui:f5020e2:nanogui/source/MaterialXView/NanoGUI \
		ocornut:imgui:9aae45e:imgui/source/MaterialXGraphEditor/External/ImGui \
		thedmd:imgui-node-editor:2f99b2d:nodeeditor/source/MaterialXGraphEditor/External/ImGuiNodeEditor \
		wjakob:glfw:e130e55:glfw/source/MaterialXView/NanoGUI/ext/glfw \
		wjakob:nanobind:07b4e1f:nanobind/source/MaterialXView/NanoGUI/ext/nanobind \
		wjakob:nanovg:bf2320d:nanovg/source/MaterialXView/NanoGUI/ext/nanovg \
		wjakob:nanovg_metal:075b04f:nanovgmetal/source/MaterialXView/NanoGUI/ext/nanovg_metal

CMAKE_ON+=	MATERIALX_BUILD_SHARED_LIBS \
		MATERIALX_BUILD_PYTHON \
		MATERIALX_BUILD_OIIO \
		MATERIALX_BUILD_VIEWER \
		MATERIALX_BUILD_GRAPH_EDITOR \
		MATERIALX_INSTALL_PYTHON=${STAGEDIR}${PREFIX}
CMAkE_OFF=	MATERIALX_BUILD_TESTS

CMAKE_INSTALL_PREFIX=${STAGEDIR}${PREFIX}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.build/bin/MaterialXGraphEditor ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/.build/bin/MaterialXView ${STAGEDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKDIR}/.build/lib/*.so* ${STAGEDIR}${PREFIX}/lib/
	(cd ${WRKSRC}/resources  && ${COPYTREE_SHARE} . ${STAGEDIR}/${DATADIR}/${PORTNAME})
	(cd ${WRKSRC}/source && ${COPYTREE_SHARE} .  ${STAGEDIR}${PREFIX}/include/${PORTNAME} "-name *.h")

.include <bsd.port.mk>
