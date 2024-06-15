PORTNAME=	nodeeditor
DISTVERSION=	3.0.11
CATEGORIES=	devel

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Qt Node Editor. Dataflow programming framework.
WWW=		https://github.com/paceholder/nodeeditor

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

USES=		cmake qt:6
USE_GL=		gl
USE_QT=		base

USE_GITHUB=     yes
GH_ACCOUNT=     paceholder
GH_PROJECT=	nodeeditor

CMAKE_ARGS=	-DBUILD_DOCS=OFF

.include <bsd.port.mk>
