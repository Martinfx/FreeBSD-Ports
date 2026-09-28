PORTNAME=	blender
DISTVERSION=	5.2.2
PORTEPOCH=	1
CATEGORIES=	graphics multimedia
MASTER_SITES=	http://download.blender.org/source/ \
		http://mirror.cs.umn.edu/blender.org/source/ \
		http://public.planetmirror.com/pub/blender/source/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	FreeBSD@Shaneware.biz
COMMENT=	3D modeling/rendering/animation package
WWW=		https://www.blender.org/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/doc/license/GPL3-license.txt

ONLY_FOR_ARCHS=	aarch64 amd64 powerpc64le riscv64
ONLY_FOR_ARCHS_REASON=	upstream supports 64-bit little-endian platforms only

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=2.0:math/py-numpy@${PY_FLAVOR}
# OpenColorIO and OpenEXR are no longer optional
LIB_DEPENDS=	libepoxy.so:graphics/libepoxy \
		libexpat.so:textproc/expat2 \
		libfmt.so:devel/libfmt \
		libfreetype.so:print/freetype2 \
		libImath.so:math/Imath \
		libOpenColorIO.so:graphics/opencolorio \
		libOpenEXR.so:graphics/openexr \
		libOpenImageIO.so:graphics/openimageio \
		libpng.so:graphics/png \
		libpystring.so:devel/pystring \
		libsamplerate.so:audio/libsamplerate \
		libtiff.so:graphics/tiff \
		libyaml-cpp.so:devel/yaml-cpp \
		libzstd.so:archivers/zstd
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR}

# Python 3.13 is the minimum since blender 5.1.  While the ports tree defaults to
# an older python, math/py-numpy only has a flavor for that default one:
# DEPENDS_ARGS lets "make" build its py313 flavor, poudriere needs
# DEFAULT_VERSIONS+=python=3.13 (or BUILD_ALL_PYTHON_FLAVORS=yes) in make.conf.
USES=		cmake:noninja compiler:c++20-lang cpe eigen:3 jpeg \
		llvm:build,run minizip pkgconfig python:3.13+ shebangfix \
		tar:xz xorg
DEPENDS_ARGS+=	BUILD_ALL_PYTHON_FLAVORS=yes
USE_XORG=	x11 xext xfixes xmu xrender

SHEBANG_FILES=	scripts/modules/blend_render_info.py

CMAKE_ARGS=	-DCMAKE_CXX_STANDARD:INTEGER=20 \
		-DCMAKE_POLICY_DEFAULT_CMP0167=NEW \
		-DLLVM_CONFIG:STRING="${LOCALBASE}/bin/llvm-config${LLVM_VERSION}" \
		-DPYTHON_VERSION=${PYTHON_VER}
.if defined(WITH_DEBUG)
CMAKE_ARGS+=	-DWITH_GHOST_DEBUG:BOOL=ON
.endif
CMAKE_ON=	WITH_AUDASPACE WITH_CLANG WITH_GHOST_X11 WITH_GHOST_XDND \
		WITH_HYDRA WITH_IO_PLY WITH_IO_STL WITH_IO_WAVEFRONT_OBJ \
		WITH_LLVM WITH_OPENGL_BACKEND WITH_PYTHON WITH_SYSTEM_FREETYPE \
		WITH_X11_XFIXES WITH_X11_XINPUT
CMAKE_OFF=	LLVM_STATIC WITH_GHOST_SDL WITH_INSTALL_PORTABLE \
		WITH_LIBS_PRECOMPILED WITH_MEM_VALGRIND WITH_NANOVDB \
		WITH_PYTHON_INSTALL WITH_PYTHON_INSTALL_NUMPY
# AMD HIP needs ROCm, which FreeBSD lacks (drm-kmod has no amdkfd), so the HIP
# device could never list a GPU and would only confuse AMD users.
CMAKE_OFF+=	WITH_CYCLES_DEVICE_HIP
# WITH_GPU_SHADER_CPP_COMPILATION only compiles the GPU shaders as C++ to check
# them, WITH_LINKER_MOLD would use mold whenever it happens to be installed and
# the TBB malloc proxy only replaces malloc on Linux and macOS.
CMAKE_OFF+=	WITH_GPU_SHADER_CPP_COMPILATION WITH_LINKER_MOLD \
		WITH_TBB_MALLOC_PROXY

