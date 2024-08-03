PORTNAME=	xpipe
DISTVERSION=	10.2.2
CATEGORIES=	editors linux
MASTER_SITES=	https://github.com/xpipe-io/${PORTNAME}/releases/download/${DISTVERSION}/
DISTFILES=	${PORTNAME}-portable-linux-${ARCH:S/amd64/x86_64/:S/aarch64/arm64/}.tar.gz
PKGNAMEPREFIX=	linux-

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Your entire server infrastructure at your fingertips.
WWW=		https://xpipe.io/

LICENSE=	APACHE20

ONLY_FOR_ARCHS=	amd64 aarch64

USES=		linux:rl9

USE_JAVA=	yes
JAVA_VERSION=	20+

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${LINUXBASE}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} app ${STAGEDIR}${LINUXBASE})
	${CHMOD} +x ${STAGEDIR}${LINUXBASE}/app/bin/xpiped

.include <bsd.port.mk>
