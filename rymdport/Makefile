PORTNAME=	rymdport
DISTVERSIONPREFIX=v
DISTVERSION=	3.6.0
CATEGORIES=	net-im

MASTER_SITES=	https://salsa.debian.org/vasudev/gospake2/-/archive/d9162995/
DISTFILES=	gospake2-d9162995.tar.gz
MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Cross-platform application for easy encrypted file, \
		folder, and text sharing between devices.
WWW=		https://rymdport.github.io/

LICENSE=	GPLv3

USES=		go:1.22 go:modules pkgconfig xorg gl
USE_XORG=	x11 xau xi xcb xcursor xdmcp xrandr xinerama
USE_GL=		gl
USE_GITHUB=    yes
GH_ACCOUNT=    jacalz

GH_TUPLE=	\
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dominikh:go-js-dom:f030747120f2:dominikh_go_js_dom/vendor/honnef.co/go/js/dom \
		fredbi:uri:v1.0.0:fredbi_uri/vendor/github.com/fredbi/uri \
		fsnotify:fsnotify:v1.6.0:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		fyne-io:fyne:v2.4.4:fyne_io_fyne/vendor/fyne.io/fyne/v2 \
		fyne-io:gl-js:d2da28d9ccfe:fyne_io_gl_js/vendor/github.com/fyne-io/gl-js \
		fyne-io:glfw-js:ee7290d23504:fyne_io_glfw_js/vendor/github.com/fyne-io/glfw-js \
		fyne-io:image:4956b0afb3d2:fyne_io_image/vendor/github.com/fyne-io/image \
		fyne-io:systray:104f5ef7839e:fyne_io_systray/vendor/fyne.io/systray \
		fynelabs:fyneselfupdate:v0.1.1:fynelabs_fyneselfupdate/vendor/github.com/fynelabs/fyneselfupdate \
		fynelabs:selfupdate:v0.2.0:fynelabs_selfupdate/vendor/github.com/fynelabs/selfupdate \
		go-gl:gl:726fda9656d6:go_gl_gl/vendor/github.com/go-gl/gl \
		go-gl:glfw:93cebf72946b:go_gl_glfw_glfw/vendor/github.com/go-gl/glfw \
		go-text:render:35bccb6164b8:go_text_render/vendor/github.com/go-text/render \
		go-text:typesetting:v0.1.0:go_text_typesetting/vendor/github.com/go-text/typesetting \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		godbus:dbus:v5.1.0:godbus_dbus_v5/vendor/github.com/godbus/dbus/v5 \
		golang:crypto:v0.18.0:golang_crypto/../src/golang.org/x/crypto \
		golang:image:v0.11.0:golang_image/vendor/golang.org/x/image \
		golang:mobile:3c911d8e3eda:golang_mobile/vendor/golang.org/x/mobile \
		golang:net:v0.17.0:golang_net/vendor/golang.org/x/net \
		golang:sys:v0.16.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.14.0:golang_text/vendor/golang.org/x/text \
		gopherjs:gopherjs:v1.17.2:gopherjs_gopherjs/vendor/github.com/gopherjs/gopherjs \
		jsummers:gobmp:e2ba15ffa76e:jsummers_gobmp/vendor/github.com/jsummers/gobmp \
		klauspost:compress:v1.17.4:klauspost_compress/vendor/github.com/klauspost/compress \
		nhooyr:websocket:v1.8.10:nhooyr_websocket/vendor/nhooyr.io/websocket \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		rymdport:go-qrcode:v1.1.0:rymdport_go_qrcode/vendor/github.com/rymdport/go-qrcode \
		rymdport:wormhole:v0.1.0:rymdport_wormhole/vendor/github.com/rymdport/wormhole \
		srwiley:oksvg:be6e8873101c:srwiley_oksvg/vendor/github.com/srwiley/oksvg \
		srwiley:rasterx:2ab79fcdd4ef:srwiley_rasterx/vendor/github.com/srwiley/rasterx \
		stretchr:testify:v1.9.0:stretchr_testify/vendor/github.com/stretchr/testify \
		tevino:abool:v1.2.0:tevino_abool/vendor/github.com/tevino/abool \
		yuin:goldmark:v1.5.5:yuin_goldmark/vendor/github.com/yuin/goldmark 

pre-build:
	${MKDIR} ${WRKDIR}/src/salsa.debian.org/vasudev/gospake2;
	${TAR} -C ${WRKDIR}/src/salsa.debian.org/vasudev/gospake2 --strip-components=1 -xvf ${DISTDIR}/gospake2-d9162995.tar.gz;
	${REINPLACE_CMD} 's|github.com/Jacalz/rymdport/v3|rymdport|g' ${WRKSRC}/main.go ${WRKSRC}/internal/ui/about.go \
	${WRKSRC}/internal/ui/settings.go  ${WRKSRC}/internal/ui/send.go  ${WRKSRC}/internal/ui/recv.go ${WRKSRC}/internal/ui/tabs.go \
	${WRKSRC}/internal/transport/bridge/recv.go  ${WRKSRC}/internal/transport/bridge/send.go ${WRKSRC}/internal/transport/sender.go \
	${WRKSRC}/internal/transport/receiver.go
post-stage:
	${INSTALL_DATA} ${WRKSRC}/internal/assets/unix/io.github.jacalz.${PORTNAME}.desktop \
	       ${STAGEDIR}${DESKTOPDIR}
.for s in 16 24 32 48 64 128 256 512
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/
	${INSTALL_DATA} ${WRKSRC}/internal/assets/icons/icon-${s}.png \
        ${STAGEDIR}${PREFIX}/share/icons/hicolor/
.endfor
.include <bsd.port.mk>
