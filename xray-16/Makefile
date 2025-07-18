PORTNAME=	xray-16
DISTVERSION=	2921-january-2025-rc1
CATEGORIES=	games

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Improved version of the X-Ray Engine, \
		the game engine used in the world-famous S.T.A.L.K.E.R. \
		game series by GSC Game World.
WWW=		https://github.com/OpenXRay/xray-16

LICENSE=	UNKNOWN
LICENSE_NAME=	unknown
LICENSE_FILE=	${WRKSRC}/License.txt
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

BUILD_DEPENDS=	glew>0:graphics/glew \
		openal-soft>0:audio/openal-soft \
		jpeg-turbo>0:graphics/jpeg-turbo \
		libtheora>0:multimedia/libtheora

LIB_DEPENDS=	libogg.so:audio/libogg \
		libtheora.so:multimedia/libtheora \
		libvorbis.so:audio/libvorbis \
		libvorbisfile.so:audio/libvorbis  \
		libmimalloc.so:devel/mimalloc \
		liblzo2.so:archivers/lzo2

USES=		cmake desktop-file-utils jpeg localbase openal sdl
USE_GITHUB=	yes
GH_ACCOUNT=	OpenXRay
GH_PROJECT=	xray-16
GH_TAGNAME=	38ef0e93837cd892c68de58ae00b5152dc87208e
GH_TUPLE=	GPUOpen-LibrariesAndSDKs:AGS_SDK:5d8812d:AGSSDK/Externals/AGS_SDK \
		OpenXRay:BugTrap:c619077b40ee6e7ad6ffc5a194a5d3583af8f78e:BugTrap/Externals/BugTrap \
		OpenXRay:GameSpy:61d061b4b3f860865f97e659e496e11704f61eb3:GameSpy/Externals/GameSpy \
		OpenXRay:LuaJIT:5a5cd82:LuaJIT/Externals/LuaJIT \
		weidai11:cryptopp:78a64e37d3ec8aa1fd941a1309b1a2eef43b0bb0:cryptopp/Externals/cryptopp \
 		g-truc:gli:779b99ac6656e4d30c3b24e96e0136a59649a869:gli/Externals/gli \
		ocornut:imgui:efe2b21:ocornut/Externals/imgui \
		xiph:ogg:db5c7a49ce7ebda47b15b78471e78fb7f2483e22:ogg/Externals/ogg \
		xiph:theora:7180717276af1ebc7da15c83162d6c5d6203aabf:theora/Externals/theora \
		xiph:vorbis:84c023699cdf023a32fa4ded32019f194afcdad0:vorbis/Externals/vorbis \
		OpenXRay:luabind-deboostified:dd3db67:luabind/Externals/luabind \
		DLTcollab:sse2neon:658eeac:sse2neon/Externals/sse2neon \
		pattonkan:sse2rvv:f3a1d7d:sse2rvv/Externals/sse2rvv \
		OpenXRay:xrLuaFix:67b77c92f49c766c7c180cc39ffdb12799f395d:xrLuaFix/Externals/xrLuaFix \
		madler:zlib:545f1949635949159fa6282e81712aec32b5d4f1:zlib/Externals/zlib \
		OpenXRay:luafilesystem:314c0d0fe8f4676ef35ac8abf3731be8535812fb:luafilesystem/Externals/xrLuaFix/lfs \
		OpenXRay:lua-marshal:983a3bfd646486292daa9f2ec9b72409f86dc931:marsal/Externals/xrLuaFix/lua-marshal \
		OpenXRay:lua-pack:c1e5a149b571cc31069e7e3146e881c203bdd052:pack/Externals/xrLuaFix/lua-pack

USE_SDL=        sdl2
CMAKE_ON=	XRAY_USE_LUAJIT

.include <bsd.port.mk>
