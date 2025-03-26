PORTNAME=	filestash
DISTVERSIONPREFIX=v
DISTVERSION=	0.4
CATEGORIES=	sysutils

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	A file manager / web client for SFTP, \
		S3, FTP, WebDAV, Git, Minio, LDAP, CalDAV, \
		CardDAV, Mysql, Backblaze, ...
WWW=		https://www.filestash.app/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	npm:www/npm \
		libraw>0:graphics/libraw \
		giflib>0:graphics/giflib

USES=		go:1.23 go:module gmake

USE_GITHUB=	yes
GH_ACCOUNT=	mickael-kerjean
GH_TAGNAME=	c7d48c9
GH_TUPLE=	Azure:azure-sdk-for-go:76e5495a4d1c:azure_azure_sdk_for_go_azcore/vendor/github.com/Azure/azure-sdk-for-go \
		Azure:azure-sdk-for-go:95f7bc67b7a7:azure_azure_sdk_for_go_azblob \
		Azure:azure-sdk-for-go:e14a52008cf2:azure_azure_sdk_for_go_internal \
		Azure:go-ntlmssp:754e69321358:azure_go_ntlmssp/vendor/github.com/Azure/go-ntlmssp \
		FiloSottile:edwards25519:v1.1.0:filosottile_edwards25519/vendor/filippo.io/edwards25519 \
		Microsoft:go-winio:v0.6.2:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		alexcesaro:quotedprintable:2caba252f4dc:alexcesaro_quotedprintable/vendor/gopkg.in/alexcesaro/quotedprintable.v3 \
		aws:aws-sdk-go:v1.53.14:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		aybabtme:rgbterm:cc83f3b3ce59:aybabtme_rgbterm/vendor/github.com/aybabtme/rgbterm \
		beevik:etree:v1.4.0:beevik_etree/vendor/github.com/beevik/etree \
		bluekeyes:go-gitdiff:v0.7.3:bluekeyes_go_gitdiff/vendor/github.com/bluekeyes/go-gitdiff \
		calebcase:tmpfile:v1.0.3:calebcase_tmpfile/vendor/github.com/calebcase/tmpfile \
		census-instrumentation:opencensus-go:v0.24.0:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		creack:pty:v1.1.21:creack_pty/vendor/github.com/creack/pty \
		cretz:bine:v0.2.0:cretz_bine/vendor/github.com/cretz/bine \
		crewjam:httperr:v0.2.0:crewjam_httperr/vendor/github.com/crewjam/httperr \
		davecgh:go-spew:d8f796af33cc:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		duosecurity:duo_universal_golang:v1.0.3:duosecurity_duo_universal_golang/vendor/github.com/duosecurity/duo_universal_golang \
		dustin:go-humanize:v1.0.1:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		emirpasic:gods:v1.18.1:emirpasic_gods/vendor/github.com/emirpasic/gods \
		felixge:httpsnoop:v1.0.4:felixge_httpsnoop/vendor/github.com/felixge/httpsnoop \
		flynn:noise:v1.1.0:flynn_noise/vendor/github.com/flynn/noise \
		geoffgarside:ber:v1.1.0:geoffgarside_ber/vendor/github.com/geoffgarside/ber \
		go-asn1-ber:asn1-ber:v1.5.7:go_asn1_ber_asn1_ber/vendor/github.com/go-asn1-ber/asn1-ber \
		go-gomail:gomail:81ebce5c23df:go_gomail_gomail/vendor/gopkg.in/gomail.v2 \
		go-ldap:ldap:v3.4.8:go_ldap_ldap_v3/vendor/github.com/go-ldap/ldap \
		go-logr:logr:v1.4.2:go_logr_logr/vendor/github.com/go-logr/logr \
		go-logr:stdr:v1.2.2:go_logr_stdr/vendor/github.com/go-logr/stdr \
		go-sql-driver:mysql:v1.8.1:go_sql_driver_mysql/vendor/github.com/go-sql-driver/mysql \
		go-warnings:warnings:v0.1.2:go_warnings_warnings/vendor/gopkg.in/warnings.v0 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		goccy:go-json:v0.10.3:goccy_go_json/vendor/github.com/goccy/go-json \
		gogo:protobuf:v1.3.2:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang-jwt:jwt:v4.5.0:golang_jwt_jwt_v4/vendor/github.com/golang-jwt/jwt/v4 \
		golang:crypto:v0.23.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:exp:fd00a4e0eefc:golang_exp/vendor/golang.org/x/exp \
		golang:groupcache:41bb18bfe9da:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:image:v0.16.0:golang_image/vendor/golang.org/x/image \
		golang:net:v0.25.0:golang_net/vendor/golang.org/x/net \
		golang:oauth2:v0.20.0:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.5.4:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sync:v0.7.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.20.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.15.0:golang_text/vendor/golang.org/x/text \
		golang:time:v0.5.0:golang_time/vendor/golang.org/x/time \
		google:go-genproto:531527333157:google_go_genproto/vendor/google.golang.org/genproto \
		google:s2a-go:v0.1.7:google_s2a_go/vendor/github.com/google/s2a-go \
		google:uuid:v1.6.0:google_uuid/vendor/github.com/google/uuid \
		googleapis:enterprise-certificate-proxy:v0.3.2:googleapis_enterprise_certificate_proxy/vendor/github.com/googleapis/enterprise-certificate-proxy \
		googleapis:gax-go:v2.12.4:googleapis_gax_go_v2/vendor/github.com/googleapis/gax-go \
		googleapis:google-api-go-client:v0.182.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:auth/v0.5.1:googleapis_google_cloud_go_auth \
		googleapis:google-cloud-go:iam/v1.1.8:googleapis_google_cloud_go_iam \
		googleapis:google-cloud-go:storage/v1.41.0:googleapis_google_cloud_go_storage \
		googleapis:google-cloud-go:v0.114.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		googleapis:google-cloud-go:auth/oauth2adapt/v0.2.2:googleapis_google_cloud_go/vendor/cloud.google.com/go/auth/oauth2adapt \
		googleapis:google-cloud-go:v0.3.0:googleapis_google_cloud_go_2/vendor/cloud.google.com/go/compute/metadata \
		gorilla:mux:v1.8.1:gorilla_mux/vendor/github.com/gorilla/mux \
		gorilla:websocket:v1.5.1:gorilla_websocket/vendor/github.com/gorilla/websocket \
		grpc:grpc-go:v1.64.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		h2non:bimg:v1.1.9:h2non_bimg/vendor/github.com/h2non/bimg \
		hashicorp:golang-lru:v2.0.7:hashicorp_golang_lru_v2/vendor/github.com/hashicorp/golang-lru/v2 \
		hirochachacha:go-smb2:v1.1.0:hirochachacha_go_smb2/vendor/github.com/hirochachacha/go-smb2 \
		jbenet:go-context:d14ea06fba99:jbenet_go_context/vendor/github.com/jbenet/go-context \
		jmespath:go-jmespath:v0.4.0:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		jonboulle:clockwork:v0.4.0:jonboulle_clockwork/vendor/github.com/jonboulle/clockwork \
		jtolio:noiseconn:f6d9ecbf1de7:jtolio_noiseconn/vendor/github.com/jtolio/noiseconn \
		kevinburke:ssh_config:v1.2.0:kevinburke_ssh_config/vendor/github.com/kevinburke/ssh_config \
		klauspost:compress:v1.17.8:klauspost_compress/vendor/github.com/klauspost/compress \
		klauspost:cpuid:v2.2.7:klauspost_cpuid_v2/vendor/github.com/klauspost/cpuid/v2 \
		kr:fs:v0.1.0:kr_fs/vendor/github.com/kr/fs \
		lestrrat-go:backoff:v2.0.8:lestrrat_go_backoff_v2/vendor/github.com/lestrrat-go/backoff/v2 \
		lestrrat-go:blackmagic:v1.0.2:lestrrat_go_blackmagic/vendor/github.com/lestrrat-go/blackmagic \
		lestrrat-go:httpcc:v1.0.1:lestrrat_go_httpcc/vendor/github.com/lestrrat-go/httpcc \
		lestrrat-go:iter:v1.0.2:lestrrat_go_iter/vendor/github.com/lestrrat-go/iter \
		lestrrat-go:jwx:v1.2.29:lestrrat_go_jwx/vendor/github.com/lestrrat-go/jwx \
		lestrrat-go:option:v1.0.1:lestrrat_go_option/vendor/github.com/lestrrat-go/option \
		mattermost:xml-roundtrip-validator:v0.1.0:mattermost_xml_roundtrip_validator/vendor/github.com/mattermost/xml-roundtrip-validator \
		mattn:go-isatty:v0.0.20:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-sqlite3:v1.14.22:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
		mickael-kerjean:net:2457c043ba06:mickael_kerjean_net/vendor/github.com/mickael-kerjean/net \
		mickael-kerjean:saml:4629e91322ce:mickael_kerjean_saml/vendor/github.com/mickael-kerjean/saml \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:hashstructure:v1.1.0:mitchellh_hashstructure/vendor/github.com/mitchellh/hashstructure \
		ncruces:go-strftime:v0.1.9:ncruces_go_strftime/vendor/github.com/ncruces/go-strftime \
		nfnt:resize:83c6a9932646:nfnt_resize/vendor/github.com/nfnt/resize \
		open-telemetry:opentelemetry-go-contrib:v1.31.0:open_telemetry_opentelemetry_go_contrib/vendor/go.opentelemetry.io/contrib/instrumentation/google.golang.org/grpc/otelgrpc \
		open-telemetry:opentelemetry-go-contrib:v1.31.0:open_telemetry_opentelemetry_go_contrib/vendor/go.opentelemetry.io/contrib/instrumentation/net/http/otelhttp \
		open-telemetry:opentelemetry-go:v1.27.0:open_telemetry_opentelemetry_go/vendor/go.opentelemetry.io/otel \
		patrickmn:go-cache:v2.1.0:patrickmn_go_cache/vendor/github.com/patrickmn/go-cache \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pkg:sftp:v1.13.6:pkg_sftp/vendor/github.com/pkg/sftp \
		pmezard:go-difflib:5d4384ee4fb2:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prasad83:goftp:f57aaed46a32:prasad83_goftp/vendor/github.com/prasad83/goftp \
		protocolbuffers:protobuf-go:v1.34.1:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		qeesung:image2ascii:v1.0.1:qeesung_image2ascii/vendor/github.com/qeesung/image2ascii \
		rasky:go-xdr:1a41d1a06c93:rasky_go_xdr/vendor/github.com/rasky/go-xdr \
		remyoudompheng:bigfft:24d4a6f8daec:remyoudompheng_bigfft/vendor/github.com/remyoudompheng/bigfft \
		russellhaering:goxmldsig:v1.4.0:russellhaering_goxmldsig/vendor/github.com/russellhaering/goxmldsig \
		secsy:goftp:aa2de14babf4:secsy_goftp/vendor/github.com/secsy/goftp \
		sergi:go-diff:v1.3.1:sergi_go_diff/vendor/github.com/sergi/go-diff \
		spacemonkeygo:monkit:v3.0.23:spacemonkeygo_monkit_v3/vendor/github.com/spacemonkeygo/monkit/v3 \
		src-d:gcfg:v1.4.0:src_d_gcfg/vendor/github.com/src-d/gcfg \
		src-d:go-billy:v4.3.2:src_d_go_billy/vendor/gopkg.in/src-d/go-billy.v4 \
		src-d:go-git:v4.13.1:src_d_go_git/vendor/gopkg.in/src-d/go-git.v4 \
		srwiley:oksvg:be6e8873101c:srwiley_oksvg/vendor/github.com/srwiley/oksvg \
		srwiley:rasterx:2ab79fcdd4ef:srwiley_rasterx/vendor/github.com/srwiley/rasterx \
		storj:common:0608f3092c42:storj_common/vendor/storj.io/common \
		storj:drpc:v0.0.34:storj_drpc/vendor/storj.io/drpc \
		storj:eventkit:1d9596fee086:storj_eventkit/vendor/storj.io/eventkit \
		storj:infectious:v0.0.2:storj_infectious/vendor/storj.io/infectious \
		storj:picobuf:v0.0.3:storj_picobuf/vendor/storj.io/picobuf \
		storj:uplink:v1.13.0:storj_uplink/vendor/storj.io/uplink \
		stretchr:testify:v1.9.0:stretchr_testify/vendor/github.com/stretchr/testify \
		suyashkumar:dicom:v1.0.7:suyashkumar_dicom/vendor/github.com/suyashkumar/dicom \
		tidwall:gjson:v1.17.1:tidwall_gjson/vendor/github.com/tidwall/gjson \
		tidwall:match:v1.1.1:tidwall_match/vendor/github.com/tidwall/match \
		tidwall:pretty:v1.2.1:tidwall_pretty/vendor/github.com/tidwall/pretty \
		tidwall:sjson:v1.2.5:tidwall_sjson/vendor/github.com/tidwall/sjson \
		vmware:go-nfs-client:d43b92724c1b:vmware_go_nfs_client/vendor/github.com/vmware/go-nfs-client \
		wayneashleyberry:terminal-dimensions:v1.1.0:wayneashleyberry_terminal_dimensions/vendor/github.com/wayneashleyberry/terminal-dimensions \
		xanzy:ssh-agent:v0.3.3:xanzy_ssh_agent/vendor/github.com/xanzy/ssh-agent \
		zeebo:blake3:v0.2.3:zeebo_blake3/vendor/github.com/zeebo/blake3 \
		zeebo:errs:v1.3.0:zeebo_errs/vendor/github.com/zeebo/errs

