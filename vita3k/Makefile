PORTNAME=	vita3k
DISTVERSION=	G20250828
CATEGORIES=	emulators
MASTER_SITES=	https://ffmpeg.org/releases/:ffmpeg
DISTFILES=	ffmpeg-${FFMPEG_VERSION}.tar.xz:ffmpeg

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Experimental PlayStation Vita emulator
WWW=		https://vita3k.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.txt

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	JIT and guest memory fault handling are only ported to x86_64 on FreeBSD

BUILD_DEPENDS=	gmake:devel/gmake \
		nasm:devel/nasm
LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs \
		libcurl.so:ftp/curl \
		libSDL3.so:devel/sdl3
RUN_DEPENDS=	vulkan-loader>0:graphics/vulkan-loader

USES=		cmake compiler:c++20-lang desktop-file-utils gl localbase:ldflags \
		pkgconfig ssl
USE_GL=		gl
USE_GITHUB=	yes
GH_ACCOUNT=	Vita3K
GH_PROJECT=	Vita3K
GH_TAGNAME=	4e526f0c8057e4eae0e00a323d7d4c58cdee8813
GH_TUPLE=	Vita3K:LibAtrac9:82767fe38823c32536726ea798f392b0b49e66b9:libatrac/external/LibAtrac9 \
		KhronosGroup:SPIRV-Cross:bccaa94db814af33d8ef05c153e7c34d8bd4d685:spirv/external/SPIRV-Cross \
		YaaZ:VulkanMemoryAllocator-Hpp:2059f0fdd73492b03d60a90c73e5038224b99093:vulkanmemory/external/VulkanMemoryAllocator-Hpp \
		KhronosGroup:Vulkan-Headers:952f776f6573aafbb62ea717d871cd1d6816c387:header/external/VulkanMemoryAllocator-Hpp/Vulkan-Headers \
		GPUOpen-LibrariesAndSDKs:VulkanMemoryAllocator:c788c52156f3ef7bc7ab769cb03c110a53ac8fcb:allocator/external/VulkanMemoryAllocator-Hpp/VulkanMemoryAllocator \
		aantron:better-enums:c35576bed0295689540b39873126129adfa0b4c8:better/external/better-enums \
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
		gabime:spdlog:48bcf39a661a13be22666ac64db8a7f886f2637e:spdlog/external/spdlog \
		nothings:stb:f0569113c93ad095470c54bf34a17b36646bbbb5:stb/external/stb \
		wolfpld:tracy:5d542dc09f3d9378d005092a4ad446bd405f819a:tracy/external/tracy \
		vitasdk:vita-toolchain:77f17b979678e7af0acfe708dc97a45ca6fd55e2:vitatoolchain/external/vita-toolchain \
		Cyan4973:xxHash:e626a72bc2321cd320e953a0ccf1584cad60f363:xxhash/external/xxHash \
		jbeder:yaml-cpp:f7320141120f720aecc4c32be25586e7da9eb978:yamlcpp/external/yaml-cpp \
		Vita3K:unicorn:9c816e02de9a0fd7f68ce94766335a409ffac5e1:unicorn/external/unicorn \
		aquynh:capstone:accf4df62f1fba6f92cae692985d27063552601c:capstone/external/capstone

CMAKE_ARGS=	-DFFMPEG_PREBUILT_LIBDIR:PATH=${FFMPEG_PREFIX}/lib \
		-DUSE_LTO:STRING=NEVER
CMAKE_ON=	DYNARMIC_USE_BUNDLED_EXTERNALS VITA3K_FORCE_SYSTEM_BOOST
CMAKE_OFF=	USE_ALSA USE_DISCORD_RICH_PRESENCE USE_VITA3K_UPDATE

# Keep the build from picking up git metadata of an enclosing ports tree
CONFIGURE_ENV=	GIT_CEILING_DIRECTORIES=${WRKDIR}
LDFLAGS+=	-lexecinfo

OPTIONS_SINGLE=		DIALOG
OPTIONS_SINGLE_DIALOG=	GTK3 PORTAL
OPTIONS_DEFAULT=	GTK3
DIALOG_DESC=		File dialog backend

