# $FreeBSD$

PORTNAME=	shadered
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.6
CATEGORIES=	devel

MAINTAINER=	maintainer@email.com
COMMENT=	Lightweight tool for writing and debugging shaders.

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++17-lang
USE_GITHUB=	yes
GH_ACCOUNT=	dfranx
GH_PROJECT=	SHADERed

GH_TUPLE+=	dfranx:ImGuiColorTextEdit:2d9681aada3c51051be2b4e6f329f7d9d81caa9d:SHADERed/libs/ImGuiColorTextEdit \
		dfranx:SPIRV-VM:8c8b198db468b4408b5cd6611acb8fa3f668d043:SHADERed/libs/SPIRVVM
#GH_TUPLE+=	dfranx:ShaderExpressionParser:ac2e324f5d484dfdb58b697bacb591cf784ee072:SHADERed/libs/ShaderExpressionParser
#GH_TUPLE+=	dfranx:SpvGenTwo:ed86a3e:SHADERed/libs/SpvGenTwo
#GH_TUPLE+=	dfranx:assimp:2012451:SHADERed/libs/assimp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
