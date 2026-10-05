PORTNAME=	shadps4
DISTVERSIONPREFIX=	v.
DISTVERSION=	0.19.0
PORTREVISION=	1
CATEGORIES=	emulators

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	PlayStation 4 emulator written C++
WWW=		https://github.com/shadps4-emu/shadPS4

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	runs PS4 x86-64 code natively

BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libavfilter.so:multimedia/ffmpeg \
		libavformat.so:multimedia/ffmpeg \
		libavutil.so:multimedia/ffmpeg \
		libswresample.so:multimedia/ffmpeg \
		libswscale.so:multimedia/ffmpeg \
		libuuid.so:misc/libuuid \
		libwayland-client.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	vulkan-loader>0:graphics/vulkan-loader

USES=		cmake:noninja compiler:c++23-lang elfctl gl gmake llvm:min=19 \
		localbase:ldflags pkgconfig python:build ssl xorg
USE_GL=		egl gl
USE_XORG=	x11 xcursor xext xfixes xi xrandr xscrnsaver xtst
USE_GITHUB=	yes
GH_ACCOUNT=	shadps4-emu
GH_PROJECT=	shadPS4
GH_TUPLE=	shadexternals:CLI11:12ba4ac4dbaa6489cb07e01be796e2bc074ef4f4:cli11/externals/CLI11 \
		shadexternals:ImGuiFileDialog:57a1c6a6d44bd99e844e3642d27851f6c065af62:imguifiledialog/externals/ImGuiFileDialog \
		shadps4-emu:ext-LibAtrac9:946e05a9212976626a9f5e52f29c0a7202871f29:libatrac9/externals/LibAtrac9 \
		mstorsjo:fdk-aac:ee76460efbdb147e26d804c798949c23f174460b:fdk_aac/externals/aacdec/fdk-aac \
		abseil:abseil-cpp:76bb24329e8bf5f39704eb10d21b9a80befa7c81:abseil_cpp/externals/abseil-cpp \
		shadexternals:cpp-httplib:28f8264d134a576422cd0f99f19719c2749d9e47:cpp_httplib/externals/cpp-httplib \
		HowardHinnant:date:a45ea7c17b4a7f320e199b71436074bd624c9e15:date/externals/date \
		shadps4-emu:ext-discord-rpc:19f66e6dcabb2268965f453db9e5774ede43238f:discord_rpc/externals/discord-rpc \
		jiixyj:epoll-shim:18159584bb3d17e601b9315a7398ace018251bdc:epoll_shim/externals/epoll-shim \
		shadps4-emu:ext-boost:ca6f230e67be7cc45fc919057f07b2aee64dadc1:ext_boost/externals/ext-boost \
		shadps4-emu:ext-fmt:ec73fb72477d80926c758894a3ab2cb3994fd051:fmt/externals/fmt \
		freetype:freetype:b91f75bd02db43b06d634591eb286d3eb0ce3b65:freetype/externals/freetype \
		KhronosGroup:glslang:ba1640446f3826a518721d1f083f3a8cca1120c3:glslang/externals/glslang \
		ROCm:half:1ddada225144cac0de8f6b5c0dd9acffd99a2e68:half/externals/half \
		shadps4-emu:ext-hwinfo:8660006e0ca4aae5dda7a29e585968b50b0273b7:hwinfo/externals/hwinfo \
		shadexternals:imgui:7e1b65d26d52e9dd199d889c148c72184de647b4:imgui/externals/imgui \
		nlohmann:json:55f93686c01528224f448c19128836e7df245f72:json/externals/json \
		pnggroup:libpng:c1cc0f3f4c3d4abd11ca68c59446a29ff6f95003:libpng/externals/libpng \
		Neargye:magic_enum:a413fcc9c46a020a746907136a384c227f3cd095:magic_enum/externals/magic_enum \
		lieff:minimp3:7b590fdcfa5a79c033e76eacc05d0c3e4c79f536:minimp3/externals/minimp3 \
		miniupnp:miniupnp:bf4215a7574f88aa55859db9db00e3ae58cf42d6:miniupnp/externals/miniupnp \
		richgel999:miniz:174573d60290f447c13a2b1b3405de2b96e27d6c:miniz/externals/miniz \
		shadexternals:openal-soft:83ea7236c6f23fc98e2b62eb9c5b3abfd4b2be86:openal_soft/externals/openal-soft \
		shadexternals:protobuf:5917ee224a7e47383a78acc129628511fe210dff:protobuf/externals/protobuf \
		zeux:pugixml:caade5a28aad86b92a4b5337a9dc70c4ba73c5eb:pugixml/externals/pugixml \
		Tessil:robin-map:4ec1bf19c6a96125ea22062f38c2cf5b958e448e:robin_map/externals/robin-map \
		shadexternals:sdl3:d5af35e3fbb5bb6555ed00e69740d52af2a4e877:sdl3/externals/sdl3 \
		shadps4-emu:sirit:c58f4d441cfdb6905d011a906704716833485486:sirit/externals/sirit \
		gabime:spdlog:b8944a4bcd478ee03375c9c50dc8d6c741f43f7b:spdlog/externals/spdlog \
		ToruNiina:toml11:a01fe3b4c14c6d7b99ee3f07c9e80058c6403097:toml11/externals/toml11 \
		shadps4-emu:tracy:143a53d1985b8e52a7590a0daca30a0a7c653b42:tracy/externals/tracy \
		GPUOpen-LibrariesAndSDKs:VulkanMemoryAllocator:f378e7b3f18f6e2b06b957f6ba7b1c7207d2a536:vma/externals/vma \
		KhronosGroup:Vulkan-Headers:ee3b5caaa7e372715873c7b9c390ee1c3ca5db25:vulkan_headers/externals/vulkan-headers \
		herumi:xbyak:44a72f369268f7d552650891b296693e91db86bb:xbyak/externals/xbyak \
		Cyan4973:xxHash:953a09abc39096da9e216b6eb0002c681cdc1199:xxhash/externals/xxhash \
		shadexternals:ZArchive:965b66c8d67b6b7e30fd63b3b75aa91a99ff303b:zarchive/externals/zarchive \
		shadps4-emu:ext-zlib-ng:fd0d263cedab1a136f40d65199987e3eaeecfcbd:zlib_ng/externals/zlib-ng \
		shadexternals:zstd:5c7b7bad26808e6b40ac3b3d0075466e27738a9d:zstd/externals/zstd \
		zyantific:zydis:120e0e705f8e3b507dc49377ac2879979f0d545c:zydis/externals/zydis \
		Tencent:rapidjson:d621dc9e9c77f81e5c8a35b8dcc16dcd63351321:rapidjson/externals/discord-rpc/thirdparty/rapidjson \
		KhronosGroup:SPIRV-Headers:2acb319af38d43be3ea76bfabf3998e5281d8d12:spirv_headers/externals/sirit/externals/SPIRV-Headers \
		zyantific:zycore-c:38d4f0285e6157ee840ea82a9b90aba71c8a705d:zycore/externals/zydis/dependencies/zycore

