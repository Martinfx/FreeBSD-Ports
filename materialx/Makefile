PORTNAME=	materialx
DISTVERSIONPREFIX=v
DISTVERSION=	1.38.10
DISTVERSIONSUFFIX=-OpenPBR
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
		libOpenImageIO_Util.so:graphics/openimageio


USES=		cmake localbase python:3.11 pathfix gl
USE_GITHUB=	yes
GH_ACCOUNT=	AcademySoftwareFoundation
GH_PROJECT=	MaterialX
GH_TUPLE+=	mitsuba-renderer:nanogui:f5020e2:nanogui/source/MaterialXView/NanoGUI \
		ocornut:imgui:9aae45e:imgui/source/MaterialXGraphEditor/External/ImGui \
		thedmd:imgui-node-editor:2f99b2d:nodeeditor/source/MaterialXGraphEditor/External/ImGuiNodeEditor \
		wjakob:glfw:e130e55:glfw/source/MaterialXView/NanoGUI/ext/glfw \
		wjakob:nanobind:07b4e1f:nanobind/source/MaterialXView/NanoGUI/ext/nanobind \
		wjakob:nanovg:bf2320d:nanovg/source/MaterialXView/NanoGUI/ext/nanovg \
		wjakob:nanovg_metal:075b04f:nanovgmetal/source/MaterialXView/NanoGUI/ext/nanovg_metal
USE_LDCONFIG=   yes

CMAKE_ARGS+=	-DMATERIALX_BUILD_SHARED_LIBS=ON \
		-DMATERIALX_BUILD_PYTHON=ON \
		-DMATERIALX_BUILD_OIIO=ON \
		-DMATERIALX_BUILD_TESTS=OFF \
		-DMATERIALX_BUILD_VIEWER=ON \
		-DMATERIALX_BUILD_GRAPH_EDITOR=ON \
		-DMATERIALX_INSTALL_PYTHON=${STAGEDIR}${PREFIX} \
		-DMATERIALX_INSTALL_INCLUDE_PATH=${STAGEDIR}${PREFIX}/include \
		-DMATERIALX_INSTALL_LIB_PATH=${STAGEDIR}${PREFIX}/lib \
		-DMATERIALX_INSTALL_STDLIB_PATH=${STAGEDIR}${DATADIR}/materialX/libraries


CMAKE_INSTALL_PREFIX=${STAGEDIR}${PREFIX}

USE_GL=         gl opengl
USE_XORG=       x11 xt ice sm

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.build/bin/MaterialXGraphEditor ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/.build/bin/MaterialXView ${STAGEDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKDIR}/.build/lib/*.so* ${STAGEDIR}${PREFIX}/lib/
#	${MKDIR} ${STAGEDIR}${PREFIX}/lib/cmake/${PORTNAME}
#	${CP} -v ${WRKDIR}/.build/cmake/*.cmake ${STAGEDIR}${PREFIX}/lib/cmake/${PORTNAME}
#	${MKDIR} ${STAGEDIR}${DATADIR}/${PORTNAME}
#	${CP} -vR ${WRKSRC}/resources ${STAGEDIR}${DATADIR}/${PORTNAME}
#	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}/MaterialXCore
#	${CP} -vR ${WRKSRC}/source/MaterialXCore/*.h ${STAGEDIR}${PREFIX}/include/${PORTNAME}/MaterialXCore
#	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}/MaterialXFormat
#	${CP} -vR ${WRKSRC}/source/MaterialXFormat/*.h ${STAGEDIR}${PREFIX}/include/${PORTNAME}/MaterialXFormat
#	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}/MaterialXGenGlsl
#	${CP} -vR ${WRKSRC}/source/MaterialXGenGlsl/*.h ${STAGEDIR}${PREFIX}/include/${PORTNAME}/MaterialXGenGlsl
#	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}/MaterialXGenMdl
#	${CP} -vR ${WRKSRC}/source/MaterialXGenMdl/*.h ${STAGEDIR}${PREFIX}/include/${PORTNAME}/MaterialXGenMdl
#	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}/MaterialXGenMsl
#	${CP} -vR ${WRKSRC}/source/MaterialXGenMsl/*.h ${STAGEDIR}${PREFIX}/include/${PORTNAME}/MaterialXGenMsl
#	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}/MaterialXGenShader
#	${CP} -vR ${WRKSRC}/source/MaterialXGenShader/*.h ${STAGEDIR}${PREFIX}/include/${PORTNAME}/MaterialXGenShader
#	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}/MaterialXRender
#	${CP} -vR ${WRKSRC}/source/MaterialXRender/*.h ${STAGEDIR}${PREFIX}/include/${PORTNAME}/MaterialXRender
#	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}/MaterialXRenderGlsl
#	${CP} -vR ${WRKSRC}/source/MaterialXRenderGlsl/*.h ${STAGEDIR}${PREFIX}/include/${PORTNAME}/MaterialXRenderGlsl
#	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}/MaterialXRenderHw
#	${CP} -vR ${WRKSRC}/source/MaterialXRenderHw/*.h ${STAGEDIR}${PREFIX}/include/${PORTNAME}/MaterialXRenderHw
#	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}/MaterialXRenderOsl
#	${CP} -vR ${WRKSRC}/source/MaterialXRenderOsl/*.h ${STAGEDIR}${PREFIX}/include/${PORTNAME}/MaterialXRenderOsl


.include <bsd.port.mk>
