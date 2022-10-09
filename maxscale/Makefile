PORTNAME=       MaxScale
DISTVERSION=    22.08.1

CATEGORIES=     databases

MAINTAINER=     freebsd@sysctl.cz
COMMENT=        An intelligent database proxy.
WWW=            https://github.com/mariadb-corporation/MaxScale

LICENSE=	BUSINESS GPLv3
LICENSE_COMB=	multi
LICENSE_NAME_BUSINESS=	Business Source License
LICENSE_FILE_BUSINESS=	${WRKSRC}/LICENSE.TXT
LICENSE_PERMS_BUSINESS=dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	libepoll-shim>0:devel/libepoll-shim
LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim

USES=           compiler:c++11-lang cmake:noninja gmake
USE_GITHUB=     yes
GH_ACCOUNT=     mariadb-corporation
GH_PROJECT=     MaxScale

MAKE_ENV+=	CPATH="${LOCALBASE}/include/libepoll-shim"

#REINPLACE_ARGS=	-i ''

post-patch:
	${REINPLACE_CMD} -e "s|program_invocation_short_name|getprogname()|g" ${WRKSRC}/maxutils/maxbase/src/log.cc
	${REINPLACE_CMD} -e "s|program_invocation_short_name|getprogname()|g" ${WRKSRC}/maxutils/maxbase/src/logger.cc

.include <bsd.port.mk>