# Everything else is bundled. spdlog would download its own copy of fmt,
# point it to the bundled one and forbid any network access during the build.
CMAKE_ARGS=	-DFETCHCONTENT_FULLY_DISCONNECTED=ON \
		-DFETCHCONTENT_SOURCE_DIR_FMT=${WRKSRC}/externals/fmt \
		-DPython3_EXECUTABLE=${PYTHON_CMD}
CMAKE_OFF=	ENABLE_UPDATER

OPTIONS_DEFINE=	QT
OPTIONS_DEFAULT=	QT
QT_DESC=	Build the Qt launcher (shadps4-qtlauncher)

# The Qt GUI lives in its own repository upstream (snapshot of 2026-10-02),
# build it in a second CMake tree. fmt, SDL3, toml11, Vulkan-Headers and
# OpenAL come from the system; spdlog, zstd and ZArchive are shared with the
# emulator sources.
QT_GH_TUPLE=	shadps4-emu:shadps4-qtlauncher:4c4e1090ea53dc1ec956fa9954acbf143d104b2e:qtlauncher/qtlauncher \
		nlohmann:json:54be9b04f0ec65d0bcfe0da54e7f01ea86fbfc3e:ql_json/qtlauncher/externals/json \
		zeux:volk:e51c647181c7a8101454e69446079bc34100a320:ql_volk/qtlauncher/externals/volk
