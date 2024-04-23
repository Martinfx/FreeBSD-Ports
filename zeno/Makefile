PORTNAME=	zeno
DISTVERSION=	2023.11.16
CATEGORIES=	graphics

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Zen node system - a simulation

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	openmpi>0:net/openmpi \
		cgal>=5.0.2:math/cgal \
		onetbb>0:devel/onetbb \
		openvdb>0:misc/openvdb

#LIB_DEPENDS+=	libopenvdb.so:misc/openvdb #\
#		libtbb.so:devel/onetbb \

USES=		cmake compiler:c++17-lang localbase:ldflags eigen:3 qt:5
USE_QT=		buildtools core widgets gui linguisttools network opengl svg qmake
USE_GCC=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	zenustech

CXXFLAGS+=	-I${WRKSRC}/ui/zenoui/style -I${WRKSRC}/ui/zenoedit/launch

CMAKE_ON=	ZENO_BUILD_EDITOR ZENO_MULTIPROCESS \
		ZENO_BUILD_SHARED ZENO_USE_CCACHE ZENO_NO_WARNING \
		ZENO_IPC_USE_TCP
CMAKE_OFF=	ZENO_BUILD_DESIGNER ZENO_BUILD_PLAYER ZENO_INSTALL_TARGET \
		ZENO_WITH_CUDA ZENO_MARCH_NATIVE ZENO_USE_FAST_MATH \
		ZENO_OPTIX_PROC ZENO_WIN32_RC
		# ZENO_BUILD_DESIGNER - bug https://github.com/zenustech/zeno/issues/1907

CMAKE_ARGS+=	-DCMAKE_VERBOSE_MAKEFILE="ON" -DCMAKE_BUILD_PARALLEL_LEVEL=${MAKE_JOBS_NUMBER}

PLIST_FILES=	bin/zenoedit \
		bin/autotest \
		lib/libzeno.so
do-install:

.include <bsd.port.mk>
