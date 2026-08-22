PORTNAME=	dsview
DISTVERSIONPREFIX=v
DISTVERSION=	1.3.2
CATEGORIES=	devel

MAINTAINER=	root@hades
COMMENT=	DSView is a GUI program for logic analyzers, oscilloscopes.
WWW=		https://github.com/DreamSourceLab/DSView

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	boost-libs>=1.89.0:devel/boost-libs
LIB_DEPENDS=	libfftw3.so:math/fftw3

USES=		cmake localbase:ldflags pkgconfig python gl qt:6

USE_GITHUB=	yes
GH_ACCOUNT=	DreamSourceLab
GH_PROJECT=	DSView

USE_GNOME=	glib20
USE_GL=		gl opengl
USE_QT=		base
LDFLAGS=	-I/usr/include -L/usr/lib -lusb

.include <bsd.port.mk>