PORTNAME=	libdatovka
DISTVERSION=	0.2.1
CATEGORIES=	devel
MASTER_SITES=	https://secure.nic.cz/files/datove_schranky/libdatovka/

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	ISDS client library
WWW=		https://gitlab.nic.cz/datovka/libdatovka

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=  docbook-xsl>0:textproc/docbook-xsl \
		expat>0:textproc/expat2 \
		gpgme>0:security/gpgme \
		libgcrypt>0:security/libgcrypt \
		libiconv>0:converters/libiconv \
		xsltproc:textproc/libxslt

LIB_DEPENDS+=	libassuan.so:security/libassuan \
		libcurl.so:ftp/curl \
		libexpat.so:textproc/expat2 \
		libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error \
		libgpgme.so:security/gpgme

USES=		autoreconf localbase gettext gmake libtool tar:xz
#CFLAGS+=	Wno-error
USE_GNOME=	libxslt libxml2

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-docbook-xsl-stylesheets=${LOCALBASE}/share/xsl/docbook --disable-fatalwarnings

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>

