PORTNAME=	vivaldi
DISTVERSION=    5.3.2679
CATEGORIES=	www
MASTER_SITES=   https://source.vivaldi.com/
EXTRACT_SUFX=	tar.xz
DISTNAME=	${PORTNAME}-source_${DISTVERSION}.
MAINTAINER=	maintainer@maintainer.com
COMMENT=

#LICENSE=	vivaldi technologies
LICENSE_FILE=   ${WRKSRC}/LICENCE

WRKSRC=		${WRKDIR}/${PORTNAME}-source

BUILD_DEPENDS=	bash:shells/bash \
                ${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
                ${PYTHON_PKGNAMEPREFIX}ply>0:devel/py-ply@${PY_FLAVOR} \
                gperf:devel/gperf \
                flock:sysutils/flock \
                node:www/node \
                xcb-proto>0:x11/xcb-proto \
                ${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat \
                ${LOCALBASE}/share/usbids/usb.ids:misc/usbids \
                ${PYTHON_PKGNAMEPREFIX}html5lib>0:www/py-html5lib@${PY_FLAVOR} \
                ${LOCALBASE}/include/va/va.h:multimedia/libva \
                ${LOCALBASE}/libdata/pkgconfig/dri.pc:graphics/mesa-dri

LIB_DEPENDS=	libatk-bridge-2.0.so:accessibility/at-spi2-atk \
                libatspi.so:accessibility/at-spi2-core \
                libspeechd.so:accessibility/speech-dispatcher \
                libsnappy.so:archivers/snappy \
                libFLAC.so:audio/flac \
                libopus.so:audio/opus \
                libspeex.so:audio/speex \
                libdbus-1.so:devel/dbus \
                libdbus-glib-1.so:devel/dbus-glib \
                libicuuc.so:devel/icu \
                libjsoncpp.so:devel/jsoncpp \
                libpci.so:devel/libpci \
                libnspr4.so:devel/nspr \
                libre2.so:devel/re2 \
                libcairo.so:graphics/cairo \
                libdrm.so:graphics/libdrm \
                libexif.so:graphics/libexif \
                libpng.so:graphics/png \
                libwebp.so:graphics/webp \
                libopenh264.so:multimedia/openh264 \
                libfreetype.so:print/freetype2 \
                libharfbuzz.so:print/harfbuzz \
                libharfbuzz-icu.so:print/harfbuzz-icu \
                libgcrypt.so:security/libgcrypt \
                libsecret-1.so:security/libsecret \
                libnss3.so:security/nss \
                libexpat.so:textproc/expat2 \
                libfontconfig.so:x11-fonts/fontconfig \
                libwayland-client.so:graphics/wayland \
                libxkbcommon.so:x11/libxkbcommon \
                libxshmfence.so:x11/libxshmfence

RUN_DEPENDS=	xdg-open:devel/xdg-utils \
                noto-basic>0:x11-fonts/noto-basic

USES=		bison compiler:c++17-lang cpe desktop-file-utils gl gnome jpeg localbase:ldflags \
                ninja perl5 pkgconfig python:3.7+,build shebangfix tar:xz xorg

#CPE_VENDOR=	vivaldi
#CPE_PRODUCT=	chrome
USE_GL=		gbm gl
USE_GNOME=	atk dconf gdkpixbuf2 glib20 gtk30 libxml2 libxslt
USE_LDCONFIG=	${DATADIR}
USE_PERL5=	build
USE_XORG=	x11 xcb xcomposite xcursor xext xdamage xfixes xi \
                xorgproto xrandr xrender xscrnsaver xtst
#SHEBANG_FILES=	chromium/chrome/tools/build/linux/chrome-wrapper chromium/buildtools/linux64/clang-format

#BUILD_TYPE= Release
MAKE_ARGSs=	-C -v out/Release
ALL_TARGET=	vivaldi

BINARY_ALIAS=	python3=${PYTHON_CMD}

# TODO bz@ : install libwidevinecdm.so (see third_party/widevine/cdm/BUILD.gn)
#
# Run "./out/${BUILDTYPE}/gn args out/${BUILDTYPE} --list" for all variables.
# Some parts don't have use_system_* flag, and can be turned on/off by using
# replace_gn_files.py script, some parts just turned on/off for target host
# OS "target_os == is_bsd", like libusb, libpci.
GN_ARGS+=	clang_use_chrome_plugins=false \
                enable_hangout_services_extension=true \
                enable_js_type_check=false \
                enable_nacl=false \
                enable_one_click_signin=true \
                enable_remoting=false \
                enable_wmax_tokens=false \
                fatal_linker_warnings=false \
                is_clang=true \
                optimize_webui=true \
                toolkit_views=true \
                treat_warnings_as_errors=false \
                use_allocator="none" \
                use_allocator_shim=false \
                use_aura=true \
                use_custom_libcxx=false \
                use_gnome_keyring=false \
                use_lld=true \
                use_sysroot=false \
                use_system_freetype=false \
                use_system_harfbuzz=true \
                use_system_libjpeg=true \
                use_system_wayland_scanner=true \
                use_udev=false \
                extra_cxxflags="${CXXFLAGS}" \
                extra_ldflags="${LDFLAGS}"

# TODO: investigate building with these options:
# use_system_minigbm
GN_BOOTSTRAP_FLAGS=	--no-clean --no-rebuild --skip-generate-buildfiles

#.if ${COMPILER_VERSION} < 130
#LLVM_DEFAULT=		13
#BUILD_DEPENDS+=		clang${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT}
#BINARY_ALIAS+=		cpp=${LOCALBASE}/bin/clang-cpp${LLVM_DEFAULT} \
                        cc=${LOCALBASE}/bin/clang${LLVM_DEFAULT} \
                        c++=${LOCALBASE}/bin/clang++${LLVM_DEFAULT} \
                        ar=${LOCALBASE}/bin/llvm-ar${LLVM_DEFAULT} \
                        nm=${LOCALBASE}/bin/llvm-nm${LLVM_DEFAULT} \
                        ld=${LOCALBASE}/bin/ld.lld${LLVM_DEFAULT}
#.else
#BINARY_ALIAS+=		ar=/usr/bin/llvm-ar \
#                        nm=/usr/bin/llvm-nm
#.endif


# swiftshader/lib/{libEGL.so,libGLESv2.so} is x86 only
#.if ${ARCH} == aarch64
#PLIST_SUB+=	NOT_AARCH64="@comment "
#.else
#PLIST_SUB+=	NOT_AARCH64=""
#.endif

# Allow relocations against read-only segments (override lld default)
LDFLAGS_i386=	-Wl,-znotext

# TODO: -isystem, would be just as ugly as this approach, but more reliably
# build would fail without C_INCLUDE_PATH/CPLUS_INCLUDE_PATH env var set.
MAKE_ENV+=	C_INCLUDE_PATH=${LOCALBASE}/include \
                CPLUS_INCLUDE_PATH=${LOCALBASE}/include

pre-configure:
        # We used to remove bundled libraries to be sure that chromium uses
        # system libraries and not shipped ones.
        # cd ${WRKSRC} && ${PYTHON_CMD} \
        #./build/linux/unbundle/remove_bundled_libraries.py [list of preserved]
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${PYTHON_CMD} \
	./chromium/build/linux/unbundle/replace_gn_files.py --system-libraries \
        flac fontconfig freetype harfbuzz-ng libdrm libpng libwebp libxml libxslt openh264 opus snappy || ${FALSE}

#post-configure:#
#	        cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${PYTHON_CMD} \
#        ./chromium/third_party/ffmpeg/chromium/scripts/generate_gn.py


do-configure:
	# GN generator bootstrapping and generating ninja files
#	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} CC=${CC} CXX=${CXX} LD=${CXX} \
#	READELF=${READELF} AR=${AR} NM=${NM} ${PYTHON_CMD} \
#	./chromium/tools/gn/bootstrap/bootstrap.py ${GN_BOOTSTRAP_FLAGS}

#	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${PYTHON_CMD} \
#        ./chromium/third_party/ffmpeg/chromium/scripts/generate_gn.py

	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${PYTHON_CMD} \
	./scripts/rungn.py gen --args='${GN_ARGS}' out/Release

#	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${PYTHON_CMD} \
#	./chromium/third_party/ffmpeg/chromium/scripts/generate_gn.py

do-install:


#@${MKDIR} ${STAGEDIR}${DATADIR}
#${INSTALL_MAN} ${WRKSRC}/chrome/app/resources/manpage.1.in \
#        ${STAGEDIR}${MANPREFIX}/man/man1/chrome.1
#@${SED} -i "" -e 's,\@\@PACKAGE\@\@,chromium,g;s,\@\@MENUNAME\@\@,Chromium Web Browser,g' \
#        ${STAGEDIR}${MANPREFIX}/man/man1/chrome.1	
#${CP} ${WRKSRC}/chrome/app/theme/chromium/product_logo_22_mono.png ${WRKSRC}/chrome/app/theme/chromium/product_logo_22.png
#.for s in 22 24 48 64 128 256
# @${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/app
# ${INSTALL_DATA} ${WRKSRC}/chrome/app/theme/chromium/product_logo_${s}.png \	
#        ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps/chrome.png
#.endfor
#${INSTALL_DATA} ${WRKSRC}/out/${BUILDTYPE}/*.png ${STAGEDIR}${DATADIR}
#${INSTALL_DATA} ${WRKSRC}/out/${BUILDTYPE}/*.pak ${STAGEDIR}${DATADIR}
#.for d in protoc mksnapshot
#${INSTALL_PROGRAM} ${WRKSRC}/out/${BUILDTYPE}/${d} ${STAGEDIR}${DATADIR}
#.endfor
#.for d in icudtl.dat snapshot_blob.bin v8_context_snapshot.bin
#${INSTALL_DATA} ${WRKSRC}/out/${BUILDTYPE}/${d} ${STAGEDIR}${DATADIR}
#.endfor
#${INSTALL_PROGRAM} ${WRKSRC}/out/${BUILDTYPE}/chrome \
#        ${STAGEDIR}${DATADIR}
#cd ${WRKSRC}/out/${BUILDTYPE} && \
#        ${COPYTREE_SHARE} "locales resources" ${STAGEDIR}${DATADIR}
#@${MKDIR} ${STAGEDIR}${DESKTOPDIR}
#${INSTALL_DATA} ${WRKDIR}/chromium-browser.desktop \
#        ${STAGEDIR}${DESKTOPDIR}
#${INSTALL_SCRIPT} ${WRKDIR}/chrome ${STAGEDIR}${PREFIX}/bin
#${INSTALL_SCRIPT} ${WRKSRC}/chrome/tools/build/linux/chrome-wrapper \
#        ${STAGEDIR}${DATADIR}

## ANGLE, EGL, Vk
#.for f in libEGL.so libGLESv2.so libVkICD_mock_icd.so
#${INSTALL_LIB} ${WRKSRC}/out/${BUILDTYPE}/${f} ${STAGEDIR}${DATADIR}
#.endfor
#${INSTALL_LIB} ${WRKSRC}/out/${BUILDTYPE}/libvulkan.so.1 \
#${STAGEDIR}${DATADIR}/libvulkan.so
##.if ${BUILDTYPE} == Debug
#${INSTALL_LIB} ${WRKSRC}/out/${BUILDTYPE}/libVkLayer_khronos_validation.so ${STAGEDIR}${DATADIR}
##.endif

## SwiftShader
##.if ${ARCH} != aarch64
##	 ${INSTALL_LIB} ${WRKSRC}/out/${BUILDTYPE}/libvk_swiftshader.so ${STAGEDIR}${DATADIR}
##.endif

.include <bsd.port.mk>
