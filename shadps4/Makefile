PORTNAME=	shadps4
DISTVERSIONPREFIX=	v.
DISTVERSION=	0.7.0
CATEGORIES=	emulators

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	PlayStation 4 emulator written C++
WWW=		https://github.com/shadps4-emu/shadPS4

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	alsa-lib>0:audio/alsa-lib \
		date>0:devel/date \
		ffmpeg>0:multimedia/ffmpeg \
		rapidjson>0:devel/rapidjson \
		sndio>0:audio/sndio

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libavfilter.so:multimedia/ffmpeg \
		libavformat.so:multimedia/ffmpeg \
		libavutil.so:multimedia/ffmpeg \
		libcryptopp.so:security/cryptopp \
		libdate-tz.so:devel/date \
		libfmt.so:devel/libfmt \
		libinotify.so:devel/libinotify \
		libpng16.so:graphics/png \
		libpugixml.so:textproc/pugixml \
		libswresample.so:multimedia/ffmpeg \
		libswscale.so:multimedia/ffmpeg \
		libxxhash.so:devel/xxhash \
		libZycore.so:devel/zycore-c

USES=		cmake compiler:c++23-lang llvm:min=19 localbase pkgconfig qt:6 \
		ssl
USE_GL=		gl opengl
USE_QT=		base multimedia tools translations
USE_GITHUB=	yes
GH_ACCOUNT=	shadps4-emu
GH_PROJECT=	shadPS4
GH_TAGNAME=	d339b3f7d663ba89bb5b3cd572ead77b41b0f0a8
GH_TUPLE+=	shadps4-emu:ext-LibAtrac9:ec8899dadf393f655f2871a94e0fe4b3d6220c9a:libatrac/externals/LibAtrac9 \
		HowardHinnant:date:28b7b232521ace2c8ef3f2ad4126daec3569c14f:date/externals/date \
		shadps4-emu:ext-imgui:636cd4a7d623a2bc9bf59bb3acbb4ca075befba3:imgui/externals/dear_imgui \
		shadps4-emu:ext-discord-rpc:d3b5af8827031f3bccbf8c15d5dc1bfdc9467f17:discord/externals/discord-rpc \
		shadps4-emu:ext-boost:ca6f230e67be7cc45fc919057f07b2aee64dadc1:boost/externals/ext-boost \
		shadps4-emu:ext-fmt:8ee89546ffcf046309d1f0d38c0393f02fde56c8:fmt/externals/fmt \
		KhronosGroup:glslang:a0995c49ebcaca2c6d3b03efbabf74f3843decdb:glslang/externals/glslang \
		ROCm:half:1ddada225144cac0de8f6b5c0dd9acffd99a2e68:half/externals/half \
		pnggroup:libpng:c1cc0f3f4c3d4abd11ca68c59446a29ff6f95003:libpng/externals/libpng \
		Neargye:magic_enum:1a1824df7ac798177a521eed952720681b0bf482:magic/externals/magic_enum \
		zeux:pugixml:4bc14418d12d289dd9978fdce9490a45deeb653e:pugixml/externals/pugixml \
		Tessil:robin-map:fe845fd7852ef541c5479ae23b3d36b57f8608ee:robin/externals/robin-map \
		shadps4-emu:ext-SDL:a336b62d8b0b97b09214e053203e442e2b6e2be5:sdl/externals/sdl3 \
		shadps4-emu:sirit:427a42c9ed99b38204d9107bc3dc14e92458acf1:sirit/externals/sirit \
		KhronosGroup:SPIRV-Headers:2acb319af38d43be3ea76bfabf3998e5281d8d12:spirv/externals/sirit/externals/SPIRV-Headers \
		ToruNiina:toml11:7f6c574ff5aa1053534e7e19c0a4f22bf4c6aaca:toml/externals/toml11 \
		shadps4-emu:tracy:143a53d1985b8e52a7590a0daca30a0a7c653b42:tracy/externals/tracy \
		GPUOpen-LibrariesAndSDKs:VulkanMemoryAllocator:5a53a198945ba8260fbc58fadb788745ce6aa263:vma/externals/vma \
		KhronosGroup:Vulkan-Headers:a03d2f6d5753b365d704d58161825890baad0755:vulkan/externals/vulkan-headers \
		Cyan4973:xxHash:2bf8313b934633b2a5b7e8fd239645b85e10c852:xxhash/externals/xxhash \
		shadps4-emu:winpthreads:f00c973a6ab2a23573708568b8ef4acc20a9d36b:winpthreads/externals/winpthreads \
		herumi:xbyak:4e44f4614ddbf038f2a6296f5b906d5c72691e0f:xbyak/externals/xbyak \
		shadps4-emu:ext-zlib-ng:d54e3769be0c522015b784eca2af258b1c026107:zlib/externals/zlib-ng \
		zyantific:zydis:bffbb610cfea643b98e87658b9058382f7522807:zybis/externals/zydis \
		shadps4-emu:ext-cryptopp-cmake:2c384c28265a93358a2455e610e76393358794df:cmake/externals/cryptopp-cmake \
		shadps4-emu:ext-cryptopp:effed0d0b865afc23ed67e0916f83734e4b9b3b7:cryptopp/externals/cryptopp \
		zyantific:zycore-c:0b2432ced0884fd152b471d97ecf0258ff4d859f:zycore/externals/zydis/dependencies/zycore

LDFLAGS=	-L${LOCALBASE}/lib -ldate-tz -L/usr/lib -lusb
CXXFLAGS=	-I/usr/include
CMAKE_ON=	ENABLE_QT_GUI
CMAKE_ARGS=	-DLibUSB_LIBRARY="/usr/lib/libusb.so" -DCMAKE_BUILD_TYPE=Debug

PLIST_FILES=	bin/shadps4 \
		share/applications/net.shadps4.shadPS4.desktop \
		share/icons/hicolor/scalable/apps/net.shadps4.shadPS4.svg \
		share/metainfo/net.shadps4.shadPS4.metainfo.xml

.include <bsd.port.options.mk>

# Fix segmentation fault
.if ${ARCH} == i386 || ${ARCH} == amd64
CXXFLAGS+=	-DCRYPTOPP_DISABLE_ASM
.endif

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/dist/net.shadps4.shadPS4.desktop \
			${STAGEDIR}${DESKTOPDIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/src/images/net.shadps4.shadPS4.svg \
			${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${MKDIR} ${STAGEDIR}${PREFIX}/share/metainfo
	${INSTALL_DATA} ${WRKSRC}/dist/net.shadps4.shadPS4.metainfo.xml \
			${STAGEDIR}${PREFIX}/share/metainfo

.include <bsd.port.mk>

