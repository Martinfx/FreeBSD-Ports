PORTNAME=	openscap
DISTVERSION= 1.3.5
CATEGORIES=	devel

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	

LICENSE= GPLv2
LICENSE_FILE= ${WRKSRC}/COPYING

LIB_DEPENDS=	libxmlsec1.so:security/xmlsec1 \
				libxmlsec1-openssl.so:security/xmlsec1 \
				libpcre.so:devel/pcre \
				libcurl.so:ftp/curl \
				libgcrypt.so:security/libgcrypt \
				libdbus-1.so:devel/dbus \
				libpython3.8.so:lang/python38 \
				libperl.so:lang/perl5.32

USES=           cmake localbase:ldflags ssl shebangfix
USE_GNOME=	    libxml2 libxslt
SHEBANG_FILES=	bin/autotailor bin/oscap-docker bin/scap-as-rpm

USE_GITHUB=     yes
GH_ACCOUNT=     OpenSCAP
GH_PROJECT=     openscap

.include <bsd.port.mk>
