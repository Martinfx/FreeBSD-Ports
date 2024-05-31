PORTNAME=	brook
DISTVERSIONPREFIX=v
DISTVERSION=	20240606
CATEGORIES=	sysutils

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	A cross-platform programmable network tool
WWW=		https://brook.app/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.22 go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	txthinking

GH_TUPLE=	\
		andybalholm:brotli:v1.0.5:andybalholm_brotli/vendor/github.com/andybalholm/brotli \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		cespare:xxhash:v2.2.0:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		cloudflare:circl:v1.3.7:cloudflare_circl/vendor/github.com/cloudflare/circl \
		cpuguy83:go-md2man:v2.0.2:cpuguy83_go_md2man_v2/vendor/github.com/cpuguy83/go-md2man/v2 \
		gaukas:godicttls:v0.0.4:gaukas_godicttls/vendor/github.com/gaukas/godicttls \
		go-task:slim-sprig:52ccab3ef572:go_task_slim_sprig/vendor/github.com/go-task/slim-sprig \
		golang:crypto:v0.22.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:exp:47842c84f3db:golang_exp/vendor/golang.org/x/exp \
		golang:mod:v0.12.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:v0.24.0:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.5.3:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:v0.19.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.14.0:golang_text/vendor/golang.org/x/text \
		golang:tools:v0.13.0:golang_tools/vendor/golang.org/x/tools \
		google:pprof:94a9f03dee38:google_pprof/vendor/github.com/google/pprof \
		gorilla:mux:v1.8.1:gorilla_mux/vendor/github.com/gorilla/mux \
		gorilla:websocket:v1.5.1:gorilla_websocket/vendor/github.com/gorilla/websocket \
		klauspost:compress:v1.16.7:klauspost_compress/vendor/github.com/klauspost/compress \
		krolaw:dhcp4:a50d88189771:krolaw_dhcp4/vendor/github.com/krolaw/dhcp4 \
		matttproud:golang_protobuf_extensions:v1.0.4:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		miekg:dns:v1.1.57:miekg_dns/vendor/github.com/miekg/dns \
		onsi:ginkgo:v2.9.5:onsi_ginkgo_v2/vendor/github.com/onsi/ginkgo/v2 \
		patrickmn:go-cache:v2.1.0:patrickmn_go_cache/vendor/github.com/patrickmn/go-cache \
		phuslu:iploc:v1.0.20240501:phuslu_iploc/vendor/github.com/phuslu/iploc \
		prometheus:client_golang:v1.17.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:9a2bf3000d16:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.44.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.11.1:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.33.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		quic-go:quic-go:v0.42.0:quic_go_quic_go/vendor/github.com/quic-go/quic-go \
		refraction-networking:utls:v1.5.4:refraction_networking_utls/vendor/github.com/refraction-networking/utls \
		russross:blackfriday:v2.1.0:russross_blackfriday_v2/vendor/github.com/russross/blackfriday/v2 \
		tdewolff:minify:v2.3.6:tdewolff_minify/vendor/github.com/tdewolff/minify \
		tdewolff:parse:v2.3.4:tdewolff_parse/vendor/github.com/tdewolff/parse \
		tdewolff:test:v1.0.10:tdewolff_test/vendor/github.com/tdewolff/test \
		txthinking:runnergroup:408dc5853f86:txthinking_runnergroup/vendor/github.com/txthinking/runnergroup \
		txthinking:socks5:4230056ae301:txthinking_socks5/vendor/github.com/txthinking/socks5 \
		txthinking:x:6f68aba84c87:txthinking_x/vendor/github.com/txthinking/x \
		uber-go:mock:v0.4.0:uber_go_mock/vendor/go.uber.org/mock \
		urfave:cli:v2.25.7:urfave_cli_v2/vendor/github.com/urfave/cli/v2 \
		urfave:negroni:v1.0.0:urfave_negroni/vendor/github.com/urfave/negroni \
		xrash:smetrics:039620a65673:xrash_smetrics/vendor/github.com/xrash/smetrics

.include <bsd.port.mk>
