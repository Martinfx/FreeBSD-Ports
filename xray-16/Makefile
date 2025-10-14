PORTNAME=	xray-16
DISTVERSION=	2921-january-2025-rc1.20251014
CATEGORIES=	games

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Improved version of the X-Ray Engine (used for run S.T.A.L.K.E.R.)
WWW=		https://github.com/OpenXRay/xray-16/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/License.txt

ONLY_FOR_ARCHS=	aarch64 amd64 i386

LIB_DEPENDS=	libogg.so:audio/libogg \
		libtheora.so:multimedia/libtheora \
		libvorbis.so:audio/libvorbis \
		libvorbisfile.so:audio/libvorbis \
		libmimalloc.so:devel/mimalloc \
		liblzo2.so:archivers/lzo2

USES=		cmake compiler:c++23-lang jpeg localbase:ldflags openal sdl
USE_GITHUB=	yes
GH_ACCOUNT=	OpenXRay
GH_TAGNAME=	64b0f07062e7c9e064c9692f0489f202dc1aa444
GH_TUPLE=	GPUOpen-LibrariesAndSDKs:AGS_SDK:5d8812d:AGSSDK/Externals/AGS_SDK \
		OpenXRay:GameSpy:3e43480:GameSpy/Externals/GameSpy \
		OpenXRay:LuaJIT:5a5cd82:LuaJIT/Externals/LuaJIT \
 		g-truc:gli:779b99ac6656e4d30c3b24e96e0136a59649a869:gli/Externals/gli \
		OpenXRay:luabind-deboostified:8da131b:luabind/Externals/luabind \
		DLTcollab:sse2neon:42eee28:sse2neon/Externals/sse2neon \
		pattonkan:sse2rvv:373f788:sse2rvv/Externals/sse2rvv \
		OpenXRay:xrLuaFix:0e89050:xrLuaFix/Externals/xrLuaFix \
		OpenXRay:luafilesystem:314c0d0fe8f4676ef35ac8abf3731be8535812fb:luafilesystem/Externals/xrLuaFix/lfs \
		OpenXRay:lua-marshal:983a3bfd646486292daa9f2ec9b72409f86dc931:marsal/Externals/xrLuaFix/lua-marshal \
		OpenXRay:lua-pack:c1e5a149b571cc31069e7e3146e881c203bdd052:pack/Externals/xrLuaFix/lua-pack \
		ocornut:imgui:8d9c90391937e389ed19a8abd96a5ec08c8876c2:imgui/Externals/imgui

USE_SDL=	sdl2
CMAKE_ON=	XRAY_USE_LUAJIT

post-patch:
	${REINPLACE_CMD} -e 's|^    COMMAND make clean$$|    COMMAND /bin/echo make clean|' \
		${WRKSRC}/Externals/LuaJIT-proj/CMakeLists.txt

.include <bsd.port.mk>
