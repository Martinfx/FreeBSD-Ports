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

LIB_DEPENDS+=	libopenvdb.so:misc/openvdb #\
#		libtbb.so:devel/onetbb \

USES=		cmake compiler:c++17-lang localbase:ldflags eigen:3 qt:5
USE_QT=		widgets gui network linguisttools buildtools svg
USE_GCC=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	zenustech
#GH_TAGNAME=	b6b568b

CXXFLAGS+=	-I${WRKSRC}/projects/zenvdb/include
CMAKE_ARGS=	-DTBB_ENABLE_IPO=OFF -DOPENVDB_11_ABI_COMPATIBLE=ON #-D__linux__

.include <bsd.port.mk>
