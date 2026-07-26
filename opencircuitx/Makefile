PORTNAME=	opencircuitx
DISTVERSIONPREFIX=v
DISTVERSION=	1.0.0
CATEGORIES=	devel

MAINTAINER=	maxfx@hades
COMMENT=	Free, open-source EDA platform for VHDL and Verilog. HDL editor.
WWW=		https://github.com/openlab-x/OpenCircuitX

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libwx_gtk3u_core-3.2.so:x11-toolkits/wxgtk32 \
		libwx_baseu-3.2.so:x11-toolkits/wxgtk32 \
		libwx_gtk3u_stc-3.2.so:x11-toolkits/wxgtk32 \
		libwx_gtk3u_aui-3.2.so:x11-toolkits/wxgtk32 \
		libwx_baseu_net-3.2.so:x11-toolkits/wxgtk32

RUN_DEPENDS=	ghdl>0:cad/ghdl \
		verilator>0:cad/verilator \
		iverilog>0:cad/iverilog \
		yosys>0:cad/yosys \
		nextpnr>0:devel/nextpnr \
		openfpgaloader>0:cad/openfpgaloader

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	openlab-x
GH_PROJECT=	OpenCircuitX
GH_TAGNAME=	cbfb1f9

.include <bsd.port.mk>
