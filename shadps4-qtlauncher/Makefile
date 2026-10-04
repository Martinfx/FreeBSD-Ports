PORTNAME=	shadps4-qtlauncher
DISTVERSION=	2026.10.02
CATEGORIES=	emulators

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Qt launcher for the shadPS4 PlayStation 4 emulator
WWW=		https://github.com/shadps4-emu/shadps4-qtlauncher

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	the shadPS4 emulator only runs on amd64

BUILD_DEPENDS=	toml11>0:devel/toml11 \
		vulkan-headers>0:graphics/vulkan-headers
LIB_DEPENDS=	libfmt.so:devel/libfmt \
		libopenal.so:audio/openal-soft \
		libSDL3.so:devel/sdl3
RUN_DEPENDS=	shadps4:emulators/shadps4

USES=		cmake compiler:c++23-lang gl llvm:min=19 pkgconfig qt:6 ssl
USE_GL=		gl opengl
USE_QT=		base multimedia tools:build
USE_GITHUB=	yes
GH_ACCOUNT=	shadps4-emu
GH_TAGNAME=	4c4e1090ea53dc1ec956fa9954acbf143d104b2e
GH_TUPLE=	gabime:spdlog:b8944a4bcd478ee03375c9c50dc8d6c741f43f7b:spdlog/externals/spdlog \
		nlohmann:json:54be9b04f0ec65d0bcfe0da54e7f01ea86fbfc3e:json/externals/json \
		zeux:volk:e51c647181c7a8101454e69446079bc34100a320:volk/externals/volk \
		shadexternals:zstd:5c7b7bad26808e6b40ac3b3d0075466e27738a9d:zstd/externals/zstd \
		shadexternals:ZArchive:965b66c8d67b6b7e30fd63b3b75aa91a99ff303b:zarchive/externals/zarchive

# fmt, SDL3, toml11, Vulkan-Headers and OpenAL come from the system, the rest
# is bundled. Forbid any download during the build.
CMAKE_ARGS=	-DFETCHCONTENT_FULLY_DISCONNECTED=ON \
		-DSHADPS4_SYSTEM_EXECUTABLE=${LOCALBASE}/bin/shadps4
CMAKE_OFF=	ENABLE_UPDATER
# std::stop_token is still experimental in the libc++ of FreeBSD 14.
CXXFLAGS+=	-D_LIBCPP_ENABLE_EXPERIMENTAL

PLIST_FILES=	bin/shadPS4QtLauncher \
		share/applications/net.shadps4.shadps4-qtlauncher.desktop \
		share/icons/hicolor/512x512/apps/net.shadps4.shadPS4.png \
		share/metainfo/net.shadps4.shadps4-qtlauncher.metainfo.xml

# Install by hand, the bundled externals would install their own files.
do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/shadPS4QtLauncher ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/dist/net.shadps4.shadps4-qtlauncher.desktop \
		${STAGEDIR}${DESKTOPDIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/512x512/apps
	${INSTALL_DATA} ${WRKSRC}/.github/shadps4.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/512x512/apps/net.shadps4.shadPS4.png
	${MKDIR} ${STAGEDIR}${PREFIX}/share/metainfo
	${INSTALL_DATA} ${WRKSRC}/dist/net.shadps4.shadps4-qtlauncher.metainfo.xml \
		${STAGEDIR}${PREFIX}/share/metainfo

.include <bsd.port.mk>