QT_BUILD_DEPENDS=	toml11>0:devel/toml11 \
			vulkan-headers>0:graphics/vulkan-headers
QT_LIB_DEPENDS=	libfmt.so:devel/libfmt \
		libopenal.so:audio/openal-soft \
		libSDL3.so:devel/sdl3
QT_USES=	qt:6
QT_USE=		QT=base,multimedia,tools:build
QT_EXTRA_PATCHES=	${PATCHDIR}/qtlauncher
QT_PLIST_FILES=	bin/shadPS4QtLauncher \
		share/applications/net.shadps4.shadps4-qtlauncher.desktop \
		share/icons/hicolor/512x512/apps/net.shadps4.shadPS4.png \
		share/metainfo/net.shadps4.shadps4-qtlauncher.metainfo.xml

QTLAUNCHER_BUILD=	${WRKDIR}/.build-qtlauncher

# The PS4 address space (0x400000 - 0xfffffffffff) is reserved with MAP_FIXED,
# which requires a deterministic memory layout: disable ASLR. Patched guest
# code and trampolines also need W+X mappings.
ELF_FEATURES=	+noaslr:${PORTNAME} \
		+wxneeded:${PORTNAME}

PLIST_FILES=	bin/shadps4 \
		share/applications/net.shadps4.shadPS4.desktop \
		share/icons/hicolor/scalable/apps/net.shadps4.shadPS4.svg

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/src/dist/net.shadps4.shadPS4.desktop \
		${STAGEDIR}${DESKTOPDIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/src/dist/net.shadps4.shadPS4.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps

pre-patch-QT-on:
.for d in spdlog zstd zarchive
	@${RMDIR} ${WRKSRC}/qtlauncher/externals/${d} 2>/dev/null || :
	${LN} -s ../../externals/${d} ${WRKSRC}/qtlauncher/externals/${d}
.endfor

post-configure-QT-on:
	@${MKDIR} ${QTLAUNCHER_BUILD}
	cd ${QTLAUNCHER_BUILD} && ${SETENVI} ${WRK_ENV} ${CONFIGURE_ENV} ${CMAKE_BIN} \
		${CMAKE_ARGS} -DSHADPS4_SYSTEM_EXECUTABLE=${PREFIX}/bin/shadps4 \
		${WRKSRC}/qtlauncher

post-build-QT-on:
	cd ${QTLAUNCHER_BUILD} && ${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${CMAKE_BIN} \
		--build . --target shadPS4QtLauncher --parallel ${MAKE_JOBS_NUMBER}

post-install-QT-on:
	${INSTALL_PROGRAM} ${QTLAUNCHER_BUILD}/shadPS4QtLauncher ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/qtlauncher/dist/net.shadps4.shadps4-qtlauncher.desktop \
		${STAGEDIR}${DESKTOPDIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/512x512/apps
	${INSTALL_DATA} ${WRKSRC}/qtlauncher/.github/shadps4.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/512x512/apps/net.shadps4.shadPS4.png
	${MKDIR} ${STAGEDIR}${PREFIX}/share/metainfo
	${INSTALL_DATA} ${WRKSRC}/qtlauncher/dist/net.shadps4.shadps4-qtlauncher.metainfo.xml \
		${STAGEDIR}${PREFIX}/share/metainfo

.include <bsd.port.mk>
