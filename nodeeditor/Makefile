PORTNAME=	nodeeditor
DISTVERSION=	3.0.12
CATEGORIES=	devel

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Qt Node Editor, Dataflow programming framework
WWW=		https://github.com/paceholder/nodeeditor

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

BUILD_DEPENDS=	catch2>0:devel/catch2

USES=		cmake localbase gl qt:6
USE_GITHUB=	yes
GH_ACCOUNT=	paceholder
GH_PROJECT=	nodeeditor
USE_GL=		gl
USE_QT=		base

CMAKE_ARGS=	-DBUILD_DOCS=OFF -D_BUILD_TESTING=OFF

post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} \
		-E -e 's|#include <catch2/catch.hpp>|#include <catch2/catch_all.hpp>|g'

post-extract:
	${MKDIR} ${WRKDIR}/.build/external/Catch2/single_include/catch2
	${LN} -s ${DISTDIR}/catch.hpp ${WRKDIR}/.build/external/Catch2/single_include/catch2

.include <bsd.port.mk>
