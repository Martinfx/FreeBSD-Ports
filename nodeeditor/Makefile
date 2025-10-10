PORTNAME=	nodeeditor
DISTVERSION=	3.0.12
CATEGORIES=	devel

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Qt Node Editor, Dataflow programming framework
WWW=		https://github.com/paceholder/nodeeditor

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers

USES=		cmake gl qt:6
USE_GITHUB=	yes
GH_ACCOUNT=	paceholder
USE_GL=		gl
USE_QT=		base

.if defined(WITH_DEBUG)
BUILD_DEPENDS+=	catch2>0:devel/catch2
CMAKE_ON=	BUILD_TESTING
.else
CMAKE_OFF=	BUILD_TESTING
.endif
CMAKE_OFF+=	BUILD_DOCS

PORTEXAMPLES=	*

OPTIONS_DEFINE=		EXAMPLES
OPTIONS_SUB=		yes
EXAMPLES_CMAKE_BOOL=	BUILD_EXAMPLES

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/.build/bin/* ${STAGEDIR}${EXAMPLESDIR}/bin
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
