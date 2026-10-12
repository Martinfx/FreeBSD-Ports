MASTERDIR=	${.CURDIR}/../u-boot-master

MODEL=		bananapi-r64
BOARD_CONFIG=	mt7622_bananapi_bpi-r64_defconfig
FAMILY=		mt7622
UBOOT_ARCH=	aarch64

DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DISTINFO_FILE=	${.CURDIR}/distinfo
EXTRA_PATCHES=	${.CURDIR}/files/

# Mainline TF-A has no MT7622 support, use MediaTek's fork (as OpenWrt does)
USE_GITHUB=	nodefault
GH_TUPLE=	mtk-openwrt:arm-trusted-firmware:476cf6629f7675c9857b59458851dda64de88343:atf/atf

UBOOT_PLIST=	bl2.img fip.bin sdcard.img

# MAKE_ENV carries the host compiler and flags, TF-A would build with them
ATF_MAKE_ARGS=	ARCH=aarch64 PLAT=mt7622 BOOT_DEVICE=sdmmc DDR3_FLYBY=1 \
		CC=${CROSS_COMPILE}gcc CPP=${CROSS_COMPILE}gcc \
		CFLAGS= CPPFLAGS= LDFLAGS= HOSTCC=${CC} \
		OPENSSL_DIR=${OPENSSLBASE} USE_MKIMAGE=1 \
		MKIMAGE=${WRKSRC}/tools/mkimage BL33=${WRKSRC}/u-boot.bin V=1
ATF_BUILD=	${WRKSRC}/atf/build/mt7622/release

post-build:
	(cd ${WRKSRC}/atf; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${ATF_MAKE_ARGS} bl2 fip)
	${CP} ${ATF_BUILD}/bl2.img ${ATF_BUILD}/fip.bin ${WRKSRC}/
	${PYTHON_CMD} -I ${.CURDIR}/files/mksdimage.py ${WRKSRC}/bl2.img \
		${WRKSRC}/fip.bin ${WRKSRC}/sdcard.img

.include "${MASTERDIR}/Makefile"
