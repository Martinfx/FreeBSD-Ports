PORTNAME=	video2x
DISTVERSION=	6.4.0-21
DISTVERSIONSUFFIX=	-g7db9c18
CATEGORIES=	multimedia graphics

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Machine learning-based video super resolution and frame interpolation
WWW=		https://github.com/k4yt3x/video2x

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

# graphics/glslang's default flavor installs static libraries only, so there
# is no libglslang.so to link against: the glslang that the static libncnn.a
# references, and the glslangValidator that compiles the shaders, are both
# build dependencies.
BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers \
		${LOCALBASE}/lib/libglslang.a:graphics/glslang \
		${LOCALBASE}/lib/libncnn.a:misc/ncnn
LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libavfilter.so:multimedia/ffmpeg \
		libavformat.so:multimedia/ffmpeg \
		libavutil.so:multimedia/ffmpeg \
		libswscale.so:multimedia/ffmpeg \
		libboost_program_options.so:devel/boost-libs \
		libfmt.so:devel/libfmt \
		libspdlog.so:devel/spdlog \
		libvulkan.so:graphics/vulkan-loader

USES=		cmake compiler:c++20-lang localbase:ldflags pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	k4yt3x
GH_TUPLE=	k4yt3x:librealesrgan-ncnn-vulkan:c1f255524f79566c40866b38e5e65b40adf77eee:realesrgan/third_party/librealesrgan_ncnn_vulkan \
		k4yt3x:librealcugan-ncnn-vulkan:d9c5a7eb4c8475af6110496c27c3d1f702f9b96a:realcugan/third_party/librealcugan_ncnn_vulkan \
		k4yt3x:librife-ncnn-vulkan:f1de3a97c49e1bed4a625aa8eef92586a4871e74:rife/third_party/librife_ncnn_vulkan
USE_LDCONFIG=	yes

# The wrapper repositories carry their own copies of the models, the
# ones installed come from the main distfile.
EXTRACT_AFTER_ARGS=	--exclude 'librealcugan-ncnn-vulkan-*/models' \
			--exclude 'librife-ncnn-vulkan-*/models' \
			--no-same-owner --no-same-permissions

SUB_FILES=	pkg-message

# ncnn, spdlog and Boost come from the ports tree. The Real-ESRGAN,
# Real-CUGAN and RIFE wrappers are built as static libraries and linked
# into libvideo2x, so the static libncnn ends up there only once.
CMAKE_ON=	VIDEO2X_BUILD_CLI \
		VIDEO2X_USE_EXTERNAL_BOOST \
		VIDEO2X_USE_EXTERNAL_NCNN \
		VIDEO2X_USE_EXTERNAL_SPDLOG
CMAKE_OFF=	VIDEO2X_ENABLE_NATIVE \
		VIDEO2X_ENABLE_X86_64_V3 \
		VIDEO2X_ENABLE_X86_64_V4

OPTIONS_DEFINE=		QT6
OPTIONS_DEFAULT=	QT6
OPTIONS_SUB=		yes

QT6_DESC=		Build the video2x-qt6 graphical user interface

# The GUI has a repository of its own. It is extracted into gui/, where the
# patched top level CMakeLists.txt picks it up, so that the interface links
# against the libvideo2x built here instead of a second copy of it.
QT6_GH_TUPLE=		k4yt3x:video2x-qt6:2c70706293c5c6cfe56db0a3a430d4468e3c402c:qt6/gui
QT6_USES=		desktop-file-utils qt:6
QT6_USE=		QT=base,svg,tools:build
QT6_CMAKE_BOOL=		VIDEO2X_BUILD_QT6
QT6_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-gui_CMakeLists.txt \
			${PATCHDIR}/extra-patch-gui_src_mainwindow.cpp \
			${PATCHDIR}/extra-patch-gui_src_taskconfigdialog.cpp

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} 's|%%DATADIR%%|${DATADIR}|' ${WRKSRC}/src/fsutils.cpp
.if ${ARCH} != amd64
# Function multi-versioning uses x86-64-v3/v4 clones
	${REINPLACE_CMD} '/gnu::target_clones/d' ${WRKSRC}/src/*.cpp
.endif

.include <bsd.port.mk>
