PORTNAME=	terraforge3D
DISTVERSIONPREFIX=v
DISTVERSION=	2.3
CATEGORIES=	graphics

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Cross Platform Professional Procedural \
		Terrain Generation & Texturing Tool.
WWW=		https://jaysmito101.github.io/TerraForge3D/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	webp>0:graphics/webp

USES=	 	cmake localbase pathfix pkgconfig
USE_XORG=       x11
USE_GITHUB=	yes
GH_ACCOUNT=	Jaysmito101
GH_TAGNAME=	f36910e
GH_TUPLE=	avaneev:avir:6fa7ef5:avir/TerraForge3D/vendor/avir \
		delfrrr:delaunator-cpp:c1521f6:delfrr/TerraForge3D/vendor/delaunator \
		tronkko:dirent:328e7fc:dirent/TerraForge3D/vendor/dirent \
		fmtlib:fmt:9158bea:fmtlib/TerraForge3D/vendor/fmt \
		glfw:glfw:9a87635:glfw/TerraForge3D/vendor/glfw \
		g-truc:glm:efec5db:glm/TerraForge3D/vendor/glm \
		yhirose:cpp-httplib:88a9278:httplib/TerraForge3D/vendor/httplib \
		ocornut:imgui:6b3435a:imgui/TerraForge3D/vendor/imgui \
		thedmd:imgui-node-editor:99ec923:node/TerraForge3D/vendor/imgui-node-editor \
		nlohmann:json:546370c:json/TerraForge3D/vendor/json \
		nothings:stb:5736b15:stb/TerraForge3D/vendor/stb \
		syoyo:tinyexr:adb31d9:tinyexr/TerraForge3D/vendor/tinyexr

WRKSRC=		${WRKDIR}/TerraForge3D-${GH_TAGNAME}

.include <bsd.port.mk>
