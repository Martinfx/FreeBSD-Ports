MASTERDIR=	${.CURDIR}/../u-boot-master

EXTRA_PATCHES=	${.CURDIR}/files/

MODEL=		coral-dev-board-mini
BOARD_CONFIG=	mt8516_pumpkin_defconfig
FAMILY=		mediatek
UBOOT_ARCH=	aarch64

UBOOT_PLIST=	u-boot.bin

CONFIG_FRAGMENT=	${.CURDIR}/files/coral-dev-board-mini_fragment
FRAGMENT_NAME=		coral-dev-board-mini_fragment

.include "${MASTERDIR}/Makefile"
