PORTNAME=	gaffer
DISTVERSION=	1.5.6.0
CATEGORIES=	graphics

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Gaffer is a node-based application for lookdev, lighting and automation.
WWW=		http://www.gafferhq.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PyOpenGL>0:graphics/py-PyOpenGL@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyside2>0:devel/pyside2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}QtPy>0:devel/py-QtPy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}types-MarkupSafe>0:devel/py-types-MarkupSafe@${PY_FLAVOR} \
		libatomic_ops>0:devel/libatomic_ops \
		bitstream-vera>0:x11-fonts/bitstream-vera \
		boost-libs>=1.85.0:devel/boost-libs \
		blender>0:graphics/blender \
		c-blosc2>0:archivers/c-blosc2 \
		cmark>0:textproc/cmark \
		cortex>0:graphics/cortex \
		cycles>0:graphics/cycles \
		embree>0:graphics/embree \
		expat>0:textproc/expat2 \
		freetype2>0:print/freetype2 \
		glew>0:graphics/glew \
		hdf5>0:science/hdf5 \
		Imath>0:math/Imath \
		inkscape:graphics/inkscape \
		libffi>0:devel/libffi \
		libfmt>0:devel/libfmt \
		libjpeg-turbo>0:graphics/libjpeg-turbo \
		liblz4>0:archivers/liblz4 \
		libraw>0:graphics/libraw \
		minizip-ng>0:archivers/minizip-ng \
		onetbb>0:devel/onetbb \
		openexr>0:graphics/openexr \
		openimageio>0:graphics/openimageio \
		openjpeg>0:graphics/openjpeg \
		openpgl>0:graphics/openpgl \
		openshadinglanguage>0:graphics/openshadinglanguage \
		opensubdiv>0:graphics/opensubdiv \
		openvdb>0:misc/openvdb \
		partio>0:graphics/partio \
		pcg-cpp>0:devel/pcg-cpp \
		png>0:graphics/png \
		pugixml>0:textproc/pugixml \
		pybind11>0:devel/pybind11 \
		pystring>0:devel/pystring \
		webp>0:graphics/webp \
		yaml-cpp>0:devel/yaml-cpp \
		zlib-ng>0:archivers/zlib-ng \
		zstd>0:archivers/zstd
		# usd>0:misc/usd dependent on old tbb

USES=		llvm:min=15,build,run localbase compiler:c++20-lang python:3.11+,env qt:5 scons
USE_QT=		core gui widgets opengl buildtools:build qmake:build
USE_GITHUB=	yes
GH_ACCOUNT=	GafferHQ
GH_PROJECT=	gaffer

SCONS_ARGS=	LOCATE_DEPENDENCY_LIBPATH=${LOCALBASE}/lib \
		LOCATE_DEPENDENCY_SYSTEMPATH=${LOCALBASE}/include
#SCONS_ARGS+=	BOOST_INCLUDE_PATH=${LOCALBASE}/include
#SCONS_ARGS+=	BOOST_LIB_PATH=${LOCALBASE}/lib
SCONS_ARGS+=	BOOST_LIB_SUFFIX="" SPHINX=${LOCALBASE}/bin/sphinx-build \
		INKSCAPE=${LOCALBASE}/bin/inkscape WARNINGS_AS_ERRORS=0 \
		CXXSTD=c++20
#SCONS_ARGS+=	PYTHON=${PYTHON_CMD}
#SCONS_ARGS+=	CXX=${CXX}
#SCONS_ARGS+=	PATH=${PYTHON_CMD}
#SCONS_ARGS+=	CYCLES_ROOT=${LOCALBASE}/bin/cycles

.include <bsd.port.pre.mk>
MAKE_ARGS+=	${SCONS_ARGS}
.include <bsd.port.post.mk>