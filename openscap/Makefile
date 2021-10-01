PORTNAME=	openscap
DISTVERSION= 1.3.5
CATEGORIES=	devel

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	NIST Certified SCAP 1.2 toolkit 	

LICENSE= GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libxmlsec1.so:security/xmlsec1 \
				libxmlsec1-openssl.so:security/xmlsec1 \
				libpcre.so:devel/pcre \
				libcurl.so:ftp/curl \
				libgcrypt.so:security/libgcrypt \
				libdbus-1.so:devel/dbus \
				libpython3.8.so:lang/python38 \
				libperl.so:lang/perl5.32

USES=           cmake gnome localbase:ldflags ssl shebangfix python:3.8
USE_GNOME+=		libxml2 libxslt
CMAKE_ARGS+=    OSCAP_DOCKER_PYTHON=${PYTHON_CMD}
SHEBANG_GLOB=	*.sh *.py *.pl
SHEBANG_FILES=  utils/autotailor \
				utils/scap-as-rpm \
				bin/oscap-docker

USE_GITHUB=     yes
GH_ACCOUNT=     OpenSCAP
GH_PROJECT=     openscap

#do-install:
	#@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*
	#@${REINPLACE_CMD} -e 's|/usr/bin/env python3 python3|${PYTHON_CMD}|' ${WRKSRC}/util/scap-as-rpm
	
.include <bsd.port.mk>
