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

OPTIONS_DEFINE=		DRACO EMBREE IMAGING MONOLITHIC OCIO OIIO OPENVDB OSL \
			PTEX TOOLS
OPTIONS_DEFAULT=	DRACO EMBREE IMAGING MONOLITHIC OCIO OIIO OPENVDB OSL \
			PTEX TOOLS
OPTIONS_EXCLUDE_aarch64=	EMBREE # graphics/embree is amd64/i386 only
OPTIONS_SUB=		yes

DRACO_DESC=		Draco mesh compression file format plugin
EMBREE_DESC=		Embree ray tracing Hydra render delegate
IMAGING_DESC=		Build imaging components
MONOLITHIC_DESC=	Build a monolithic library (required for blender)
OCIO_DESC=		OpenColorIO color management in Hydra
OIIO_DESC=		OpenImageIO image reading and writing plugin
OPENVDB_DESC=		OpenVDB volume support
OSL_DESC=		OpenShadingLanguage shader parser plugin
PTEX_DESC=		Ptex texture support
TOOLS_DESC=		Build commandline tools

DRACO_LIB_DEPENDS=	libdraco.so:archivers/draco
DRACO_CMAKE_BOOL=	PXR_BUILD_DRACO_PLUGIN

EMBREE_IMPLIES=		IMAGING
EMBREE_LIB_DEPENDS=	libembree4.so:graphics/embree
EMBREE_CMAKE_BOOL=	PXR_BUILD_EMBREE_PLUGIN

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
IMAGING_CMAKE_ON=	-DPYSIDEUICBINARY:FILEPATH=${LOCALBASE}/PySide6/bin/uic

MONOLITHIC_CMAKE_BOOL=	PXR_BUILD_MONOLITHIC

OCIO_IMPLIES=		IMAGING
OCIO_LIB_DEPENDS=	libOpenColorIO.so:graphics/opencolorio
OCIO_CMAKE_BOOL=	PXR_BUILD_OPENCOLORIO_PLUGIN

OIIO_IMPLIES=		IMAGING
OIIO_LIB_DEPENDS=	libOpenImageIO.so:graphics/openimageio
OIIO_CMAKE_BOOL=	PXR_BUILD_OPENIMAGEIO_PLUGIN

OPENVDB_IMPLIES=	IMAGING
OPENVDB_BUILD_DEPENDS=	${LOCALBASE}/include/boost/version.hpp:devel/boost-libs
OPENVDB_LIB_DEPENDS=	libopenvdb.so:misc/openvdb
OPENVDB_CMAKE_BOOL=	PXR_ENABLE_OPENVDB_SUPPORT

OSL_LIB_DEPENDS=	libOpenImageIO.so:graphics/openimageio \
			liboslquery.so:graphics/openshadinglanguage
OSL_CMAKE_BOOL=		PXR_ENABLE_OSL_SUPPORT

PTEX_IMPLIES=		IMAGING
PTEX_LIB_DEPENDS=	libPtex.so:graphics/ptex
PTEX_CMAKE_BOOL=	PXR_ENABLE_PTEX_SUPPORT

TOOLS_CMAKE_BOOL=	PXR_BUILD_USD_TOOLS

post-install:
# The Python bindings are installed into ${PREFIX}/lib/python/pxr, which is
# not in sys.path; without this usdview and "from pxr import Usd" fail.
	${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	${ECHO_CMD} ${PREFIX}/lib/python > ${STAGEDIR}${PYTHON_SITELIBDIR}/openusd.pth

# The tests refer to ${PREFIX} (tests, tools, PYTHONPATH=${PREFIX}/lib/python)
# and the binaries have ${PREFIX}/lib in their RUNPATH, so point all of that at
# the staged build.  The imaging tests need an X display with GL, e.g. Xvfb
# from x11-servers/xorg-server@xvfb.
TEST_ENV=	${MAKE_ENV} \
		DISPLAY=${DISPLAY} \
		XAUTHORITY=${XAUTHORITY} \
		LD_LIBRARY_PATH=${STAGEDIR}${PREFIX}/lib:${LOCALBASE}/lib
# The imaging tests compare their renders with baselines made on Pixar's
# reference GPU, which other GPUs and drivers do not match exactly.  The
# comparisons are only done with IMAGE_DIFF_TOOL set, e.g. to
# ${LOCALBASE}/bin/idiff from graphics/openimageio.
IMAGE_DIFF_TOOL?=
# these expect write-protected files and directories (e.g. /etc) not to be
# writable, which is never the case for root, so they are skipped as root
TESTS_FAILING_AS_ROOT=	TfAtomicOfstreamWrapper TfFileUtils TfSafeOutputFile \
			testUsdEditFilePermissions1 testUsdUtilsStitchClips

do-test: # tests are expected to be installed, see https://github.com/PixarAnimationStudios/USD/issues/1707
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} \
			-DPXR_BUILD_TESTS=ON -DPYTHON_EXECUTABLE=${PYTHON_CMD} \
			-DIMAGE_DIFF_TOOL:STRING=${IMAGE_DIFF_TOOL} ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} install && \
		${FIND} ${BUILD_WRKSRC} -name CTestTestfile.cmake -type f -exec \
			${REINPLACE_CMD} -e 's|${PREFIX}/bin/python|@PYTHON@|g' \
				-e 's|${PREFIX}/bin|${STAGEDIR}${PREFIX}/bin|g' \
				-e 's|@PYTHON@|${PREFIX}/bin/python|g' \
				-e 's|${PREFIX}/lib/python|${STAGEDIR}${PREFIX}/lib/python|g' \
				-e 's|${PREFIX}/share/usd|${STAGEDIR}${PREFIX}/share/usd|g' \
				-e 's|${PREFIX}/tests|${STAGEDIR}${PREFIX}/tests|g' {} + && \
		if [ ${UID} -eq 0 ]; then \
			${ECHO_MSG} "===>   Running as root, skipping ${TESTS_FAILING_AS_ROOT:u}"; \
			set -- -E "^(${TESTS_FAILING_AS_ROOT:ts|})$$"; \
		fi && \
		${SETENV} ${TEST_ENV} ctest -C ${CMAKE_BUILD_TYPE} ${_MAKE_JOBS} --output-on-failure "$$@"

.include <bsd.port.mk>
