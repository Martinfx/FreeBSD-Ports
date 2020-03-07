# $FreeBSD$

PORTNAME=	ungoogled-chromium
DISTVERSION=	80.0.3987.87-2
CATEGORIES=	www

MAINTAINER=	maintainer@email.com
COMMENT=	ungoogled chromium

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_PROJECT=	${PORTNAME}
GH_ACCOUNT=	Eloston


#.if defined(GN_ONLY)
#USES=		compiler:c++14-lang dos2unix localbase:ldflags ninja pkgconfig \
#		python:3.7,build shebangfix tar:xz
#.else
USES=		bison cpe desktop-file-utils dos2unix gl gnome jpeg localbase:ldflags \
		ninja perl5 pkgconfig python:3.7,build shebangfix tar:xz xorg
#.endif


#USE_LDCONFIG=	${DATADIR}
USE_XORG=	x11 xcb xcomposite xcursor xext xdamage xfixes xi \
		xorgproto xrandr xrender xscrnsaver xtst
USE_GL=		gl

MAKE_ARGS=	-C out/Default
BINARY_ALIAS=	python=${PYTHON_CMD}


# OS "target_os == is_bsd"
GN_ARGS+=	clang_use_chrome_plugins=false		\
		closure_compile=false			\
		enable_hangout_services_extension=false \
		enable_mdns=false			\
		enable_mse_mpeg2ts_stream_parser=true	\
		enable_nacl=false					\
		enable_nacl_nonsfi=false				\
		enable_one_click_signin=false				\
		enable_reading_list=false				\
		enable_remoting=false					\
		enable_reporting=false					\
		enable_service_discovery=false				\
		enable_widevine=true					\
		exclude_unwind_tables=true				\
		fieldtrial_testing_like_official_build=true \
		google_api_key=""			\
		google_default_client_id=""		\
		google_default_client_secret=""		\
		optimize_webui=false			\
		safe_browsing_mode=0			\
		treat_warnings_as_errors=false		\
		use_official_google_api_keys=false	\
		use_unofficial_version_number=false	\
		fieldtrial_testing_like_official_build=true \
		is_clang=true				\
		jumbo_file_merge_limit=8 		\
		toolkit_views=true 			\
		treat_warnings_as_errors=false		\
		use_allocator="none" 					\
		use_allocator_shim=false 				\
#		use_aura=true 							\
#		use_bundled_fontconfig=false \
#		use_custom_libcxx=false \
#		use_gnome_keyring=false \
#		use_jumbo_build=true \
		use_lld=true 							\
		use_sysroot=false 						\
#		use_system_freetype=true \
#		use_system_harfbuzz=true \
#		use_system_libjpeg=true \
		extra_cxxflags="${CXXFLAGS}" 			\
		extra_ldflags="${LDFLAGS}"

GN_BOOTSTRAP_FLAGS=	--no-clean --no-rebuild --skip-generate-buildfiles

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "To build Chromium, you should have around 2GB of memory"
	@${ECHO_MSG} "and ${WANTSPACE}."
	@${ECHO_MSG}

#pre-configure:
post-extract:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${MKDIR} build/download_cache \
	&& ${PYTHON_CMD} ./utils/downloads.py retrieve -c build/download_cache -i downloads.ini \
	&& ./utils/downloads.py unpack -c build/download_cache -i downloads.ini -- build/src

post-patch:
	# cd ${WRKSRC} && ${PYTHON_CMD} \
	#./build/linux/unbundle/remove_bundled_libraries.py [list of preserved]
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${MKDIR} build/download_cache \
	&& ${PYTHON_CMD} utils/prune_binaries.py build/src pruning.list          \
	&& ${PYTHON_CMD} utils/patches.py apply build/src patches                \
	&& ${PYTHON_CMD} utils/domain_substitution.py apply -r domain_regex.list -f domain_substitution.list -c build/domsubcache.tar.gz build/src

do-configure:
	# GN generator bootstrapping and generating ninja files
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} CC=${CC} CXX=${CXX} LD=${CXX} \
	${MKDIR} build/src/out/Default && cd build/src                           \
	${PYTHON_CMD} ./out/Default/gn gen out/Default --fail-on-unused-args     \
	${PYTHON_CMD} tools/gn/bootstrap/bootstrap.py --skip-generate-buildfiles -o out/Default/

.include <bsd.port.mk>
