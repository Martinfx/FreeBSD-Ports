PORTNAME=	shadps4plus
DISTVERSIONPREFIX=	v.
DISTVERSION=	0.11.0
CATEGORIES=	emulators

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	PlayStation 4 emulator written C++
WWW=		https://github.com/shadps4-emu/shadPS4

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	alsa-lib>0:audio/alsa-lib \
		cryptopp>0:security/cryptopp \
		date>0:devel/date \
		ffmpeg>0:multimedia/ffmpeg \
		rapidjson>0:devel/rapidjson \
		sndio>0:audio/sndio \
		tracy>0:devel/tracy \
		vulkan-headers>0:graphics/vulkan-headers

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
		libuuid.so:misc/libuuid \
		libxxhash.so:devel/xxhash \
		libZycore.so:devel/zycore-c

USES=		cmake:noninja gmake llvm:min=21 localbase \
		pkgconfig qt:6 ssl
USE_GL=		gl opengl
USE_QT=		base multimedia tools translations
USE_GITHUB=	yes
GH_ACCOUNT=	AzaharPlus
GH_PROJECT=	shadPS4Plus
GH_TAGNAME=	edf0c21505299a3b9bccca1f04959f5f2fab9547
GH_TUPLE+=	shadps4-emu:ext-LibAtrac9:ec8899dadf393f655f2871a94e0fe4b3d6220c9a:libatrac/externals/LibAtrac9 \
		HowardHinnant:date:a45ea7c:date/externals/date \
		shadps4-emu:ext-imgui:f4d9359:imgui/externals/dear_imgui \
		shadps4-emu:ext-discord-rpc:19f66e6:discord/externals/discord-rpc \
		shadps4-emu:ext-boost:ca6f230e67be7cc45fc919057f07b2aee64dadc1:boost/externals/ext-boost \
		shadps4-emu:ext-fmt:64db979:fmt/externals/fmt \
		KhronosGroup:glslang:ba16404:glslang/externals/glslang \
		ROCm:half:1ddada225144cac0de8f6b5c0dd9acffd99a2e68:half/externals/half \
		pnggroup:libpng:c1cc0f3f4c3d4abd11ca68c59446a29ff6f95003:libpng/externals/libpng \
		libusb:libusb-cmake:8f0b4a38fc3eefa2b26a99dff89e1c12bf37afd4:libusb/externals/libusb \
		Neargye:magic_enum:1a1824df7ac798177a521eed952720681b0bf482:magic/externals/magic_enum \
		zeux:pugixml:4bc14418d12d289dd9978fdce9490a45deeb653e:pugixml/externals/pugixml \
		Tessil:robin-map:fe845fd7852ef541c5479ae23b3d36b57f8608ee:robin/externals/robin-map \
		shadps4-emu:ext-SDL:e9c2e9b:sdl/externals/sdl3 \
		shadps4-emu:sirit:282083a:sirit/externals/sirit \
		shadps4-emu:tracy:143a53d1985b8e52a7590a0daca30a0a7c653b42:tracy/externals/tracy \
		KhronosGroup:SPIRV-Headers:2acb319:spirv/externals/sirit/externals/SPIRV-Headers \
		ToruNiina:toml11:7f6c574ff5aa1053534e7e19c0a4f22bf4c6aaca:toml/externals/toml11 \
		GPUOpen-LibrariesAndSDKs:VulkanMemoryAllocator:5a53a198945ba8260fbc58fadb788745ce6aa263:vma/externals/vma \
		Cyan4973:xxHash:2bf8313b934633b2a5b7e8fd239645b85e10c852:xxhash/externals/xxhash \
		shadps4-emu:winpthreads:f00c973a6ab2a23573708568b8ef4acc20a9d36b:winpthreads/externals/winpthreads \
		herumi:xbyak:4e44f4614ddbf038f2a6296f5b906d5c72691e0f:xbyak/externals/xbyak \
		shadps4-emu:ext-hwinfo:351c59828a79958f74f3ccab5e7773ffd724f6f7:hwinfo/externals/hwinfo \
		shadps4-emu:ext-zlib-ng:d54e3769be0c522015b784eca2af258b1c026107:zlib/externals/zlib-ng \
		zyantific:zydis:120e0e7:zybis/externals/zydis \
		KhronosGroup:Vulkan-Headers:a01329f307fa6067da824de9f587f292d761680b:headers/externals/vulkan-headers \
		shadps4-emu:ext-cryptopp-cmake:2c384c28265a93358a2455e610e76393358794df:cmake/externals/cryptopp-cmake \
		shadps4-emu:ext-cryptopp:effed0d:cryptopp/externals/cryptopp \
		zyantific:zycore-c:38d4f02:zycore/externals/zydis/dependencies/zycore

LDFLAGS=	-L${LOCALBASE}/lib -ldate-tz -I/usr/include -L/usr/lib -lusb
CMAKE_ON=	ENABLE_QT_GUI

PLIST_FILES=	bin/shadps4 \
		share/applications/net.shadps4.shadPS4.desktop \
		share/icons/hicolor/scalable/apps/net.shadps4.shadPS4.svg \
		share/metainfo/net.shadps4.shadPS4.metainfo.xml

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/shadps4 ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/dist/net.shadps4.shadPS4.desktop \
			${STAGEDIR}${DESKTOPDIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/src/images/net.shadps4.shadPS4.svg \
			${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${MKDIR} ${STAGEDIR}${PREFIX}/share/metainfo
	${INSTALL_DATA} ${WRKSRC}/dist/net.shadps4.shadPS4.metainfo.xml \
			${STAGEDIR}${PREFIX}/share/metainfo

.include <bsd.port.mk>
