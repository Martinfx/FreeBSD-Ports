PORTNAME=	libdatovka
DISTVERSIONSUFFIX=v
DISTVERSION=	0.2.0
CATEGORIES=	devel

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	test

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/GPL-3

USES=           autoreconf gmake
GNU_CONFIGURE=  yes
#CONFIGURE_ARGS+= 

USE_GITLAB=	yes
GL_SITE=	https://gitlab.nic.cz/datovka/libdatovka
GL_ACCOUNT=	datovka
GL_PROJECT=	libdatovka
GL_COMMIT=	b2c5ddbf3843f961046e9708ee36c0169656e4cc

TAR_CMD=	${PREFIX}/bin/gtar
#EXTRACT_CMD=	${GZIP_CMD}
.include <bsd.port.mk>