GL_TUPLE=	\
		cznic:gc:f0dba7c97c2b9a339c26efa9f85898b1d4d62c59:cznic_gc/vendor/modernc.org/gc/v3 \
		cznic:libc:0e8ec9d3a591d73b23123762b38c5f5ca28308d5:cznic_libc/vendor/modernc.org/libc \
		cznic:mathutil:aabd79189264b253ce2360e80193242239022080:cznic_mathutil/vendor/modernc.org/mathutil \
		cznic:memory:cd6b9df5067aec83c6c73e18fa974cdfc1c400dd:cznic_memory/vendor/modernc.org/memory \
		cznic:sqlite:4f4c689c06c400cca2e30bb66ce9a3533f7e5d1d:cznic_sqlite/vendor/modernc.org/sqlite \
		cznic:strutil:f4c290107e9e43b1bb4a8bc7dcd154eb9b565cd8:cznic_strutil/vendor/modernc.org/strutil \
		cznic:token:24e30cd78ee0f2d5d4516917d9cc1101e3ccc1ab:cznic_token/vendor/modernc.org/token

BINARY_ALIAS+=	go=go${GO_SUFFIX} gofmt=gofmt${GO_SUFFIX}

post-extract:
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/auth
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_auth}/auth ${WRKSRC}/vendor/cloud.google.com/go/auth
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/iam
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_iam}/iam ${WRKSRC}/vendor/cloud.google.com/go/iam
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/storage
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_storage}/storage ${WRKSRC}/vendor/cloud.google.com/go/storage
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/azure-sdk-for-go/sdk/internal
	@${RLN} ${WRKSRC_azure_azure_sdk_for_go_internal}/sdk/internal ${WRKSRC}/vendor/github.com/Azure/azure-sdk-for-go/sdk/internal
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/azure-sdk-for-go/sdk/storage/azblob
	@${RLN} ${WRKSRC_azure_azure_sdk_for_go_azblob}/sdk/storage/azblob ${WRKSRC}/vendor/github.com/Azure/azure-sdk-for-go/sdk/storage/azblob

pre-build:
	@(cd ${WRKSRC} && ${SETENV} XDG_CACHE_HOME=${WRKDIR}/.cache HOME=${WRKDIR}/home ${GO_ENV} GO111MODULE="off" ${GMAKE} all)

do-install:

.include <bsd.port.mk>
