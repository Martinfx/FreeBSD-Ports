PORTNAME=	zydis
DISTVERSIONPREFIX=	v
DISTVERSION=	3.2.1
CATEGORIES=	devel

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Fast and lightweight x86/x86-64 disassembler library
WWW=		https://zydis.re

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=		aarch64 amd64 armv6 armv7 i386 powerpc powerpc64 powerpc64le riscv64
ONLY_FOR_ARCHS_REASON=	see definitions in include/Zycore/Defines.h

USES=		cmake cpe dos2unix localbase:ldflags
USE_GITHUB=	yes
DOS2UNIX_FILES=	src/String.c
GH_ACCOUNT=	zyantific
GH_TUPLE=	zyantific:zycore-c:7c33e13:zydis/dependencies/zycore
CPE_VENDOR=	zyantific

.include <bsd.port.mk>
