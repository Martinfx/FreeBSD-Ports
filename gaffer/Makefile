PORTNAME=	gaffer
DISTVERSION=	1.5.1.0
CATEGORIES=	graphics

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Gaffer is a node-based application \
		for lookdev, lighting and automation.
WWW=		http://www.gafferhq.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=  bitstream-vera>0:x11-fonts/bitstream-vera \
		c-blosc2>0:archivers/c-blosc2 \
		cmark>0:textproc/cmark \
		expat>0:textproc/expat2 \
		freetype2>0:print/freetype2 \
		glew>0:graphics/glew \
		hdf5>0:science/hdf5 \
		libfmt>0:devel/libfmt \
		liblz4>0:archivers/liblz4 \
		libffi>0:devel/libffi \
		libraw>0:graphics/libraw \
		libjpeg-turbo>0:graphics/libjpeg-turbo \
		png>0:graphics/png \
		webp>0:graphics/webp \
		inkscape:graphics/inkscape \
		Imath>0:math/Imath \
		boost-libs>=1.85.0:devel/boost-libs \
		onetbb>0:devel/onetbb \
		minizip-ng>0:archivers/minizip-ng \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}types-MarkupSafe>0:devel/py-types-MarkupSafe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PyOpenGL>0:graphics/py-PyOpenGL@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyside2>0:devel/pyside2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}QtPy>0:devel/py-QtPy@${PY_FLAVOR} \
		embree>0:graphics/embree \
		cycles>0:graphics/cycles \
		openshadinglanguage>0:graphics/openshadinglanguage \
		openexr>0:graphics/openexr \
		openimageio>0:graphics/openimageio \
		openjpeg>0:graphics/openjpeg \
		openpgl>0:graphics/openpgl \
		opensubdiv>0:graphics/opensubdiv \
		openvdb>0:misc/openvdb \
		pcg-cpp>0:devel/pcg-cpp\
		partio>0:graphics/partio \
		pugixml>0:textproc/pugixml \
		pybind11>0:devel/pybind11 \
		pystring>0:devel/pystring \
		yaml-cpp>0:devel/yaml-cpp \
		zlib-ng>0:archivers/zlib-ng \
		zstd>0:archivers/zstd \
		cortex>0:graphics
		# usd>0:misc/usd dependent on old tbb

USES=		python:3.11,env llvm:min=15,build,run localbase scons qt:5
USE_QT=		core
USE_GITHUB=	yes
GH_ACCOUNT=	GafferHQ
GH_PROJECT=	gaffer

SCONS_ARGS=	LOCATE_DEPENDENCY_LIBPATH=${LOCALBASE}/lib
SCONS_ARGS+=	LOCATE_DEPENDENCY_SYSTEMPATH=${LOCALBASE}/include
#SCONS_ARGS+=	BOOST_INCLUDE_PATH=${LOCALBASE}/include
#SCONS_ARGS+=	BOOST_LIB_PATH=${LOCALBASE}/lib
SCONS_ARGS+=	BOOST_LIB_SUFFIX=""
SCONS_ARGS+= 	SPHINX=${LOCALBASE}/bin/sphinx-build
SCONS_ARGS+=	INKSCAPE=${LOCALBASE}/bin/inkscape
SCONS_ARGS+=	WARNINGS_AS_ERRORS=0
SCONS_ARGS+=	CXXSTD=c++17
#SCONS_ARGS+=	PYTHON=${PYTHON_CMD}
#SCONS_ARGS+=	CXX=${CXX}
#SCONS_ARGS+=	PATH=${PYTHON_CMD}
#SCONS_ARGS+=	CYCLES_ROOT=${LOCALBASE}/bin/cycles

.include <bsd.port.pre.mk>
MAKE_ARGS+=	${SCONS_ARGS}
.include <bsd.port.post.mk>