--- hack/lib/util.sh.orig	2024-06-19 07:38:18 UTC
+++ hack/lib/util.sh
@@ -147,6 +147,15 @@ kube::util::host_os() {
     Linux)
       host_os=linux
       ;;
+    SunOS)
+      host_os=solaris
+      ;;
+    FreeBSD)
+      host_os=freebsd
+      ;;
+    OpenBSD)
+      host_os=openbsd
+      ;;
     *)
       kube::log::error "Unsupported host OS.  Must be Linux or Mac OS X."
       exit 1
@@ -164,6 +173,9 @@ kube::util::host_arch() {
     i?86_64*)
       host_arch=amd64
       ;;
+    i86pc*)
+      host_arch=amd64
+      ;;
     amd64*)
       host_arch=amd64
       ;;
@@ -243,6 +255,59 @@ kube::util::find-binary() {
   kube::util::find-binary-for-platform "$1" "$(kube::util::host_platform)"
 }
 
+# Run all known doc generators (today gendocs and genman for kubectl)
+# $1 is the directory to put those generated documents
+kube::util::gen-docs() {
+  local dest="$1"
+
+  # Find binary
+  gendocs=$(kube::util::find-binary "gendocs")
+  genkubedocs=$(kube::util::find-binary "genkubedocs")
+  genman=$(kube::util::find-binary "genman")
+  genyaml=$(kube::util::find-binary "genyaml")
+
+  mkdir -p "${dest}/docs/user-guide/kubectl/"
+  "${gendocs}" "${dest}/docs/user-guide/kubectl/"
+  mkdir -p "${dest}/docs/admin/"
+  "${genkubedocs}" "${dest}/docs/admin/" "kube-apiserver"
+  "${genkubedocs}" "${dest}/docs/admin/" "kube-controller-manager"
+  "${genkubedocs}" "${dest}/docs/admin/" "kube-proxy"
+  "${genkubedocs}" "${dest}/docs/admin/" "kube-scheduler"
+  "${genkubedocs}" "${dest}/docs/admin/" "kubelet"
+  "${genkubedocs}" "${dest}/docs/admin/" "kubeadm"
+
+  mkdir -p "${dest}/docs/man/man1/"
+  "${genman}" "${dest}/docs/man/man1/" "kube-apiserver"
+  "${genman}" "${dest}/docs/man/man1/" "kube-controller-manager"
+  "${genman}" "${dest}/docs/man/man1/" "kube-proxy"
+  "${genman}" "${dest}/docs/man/man1/" "kube-scheduler"
+  "${genman}" "${dest}/docs/man/man1/" "kubelet"
+  "${genman}" "${dest}/docs/man/man1/" "kubectl"
+  "${genman}" "${dest}/docs/man/man1/" "kubeadm"
+
+  mkdir -p "${dest}/docs/yaml/kubectl/"
+  "${genyaml}" "${dest}/docs/yaml/kubectl/"
+
+  # create the list of generated files
+  pushd "${dest}" > /dev/null || return 1
+  touch docs/.generated_docs
+  find . -type f | cut -sd / -f 2- | LC_ALL=C sort > docs/.generated_docs
+  popd > /dev/null || return 1
+}
+
+# Removes previously generated docs-- we don't want to check them in. $KUBE_ROOT
+# must be set.
+kube::util::remove-gen-docs() {
+  if [ -e "${KUBE_ROOT}/docs/.generated_docs" ]; then
+    # remove all of the old docs; we don't want to check them in.
+    while read -r file; do
+      rm "${KUBE_ROOT}/${file}" 2>/dev/null || true
+    done <"${KUBE_ROOT}/docs/.generated_docs"
+    # The docs/.generated_docs file lists itself, so we don't need to explicitly
+    # delete it.
+  fi
+}
+
 # Takes a group/version and returns the path to its location on disk, sans
 # "pkg". E.g.:
 # * default behavior: extensions/v1beta1 -> apis/extensions/v1beta1
@@ -255,28 +320,16 @@ kube::util::find-binary() {
 kube::util::group-version-to-pkg-path() {
   local group_version="$1"
 
-  # Make a list of all know APIs by listing their dirs.
-  local apidirs=()
-  kube::util::read-array apidirs < <(
-      cd "${KUBE_ROOT}/staging/src/k8s.io/api" || return 1 # make shellcheck happy
-      find . -name types.go -exec dirname {} \; \
-        | sed "s|\./||g" \
-        | LC_ALL=C sort -u)
-
-  # Compare each API dir against the requested GV, and if we find it, no
-  # special handling needed.
-  for api in "${apidirs[@]}"; do
-    # Change "foo.bar.k8s.io/v1" -> "foo/v1" notation.
-    local simple_gv="${group_version/.*k8s.io/}"
-    if [[ "${api}" = "${simple_gv}" ]]; then
-      echo "staging/src/k8s.io/api/${simple_gv}"
+  while IFS=$'\n' read -r api; do
+    if [[ "${api}" = "${group_version/.*k8s.io/}" ]]; then
+      echo "vendor/k8s.io/api/${group_version/.*k8s.io/}"
       return
     fi
-  done
+  done < <(cd "${KUBE_ROOT}/staging/src/k8s.io/api" && find . -name types.go -exec dirname {} \; | sed "s|\./||g" | sort)
 
   # "v1" is the API GroupVersion
   if [[ "${group_version}" == "v1" ]]; then
-    echo "staging/src/k8s.io/api/core/v1"
+    echo "vendor/k8s.io/api/core/v1"
     return
   fi
 
@@ -289,13 +342,13 @@ kube::util::group-version-to-pkg-path() {
       echo "pkg/apis/core"
       ;;
     meta/v1)
-      echo "staging/src/k8s.io/apimachinery/pkg/apis/meta/v1"
+      echo "vendor/k8s.io/apimachinery/pkg/apis/meta/v1"
       ;;
     meta/v1beta1)
-      echo "staging/src/k8s.io/apimachinery/pkg/apis/meta/v1beta1"
+      echo "vendor/k8s.io/apimachinery/pkg/apis/meta/v1beta1"
       ;;
     internal.apiserver.k8s.io/v1alpha1)
-      echo "staging/src/k8s.io/api/apiserverinternal/v1alpha1"
+      echo "vendor/k8s.io/api/apiserverinternal/v1alpha1"
       ;;
     *.k8s.io)
       echo "pkg/apis/${group_version%.*k8s.io}"
@@ -676,8 +729,7 @@ function kube::util::ensure-cfssl {
 # Check if we have "docker buildx" commands available
 #
 function kube::util::ensure-docker-buildx {
-  # podman returns 0 on `docker buildx version`, docker on `docker buildx`. One of them must succeed.
-  if docker buildx version >/dev/null 2>&1 || docker buildx >/dev/null 2>&1; then
+  if docker buildx --help >/dev/null 2>&1; then
     return 0
   else
     echo "ERROR: docker buildx not available. Docker 19.03 or higher is required with experimental features enabled"
@@ -779,8 +831,8 @@ function kube::util::md5() {
 # kube::util::read-array
 # Reads in stdin and adds it line by line to the array provided. This can be
 # used instead of "mapfile -t", and is bash 3 compatible.  If the named array
-# exists and is an array, it will be overwritten.  Otherwise it will be unset
-# and recreated.
+# exists and is an array, it will be used.  Otherwise it will be unset and
+# recreated.
 #
 # Assumed vars:
 #   $1 (name of array to create/modify)
@@ -848,3 +900,4 @@ if [[ -z "${color_start-}" ]]; then
 fi
 
 # ex: ts=2 sw=2 et filetype=sh
+
