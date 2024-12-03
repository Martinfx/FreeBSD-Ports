PORTNAME=	jemalloc
DISTVERSION=	3.6.0
CATEGORIES=	devel

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	jemalloc is a general purpose malloc(3) implementation \
		that emphasizes fragmentation avoidance and \
		scalable concurrency support.

LICENSE=	unknow
LICENSE_NAME=	unknow
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

BUILD_DEPENDS=	autoreconf:devel/autoconf \
		libxslt>0:textproc/libxslt

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	jemalloc
GH_PROJECT=	jemalloc
#CONFIGURE_ARGS+=--with-xslroot=${LOCALBASE}/share/xsl/docbook

pre-build:
	@(cd ${WRKSRC} && ./autogen.sh)

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/jemalloc
	${INSTALL_DATA} ${WRKSRC}/include/jemalloc/jemalloc.h ${STAGEDIR}${PREFIX}/include/jemalloc
	${INSTALL_LIB} ${WRKSRC}/lib/libjemalloc.* ${STAGEDIR}${PREFIX}/lib/
	${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/jemalloc

.include <bsd.port.mk>
