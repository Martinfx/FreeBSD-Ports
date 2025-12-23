PORTNAME= friction
DISTVERSIONPREFIX=v
DISTVERSION=	1.0.0
DISTVERSIONSUFFIX=-rc.2
CATEGORIES=	graphics

MAINTAINER=	maxfx@hades
COMMENT=	Friction Graphics
WWW=		https://friction.graphics

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	gn:devel/gn
LIB_DEPENDS=	libunwind.so:devel/libunwind

USES=		cmake localbase gl qt:5
USE_QT=		core gui opengl svg widgets qmake:build
USE_GL=		gl
USE_GITHUB=	yes
GH_ACCOUNT=	friction2d
GH_PROJECT=	friction
GH_TUPLE=	friction2d:gperftools:b97c293c812c7ec3cdeccd50a89769e746c01377:gperf/src/gperftools \
 		friction2d:skia:c30d2c4f604a9b65a98e847ba008ac6e1a936eda:skia/src/engine/skia \
		friction2d:sfntly:b55ff303ea2f9e26702b514cf6a3196a2e3e2974:sfntly/src/skia/third_party/externals \
		friction2d:friction-icon-theme:c19e059527a5ca96b6a6f831df55e88ed948d677:icon/src/app/icons \
		friction2d:friction2d.github.io:ff53ffec5ae6ca10dd8605577ba8545590b77f15:docs/docs \
		friction2d:gn:70a9617aad7c09642457b6296d35638b97375dad:gn/src/engine/skia/gn-src
LDFLAGS=	-L${LOCALBASE}/lib -lunwind -lskia

.include <bsd.port.mk>
