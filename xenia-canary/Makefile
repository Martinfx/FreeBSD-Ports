PORTNAME=	xenia-canary
DISTVERSION=	g20261027
CATEGORIES=	emulators

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Experimental Xbox 360 emulator
WWW=		https://github.com/xenia-canary/xenia-canary

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	x86-64 JIT and guest memory fault handling are only ported to amd64 on FreeBSD

BUILD_DEPENDS=	glslangValidator:graphics/glslang \
		spirv-opt:graphics/spirv-tools
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		liblz4.so:archivers/liblz4
RUN_DEPENDS=	vulkan-loader>0:graphics/vulkan-loader

USES=		cmake compiler:c++20-lang desktop-file-utils elfctl \
		gettext-runtime gnome localbase:ldflags pkgconfig python:build \
		sdl xorg
USE_GITHUB=	yes
GH_ACCOUNT=	xenia-canary
GH_TAGNAME=	48b318a2ad7c36f8f3901a94e290ba70ae0ffec5
GH_TUPLE=	openluopworld:aes_128:7e3ac3bb6b478187472b4ac6f1698eb203e8e90b:aes128/third_party/aes_128 \
		capstone-engine:capstone:66b08439abd988e87b4542389b4937ce13bd0063:capstone/third_party/capstone \
		jarro2783:cxxopts:f029892dab60526184ee42ae63a7f6d19a6b0e49:cxxopts/third_party/cxxopts \
		HowardHinnant:date:f94b8f36c6180be0021876c4a397a054fe50c6f2:date/third_party/date \
		discordapp:discord-rpc:963aa9f3e5ce81a4682c6ca3d136cddda614db33:discordrpc/third_party/discord-rpc \
		xenia-canary:disruptorplus:bf9c70c0cc92b6435f7edec75e12751ea37e5c2f:disruptorplus/third_party/disruptorplus \
		has207:FFmpeg:d980192e175e6ff95bcd287af77e16fcb6597974:ffmpeg/third_party/FFmpeg \
		GPUOpen-Effects:FidelityFX-CAS:9fabcc9a2c45f958aff55ddfda337e74ef894b7f:ffxcas/third_party/FidelityFX-CAS \
		GPUOpen-Effects:FidelityFX-FSR:a21ffb8f6c13233ba336352bdff293894c706575:ffxfsr/third_party/FidelityFX-FSR \
		fmtlib:fmt:407c905e45ad75fc29bf0f9bb7c5c2fd3475976f:fmt/third_party/fmt \
		KhronosGroup:glslang:a57276bf558f5cf94d3a9854ebdf5a2236849a5a:glslang/third_party/glslang \
		ocornut:imgui:4806a1924ff6181180bf5e4b8b79ab4394118875:imgui/third_party/imgui \
		zeux:pugixml:b2b466403084667c90a0f0cc4e960405cfc8117a:pugixml/third_party/pugixml \
		d99kris:rapidcsv:a98b85e663114b8fdc9c0dc03abf22c296f38241:rapidcsv/third_party/rapidcsv \
		Tencent:rapidjson:7c73dd7de7c4f14379b781418c6e947ad464c818:rapidjson/third_party/rapidjson \
		google:snappy:6af9287fbdb913f0794d0148c6aa43b58e63c8e3:snappy/third_party/snappy \
		p-ranav:tabulate:3a58301067bbc03da89ae5a51b3e05b7da719d38:tabulate/third_party/tabulate \
		marzer:tomlplusplus:708fff700f36ab3c2ab107b984ec9f3b8be5f055:tomlplusplus/third_party/tomlplusplus \
		nemtrif:utfcpp:65701fe00700577f9f4e9b96d682bd7cfcc0b76e:utfcpp/third_party/utfcpp \
		KhronosGroup:Vulkan-Headers:2cd90f9d20df57eac214c148f3aed885372ddcfe:vulkanheaders/third_party/Vulkan-Headers \
		GPUOpen-LibrariesAndSDKs:VulkanMemoryAllocator:1d8f600fd424278486eade7ed3e877c99f0846b1:vma/third_party/VulkanMemoryAllocator \
		herumi:xbyak:4e44f4614ddbf038f2a6296f5b906d5c72691e0f:xbyak/third_party/xbyak \
		Cyan4973:xxHash:e626a72bc2321cd320e953a0ccf1584cad60f363:xxhash/third_party/xxhash \
		exzap:ZArchive:b467f7aa342895e66a1a003377ed63b3c1be3de3:zarchive/third_party/zarchive \
		zlib-ng:zlib-ng:860e4cff7917d93f54f5d7f0bc1d0e8b1a3cb988:zlibng/third_party/zlib-ng \
		facebook:zstd:20707e3718ee14250fb8a44b3bf023ea36bd88df:zstd/third_party/zstd
USE_GNOME=	cairo gdkpixbuf glib20 gtk30 pango
USE_SDL=	sdl2
USE_XORG=	x11 xcb

CMAKE_ARGS=	-DPython3_EXECUTABLE=${PYTHON_CMD}
CMAKE_OFF=	XENIA_BUILD_MISC XENIA_BUILD_TESTS
# libc++ 19 only provides std::jthread with the experimental library.
CXXFLAGS+=	-fexperimental-library

# Guest memory, the JIT code cache and its indirection table are mapped at
# fixed addresses (some below 4 GB), and the trampolines are W+X.
ELF_FEATURES=	+noaslr:bin/Linux/xenia_canary \
		+wxneeded:bin/Linux/xenia_canary

ICON_SIZES=	16 32 48 64 128 256 512
PLIST_FILES=	bin/xenia_canary \
		share/applications/xenia_canary.desktop \
		${ICON_SIZES:@s@share/icons/hicolor/${s}x${s}/apps/xenia_canary.png@}

# The SDL2 and SPIRV-Tools submodules are only needed for their headers (both
# libraries are loaded with dlopen()), use the ones of the system instead.
post-extract:
	@${MKDIR} ${WRKSRC}/third_party/SDL2 ${WRKSRC}/third_party/SPIRV-Tools
	${LN} -sf ${LOCALBASE}/include/SDL2 ${WRKSRC}/third_party/SDL2/include
	${LN} -sf ${LOCALBASE}/include ${WRKSRC}/third_party/SPIRV-Tools/include

# Don't let new compiler warnings break the build.
post-patch:
	@${REINPLACE_CMD} -e '/PRIVATE -Werror)/d' \
		${WRKSRC}/cmake/XeniaHelpers.cmake

# Normally written by xenia-build.py from the git metadata.
pre-configure:
	@${MKDIR} ${CONFIGURE_WRKSRC}
	@${PRINTF} '%s\n' '#ifndef GENERATED_VERSION_H_' \
		'#define GENERATED_VERSION_H_' \
		'#define XE_BUILD_BRANCH "canary_experimental"' \
		'#define XE_BUILD_COMMIT "${GH_TAGNAME}"' \
		'#define XE_BUILD_COMMIT_SHORT "${GH_TAGNAME:C/^(.......).*/\1/}"' \
		'#define XE_BUILD_DATE __DATE__' \
		'#endif' > ${CONFIGURE_WRKSRC}/version.h

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/bin/Linux/xenia_canary \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/assets/xenia_canary.desktop \
		${STAGEDIR}${DESKTOPDIR}
.for s in ${ICON_SIZES}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps
	${INSTALL_DATA} ${WRKSRC}/assets/icon/${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps/xenia_canary.png
.endfor

.include <bsd.port.mk>
