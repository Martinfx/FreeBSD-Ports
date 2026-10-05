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
DATADIR=	${PREFIX}/share/obs/obs-plugins/${PORTNAME}

USE_GITHUB=	yes
GH_ACCOUNT=	royshil

post-patch:
	${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/CMakeLists.txt

do-install:
	${MKDIR} \
		${STAGEDIR}${PREFIX}/lib/obs-plugins \
		${STAGEDIR}${DATADIR}
	${INSTALL_LIB} \
		${BUILD_WRKSRC}/${PORTNAME}.so \
		${STAGEDIR}${PREFIX}/lib/obs-plugins
	cd ${WRKSRC}/data && \
		${COPYTREE_SHARE} "effects locale models" ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
