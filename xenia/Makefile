PORTNAME=	xenia
DISTVERSION=	20250306
CATEGORIES=	emulators

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Xbox 360 Emulator Research Project 
WWW=		https://xenia.jp/

LICENSE=	UNKNOWN
LICENSE_NAME=	unknown
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

BUILD_DEPENDS=	premake5>0:devel/premake5 \
		gtk3>0:x11-toolkits/gtk30 \
		sdl2>0:devel/sdl20

USES=		gmake localbase
USE_GNOME=	gtk30
USE_GITHUB=	yes
GH_ACCOUNT=	xenia-project
GH_PROJECT=	xenia
GH_TAGNAME=	3d30b2eec3ab1f83140b09745bee881fb5d5dde2
GH_TUPLE+=	microsoft:DirectXShaderCompiler:6b6f40200bea5ed99367513f53f6a28e52fd3d0e:shadercompiler/third_party/DirectXShaderCompiler \
		xenia-project:FFmpeg:15ece0882e8d5875051ff5b73c5a8326f7cee9f5:ffmpeg/third_party/FFmpeg \
		GPUOpen-Effects:FidelityFX-CAS:9fabcc9a2c45f958aff55ddfda337e74ef894b7f:cas/third_party/FidelityFX-CAS \
		GPUOpen-Effects:FidelityFX-FSR:a21ffb8f6c13233ba336352bdff293894c706575:fsr/third_party/FidelityFX-FSR \
		libsdl-org:SDL:55b03c7493a7abed33cf803d1380a40fa8af903f:sdl2/third_party/SDL2 \
		KhronosGroup:SPIRV-Tools:dd534e877e725c9bb6f751c427442456a05384e4:spirv/third_party/SPIRV-Tools \
		KhronosGroup:Vulkan-Headers:31aa7f634b052d87ede4664053e85f3f4d1d50d3:headers/third_party/Vulkan-Headers \
		GPUOpen-LibrariesAndSDKs:VulkanMemoryAllocator:51c8b56011303e94840370089f816b19dbe7edf0:allocator/third_party/VulkanMemoryAllocator \
		openluopworld:aes_128:b5b7f559cf4b1acbb506a7a8752bbe4adfdc3274:aes/third_party/aes_128 \
		xenia-project:capstone:f9c6a90489be7b3637ff1c7298e45efafe7cf1b9:capstone/third_party/capstone \
		catchorg:Catch2:62fd660583d3ae7a7886930b413c3c570e89786c:catch2/third_party/catch \
		skystrife:cpptoml:fededad7169e538ca47e11a9ee9251bc361a9a65:cpptoml/third_party/cpptoml \
		jarro2783:cxxopts:48e265dc4b347d3178e4458de81704e0d88047b2:cxxopts/third_party/cxxopts \
		HowardHinnant:date:9ea5654c1206e19245dc21d8a2c433e090c8c3f5:date/third_party/date \
		discordapp:discord-rpc:eff23a770a07c3574cb48f299736c461c576286b:rpc/third_party/discord-rpc \
		xenia-project:disruptorplus:5787e9cb7551c8c79cf9ce14f7be860dc907e9a4:disruptorplus/third_party/disruptorplus \
		fmtlib:fmt:27e3c0fe9b5dc99f339637ec2ea7efae5b945ab8:fmt/third_party/fmt \
		KhronosGroup:glslang:f4f1d8a352ca1908943aea2ad8c54b39b4879080:glslang/third_party/glslang \
		ocornut:imgui:81160fee56027226bc80b48e196d0332f5541a8c:imgui/third_party/imgui \
		Triang3l:premake-androidndk:e6132d3f7877f9ad361c634db35b708c41075e3a:ndk/third_party/premake-androidndk \
		JoelLinn:premake-cmake:91c646f638a6fbff20f0ea90769df8dcf62bc5e4:cmake/third_party/premake-cmake \
		xenia-project:premake-core:fe71eb790c7d085cd3c6a7b71a50167b4da06e69:core/third_party/premake-core \
		xenia-project:premake-export-compile-commands:59e3e55df8dd87eea70556f50d172a17f1c4b6d0:commands/third_party/premake-export-compile-commands \
		Tencent:rapidjson:d87b698d0fcc10a5f632ecbc80a9cb2a8fa094a5:rapidjson/third_party/rapidjson \
		xenia-project:snappy:303cd2c64c62c579a8592236f723b611afd3bc15:snappy/third_party/snappy \
		xenia-project:utfcpp:f295c4b9a1f4db635164ab4defc3938049152a3c:utf/third_party/utfcpp \
		xenia-project:xbyak:bc70e7e11ad37f207ece73330c5b72a55fef1ceb:xbyak/third_party/xbyak \
		Cyan4973:xxHash:4c881f796d6af27ef7d9c48f87817da0d3d75dc1:xxhash/third_party/xxhash

do-configure:
	cd ${WRKSRC} && premake5 --os=bsd gmake2
do-build:
	cd ${WRKSRC}/build && ${MAKE_ENV} ${MAKE_CMD} config=debug

.include <bsd.port.mk>
