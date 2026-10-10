--- hack/lib/golang.sh.orig	2024-06-11 20:20:59 UTC
+++ hack/lib/golang.sh
@@ -16,23 +16,30 @@
 
 # shellcheck disable=SC2034 # Variables sourced in other scripts.
 
-readonly KUBE_GOPATH="${KUBE_GOPATH:-"${KUBE_OUTPUT}/go"}"
-export KUBE_GOPATH
+# The golang package that we are building.
+readonly KUBE_GO_PACKAGE=k8s.io/kubernetes
+readonly KUBE_GOPATH="${KUBE_OUTPUT}/go"
 
 # The server platform we are building on.
 readonly KUBE_SUPPORTED_SERVER_PLATFORMS=(
   linux/amd64
+  linux/arm
   linux/arm64
   linux/s390x
   linux/ppc64le
+  freebsd/amd64
+  openbsd/amd64
 )
 
 # The node platforms we build for
 readonly KUBE_SUPPORTED_NODE_PLATFORMS=(
   linux/amd64
+  linux/arm
   linux/arm64
   linux/s390x
   linux/ppc64le
+  freebsd/amd64
+  openbsd/amd64
   windows/amd64
 )
 
@@ -47,6 +54,8 @@ readonly KUBE_SUPPORTED_CLIENT_PLATFORMS=(
   linux/ppc64le
   darwin/amd64
   darwin/arm64
+  solaris/amd64
+  openbsd/amd64
   windows/amd64
   windows/386
   windows/arm64
@@ -56,11 +65,14 @@ readonly KUBE_SUPPORTED_CLIENT_PLATFORMS=(
 # Not all client platforms need these tests
 readonly KUBE_SUPPORTED_TEST_PLATFORMS=(
   linux/amd64
+  linux/arm
   linux/arm64
   linux/s390x
   linux/ppc64le
   darwin/amd64
   darwin/arm64
+  freebsd/amd64
+  openbsd/amd64
   windows/amd64
   windows/arm64
 )
@@ -74,9 +86,9 @@ kube::golang::server_targets() {
     cmd/kubelet
     cmd/kubeadm
     cmd/kube-scheduler
-    staging/src/k8s.io/component-base/logs/kube-log-runner
-    staging/src/k8s.io/kube-aggregator
-    staging/src/k8s.io/apiextensions-apiserver
+    vendor/k8s.io/component-base/logs/kube-log-runner
+    vendor/k8s.io/kube-aggregator
+    vendor/k8s.io/apiextensions-apiserver
     cluster/gce/gci/mounter
   )
   echo "${targets[@]}"
@@ -94,7 +106,6 @@ kube::golang::server_image_targets() {
     cmd/kube-controller-manager
     cmd/kube-scheduler
     cmd/kube-proxy
-    cmd/kubectl
   )
   echo "${targets[@]}"
 }
@@ -124,7 +135,7 @@ kube::golang::node_targets() {
     cmd/kube-proxy
     cmd/kubeadm
     cmd/kubelet
-    staging/src/k8s.io/component-base/logs/kube-log-runner
+    vendor/k8s.io/component-base/logs/kube-log-runner
   )
   echo "${targets[@]}"
 }
