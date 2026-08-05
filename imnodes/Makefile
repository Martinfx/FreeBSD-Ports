PORTNAME=	imnodes
DISTVERSIONPREFIX=v
DISTVERSION=	0.5
CATEGORIES=	x11-toolkits

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Dependency-free node editor for dear imgui.
WWW=		https://github.com/Nelarius/imnodes

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	imgui>0:x11-toolkits/imgui

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	Nelarius
GH_TAGNAME=	8563e16

# broken imgui sdl backend on freebsd
CMAKE_OFF=	IMNODES_EXAMPLES

PLIST_FILES=	include/imnodes.h \
		lib/libimnodes.a

do-install:
	${INSTALL_LIB} ${BUILD_WRKSRC}/libimnodes.a \
		${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/imnodes.h \
		${STAGEDIR}${PREFIX}/include
.include <bsd.port.mk>
