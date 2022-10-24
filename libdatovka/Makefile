PORTNAME=	libdatovka
DISTVERSION=	0.2.1
CATEGORIES=	devel
MASTER_SITES=	https://secure.nic.cz/files/datove_schranky/libdatovka/

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	library for program datovka

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS= 	${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:textproc/docbook-xsl \
		xsltproc:textproc/libxslt \
		docbook-xsl>0:textproc/docbook-xsl \
		libgcrypt>0:security/libgcrypt\
		expat>0:textproc/expat2  \
		libiconv>0:converters/libiconv

USES=		autoreconf localbase gettext gmake tar:xz
USE_GNOME=	libxml2:build libxslt

GNU_CONFIGURE= yes
CONFIGURE_ARGS+=  --with-docbook-xsl-stylesheets=${LOCALBASE}/share/xsl/docbook

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e "s|/usr/share/sgml/docbook/xsl-stylesheets|${LOCALBASE}/share/xsl/docbook/|g"

.include <bsd.port.mk>
