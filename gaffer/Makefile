PORTNAME=	gaffer
DISTVERSION=	1.7.3.0
CATEGORIES=	graphics

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Node based application for lookdev, lighting and automation
WWW=		https://www.gafferhq.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=		aarch64 amd64
ONLY_FOR_ARCHS_REASON=	depends on graphics/cortex and graphics/openusd

BUILD_DEPENDS=	${GAFFER_PY_DEPENDS} \
		bash:shells/bash \
		inkscape:graphics/inkscape \
		${LOCALBASE}/include/pcg_random.hpp:devel/pcg-cpp \
		${LOCALBASE}/include/pybind11/pybind11.h:devel/pybind11
LIB_DEPENDS=	libboost_regex.so:devel/boost-libs \
		libfmt.so:devel/libfmt \
		libfreetype.so:print/freetype2 \
		libGLEW.so:graphics/glew \
		libIECore.so:graphics/cortex \
		libImath.so:math/Imath \
		libOpenColorIO.so:graphics/opencolorio \
		libOpenEXR.so:graphics/openexr \
		libOpenImageIO.so:graphics/openimageio \
		libopenvdb.so:misc/openvdb \
		libosdCPU.so:graphics/opensubdiv \
		liboslexec.so:graphics/openshadinglanguage \
		libtbb.so:devel/onetbb \
		libusd_ms.so:graphics/openusd \
		${PY_BOOST}
RUN_DEPENDS=	${GAFFER_PY_DEPENDS} \
		${LOCALBASE}/lib/libcmark-gfm.so:textproc/cmark-gfm \
		${LOCALBASE}/share/fonts/bitstream-vera/Vera.ttf:x11-fonts/bitstream-vera \
		${PYTHON_PKGNAMEPREFIX}PyOpenGL>0:graphics/py-PyOpenGL@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyside6>0:devel/pyside6@${PY_FLAVOR} \
		bash:shells/bash

# Python modules that Gaffer imports at startup, which the build itself also
# does to export the nodes implemented as Boxes.
GAFFER_PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}opencolorio>0:graphics/py-opencolorio@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}openimageio>0:graphics/py-openimageio@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR}

USES=		compiler:c++17-lang gl python qt:6 scons shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	GafferHQ
GH_TUPLE=	GafferHQ:resources:0.54.2.0:resources \
		mottosso:Qt.py:1.4.6:qtpy
USE_GL=		gl
USE_QT=		base

SHEBANG_FILES=	bin/gaffer

BINARY_ALIAS=	moc=${MOC} \
		rcc=${RCC}

DESKTOP_ENTRIES="Gaffer" \
		"${COMMENT}" \
		"${PREFIX}/lib/gaffer/graphics/GafferLogoMini.png" \
		"gaffer" \
		"Graphics;3DGraphics;" \
		false

OPTIONS_DEFINE=		CYCLES
OPTIONS_DEFAULT=	CYCLES
OPTIONS_SUB=		yes

CYCLES_DESC=		Cycles renderer (GafferCycles)
# GafferCycles links the static libraries of Cycles and the libraries these
# use, and Cycles needs its resource path in ${LOCALBASE}/share/cycles.
CYCLES_BUILD_DEPENDS=	${LOCALBASE}/share/cycles/cycles_definitions.txt:graphics/cycles
CYCLES_LIB_DEPENDS=	libAlembic.so:graphics/alembic \
			libOpenImageDenoise.so:graphics/oidn \
			libopenpgl.so:graphics/openpgl \
			libpugixml.so:textproc/pugixml \
			libzstd.so:archivers/zstd
CYCLES_RUN_DEPENDS=	${LOCALBASE}/share/cycles/cycles_definitions.txt:graphics/cycles
CYCLES_SUB_LIST=	CYCLES_ROOT="${LOCALBASE}"
CYCLES_SUB_LIST_OFF=	CYCLES_ROOT=""

SUB_FILES=	gaffer.options pkg-message
SUB_LIST=	CXX="${CXX}" \
		CXXFLAGS="${CXXFLAGS}" \
		LDFLAGS="${LDFLAGS}" \
		QT_INCDIR="${LOCALBASE}/${QT_INCDIR_REL}" \
		QT_LIBDIR="${LOCALBASE}/${QT_LIBDIR_REL}" \
		STAGEDIR="${STAGEDIR}" \
		WRKDIR="${WRKDIR}" \
		WRKSRC_resources="${WRKSRC_resources}"

# The SConstruct refuses to run unless Python uses UTF-8 for file IO, oslc
# needs to be told where the OSL port installs stdosl.h, and running Gaffer
# during the build must not leave bytecode behind in the installed tree.
# The icons are rendered by many Inkscape processes in parallel, which abort
# with Gio::DBus::Error when they find a D-Bus session bus and hand their
# work to each other, so keep them off it.
MAKE_ENV+=	DBUS_SESSION_BUS_ADDRESS=disabled: \
		OSL_ROOT=${LOCALBASE}/share/openshadinglanguage \
		PYTHONDONTWRITEBYTECODE=1 \
		PYTHONUTF8=1

GAFFER_ROOT=	${PREFIX}/lib/gaffer
# USES=scons passes CXXFLAGS and LINKFLAGS as single strings, which the
# SConstruct turns into a single (invalid) compiler argument, so all build
# settings are passed through an options file instead.
GAFFER_SCONS=	${SETENV} ${MAKE_ENV} ${SCONS} ${_MAKE_JOBS} \
		OPTIONS=${WRKDIR}/gaffer.options

.include <bsd.port.options.mk>

# graphics/cycles uses Embree on amd64 only (graphics/embree)
.if ${PORT_OPTIONS:MCYCLES} && ${ARCH} == amd64
LIB_DEPENDS+=	libembree4.so:graphics/embree
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		-e 's|%%PYTHON_SITELIBDIR%%|${PYTHON_SITELIBDIR}|g' \
		${WRKSRC}/bin/__private/_gaffer.py

do-build:
# The build runs Gaffer itself (to export the nodes implemented as
# Boxes), and the launcher expects to find Python alongside it.
	@${MKDIR} ${WRKDIR}/build/bin
	${LN} -sf ${PYTHON_CMD} ${WRKDIR}/build/bin/python
	@cd ${WRKSRC} && ${GAFFER_SCONS} build

do-install:
	@cd ${WRKSRC} && ${GAFFER_SCONS} ${INSTALL_TARGET}
	${INSTALL_DATA} ${WRKSRC_qtpy}/Qt.py ${STAGEDIR}${GAFFER_ROOT}/python
	${RLN} ${STAGEDIR}${GAFFER_ROOT}/bin/gaffer ${STAGEDIR}${PREFIX}/bin/gaffer
	${FIND} ${STAGEDIR}${GAFFER_ROOT} -name '*.so' -type f \
		-exec ${STRIP_CMD} {} +
	${STRIP_CMD} ${STAGEDIR}${GAFFER_ROOT}/bin/__private/gaffer
	${PYTHON_CMD} -m compileall -q -d ${GAFFER_ROOT}/python \
		${STAGEDIR}${GAFFER_ROOT}/python

.include <bsd.port.mk>
