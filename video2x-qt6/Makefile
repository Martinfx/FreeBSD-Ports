PORTNAME=	video2x-qt6
DISTVERSION=	6.4.0-4
DISTVERSIONSUFFIX=	-g2c70706
CATEGORIES=	multimedia graphics

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Qt6 graphical user interface for Video2X
WWW=		https://github.com/k4yt3x/video2x-qt6

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers
LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libavutil.so:multimedia/ffmpeg \
		libfmt.so:devel/libfmt \
		libspdlog.so:devel/spdlog \
		libvideo2x.so:multimedia/video2x \
		libvulkan.so:graphics/vulkan-loader

USES=		cmake compiler:c++20-lang desktop-file-utils localbase:ldflags \
		pkgconfig qt:6
USE_GITHUB=	yes
GH_ACCOUNT=	k4yt3x
# A git describe-style DISTVERSION is not a fetchable ref, so point at the hash
GH_TAGNAME=	2c70706293c5c6cfe56db0a3a430d4468e3c402c
USE_QT=		base svg tools:build

# libvideo2x and spdlog come from the ports tree instead of the bundled
# submodules, which the GitHub tarball does not contain anyway.
CMAKE_ON=	USE_EXTERNAL_SPDLOG \
		USE_EXTERNAL_VIDEO2X
CMAKE_OFF=	USE_SHARED_VIDEO2X \
		VIDEO2X_ENABLE_NATIVE \
		VIDEO2X_ENABLE_X86_64_V3 \
		VIDEO2X_ENABLE_X86_64_V4

PLIST_FILES=	bin/video2x-qt6 \
		share/applications/video2x-qt6.desktop \
		share/icons/hicolor/16x16/apps/video2x.png \
		share/icons/hicolor/24x24/apps/video2x.png \
		share/icons/hicolor/32x32/apps/video2x.png \
		share/icons/hicolor/48x48/apps/video2x.png \
		share/icons/hicolor/64x64/apps/video2x.png \
		share/icons/hicolor/128x128/apps/video2x.png \
		share/icons/hicolor/256x256/apps/video2x.png \
		share/icons/hicolor/512x512/apps/video2x.png \
		share/icons/hicolor/1024x1024/apps/video2x.png

.include <bsd.port.mk>
