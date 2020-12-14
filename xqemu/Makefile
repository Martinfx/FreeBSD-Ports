# $FreeBSD$

PORTNAME=	xqemu
DISTVERSION=	1.0
CATEGORIES=	emulators

MAINTAINER=	maintainer@email.com
COMMENT=	XQEMU is an open-source emulator to play original Xbox games

LICENSE=	GPLv2
LICENSE_FILE=	$(WRKSRC)/COPYING

BUILD_DEPENDS=	pcre2>=10.35:devel/pcre2

LIB_DEPENDS=	libepoxy.so:graphics/libepoxy    \
		libnettle.so:security/nettle     \
		libgnutls.so:security/gnutls     \
		libcurl.so:ftp/curl		 \
		libudev.so:devel/libudev-devd    \
		libssh2.so:security/libssh2	 \
		libxkbcommon.so:x11/libxkbcommon \
		libpcre2-32.so:devel/pcre2       \
		libpng16.so:graphics/png	 \
		libsasl2.so:security/cyrus-sasl2 \
		liblzo2.so:archivers/lzo2	 \
		libsnappy.so:archivers/snappy    \
		libvdeplug.so:net/vde2		 \
		libfdt.so:sysutils/dtc

USES=		compiler:c11 gmake localbase:ldflags gettext-runtime jpeg iconv:wchar_t

USE_GITHUB=	yes
GH_ACCOUNT=	xqemu
GH_PROJECT=	xqemu
GH_TAGNAME=	e1236e1

GH_TUPLE+=	qemu:capstone:5f173b0:capstone				\
		qemu:dtc:e543880:dtc/dtc				\
		qemu:keycodemapdb:6b3d716:xqemu/ui/keycodemapdb		\
		qemu:QemuMacDrivers:90c488d:qemu/roms/QemuMacDrivers	\
		qemu:SLOF:a5b428e:roms/SLOF				\
		tianocore:edk2:8558838:tianocore/roms/edk2		\
		qemu:ipxe:de4565c:roms/ipxe				\
		qemu:openbios:3464681:roms/openbios			\
		qemu:openhackware:c559da7:roms/openhackware		\
		qemu:qemu-palcode:bf0e136:roms/palcode			\
		qemu:seabios:a5cab58:roms/seabios			\
		hdeller:seabios-hppa:0f4fe84:roms/seabios-hppa		\
		qemu:sgabios:cbaee52:roms/sgabios			\
		qemu:skiboot:261ca8e:roms/skiboot			\
		qemu:u-boot:d368926:roms/u-boot				\
		qemu:u-boot-sam460ex:60b3916:roms/u-boot-sam460ex	\
		cota:berkeley-softfloat-3:b64af41:test/fp/berkeley-softfloat-3 \
		cota:berkeley-testfloat-3:5a59dce:test/fp/berkeley-testfloat-3

HAS_CONFIGURE= 	yes
USE_GL=		gl
USE_GNOME=	atk cairo gtk30 glib20 pango gdkpixbuf2 libxml2 vte3
USE_SDL=	sdl2 image2
USE_XORG=	pixman x11

CONFIGURE_ARGS+= \
            	--extra-cflags="-DXBOX=1 -march=native" \
            	--target-list="i386-softmmu"  \
            	--enable-trace-backends="nop" \
#            	--enable-debug \
            	--enable-sdl		      \
           	--enable-opengl		      \
		--enable-bsd-user	      \
            	--disable-kvm                 \
            	--disable-linux-user	      \
            	--disable-linux-aio           \
            	--disable-xen 		      \
           	--enable-debug-info \
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
    		--python=${PYTHON_CMD}

.include <bsd.port.options.mk>

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

#post-patch-CDROM_DMA-off:
#	@${REINPLACE_CMD} -e '/USE_DMA_CDROM/d' ${WRKSRC}/include/hw/ide/internal.h

# XXX need to disable usb host code on head while it's not ported to the
# new usb stack ye
post-configure:
	@${REINPLACE_CMD} -E \
		-e "s|^(HOST_USB=)bsd|\1stub|" \
		${WRKSRC}/config-host.mak

.if !target(post-install)
post-install:
#	${INSTALL_SCRIPT} ${FILESDIR}/qemu-ifup.sample ${STAGEDIR}${PREFIX}/etc
#	${INSTALL_SCRIPT} ${FILESDIR}/qemu-ifdown.sample ${STAGEDIR}${PREFIX}/etc
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/qemu-*

post-install-DOCS-on:
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} docs ${STAGEDIR}${DOCSDIR}/)
.endif

.include <bsd.port.mk>