CFLAGS+=	${CFLAGS_${CHOSEN_COMPILER_TYPE}} -I${LOCALBASE}/include/Imath
CFLAGS_gcc=	-Wno-float-conversion
CXXFLAGS+=	-DGLOG_USE_GLOG_EXPORT
LDFLAGS+=	-lexecinfo -Wl,--undefined-version

SUB_FILES=	blender
PLIST_SUB+=	VER=${DISTVERSION:R}
OPTIONS_SUB=	yes

# Cycles CUDA kernels (CYCLES_CUDA option), must match DISTVERSION
CUDA_KERNELS_PYTAG=	cp313
CUDA_KERNELS_WHL=	bpy-${DISTVERSION}-${CUDA_KERNELS_PYTAG}-${CUDA_KERNELS_PYTAG}-manylinux_2_28_x86_64.whl
CUDA_KERNELS_DIR=	bpy/${DISTVERSION:R}/scripts/addons_core/cycles/lib

.include "${.CURDIR}/Makefile.options"

ALEMBIC_CMAKE_BOOL=		WITH_ALEMBIC
ALEMBIC_LIB_DEPENDS=		libAlembic.so:graphics/alembic
# CPUISA (amd64): the -march level reaches get_compiler_simd_flags() through
# BLENDER_X86_MARCH, WITH_COMPILER_SIMD (on by default) adds it to the compiler
# flags.  The build host must support the chosen level as build tools run during
# the build.
AVX_CMAKE_ON=			-DBLENDER_X86_MARCH:STRING="x86-64-v2 -mavx"
AVX2_CMAKE_ON=			-DBLENDER_X86_MARCH:STRING=x86-64-v3
AVX512_CMAKE_ON=		-DBLENDER_X86_MARCH:STRING=x86-64-v4
BULLET_CMAKE_BOOL=		WITH_BULLET
CAMERATRACK_CMAKE_BOOL=		WITH_LIBMV WITH_SYSTEM_GLOG
CAMERATRACK_LIB_DEPENDS=	libceres.so:math/ceres-solver \
				libglog.so:devel/glog
CINEON_CMAKE_BOOL=		WITH_IMAGE_CINEON
CYCLES_CMAKE_BOOL=		WITH_CYCLES
CYCLES_IMPLIES=			TBB
CYCLES_LDFLAGS=			-L${LOCALBASE}/lib -lgflags
CYCLES_LIB_DEPENDS=		libgflags.so:devel/gflags
# FreeBSD has neither nvcc nor a native libcuda.so, and Cycles lists CUDA
# devices only when precompiled kernels exist.  Take the kernels the Blender
# Foundation built for this exact release from the official bpy wheel, and
# let the blender wrapper load the Linux libcuda through nv-sglrun.  libc6-shim
# is not in RUN_DEPENDS: it pulls in ruby, which machines without an NVIDIA GPU
# don't need, and the wrapper asks for it once the nvidia kernel module is
# loaded.
CYCLES_CUDA_CMAKE_ON=		-DWITH_CUDA_DYNLOAD:BOOL=ON \
				-DWITH_CYCLES_CUDA_BINARIES:BOOL=OFF \
				-DWITH_CYCLES_DEVICE_CUDA:BOOL=ON
