PORTNAME=	obs-backgroundremoval
DISTVERSION=	1.4.0
PORTREVISION=	1
CATEGORIES=	multimedia

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	An OBS plugin for removing background in portrait images
WWW=		https://github.com/royshil/obs-backgroundremoval

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	curl>0:ftp/curl \
		simde>0:devel/simde

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libobs-frontend-api.so:multimedia/obs-studio \
		libobs.so:multimedia/obs-studio \
		libonnxruntime.so:misc/onnxruntime \
		libopencv_core.so:graphics/opencv

USES=		cmake localbase
USE_GITHUB=	yes
GH_ACCOUNT=	royshil

post-patch:
	${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/CMakeLists.txt

do-install:
	${MKDIR} \
		${STAGEDIR}${PREFIX}/lib/obs-plugins \
		${STAGEDIR}${PREFIX}/share/obs/obs-plugins/${PORTNAME}
	${INSTALL_LIB} \
		${BUILD_WRKSRC}/${PORTNAME}.so \
		${STAGEDIR}${PREFIX}/lib/obs-plugins
# The filters load their shaders (effects/) and ONNX models (models/) from the
# plugin data directory at run time, so install all of data/ like upstream.
	cd ${WRKSRC}/data && ${COPYTREE_SHARE} . \
		${STAGEDIR}${PREFIX}/share/obs/obs-plugins/${PORTNAME}

.include <bsd.port.mk>
