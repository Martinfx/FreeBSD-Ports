PORTNAME=	luxcorerenderer
DISVERSIONPREFIX=luxcorerender_v
DISTVERSION=2.5
CATEGORIES=	devel
MASTER_SITES=	https://github.com/LuxCoreRender/LuxCore/archive/refs/tags/
DISTNAME=	${DISVERSIONPREFIX}${DISTVERSION}
MAINTAINER=	maxfx@ 
COMMENT=	xxxx

LICENSE= APACHE20
LICENSE_FILE= ${WRKSRC}/COPYING.txt

USES=		cmake:insource localbase:ldflags
#USE_GITHUB=	yes
#GH_ACCOUNT=	LuxCoreRender
#GH_PROJECT=	LuxCore
#GH_TAG= c8ae672
WRKSRC=		${WRKDIR}/LuxCore-${DISVERSIONPREFIX}${PORTVERSION}

.include <bsd.port.mk>
