PORTNAME=	vcpkg
DISTVERSION=	2024.04.26
CATEGORIES=	ports-mgmt

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Vcpkg helps you manage C and C++ libraries on Windows, Linux and MacOS.
WWW=		https://github.com/microsoft/vcpkg

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake tar

BUILD_DEPENDS=	curl>0:ftp/curl \
		zip:archivers/zip

USE_GITHUB=	yes
GH_ACCOUNT=	microsoft

NO_BUILD=yes
PLIST_FILES=	bin/vcpkg

do-configure:
	@cd ${WRKSRC} && ./bootstrap-vcpkg.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
