PORTNAME=	openusd
DISTVERSIONPREFIX=	v
DISTVERSION=	26.05
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Universal Scene Description is a scene description management system
WWW=		http://www.openusd.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	CMakeLists.txt fails for non-64-bit architectures: Compiler does not support 64-bit builds; also: pxr/base/arch/defines.h:69:2: error: "Unsupported architecture.  x86_64 or ARM64 required."

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR}
LIB_DEPENDS=	libAlembic.so:graphics/alembic \
		libtbb.so:devel/onetbb \
		libImath-3_2.so:math/Imath \
		libMaterialXGenMsl.so:graphics/materialx \
		libMaterialXRenderGlsl.so:graphics/materialx \
		libMaterialXGenGlsl.so:graphics/materialx \
		libMaterialXRenderHw.so:graphics/materialx \
		libMaterialXRender.so:graphics/materialx \
		libMaterialXGenShader.so:graphics/materialx \
		libMaterialXFormat.so:graphics/materialx \
		libMaterialXCore.so:graphics/materialx
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR}

USES=		cmake python
USE_XORG=	xt
USE_GITHUB=	yes
GH_ACCOUNT=	PixarAnimationStudios
GH_PROJECT=	OpenUSD
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DMaterialX_DIR:STRING=${LOCALBASE}/lib/cmake/MaterialX \
		-DMATERIALX_STDLIB_DIR:STRING=${LOCALBASE}/share/MaterialX \
		-DMATERIALX_PYTHON_DIR:STRING=${PYTHON_SITELIBDIR}/MaterialX
CMAKE_ON=	PXR_ENABLE_PYTHON_SUPPORT PXR_ENABLE_MATERIALX_SUPPORT \
		PXR_BUILD_ALEMBIC_PLUGIN
CMAKE_OFF=	PXR_BUILD_EXAMPLES PXR_BUILD_TESTS PXR_BUILD_TUTORIALS

OPTIONS_DEFINE=		IMAGING MONOLITHIC TOOLS
OPTIONS_DEFAULT=	IMAGING MONOLITHIC TOOLS
OPTIONS_SUB=		yes

IMAGING_DESC=		Build imaging components
MONOLITHIC_DESC=	Build a monolithic library (required for blender)
TOOLS_DESC=		Build commandline tools

IMAGING_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}PyOpenGL>0:graphics/py-PyOpenGL@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pyside6-tools>0:devel/pyside6-tools@${PY_FLAVOR}
IMAGING_LIB_DEPENDS=	libosdCPU.so:graphics/opensubdiv \
			libosdGPU.so:graphics/opensubdiv
IMAGING_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}PyOpenGL>0:graphics/py-PyOpenGL@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pyside6>0:devel/pyside6@${PY_FLAVOR}
IMAGING_USES=		gl xorg
IMAGING_USE=		GL=gl \
			XORG=ice,sm,x11,xext
IMAGING_CMAKE_BOOL=	PXR_BUILD_IMAGING
# usdview: devel/pyside6-tools installs uic, but not the pyside6-uic wrapper
IMAGING_CMAKE_ON=	-DPTEX_INCLUDE_DIR=${LOCALBASE}/include \
			-DPYSIDEUICBINARY:FILEPATH=${LOCALBASE}/PySide6/bin/uic

MONOLITHIC_CMAKE_BOOL=	PXR_BUILD_MONOLITHIC

TOOLS_CMAKE_BOOL=	PXR_BUILD_USD_TOOLS

post-install:
# The Python bindings are installed into ${PREFIX}/lib/python/pxr, which is
# not in sys.path; without this usdview and "from pxr import Usd" fail.
	${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	${ECHO_CMD} ${PREFIX}/lib/python > ${STAGEDIR}${PYTHON_SITELIBDIR}/openusd.pth

# The tests use absolute ${PREFIX} paths (e.g. PYTHONPATH=${PREFIX}/lib/python)
# and the binaries have ${PREFIX}/lib in their RPATH, so the package has to be
# installed and the staged libraries have to take precedence.  The imaging
# tests need an X display with GL, e.g. Xvfb from x11-servers/xorg-server@xvfb.
TEST_ENV=	${MAKE_ENV} \
		DISPLAY=${DISPLAY} \
		XAUTHORITY=${XAUTHORITY} \
		LD_LIBRARY_PATH=${STAGEDIR}${PREFIX}/lib:${LOCALBASE}/lib \
		PXR_PLUGINPATH_NAME=${STAGEDIR}${PREFIX}/plugin/usd:${STAGEDIR}${PREFIX}/lib/usd

do-test: install # tests are expected to be installed, see https://github.com/PixarAnimationStudios/USD/issues/1707
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} \
			-DPXR_BUILD_TESTS=ON -DPYTHON_EXECUTABLE=${PYTHON_CMD} ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} install && \
		${FIND} ${BUILD_WRKSRC} -name CTestTestfile.cmake -type f -exec \
			${REINPLACE_CMD} -e 's|${PREFIX}/tests|${STAGEDIR}${PREFIX}/tests|g' {} + && \
		${SETENV} ${TEST_ENV} ctest -C ${CMAKE_BUILD_TYPE} ${_MAKE_JOBS} --output-on-failure

.include <bsd.port.mk>
