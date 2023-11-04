PORTNAME=	apfs-fuse
DISTVERSION=	g20231029
CATEGORIES=	sysutils
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	APFS FUSE Driver for Linux
WWW=		https://github.com/sgan81/apfs-fuse

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfuse.so:sysutils/fusefs-libs

USES=		cmake fuse

USE_GITHUB=	yes
GH_ACCOUNT=	sgan81
GH_PROJECT=	apfs-fuse
GH_TAGNAME=	b595551132779711ea9538a2e6364796b7ebe317
GH_TUPLE+=	lzfse:lzfse:e634ca58b4821d9f3d560cdc6df5dec02ffc93fd:lzfs/3rdparty/lzfse

PLIST_FILES+=	bin/apfs-fuse \
		bin/apfsutil

post-install:
	@${STRIP_CMD} ${STAGEDIR}/${PREFIX}/bin/apfs-fuse
	@${STRIP_CMD} ${STAGEDIR}/${PREFIX}/bin/apfsutil

.include <bsd.port.mk>
