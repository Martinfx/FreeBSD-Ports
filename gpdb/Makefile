PORTNAME=	gpdb
DISTVERSION=	6.22.1
CATEGORIES=	databases

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Massively Parallel PostgreSQL for Analytics. An open-source massively parallel data platform for analytics, machine learning and AI. 

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf bison gmake perl5 libtool
USE_GCC=	yes
# bison
# perl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --with-perl --with-libxml --with-gssapi  --disable-fatalwarnings --disable-python #--with-python
LDFLAGS+= 	-lexecinfo

USE_GITHUB=	yes
GH_ACCOUNT=	greenplum-db
GH_PROJECT=	gpdb
GH_TUPLE=	google:googletest:a09ea70:gpcloud/test/googletest

.include <bsd.port.mk>
