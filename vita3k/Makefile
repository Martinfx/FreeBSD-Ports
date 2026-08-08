PORTNAME=	vita3k
DISTVERSION=	G20250828
CATEGORIES=	emulators

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	emulator playstation vita.

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.txt

BUILD_DEPENDS=	ffmpeg>0:multimedia/ffmpeg \
		sndio>0:audio/sndio \
		zycore-c>0:devel/zycore-c

USES=		cmake compiler:c++20-lang llvm:min=19 localbase pathfix pkgconfig ssl
USE_GL=		gl opengl
USE_GITHUB=	yes
GH_ACCOUNT=	Vita3K
GH_PROJECT=	Vita3K
GH_TAGNAME=	4e526f0c8057e4eae0e00a323d7d4c58cdee8813
GH_TUPLE+=	Vita3K:LibAtrac9:82767fe38823c32536726ea798f392b0b49e66b9:libatrac/external/LibAtrac9 \
		KhronosGroup:SPIRV-Cross:bccaa94db814af33d8ef05c153e7c34d8bd4d685:spirv/external/SPIRV-Cross \
		YaaZ:VulkanMemoryAllocator-Hpp:2059f0fdd73492b03d60a90c73e5038224b99093:vulkanmemory/external/VulkanMemoryAllocator-Hpp \
		KhronosGroup:Vulkan-Headers:952f776f6573aafbb62ea717d871cd1d6816c387:header/external/VulkanMemoryAllocator-Hpp/Vulkan-Headers \
		GPUOpen-LibrariesAndSDKs:VulkanMemoryAllocator:c788c52156f3ef7bc7ab769cb03c110a53ac8fcb:allocator/external/VulkanMemoryAllocator-Hpp/VulkanMemoryAllocator \
		aantron:better-enums:c35576bed0295689540b39873126129adfa0b4c8:better/external/better-enums \
		Vita3K:ext-boost:d4c58aa5c6fe08433ffdbe03f7a098342bf8e2e9:boost/external/boost \
		cameron314:concurrentqueue:6dd38b8a1dbaa7863aa907045f32308a56a6ff5d:concurentqueue/external/concurrentqueue \
		mozilla:cubeb:f8633c0c9217ed5499fdda391946d416c52e6809:cubeb/external/cubeb \
		tronkko:dirent:39c1f1bc98ef3326237d03006f35d7dd44620e43:dirent/external/dirent \
		Vita3K:dlmalloc:e98f4ee160380d7c39dc1f04e7488bcf0770d391:dlmalloc/external/dlmalloc \
		Vita3K:dynarmic:838ac0f79288d2d0485345022b3d842bc2bf77bc:dynarmic/external/dynarmic \
		Vita3K:ffmpeg-core:434b71f3c16a949dffd275dcd8bee89fb637cddd:ffmpeg/external/ffmpeg \
		fmtlib:fmt:123913715afeb8a437e6388b4473fcc4753e1c9a:fmt/external/fmt \
		KhronosGroup:glslang:fc9889c889561c5882e83819dcaffef5ed45529b:glslang/external/glslang \
		google:googletest:6910c9d9165801d8827d628cb72eb7ea9dd538c5:googletest/external/googletest \
		ocornut:imgui:cb16568fca5297512ff6a8f3b877f461c4323fbe:imgui/external/imgui \
		ocornut:imgui_club:53a2df3dd1b19dd321beb0897a0d1b9f87e5429c:imguiclub/external/imgui_club \
		Vita3K:libfat16:d9a890b712dcdb46d3d33230997efc59f5ad8d62:libfat/external/libfat16 \
		btzy:nativefiledialog-extended:86d5f2005fe1c00747348a12070fec493ea2407e:nativefiledialog/external/nativefiledialog-extended \
		Vita3K:printf:c75def6db38f9978c55e8d27227858df911cd727:printf/external/printf \
		Vita3K:psvpfstools:ab1aa9b36388843f6a9f8dc86b1746f1f2a7e557:psvftools/external/psvpfstools \
		korewawatchful:libb64:3896b7a74c70baed0e2f6039a1dbd723e5d5cc8f:libb64/external/psvpfstools/libb64 \
		KorewaWatchful:libzRIF:7d1e69bee7d2f08ea5754eff4463c041aacd49af:libzRIF/external/psvpfstools/libzrif \
		Vita3K:psvpfsparser:4094450bcaac2256236d61ae3a730425ae47bd39:parser/external/psvpfstools/psvpfsparser \
		korewawatchful:zlib:cb210089eb06453199578993566012493f6f7d21:zlib/external/psvpfstools/zlib \
		zeux:pugixml:ee86beb30e4973f5feffe3ce63bfa4fbadf72f38:pugixml/external/pugixml \
		libsdl-org:SDL:17656d051b750b945fdd8b4608f9524c7879bc1b:sdl/external/sdl \
		tcbrindle:sdl2-cmake-scripts:e037fb54f32973343fada6a051d3a3f8adf3a4a0:sdlcmakescripts/external/sdl2-cmake-scripts \
		gabime:spdlog:48bcf39a661a13be22666ac64db8a7f886f2637e:spdlog/external/spdlog \
		nothings:stb:f0569113c93ad095470c54bf34a17b36646bbbb5:stb/external/stb \
		wolfpld:tracy:5d542dc09f3d9378d005092a4ad446bd405f819a:tracy/external/tracy \
		vitasdk:vita-toolchain:77f17b979678e7af0acfe708dc97a45ca6fd55e2:vitatoolchain/external/vita-toolchain \
		Cyan4973:xxHash:e626a72bc2321cd320e953a0ccf1584cad60f363:xxhash/external/xxHash \
		jbeder:yaml-cpp:f7320141120f720aecc4c32be25586e7da9eb978:yamlcpp/external/yaml-cpp \
		Vita3K:unicorn:9c816e02de9a0fd7f68ce94766335a409ffac5e1:unicorn/external/unicorn \
		aquynh:capstone:accf4df62f1fba6f92cae692985d27063552601c:capstone/external/capstone

LDFLAGS=	-lexecinfo
CMAKE_OFF=	USE_VITA3K_UPDATE USE_DISCORD_RICH_PRESENCE USE_ALSA TRACY_LIBUNWIND_BACKTRACE

.include <bsd.port.mk>
