PORTNAME=	podman-desktop
PORTVERSION=	1.14.1
CATEGORIES=	deskutils
MASTER_SITES=	https://github.com/containers/podman-desktop/releases/download/v${PORTVERSION}/

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Graphical tool for developing on containers and Kubernetes
WWW=		https://podman-desktop.io

LICENSE=	APACHE20

ONLY_FOR_ARCHS=	amd64

USES=		desktop-file-utils electronfix:30 shared-mime-info

ELECTRONFIX_MAIN_EXECUTABLE=	podman-desktop
SUB_FILES=	podman-desktop
NO_BUILD=	yes

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/podman-desktop \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${PATCHDIR}/podman-desktop.desktop \
		${STAGEDIR}${DESKTOPDIR}/podman-desktop.desktop
	${INSTALL_DATA} ${PATCHDIR}/podman-desktop.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/podman-desktop.png

.include <bsd.port.mk>
