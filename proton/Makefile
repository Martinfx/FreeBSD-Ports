PORTNAME=	Proton
DISTVERSION=	9.0-4
CATEGORIES=	devel

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Compatibility tool for Steam Play based \
		on Wine and additional components.

LICENSE=	unknown
LICENSE_NAME=	Valve license
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

USES=		gmake
USE_GITHUB=     yes
GH_ACCOUNT=     ValveSoftware
GH_PROJECT=     Proton
GH_TAGNAME=	b7cb2fc # Proton 9.0-4
GH_TUPLE+=	KhronosGroup:OpenXR-SDK:8899a91c17ce9618f565f42408b47db1d6e9ccc7:OpenXR/OpenXR-SDK \
		KhronosGroup:SPIRV-Headers:6cae8216a6ea19ff3f237af01e54378c1ff81fcd:SPIRV/SPIRV-Headers \
		KhronosGroup:Vulkan-Headers:31aa7f634b052d87ede4664053e85f3f4d1d50d3:Vulkan/Vulkan-Headers \
		videolan:dav1d:8a6f054ef1e0f7886bc6e53e6be97c427154fe85:videolan/dav1d \
		doitsujin:dxvk:d96fa54080320e9b63227e76124ffa50a927ced2:dxvk/dxvk \
		jp7677:dxvk-nvapi:afb59a8e841b0ad561250327eb6a370b925c5f03:dxvknvapi/dxvk-nvapi \
		FFmpeg:FFmpeg:a77521cd5d27e955b16e8097eecefc779ffdcb6d:ffmpeg/ffmpeg \
		KhronosGroup:glslang:df7fec2cfa966919172ee83bfcae6c9c9b3f91b8:glslang/glslang \
		ebassi:graphene:4e2578450809c2099400cf85caf18eafcd7100aa:graphene/graphene \
		GStreamer:orc:7d5bbada3f1c6cf34182abccf47a34d79b83fa97:orc/gsc-orc \
		sdroege:gst-plugin-rs:0205aa43d6d8c5d0c9d4e4f83e0a3aaa94acef89:gst/gst-plugins-rs \
		GStreamer:gstreamer:bf6ce1d64a0697e7910826147b48f8f658366a5a:gstreamer/gstreamer \
		ValveSoftware:openvr:f51d87ecf8f7903e859b0aa4d617ff1e5f33db5a:openvr/openvr \
		ValveSoftware:vkd3d:0c0a55c0382ca2149c30a07c4b85ea353567a5cc:vkd3d/vkd3d \
		HansKristian-Work:vkd3d-proton:4fd7d3ab3d351de4ad50576b1a9df0a45a4a7c74:vkd3dproton/vkd3d-proton \
		ValveSoftware:wine:3e4edd34b6f571276272fa1d8dbbbb2a32e9d0a9:wine/wine

GNU_CONFIGURE=		yes
GNU_CONFIGURE_PREFIX=	${PREFIX}/${PORTNAME}


.include <bsd.port.mk>