CYCLES_CUDA_DISTFILES=		${CUDA_KERNELS_WHL}:cudakernels
CYCLES_CUDA_IMPLIES=		CYCLES
CYCLES_CUDA_MASTER_SITES=	https://files.pythonhosted.org/packages/${CUDA_KERNELS_PYTAG}/b/bpy/:cudakernels
CYCLES_CUDA_SUB_FILES=		pkg-message
CYCLES_CUDA_SUB_LIST=		NV_SGLRUN=yes
CYCLES_CUDA_SUB_LIST_OFF=	NV_SGLRUN=no
CYCLES_EMBR_CMAKE_BOOL=		WITH_CYCLES_EMBREE
CYCLES_EMBR_IMPLIES=		CYCLES
CYCLES_EMBR_LIB_DEPENDS=	libembree4.so:graphics/embree
CYCLES_ONEAPI_CMAKE_BOOL=	WITH_CYCLES_DEVICE_ONEAPI
CYCLES_ONEAPI_LIB_DEPENDS=	libtbb.so:devel/onetbb
CYCLES_OSL_CMAKE_BOOL=		WITH_CYCLES_OSL
CYCLES_OSL_CMAKE_ON=		-DOSL_SHADER_DIR:STRING="${LOCALBASE}/share/openshadinglanguage/shaders"
CYCLES_OSL_IMPLIES=		CYCLES PUGIXML
CYCLES_OSL_LIB_DEPENDS=		liboslcomp.so:graphics/openshadinglanguage
DRACO_CMAKE_BOOL=		WITH_DRACO
DRACO_LIB_DEPENDS=		libdraco.so:archivers/draco
EBOOL_CMAKE_BOOL=		WITH_GMP
EBOOL_LIB_DEPENDS=		libgmp.so:math/gmp
FFMPEG_CMAKE_BOOL=		WITH_CODEC_FFMPEG
FFMPEG_LDFLAGS=			-L${LOCALBASE}/lib -lflite -lflite_cmu_us_kal \
				-lflite_cmulex -lflite_usenglish
FFMPEG_LIB_DEPENDS=		libavutil.so:multimedia/ffmpeg \
				libflite.so:audio/flite
FFTW3_CMAKE_BOOL=		WITH_FFTW3
FFTW3_LIB_DEPENDS=		libfftw3.so:math/fftw3 \
				libfftw3f.so:math/fftw3-float
FREESTYLE_CMAKE_BOOL=		WITH_FREESTYLE
FRIBIDI_CMAKE_BOOL=		WITH_FRIBIDI
FRIBIDI_LIB_DEPENDS=		libfribidi.so:converters/fribidi
HARFBUZZ_CMAKE_BOOL=		WITH_HARFBUZZ
HARFBUZZ_LIB_DEPENDS=		libharfbuzz.so:print/harfbuzz
HARU_CMAKE_BOOL=		WITH_HARU
HARU_LIB_DEPENDS=		libhpdf.so:print/libharu
HEADLESS_CMAKE_BOOL=		WITH_HEADLESS
HEADLESS_PREVENTS=		MENU XF86VMODE XINPUT
HEADLESS_PREVENTS_MSG=		X11 options can't be used in headless mode
INPUT_NDOF_CMAKE_BOOL=		WITH_INPUT_NDOF
INPUT_NDOF_LIB_DEPENDS=		libspnav.so:misc/libspnav
JACK_CMAKE_BOOL=		WITH_JACK WITH_JACK_DYNLOAD
JACK_LIB_DEPENDS=		libjack.so:audio/jack
MANIFOLD_CMAKE_BOOL=		WITH_MANIFOLD
MANIFOLD_LIB_DEPENDS=		libmanifold.so:math/manifold
MATERIALX_CMAKE_BOOL=		WITH_MATERIALX
MATERIALX_CMAKE_ON=		-DMaterialX_DIR:STRING=${LOCALBASE}/lib/cmake/MaterialX \
				-DMATERIALX_PYTHON_DIR:STRING=${PYTHON_SITELIBDIR}/MaterialX \
				-DMATERIALX_STDLIB_DIR:STRING=${LOCALBASE}/share/materialx
MATERIALX_LIB_DEPENDS=		libMaterialXCore.so:graphics/materialx \
				libMaterialXFormat.so:graphics/materialx
MENU_USES=			desktop-file-utils
MESHOPTIMIZER_CMAKE_BOOL=	WITH_MESHOPTIMIZER
MESHOPTIMIZER_LIB_DEPENDS=	libmeshoptimizer.so:misc/meshoptimizer
MOD_FLUID_CMAKE_BOOL=		WITH_MOD_FLUID
MOD_FLUID_IMPLIES=		TBB
MOD_OCEANSIM_CMAKE_BOOL=	WITH_MOD_OCEANSIM
MOD_OCEANSIM_IMPLIES=		FFTW3
MOD_REMESH_CMAKE_BOOL=		WITH_MOD_REMESH
NATIVE_CMAKE_ON=		-DBLENDER_X86_MARCH:STRING=native \
				-DWITH_CYCLES_NATIVE_ONLY:BOOL=ON
