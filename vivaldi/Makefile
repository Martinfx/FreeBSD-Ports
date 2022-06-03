PORTNAME=	vivaldi
DISTVERSION=    3.3.2022
CATEGORIES=	www
# https://source.vivaldi.com/vivaldi-source_1.12.955.tar.xz
MASTER_SITES=   https://source.vivaldi.com/
EXTRACT_SUFX=	tar.xz
DISTNAME=	${PORTNAME}-source_${DISTVERSION}.
MAINTAINER=	maintainer@maintainer.com
COMMENT=

#LICENSE=	vivaldi technologies
#LICENSE_FILE=   ${WRKSRC}/LICENCE

WRKSRC=		${WRKDIR}/${PORTNAME}-source

#MAKE_ARGS=	-C out/${BUILDTYPE}
ALL_TARGET=	chrome

GN_BOOTSTRAP_FLAGS=	--no-clean --no-rebuild --skip-generate-buildfiles


#do-install:


.include <bsd.port.mk>
