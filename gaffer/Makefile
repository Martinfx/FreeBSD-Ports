PORTNAME=	gaffer
DISTVERSION=	1.5.1.0
CATEGORIES=	graphics

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Gaffer is a node-based application \
		for lookdev, lighting and automation.
WWW=		http://www.gafferhq.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	inkscape:graphics/inkscape

USES=		python pkgconfig localbase scons qt:5

USE_QT=		core
USE_GITHUB=     yes
GH_ACCOUNT=     GafferHQ
GH_PROJECT=     gaffer

SCONS_ARGS+=	QT5=${LOCALBASE}/qt5/QtCore/qconfig.h

.include <bsd.port.mk>