NLS_CMAKE_BOOL=			WITH_INTERNATIONAL
NLS_USES=			gettext-tools
OPENAL_CMAKE_BOOL=		WITH_OPENAL
OPENAL_USES=			openal:al,alut
OPENIMAGEDN_CMAKE_BOOL=		WITH_OPENIMAGEDENOISE
OPENIMAGEDN_IMPLIES=		TBB
OPENIMAGEDN_LIB_DEPENDS=	libOpenImageDenoise.so:graphics/oidn
OPENJPEG_CMAKE_BOOL=		WITH_IMAGE_OPENJPEG
OPENJPEG_LIB_DEPENDS=		libopenjp2.so:graphics/openjpeg
OPENPGL_CMAKE_BOOL=		WITH_CYCLES_PATH_GUIDING
OPENPGL_LIB_DEPENDS=		libopenpgl.so:graphics/openpgl
OPENSUBDIV_CMAKE_BOOL=		WITH_OPENSUBDIV
OPENSUBDIV_LIB_DEPENDS=		libosdCPU.so:graphics/opensubdiv
OPENVDB_CMAKE_BOOL=		WITH_OPENVDB WITH_OPENVDB_BLOSC
OPENVDB_IMPLIES=		TBB
OPENVDB_LIB_DEPENDS=		libopenvdb.so:misc/openvdb
OPENXR_CMAKE_BOOL=		WITH_XR_OPENXR
OPENXR_LIB_DEPENDS=		libopenxr_loader.so:graphics/openxr
PIPEWIRE_CMAKE_BOOL=		WITH_PIPEWIRE
PIPEWIRE_LIB_DEPENDS=		libpipewire-0.3.so:multimedia/pipewire
POTRACE_CMAKE_BOOL=		WITH_POTRACE
POTRACE_LIB_DEPENDS=		libpotrace.so:graphics/libpotrace
PUGIXML_CMAKE_BOOL=		WITH_IO_GREASE_PENCIL WITH_PUGIXML
# GP IO needs pugixml - turn it off with pugi
PUGIXML_LIB_DEPENDS=		libpugixml.so:textproc/pugixml
PULSEAUDIO_CMAKE_BOOL=		WITH_PULSEAUDIO WITH_PULSEAUDIO_DYNLOAD
PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio
QUADRIFLOW_CMAKE_BOOL=		WITH_QUADRIFLOW
RUBBERBAND_CMAKE_BOOL=		WITH_RUBBERBAND
RUBBERBAND_LIB_DEPENDS=		librubberband.so:audio/rubberband
SDL_CMAKE_BOOL=			WITH_SDL_AUDIO
SDL_USE=			SDL=sdl3
SDL_USES=			sdl
SNDFILE_CMAKE_BOOL=		WITH_CODEC_SNDFILE
SNDFILE_LIB_DEPENDS=		libsndfile.so:audio/libsndfile
# SSE2: no -march flag, and no SSE4.2 in Cycles (see extra-patch-simd-off and
# patch-intern_cycles_CMakeLists.txt).
SSE2_CMAKE_ON=			-DWITH_COMPILER_SIMD:BOOL=OFF
SSE2_EXTRA_PATCHES=		${PATCHDIR}/extra-patch-simd-off
SSE42_CMAKE_ON=			-DBLENDER_X86_MARCH:STRING=x86-64-v2
TBB_CMAKE_BOOL=			WITH_TBB
TBB_LIB_DEPENDS=		libtbb.so:devel/onetbb
THUMBNAILER_CMAKE_BOOL=		WITH_BLENDER_THUMBNAILER
TRACE_CMAKE_BOOL=		WITH_POTRACE
TRACE_LIB_DEPENDS=		libpotrace.so:graphics/libpotrace
#USD_BROKEN=			does not build with current USD port
# openusd with python support links the default python, build it with
# DEFAULT_VERSIONS+=python=3.13 too, or blender loads two libpython versions.
USD_CMAKE_BOOL=			WITH_USD
USD_IMPLIES=			TBB
USD_LIB_DEPENDS=		libusd_ms.so:graphics/openusd
VULKAN_BUILD_DEPENDS=		${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers
VULKAN_CMAKE_BOOL=		WITH_VULKAN_BACKEND
VULKAN_LDFLAGS=			-lshaderc_shared -lSPIRV-Tools-shared
VULKAN_LIB_DEPENDS=		libshaderc_shared.so:graphics/shaderc \
				libSPIRV-Tools-shared.so:graphics/spirv-tools \
				libvulkan.so:graphics/vulkan-loader
VULKAN_USES=			localbase:ldflags # only relevant in the case of most options off
WAYLAND_BUILD_DEPENDS=		wayland-protocols>=1.31:graphics/wayland-protocols \
				wayland>=1.12:graphics/wayland
WAYLAND_CATEGORIES=		wayland
WAYLAND_CMAKE_BOOL=		WITH_GHOST_WAYLAND WITH_GHOST_WAYLAND_DYNLOAD
WAYLAND_LIB_DEPENDS=		libxkbcommon.so:x11/libxkbcommon
WEBP_CMAKE_BOOL=		WITH_IMAGE_WEBP
WEBP_LIB_DEPENDS=		libwebp.so:graphics/webp
XINPUT_CMAKE_BOOL=		WITH_X11_XINPUT
XINPUT_USE=			XORG=xi

.include <bsd.port.options.mk>

.if ${ARCH} == aarch64
# NEON through sse2neon is no longer optional.  WITH_COMPILER_SIMD would build
# for -march=armv8.2-a+dotprod+fp16+lse, keep the baseline so that packages run
# on any ARMv8 CPU (CPUTYPE still applies).
BUILD_DEPENDS+=	${LOCALBASE}/include/sse2neon.h:devel/sse2neon
CMAKE_ARGS+=	-DWITH_COMPILER_SIMD:BOOL=OFF
.endif

post-extract-CYCLES_CUDA-on:
	@cd ${WRKDIR} && ${TAR} -xf ${DISTDIR}/${CUDA_KERNELS_WHL} \
		'${CUDA_KERNELS_DIR}/kernel_sm_*.cubin.zst' \
		'${CUDA_KERNELS_DIR}/kernel_compute_*.ptx.zst'

post-patch:
	${REINPLACE_CMD} -e 's|%%LLVM_VER%%|${LLVM_VERSION}|g' \
		${WRKSRC}/intern/cycles/kernel/osl/CMakeLists.txt

post-build:
	@(cd ${WRKSRC}/doc/manpage && \
		${PYTHON_CMD} blender.1.py \
			--blender ${INSTALL_WRKSRC}/bin/blender \
			--output ${INSTALL_WRKSRC}/bin/${PORTNAME}.1)

post-install:
	${INSTALL_MAN} ${INSTALL_WRKSRC}/bin/${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/share/man/man1
	${MV} ${STAGEDIR}/${PREFIX}/bin/blender ${STAGEDIR}/${PREFIX}/bin/blender-bin
	${INSTALL_SCRIPT} ${WRKDIR}/blender ${STAGEDIR}/${PREFIX}/bin/blender

post-install-CYCLES_CUDA-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}/${DISTVERSION:R}/scripts/addons_core/cycles/lib
	${INSTALL_DATA} ${WRKDIR}/${CUDA_KERNELS_DIR}/kernel_*.zst \
		${STAGEDIR}${DATADIR}/${DISTVERSION:R}/scripts/addons_core/cycles/lib

# the glTF bridge libraries are installed as PROGRAMS, which install/strip skips
post-install-DRACO-on:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/${DISTVERSION:R}/scripts/addons_core/io_scene_gltf2/libbf_intern_draco_bridge.so

post-install-MESHOPTIMIZER-on:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/${DISTVERSION:R}/scripts/addons_core/io_scene_gltf2/libbf_intern_meshopt_bridge.so

post-install-MENU-on:
	@-update-desktop-database -q

.include <bsd.port.mk>