@@ -212,25 +223,51 @@ kube::golang::setup_platforms() {
       # on any platform other than amd64, arm64, ppc64le and s390x, we just default to amd64
       host_arch="amd64"
     fi
-    KUBE_SERVER_PLATFORMS=("linux/${host_arch}")
+    KUBE_SERVER_PLATFORMS=(
+      "linux/${host_arch}"
+      "solaris/${host_arch}"
+      "freebsd/${host_arch}"
+      "openbsd/${host_arch}"
+    )
     readonly KUBE_SERVER_PLATFORMS
-    KUBE_NODE_PLATFORMS=("linux/${host_arch}")
+    KUBE_NODE_PLATFORMS=(
+      "linux/${host_arch}"
+      "solaris/${host_arch}"
+      "freebsd/${host_arch}"
+      "openbsd/${host_arch}"
+    )
     readonly KUBE_NODE_PLATFORMS
     if [[ "${KUBE_BUILDER_OS:-}" == "darwin"* ]]; then
       KUBE_TEST_PLATFORMS=(
         "darwin/${host_arch}"
         "linux/${host_arch}"
+        "solaris/${host_arch}"
+        "freebsd/${host_arch}"
+        "openbsd/${host_arch}"
       )
       readonly KUBE_TEST_PLATFORMS
       KUBE_CLIENT_PLATFORMS=(
         "darwin/${host_arch}"
         "linux/${host_arch}"
+        "solaris/${host_arch}"
+        "freebsd/${host_arch}"
+        "openbsd/${host_arch}"
       )
       readonly KUBE_CLIENT_PLATFORMS
     else
-      KUBE_TEST_PLATFORMS=("linux/${host_arch}")
+      KUBE_TEST_PLATFORMS=(
+        "linux/${host_arch}"
+        "solaris/${host_arch}"
+        "freebsd/${host_arch}"
+        "openbsd/${host_arch}"
+      )
       readonly KUBE_TEST_PLATFORMS
-      KUBE_CLIENT_PLATFORMS=("linux/${host_arch}")
+      KUBE_CLIENT_PLATFORMS=(
+        "linux/${host_arch}"
+        "solaris/${host_arch}"
+        "freebsd/${host_arch}"
+        "openbsd/${host_arch}"
+      )
       readonly KUBE_CLIENT_PLATFORMS
     fi
   else
@@ -261,6 +298,11 @@ readonly KUBE_CLIENT_BINARIES_WIN=("${KUBE_CLIENT_BINA
 # The set of test targets that we are building for all platforms
 kube::golang::test_targets() {
   local targets=(
+    cmd/gendocs
+    cmd/genkubedocs
+    cmd/genman
+    cmd/genyaml
+    cmd/genswaggertypedocs
     ginkgo
     test/e2e/e2e.test
     test/conformance/image/go-runner
@@ -316,9 +358,7 @@ readonly KUBE_ALL_TARGETS=(
 )
 readonly KUBE_ALL_BINARIES=("${KUBE_ALL_TARGETS[@]##*/}")
 
-readonly KUBE_STATIC_BINARIES=(
-  apiextensions-apiserver
-  kube-aggregator
+readonly KUBE_STATIC_LIBRARIES=(
   kube-apiserver
   kube-controller-manager
   kube-scheduler
@@ -326,9 +366,7 @@ readonly KUBE_STATIC_BINARIES=(
   kube-log-runner
   kubeadm
   kubectl
-  kubectl-convert
   kubemark
-  mounter
 )
 
 # Fully-qualified package names that we want to instrument for coverage information.
@@ -342,16 +380,16 @@ readonly KUBE_COVERAGE_INSTRUMENTED_PACKAGES=(
 
 # KUBE_CGO_OVERRIDES is a space-separated list of binaries which should be built
 # with CGO enabled, assuming CGO is supported on the target platform.
-# This overrides any entry in KUBE_STATIC_BINARIES.
+# This overrides any entry in KUBE_STATIC_LIBRARIES.
 IFS=" " read -ra KUBE_CGO_OVERRIDES_LIST <<< "${KUBE_CGO_OVERRIDES:-}"
 readonly KUBE_CGO_OVERRIDES_LIST
 # KUBE_STATIC_OVERRIDES is a space-separated list of binaries which should be
 # built with CGO disabled. This is in addition to the list in
-# KUBE_STATIC_BINARIES.
+# KUBE_STATIC_LIBRARIES.
 IFS=" " read -ra KUBE_STATIC_OVERRIDES_LIST <<< "${KUBE_STATIC_OVERRIDES:-}"
 readonly KUBE_STATIC_OVERRIDES_LIST
 
-kube::golang::is_statically_linked() {
+kube::golang::is_statically_linked_library() {
   local e
   # Explicitly enable cgo when building kubectl for darwin from darwin.
   [[ "$(go env GOHOSTOS)" == "darwin" && "$(go env GOOS)" == "darwin" &&
@@ -359,18 +397,16 @@ kube::golang::is_statically_linked() {
   if [[ -n "${KUBE_CGO_OVERRIDES_LIST:+x}" ]]; then
     for e in "${KUBE_CGO_OVERRIDES_LIST[@]}"; do [[ "${1}" == *"/${e}" ]] && return 1; done;
   fi
-  for e in "${KUBE_STATIC_BINARIES[@]}"; do [[ "${1}" == *"/${e}" ]] && return 0; done;
+  for e in "${KUBE_STATIC_LIBRARIES[@]}"; do [[ "${1}" == *"/${e}" ]] && return 0; done;
   if [[ -n "${KUBE_STATIC_OVERRIDES_LIST:+x}" ]]; then
     for e in "${KUBE_STATIC_OVERRIDES_LIST[@]}"; do [[ "${1}" == *"/${e}" ]] && return 0; done;
   fi
   return 1;
 }
 
-# kube::golang::best_guess_go_targets takes a list of build targets, which might
-# be Go-style names (e.g. example.com/foo/bar or ./foo/bar) or just local paths
-# (e.g. foo/bar) and produces a respective list (on stdout) of our best guess at
-# Go target names.
-kube::golang::best_guess_go_targets() {
+# kube::binaries_from_targets take a list of build targets and return the
+# full go package to be built
+kube::golang::binaries_from_targets() {
   local target
   for target; do
     if [ "${target}" = "ginkgo" ] ||
@@ -380,75 +416,20 @@ kube::golang::best_guess_go_targets() {
       # "ginkgo" is the one that is documented in the Makefile. The others
       # are for backwards compatibility.
       echo "github.com/onsi/ginkgo/v2/ginkgo"
-      continue
-    fi
-
-    if [[ "${target}" =~ ^([[:alnum:]]+".")+[[:alnum:]]+"/" ]]; then
+    elif [[ "${target}" =~ ^([[:alnum:]]+".")+[[:alnum:]]+"/" ]]; then
       # If the target starts with what looks like a domain name, assume it has a
-      # fully-qualified Go package name.
+      # fully-qualified package name rather than one that needs the Kubernetes
+      # package prepended.
       echo "${target}"
-      continue
-    fi
-
-    if [[ "${target}" =~ ^vendor/ ]]; then
-      # Strip vendor/ prefix, since we're building in gomodule mode.  This is
-      # for backwards compatibility.
+    elif [[ "${target}" =~ ^vendor/ ]]; then
+      # Strip vendor/ prefix, since we're building in gomodule mode.
       echo "${target#"vendor/"}"
-      continue
+    else
+      echo "${KUBE_GO_PACKAGE}/${target}"
     fi
-
-    # If the target starts with "./", assume it is a local path which qualifies
-    # as a Go target name.
-    if [[ "${target}" =~ ^\./ ]]; then
-      echo "${target}"
-      continue
-    fi
-
-    # Otherwise assume it's a relative path (e.g. foo/bar or foo/bar/bar.test).
-    # We probably SHOULDN'T accept this, but we did in the past and it would be
-    # rude to break things if we don't NEED to.  We can't really test if it
-    # exists or not, because the last element might be an output file (e.g.
-    # bar.test) or even "...".
-    echo "./${target}"
   done
 }
 
-# kube::golang::normalize_go_targets takes a list of build targets, which might
-# be Go-style names (e.g. example.com/foo/bar or ./foo/bar) or just local paths
-# (e.g. foo/bar) and produces a respective list (on stdout) of Go package
-# names.
-#
-# If this cannot find (go list -find -e) one or more inputs, it will emit the
-# them on stdout, so callers can at least get a useful error.
-kube::golang::normalize_go_targets() {
-  local targets=()
-  kube::util::read-array targets < <(kube::golang::best_guess_go_targets "$@")
-  kube::util::read-array targets < <(kube::golang::dedup "${targets[@]}")
-  set -- "${targets[@]}"
-
-  for target; do
-    if [[ "${target}" =~ ".test"$ ]]; then
-      local dir
-      dir="$(dirname "${target}")"
-      local tst
-      tst="$(basename "${target}")"
-      local pkg
-      pkg="$(go list -find -e "${dir}")"
-      echo "${pkg}/${tst}"
-      continue
-    fi
-    if [[ "${target}" =~ "/..."$ ]]; then
-      local dir
-      dir="$(dirname "${target}")"
-      local pkg
-      pkg="$(go list -find -e "${dir}")"
-      echo "${pkg}/..."
-      continue
-    fi
-    go list -find -e "${target}"
-  done
-}
-
 # Asks golang what it thinks the host platform is. The go tool chain does some
 # slightly different things when the target platform matches the host platform.
 kube::golang::host_platform() {
@@ -490,6 +471,10 @@ kube::golang::set_platform_envs() {
         export CGO_ENABLED=1
         export CC=${KUBE_LINUX_S390X_CC:-s390x-linux-gnu-gcc}
         ;;
+      "solaris/amd64")
+        export CGO_ENABLED=1
+        export CC=${KUBE_LINUX_PPC64LE_CC:-i86pc-linux-gnu-gcc}
+        ;;
     esac
   fi
 
@@ -501,32 +486,22 @@ kube::golang::set_platform_envs() {
   fi
 }
 
-# Ensure the go tool exists and is a viable version.
-# Inputs:
-#   env-var GO_VERSION is the desired go version to use, downloading it if needed (defaults to content of .go-version)
-#   env-var FORCE_HOST_GO set to a non-empty value uses the go version in the $PATH and skips ensuring $GO_VERSION is used
-kube::golang::internal::verify_go_version() {
-  # default GO_VERSION to content of .go-version
-  GO_VERSION="${GO_VERSION:-"$(cat "${KUBE_ROOT}/.go-version")"}"
-  if [ "${GOTOOLCHAIN:-auto}" != 'auto' ]; then
-    # no-op, just respect GOTOOLCHAIN
-    :
-  elif [ -n "${FORCE_HOST_GO:-}" ]; then
-    # ensure existing host version is used, like before GOTOOLCHAIN existed
-    export GOTOOLCHAIN='local'
-  else
-    # otherwise, we want to ensure the go version matches GO_VERSION
-    GOTOOLCHAIN="go${GO_VERSION}"
-    export GOTOOLCHAIN
-    # if go is either not installed or too old to respect GOTOOLCHAIN then use gimme
-    if ! (command -v go >/dev/null && [ "$(go version | cut -d' ' -f3)" = "${GOTOOLCHAIN}" ]); then
-      export GIMME_ENV_PREFIX=${GIMME_ENV_PREFIX:-"${KUBE_OUTPUT}/.gimme/envs"}
-      export GIMME_VERSION_PREFIX=${GIMME_VERSION_PREFIX:-"${KUBE_OUTPUT}/.gimme/versions"}
-      # eval because the output of this is shell to set PATH etc.
-      eval "$("${KUBE_ROOT}/third_party/gimme/gimme" "${GO_VERSION}")"
-    fi
+# Create the GOPATH tree under $KUBE_OUTPUT
+kube::golang::create_gopath_tree() {
+  local go_pkg_dir="${KUBE_GOPATH}/src/${KUBE_GO_PACKAGE}"
+  local go_pkg_basedir
+  go_pkg_basedir=$(dirname "${go_pkg_dir}")
+
+  mkdir -p "${go_pkg_basedir}"
+
+  # TODO: This symlink should be relative.
+  if [[ ! -e "${go_pkg_dir}" || "$(readlink "${go_pkg_dir}")" != "${KUBE_ROOT}" ]]; then
+    ln -snf "${KUBE_ROOT}" "${go_pkg_dir}"
   fi
+}
 
+# Ensure the go tool exists and is a viable version.
+kube::golang::verify_go_version() {
   if [[ -z "$(command -v go)" ]]; then
     kube::log::usage_from_stdin <<EOF
 Can't find 'go' in PATH, please fix and retry.
@@ -538,7 +513,7 @@ EOF
   local go_version
   IFS=" " read -ra go_version <<< "$(GOFLAGS='' go version)"
   local minimum_go_version
-  minimum_go_version=go1.22
+  minimum_go_version=go1.19
   if [[ "${minimum_go_version}" != $(echo -e "${minimum_go_version}\n${go_version[2]}" | sort -s -t. -k 1,1 -k 2,2n -k 3,3n | head -n1) && "${go_version[2]}" != "devel" ]]; then
     kube::log::usage_from_stdin <<EOF
 Detected go version: ${go_version[*]}.
@@ -556,14 +531,20 @@ EOF
 # Outputs:
 #   env-var GOPATH points to our local output dir
 #   env-var GOBIN is unset (we want binaries in a predictable place)
-#   env-var PATH includes the local GOPATH
+#   env-var GO15VENDOREXPERIMENT=1
+#   current directory is within GOPATH
 kube::golang::setup_env() {
+  kube::golang::verify_go_version
+
+  # Set up GOPATH.  We have tools which depend on being in a GOPATH (see
+  # hack/run-in-gopath.sh).
+  #
   # Even in module mode, we need to set GOPATH for `go build` and `go install`
   # to work.  We build various tools (usually via `go install`) from a lot of
   # scripts.
-  #   * We can't just set GOBIN because that does not work on cross-compiles.
-  #   * We could always use `go build -o <something>`, but it's subtle wrt
-  #     cross-compiles and whether the <something> is a file or a directory,
+  #   * We can't set GOBIN because that does not work on cross-compiles.
+  #   * We could use `go build -o <something>`, but it's subtle when it comes
+  #     to cross-compiles and whether the <something> is a file or a directory,
   #     and EVERY caller has to get it *just* right.
   #   * We could leave GOPATH alone and let `go install` write binaries
   #     wherever the user's GOPATH says (or doesn't say).
@@ -571,49 +552,41 @@ kube::golang::setup_env() {
   # Instead we set it to a phony local path and process the results ourselves.
   # In particular, GOPATH[0]/bin will be used for `go install`, with
   # cross-compiles adding an extra directory under that.
+  #
+  # Eventually, when we no longer rely on run-in-gopath.sh we may be able to
+  # simplify this some.
+  kube::golang::create_gopath_tree
   export GOPATH="${KUBE_GOPATH}"
 
-  # If these are not set, set them now.  This ensures that any subsequent
-  # scripts we run (which may call this function again) use the same values.
-  export GOCACHE="${GOCACHE:-"${KUBE_GOPATH}/cache/build"}"
-  export GOMODCACHE="${GOMODCACHE:-"${KUBE_GOPATH}/cache/mod"}"
+  export GOCACHE="${KUBE_GOPATH}/cache"
 
   # Make sure our own Go binaries are in PATH.
   export PATH="${KUBE_GOPATH}/bin:${PATH}"
 
+  # Change directories so that we are within the GOPATH.  Some tools get really
+  # upset if this is not true.  We use a whole fake GOPATH here to collect the
+  # resultant binaries.
+  local subdir
+  subdir=$(kube::realpath . | sed "s|${KUBE_ROOT}||")
+  cd "${KUBE_GOPATH}/src/${KUBE_GO_PACKAGE}/${subdir}" || return 1
+
+  # Set GOROOT so binaries that parse code can work properly.
+  GOROOT=$(go env GOROOT)
+  export GOROOT
+
   # Unset GOBIN in case it already exists in the current session.
   # Cross-compiles will not work with it set.
   unset GOBIN
 
-  # Turn on modules and workspaces (both are default-on).
-  unset GO111MODULE
-  unset GOWORK
-
-  # This may try to download our specific Go version.  Do it last so it uses
-  # the above-configured environment.
-  kube::golang::internal::verify_go_version
+  # This seems to matter to some tools
+  export GO15VENDOREXPERIMENT=1
 }
 
-kube::golang::setup_gomaxprocs() {
-  # GOMAXPROCS by default does not reflect the number of cpu(s) available
-  # when running in a container, please see https://github.com/golang/go/issues/33803
-  if [[ -z "${GOMAXPROCS:-}" ]]; then
-    if ! command -v ncpu >/dev/null 2>&1; then
-      go -C "${KUBE_ROOT}/hack/tools" install ./ncpu || echo "Will not automatically set GOMAXPROCS"
-    fi
-    if command -v ncpu >/dev/null 2>&1; then
-      GOMAXPROCS=$(ncpu)
-      export GOMAXPROCS
-      kube::log::status "Set GOMAXPROCS automatically to ${GOMAXPROCS}"
-    fi
-  fi
-}
-
 # This will take binaries from $GOPATH/bin and copy them to the appropriate
-# place in ${KUBE_OUTPUT_BIN}
+# place in ${KUBE_OUTPUT_BINDIR}
 #
 # Ideally this wouldn't be necessary and we could just set GOBIN to
-# KUBE_OUTPUT_BIN but that won't work in the face of cross compilation.  'go
+# KUBE_OUTPUT_BINDIR but that won't work in the face of cross compilation.  'go
 # install' will place binaries that match the host platform directly in $GOBIN
 # while placing cross compiled binaries into `platform_arch` subdirs.  This
 # complicates pretty much everything else we do around packaging and such.
@@ -631,15 +604,14 @@ kube::golang::place_bins() {
     if [[ "${platform}" == "${host_platform}" ]]; then
       platform_src=""
       rm -f "${THIS_PLATFORM_BIN}"
-      mkdir -p "$(dirname "${THIS_PLATFORM_BIN}")"
-      ln -s "${KUBE_OUTPUT_BIN}/${platform}" "${THIS_PLATFORM_BIN}"
+      ln -s "${KUBE_OUTPUT_BINPATH}/${platform}" "${THIS_PLATFORM_BIN}"
     fi
 
     local full_binpath_src="${KUBE_GOPATH}/bin${platform_src}"
     if [[ -d "${full_binpath_src}" ]]; then
-      mkdir -p "${KUBE_OUTPUT_BIN}/${platform}"
+      mkdir -p "${KUBE_OUTPUT_BINPATH}/${platform}"
       find "${full_binpath_src}" -maxdepth 1 -type f -exec \
-        rsync -pc {} "${KUBE_OUTPUT_BIN}/${platform}" \;
+        rsync -pc {} "${KUBE_OUTPUT_BINPATH}/${platform}" \;
     fi
   done
 }
@@ -682,8 +654,7 @@ kube::golang::is_instrumented_package() {
 # Echos the path to a dummy test used for coverage information.
 kube::golang::path_for_coverage_dummy_test() {
   local package="$1"
-  local path
-  path=$(go list -find -f '{{.Dir}}' "${package}")
+  local path="${KUBE_GOPATH}/src/${package}"
   local name
   name=$(basename "${package}")
   echo "${path}/zz_generated_${name}_test.go"
@@ -750,7 +721,7 @@ kube::golang::build_some_binaries() {
 
         go test -c -o "$(kube::golang::outfile_for_binary "${package}" "${platform}")" \
           -covermode count \
-          -coverpkg k8s.io/... \
+          -coverpkg k8s.io/...,k8s.io/kubernetes/vendor/k8s.io/... \
           "${build_args[@]}" \
           -tags coverage \
           "${package}"
@@ -760,14 +731,14 @@ kube::golang::build_some_binaries() {
     done
     if [[ "${#uncovered[@]}" != 0 ]]; then
       V=2 kube::log::info "Building ${uncovered[*]} without coverage..."
-      GOPROXY=off go install "${build_args[@]}" "${uncovered[@]}"
+      GO111MODULE=on GOPROXY=off go install "${build_args[@]}" "${uncovered[@]}"
     else
       V=2 kube::log::info "Nothing to build without coverage."
-    fi
-  else
+     fi
+   else
     V=2 kube::log::info "Coverage is disabled."
-    GOPROXY=off go install "${build_args[@]}" "$@"
-  fi
+    GO111MODULE=on GOPROXY=off go install "${build_args[@]}" "$@"
+   fi
 }
 
 # Args:
@@ -786,17 +757,17 @@ kube::golang::build_binaries_for_platform() {
     if [[ "${binary}" =~ ".test"$ ]]; then
       tests+=("${binary}")
       kube::log::info "    ${binary} (test)"
-    elif kube::golang::is_statically_linked "${binary}"; then
+    elif kube::golang::is_statically_linked_library "${binary}"; then
       statics+=("${binary}")
       kube::log::info "    ${binary} (static)"
     else
       nonstatics+=("${binary}")
       kube::log::info "    ${binary} (non-static)"
     fi
-   done
+  done
 
   V=2 kube::log::info "Env for ${platform}: GOOS=${GOOS-} GOARCH=${GOARCH-} GOROOT=${GOROOT-} CGO_ENABLED=${CGO_ENABLED-} CC=${CC-}"
-  V=3 kube::log::info "Building binaries with GCFLAGS=${gogcflags} LDFLAGS=${goldflags}"
+  V=3 kube::log::info "Building binaries with GCFLAGS=${gogcflags} ASMFLAGS=${goasmflags} LDFLAGS=${goldflags}"
 
   local -a build_args
   if [[ "${#statics[@]}" != 0 ]]; then
@@ -804,6 +775,8 @@ kube::golang::build_binaries_for_platform() {
       -installsuffix=static
       ${goflags:+"${goflags[@]}"}
       -gcflags="${gogcflags}"
+      -buildvcs="false"
+      -asmflags="${goasmflags}"
       -ldflags="${goldflags}"
       -tags="${gotags:-}"
     )
@@ -814,6 +787,8 @@ kube::golang::build_binaries_for_platform() {
     build_args=(
       ${goflags:+"${goflags[@]}"}
       -gcflags="${gogcflags}"
+      -buildvcs="false"
+      -asmflags="${goasmflags}"
       -ldflags="${goldflags}"
       -tags="${gotags:-}"
     )
@@ -829,7 +804,9 @@ kube::golang::build_binaries_for_platform() {
     go test -c \
       ${goflags:+"${goflags[@]}"} \
       -gcflags="${gogcflags}" \
+      -asmflags="${goasmflags}" \
       -ldflags="${goldflags}" \
+      -buildvcs="false" \
       -tags="${gotags:-}" \
       -o "${outfile}" \
       "${testpkg}"
@@ -885,19 +862,26 @@ kube::golang::build_binaries() {
     # These are "local" but are visible to and relied on by functions this
     # function calls.  They are effectively part of the calling API to
     # build_binaries_for_platform.
-    local goflags goldflags gogcflags gotags
+    local goflags goldflags goasmflags gogcflags gotags
 
-    goflags=()
-    gogcflags="${GOGCFLAGS:-}"
-    goldflags="all=$(kube::version::ldflags) ${GOLDFLAGS:-}"
+    # This is $(pwd) because we use run-in-gopath to build.  Once that is
+    # excised, this can become ${KUBE_ROOT}.
+    local trimroot # two lines to appease shellcheck SC2155
+    trimroot=$(pwd)
 
+    goasmflags="all=-trimpath=${trimroot}"
+
+    gogcflags="all=-trimpath=${trimroot} ${GOGCFLAGS:-}"
     if [[ "${DBG:-}" == 1 ]]; then
         # Debugging - disable optimizations and inlining and trimPath
-        gogcflags="${gogcflags} all=-N -l"
-    else
-        # Not debugging - disable symbols and DWARF, trim embedded paths
+        gogcflags="${GOGCFLAGS:-} all=-N -l"
+        goasmflags=""
+    fi
+
+    goldflags="all=$(kube::version::ldflags) ${GOLDFLAGS:-}"
+    if [[ "${DBG:-}" != 1 ]]; then
+        # Not debugging - disable symbols and DWARF.
         goldflags="${goldflags} -s -w"
-        goflags+=("-trimpath")
     fi
 
     # Extract tags if any specified in GOFLAGS
@@ -915,20 +899,18 @@ kube::golang::build_binaries() {
       fi
     done
 
+    if [[ ${#targets[@]} -eq 0 ]]; then
+      targets=("${KUBE_ALL_TARGETS[@]}")
+    fi
+
     local -a platforms
     IFS=" " read -ra platforms <<< "${KUBE_BUILD_PLATFORMS:-}"
     if [[ ${#platforms[@]} -eq 0 ]]; then
       platforms=("${host_platform}")
     fi
 
-    if [[ ${#targets[@]} -eq 0 ]]; then
-      targets=("${KUBE_ALL_TARGETS[@]}")
-    fi
-    kube::util::read-array targets < <(kube::golang::dedup "${targets[@]}")
-
     local -a binaries
-    kube::util::read-array binaries < <(kube::golang::normalize_go_targets "${targets[@]}")
-    kube::util::read-array binaries < <(kube::golang::dedup "${binaries[@]}")
+    while IFS="" read -r binary; do binaries+=("$binary"); done < <(kube::golang::binaries_from_targets "${targets[@]}")
 
     local parallel=false
     if [[ ${#platforms[@]} -gt 1 ]]; then
@@ -976,3 +958,4 @@ kube::golang::build_binaries() {
     fi
   )
 }
+
