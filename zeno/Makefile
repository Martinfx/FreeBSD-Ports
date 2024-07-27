PORTNAME=	zeno
DISTVERSION=	2023.11.16
CATEGORIES=	graphics

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Zen node system - a simulation
WWW=		https://zenustech.com/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	openmpi>0:net/openmpi \
		cgal>=5.0.2:math/cgal \
		onetbb>0:devel/onetbb \
		openvdb>0:misc/openvdb

USES=		cmake compiler:c++17-lang localbase:ldflags eigen:3 qt:5
USE_QT=		buildtools core widgets gui linguisttools network opengl svg qmake
USE_GITHUB=	yes
USE_LDCONFIG=   yes
GH_ACCOUNT=	zenustech

CMAKE_ON=	ZENO_BUILD_EDITOR ZENO_MULTIPROCESS \
		ZENO_BUILD_SHARED ZENO_USE_CCACHE ZENO_NO_WARNING \
		ZENO_IPC_USE_TCP
CMAKE_OFF=	ZENO_BUILD_DESIGNER ZENO_BUILD_PLAYER ZENO_INSTALL_TARGET \
		ZENO_WITH_CUDA ZENO_MARCH_NATIVE ZENO_USE_FAST_MATH \
		ZENO_OPTIX_PROC ZENO_WIN32_RC
		# ZENO_BUILD_DESIGNER - bug https://github.com/zenustech/zeno/issues/1907

		# fix on 13.3: "ld: error: undefined reference due to --no-allow-shlib-undefined:
LDFLAGS+=	-Wl,--allow-shlib-undefined -lomp

PLIST_FILES=	bin/zenoedit \
		bin/autotest \
		lib/libzeno.so
do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.build/bin/zenoedit ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/.build/bin/autotest ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/.build/bin/libzeno.so ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
