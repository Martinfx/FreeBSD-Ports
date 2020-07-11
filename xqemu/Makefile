# $FreeBSD$

PORTNAME=	xqemu
DISTVERSION=	0.1
CATEGORIES=	emulators

MAINTAINER=	maintainer@email.com
COMMENT=	emulator for xbox


LIB_DEPENDS=	libepoxy.so:graphics/libepoxy

USES=           libtool pkgconfig compiler:c11 gettext-runtime gl gmake

LICENSE=        GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	xqemu
GH_PROJECT=	xqemu
GH_TAGNAME=	42579ba3

GH_TUPLE+=	qemu:capstone:5f173b0:capstone	        \
		qemu:dtc:e543880:dtc/dtc   			        \
		qemu:keycodemapdb:6b3d716:qemu/ui/keycodemapdb \

HAS_CONFIGURE=  yes
MAKE_ENV+=      BSD_MAKE="${MAKE}" V=1

USE_GL+= 	gl

CONFIGURE_ARGS+= \
		--extra-cflags="-DXBOX=1 -march=native ${CFLAGS}"  \
		--target-list=i386-softmmu 			   \
		--enable-trace-backends="nop" 		           \
#		--localstatedir=/var		       		   \
		--extra-ldflags=-L\"/usr/local/lib\"               \
		--extra-ldflags=-L\"${LOCALBASE}/lib\" 	           \
		--enable-debug    				   \
#		--prefix=${PREFIX} --cc=${CC} 			   \
#		--enable-netmap   	      \
#		--enable-docs                 \
		--enable-sdl		      \
#		--enable-opengl		      \
		--disable-kvm                 \
		--disable-linux-user	      \
		--disable-linux-aio           \
		--disable-xen 		      \
#		--enable-debug-info           \
		--disable-curl \
    		--disable-vnc \
    		--disable-vnc-sasl \
    		--disable-docs \
    		--disable-tools \
    		--disable-guest-agent \
    		--disable-tpm \
    		--disable-live-block-migration \
    		--disable-rdma \
    		--disable-replication \
    		--disable-capstone \
    		--disable-fdt \
    		--disable-libiscsi \
    		--disable-spice \
    		--disable-user \
    		--disable-stack-protector \
   	 	--disable-glusterfs \
    		--disable-bluez \
    		--disable-gtk \
    		--disable-curses \
    		--disable-gnutls \
    		--disable-nettle \
    		--disable-gcrypt \
    		--disable-crypto-afalg \
    		--disable-virglrenderer \
    		--disable-vhost-net \
    		--disable-vhost-crypto \
    		--disable-vhost-vsock \
    		--disable-vhost-user \
    		--disable-virtfs \
    		--disable-libssh2 \
    		--disable-snappy \
    		--disable-bzip2 \
    		--disable-vde \
    		--disable-libxml2 \
    		--disable-seccomp \
    		--disable-numa \
    		--disable-lzo \
    		--disable-smartcard \
    		--disable-usb-redir \
    		--disable-bochs \
    		--disable-cloop \
    		--disable-dmg \
    		--disable-vdi \
    		--disable-vvfat \
    		--disable-qcow1 \
    		--disable-qed \
    		--disable-parallels \
    		--disable-sheepdog \
    		--without-default-devices \
    		--disable-blobs \
		--python=${PYTHON_CMD} 	      \
		--extra-cflags=-I${WRKSRC}    \
		-I${LOCALBASE}/include -DPREFIX=\\\"\"${PREFIX}

.include <bsd.port.mk>

.if !defined(STRIP) || ${STRIP} == ""
CONFIGURE_ARGS+=--disable-strip
.endif

.if ${ARCH} == "amd64"
MAKE_ARGS+=	ARCH=x86_64
.endif

.if ${ARCH} == "powerpc"
MAKE_ARGS+=	ARCH=ppc
.endif

.if ${ARCH} == "powerpc64"
MAKE_ARGS+=	ARCH=ppc64
.endif

.if ${ARCH} == "sparc64"
CONFIGURE_ARGS+=	--sparc_cpu=v9
.endif

PLIST_SUB+=	LINUXBOOT_DMA=""

post-patch-CDROM_DMA-off:
	@${REINPLACE_CMD} -e '/USE_DMA_CDROM/d' ${WRKSRC}/include/hw/ide/internal.h
