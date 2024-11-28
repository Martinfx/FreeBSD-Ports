PORTNAME=	cortex
DISTVERSION=	10.5.11.0
CATEGORIES=	graphics

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Libraries for visual effects software development.
WWW=		https://github.com/ImageEngine/cortex

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	alembic>0:graphics/alembic \
		boost-libs>=1.85.0:devel/boost-libs \
		c-blosc>0:archivers/c-blosc \
		tbb>0:devel/tbb \
		freetype2>0:print/freetype2 \
		openimageio>0:graphics/openimageio \
		consolekit2:sysutils/consolekit2 \
		wayland:graphics/wayland
#		usd>0:misc/usd

USES=		python localbase scons
USE_GITHUB=	yes
GH_ACCOUNT=	ImageEngine
GH_PROJECT=	cortex

SCONS_ARGS=	BOOST_INCLUDE_PATH=${LOCALBASE}/include
SCONS_ARGS+=	BOOST_LIB_PATH=${LOCALBASE}/lib
SCONS_ARGS+=	BOOST_LIB_SUFFIX=""
SCONS_ARGS+=	OPENEXR_INCLUDE_PATH=${LOCALBASE}/include
SCONS_ARGS+=	OPENEXR_LIB_PATH=${LOCALBASE}/lib
SCONS_ARGS+=	FREETYPE_INCLUDE_PATH=${LOCALBASE}/include/freetype2
SCONS_ARGS+=	FREETYPE_LIB_PATH=${LOCALBASE}/lib
SCONS_ARGS+=	BLOSC_INCLUDE_PATH=${LOCALBASE}/include
SCONS_ARGS+=	BLOSC_LIB_PATH=${LOCALBASE}/lib
SCONS_ARGS+=	OIIO_INCLUDE_PATH=${LOCALBASE}/include/OpenImageIO
SCONS_ARGS+=	OIIO_LIB_PATH=${LOCALBASE}/lib
SCONS_ARGS+=	TBB_INCLUDE_PATH=${LOCALBASE}/include/tbb
SCONS_ARGS+=	TBB_LIB_PATH=${LOCALBASE}/lib
SCONS_ARGS+=	VDB_INCLUDE_PATH=${LOCALBASE}/include/openvdb
SCONS_ARGS+=	VDB_LIB_PATH=${LOCALBASE}/lib
SCONS_ARGS+=	ALEMBIC_INCLUDE_PATH=${LOCALBASE}/include/Alembic
SCONS_ARGS+=	ALEMBIC_LIB_PATH=${LOCALBASE}/lib
SCONS_ARGS+=	WARNINGS_AS_ERRORS=0
SCONS_ARGS+=	CXXFLAGS="XDG_RUNTIME_DIR=$XDG_RUNTIME_DIR"

.include <bsd.port.pre.mk>

MAKE_ARGS=	${SCONS_ARGS}


.include <bsd.port.post.mk>
