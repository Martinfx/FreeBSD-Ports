PORTNAME=	gaffer
DISTVERSION=	1.5.1.0
CATEGORIES=	graphics

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Gaffer is a node-based application \
		for lookdev, lighting and automation.
WWW=		http://www.gafferhq.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	inkscape:graphics/inkscape \
		boost-libs>=1.85.0:devel/boost-libs \

USES=		python pkgconfig localbase scons qt:5

USE_QT=		core
USE_GITHUB=     yes
GH_ACCOUNT=     GafferHQ
GH_PROJECT=     gaffer

SCONS_ARGS=	LOCATE_DEPENDENCY_LIBPATH="/usr/local/lib"
SCONS_ARGS+=	LOCATE_DEPENDENCY_CPPPATH="/usr/local/include/qt5"
SCONS_ARGS+=	LOCATE_DEPENDENCY_CPPPATH="/usr/local/include/boost"
SCONS_ARGS+=    BOOST_LIB_SUFFIX="${LOCALBASE}/include/boost"

.include <bsd.port.mk>