GTK3_DESC=		Native GTK 3 file dialogs
GTK3_USES=		gnome
GTK3_USE=		GNOME=gtk30

PORTAL_DESC=		File dialogs through xdg-desktop-portal (D-Bus)
PORTAL_LIB_DEPENDS=	libdbus-1.so:devel/dbus
PORTAL_CMAKE_BOOL=	NFD_PORTAL

DESKTOP_ENTRIES=	"Vita3K" "PlayStation Vita emulator" \
			"${PREFIX}/share/pixmaps/${PORTNAME}.png" "Vita3K" \
			"Game;Emulator;" false

# Vita3K relies on internals of FFmpeg 5.1 (libavcodec/codec_internal.h),
# so build the same static FFmpeg as upstream instead of using multimedia/ffmpeg.
FFMPEG_VERSION=	5.1.2
FFMPEG_WRKSRC=	${WRKDIR}/ffmpeg-${FFMPEG_VERSION}
FFMPEG_PREFIX=	${WRKDIR}/ffmpeg-static
FFMPEG_CONFIGURE_ARGS=	--prefix=${FFMPEG_PREFIX} \
			--cc="${CC}" \
			--extra-cflags="${CFLAGS:N-isystem:N${LOCALBASE}/include}" \
			--disable-shared \
			--enable-static \
			--enable-pic \
			--disable-doc \
			--disable-programs \
			--disable-debug \
			--enable-runtime-cpudetect \
			--disable-autodetect \
			--disable-everything \
			--disable-avdevice \
			--enable-decoder=aac,aac_latm,atrac3,atrac3p,atrac9,mp3,pcm_s16le,pcm_s8,h264,mpeg4,mpeg2video,mjpeg,mjpegb \
			--enable-encoder=pcm_s16le,ffv1,mpeg4,mjpeg \
			--enable-muxer=avi \
			--enable-demuxer=h264,m4v,mp3,mpegvideo,mpegps,mjpeg,mov,avi,aac,pmp,oma,pcm_s16le,pcm_s8,wav \
			--enable-parser=h264,mpeg4video,mpegaudio,mpegvideo,mjpeg,aac,aac_latm \
			--enable-protocol=file \
			--enable-bsf=mjpeg2jpeg

post-patch:
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|g' \
		${WRKSRC}/vita3k/app/src/app_init.cpp

# The ports framework passes ARCH=amd64 and DESTDIR down to sub-makes via
# MAKEFLAGS/MAKE_ENV. FFmpeg uses ARCH as its arch directory name (x86) and
# silently skips the x86 SIMD objects otherwise, so reset both.
pre-configure:
	cd ${FFMPEG_WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${SH} ./configure \
		${FFMPEG_CONFIGURE_ARGS}
	cd ${FFMPEG_WRKSRC} && ${SETENV} -u MAKEFLAGS -u MFLAGS -u MAKELEVEL \
		-u ARCH ${MAKE_ENV} DESTDIR= ${LOCALBASE}/bin/gmake \
		-j${MAKE_JOBS_NUMBER} install ARCH=x86 DESTDIR=
	@${TEST} -f ${FFMPEG_PREFIX}/lib/libavutil.a || \
		(${ECHO_MSG} "===> FFmpeg was not installed into ${FFMPEG_PREFIX}"; ${FALSE})
	@nm ${FFMPEG_PREFIX}/lib/libavutil.a | ${GREP} -q ' T ff_get_cpu_flags_x86' || \
		(${ECHO_MSG} "===> FFmpeg was built without its x86 code"; \
		${GREP} '^ARCH' ${FFMPEG_WRKSRC}/ffbuild/config.mak; ${FALSE})
	@${ECHO_MSG} "===> Bundled FFmpeg ${FFMPEG_VERSION} built with x86 code"

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/bin/Vita3K ${STAGEDIR}${PREFIX}/bin
	${RLN} ${STAGEDIR}${PREFIX}/bin/Vita3K ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "data lang" ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/vita3k && ${COPYTREE_SHARE} shaders-builtin ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/data/image/icon.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

.include <bsd.port.mk>
