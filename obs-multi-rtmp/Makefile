PORTNAME=	obs-multi-rtmp
DISTVERSION=	0.6.0.1-obs31
CATEGORIES=	multimedia

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Multistream plugin for OBS-Studio.
WWW=		https://github.com/sorayuki/obs-multi-rtmp/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	obs-studio>0:multimedia/obs-studio \
		libglvnd>0:graphics/libglvnd
LIB_DEPENDS=	libobs.so:multimedia/obs-studio

USES=		cmake localbase qt:6
USE_QT=		base
USE_GL=		gl opengl
USE_GITHUB=	yes
GH_ACCOUNT=	sorayuki

CMAKE_ON=	ENABLE_QT
CMAKE_OFF=	CMAKE_COMPILE_WARNING_AS_ERROR

do-install:
	${MKDIR} \
		${STAGEDIR}${PREFIX}/lib/obs-plugins \
		${STAGEDIR}${PREFIX}/share/obs/obs-plugins/obs-multi-rtmp/locale
	${INSTALL_LIB} \
		${BUILD_WRKSRC}/obs-multi-rtmp.so \
		${STAGEDIR}${PREFIX}/lib/obs-plugins
	${INSTALL_DATA} \
		${WRKSRC}/data/locale/*.ini \
		${STAGEDIR}${PREFIX}/share/obs/obs-plugins/obs-multi-rtmp/locale


.include <bsd.port.mk>
