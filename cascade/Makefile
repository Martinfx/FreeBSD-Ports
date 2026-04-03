PORTNAME=	cascade
DISTVERSIONPREFIX=v
DISTVERSION=	0.2.0
DISTVERSIONSUFFIX=-alpha
CATEGORIES=	graphics

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Node-based image editor with GPU-acceleration.
WWW=		https://github.com/ttddee/Cascade

LICENSE=	GPLv3

BUILD_DEPENDS=	openimageio>0:graphics/openimageio \
		glslang>0:graphics/glslang

USES=		qmake qt:5
USE_QT=		core gui
#USE_GCC=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	ttddee
GH_PROJECT=	Cascade
GH_TAGNAME=	05a082f

#WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}${DISTVERSIONSUFFIX}

.include <bsd.port.mk>
