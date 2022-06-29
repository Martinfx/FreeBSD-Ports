# $FreeBSD$

PORTNAME=	shadered
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.6
CATEGORIES=	devel

MAINTAINER=	maintainer@email.com
COMMENT=	Lightweight tool for writing and debugging shaders.

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	glm>0:math/glm
LIB_DEPENDS=	libsfml-system.so:devel/sfml

USES=		cmake compiler:c++17-lang gl sdl
USE_GNOME=	gtk30
USE_SDL=        sdl2
USE_GL=         gl glew
USE_GITHUB=	yes

GH_ACCOUNT=	dfranx
GH_PROJECT=	SHADERed
GH_TUPLE=	dfranx:ImGuiColorTextEdit:2d9681aada3c51051be2b4e6f329f7d9d81caa9d:SHADERed/libs/ImGuiColorTextEdit
GH_TUPLE+=	dfranx:SPIRV-VM:8c8b198:libs/SPIRVVM
GH_TUPLE+=	dfranx:assimp:2012451:libs/assimp
GH_TUPLE+=	dfranx:SpvGenTwo:ed86a3e:libs/SpvGenTwo
GH_TUPLE+=	dfranx:ShaderExpressionParser:ac2e324f5d484dfdb58b697bacb591cf784ee072:SHADERed/libs/ShaderExpressionParser

#		dfranx:SpvGenTwo:ed86a3e:SHADERed/libs/SpvGenTwo
#		dfranx:assimp:2012451:SHADERed/libs/assimp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
