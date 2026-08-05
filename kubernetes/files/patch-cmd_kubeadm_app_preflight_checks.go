--- cmd/kubeadm/app/preflight/checks.go.orig	2024-06-11 20:20:59 UTC
+++ cmd/kubeadm/app/preflight/checks.go
@@ -13,6 +13,8 @@ WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either e
 See the License for the specific language governing permissions and
 limitations under the License.
 */
+//go:build !solaris
+// +build !solaris
 
 package preflight
 
@@ -54,11 +56,13 @@ import (
 )
 
 const (
+	bridgenf                    = "/proc/sys/net/bridge/bridge-nf-call-iptables"
+	bridgenf6                   = "/proc/sys/net/bridge/bridge-nf-call-ip6tables"
 	ipv4Forward                 = "/proc/sys/net/ipv4/ip_forward"
 	ipv6DefaultForwarding       = "/proc/sys/net/ipv6/conf/default/forwarding"
-	externalEtcdRequestTimeout  = 10 * time.Second
+	externalEtcdRequestTimeout  = time.Duration(10 * time.Second)
 	externalEtcdRequestRetries  = 3
-	externalEtcdRequestInterval = 5 * time.Second
+	externalEtcdRequestInterval = time.Duration(5 * time.Second)
 )
 
 var (
@@ -382,7 +386,7 @@ func (ipc InPathCheck) Check() (warnings, errs []error
 	return nil, nil
 }
 
-// HostnameCheck checks if hostname match dns subdomain regex.
+// HostnameCheck checks if hostname match dns sub domain regex.
 // If hostname doesn't match this regex, kubelet will not launch static pods like kube-apiserver/kube-controller-manager and so on.
 type HostnameCheck struct {
 	nodeName string
@@ -393,7 +397,7 @@ func (HostnameCheck) Name() string {
 	return "Hostname"
 }
 
-// Check validates if hostname match dns subdomain regex.
+// Check validates if hostname match dns sub domain regex.
 // Check hostname length and format
 func (hc HostnameCheck) Check() (warnings, errorList []error) {
 	klog.V(1).Infoln("checking whether the given node name is valid and reachable using net.LookupHost")
@@ -576,8 +580,8 @@ func (kubever KubernetesVersionCheck) Check() (warning
 
 	// Checks if k8sVersion greater or equal than the first unsupported versions by current version of kubeadm,
 	// that is major.minor+1 (all patch and pre-releases versions included)
-	// NB. in semver patches number is a numeric, while pre-release is a string where numeric identifiers always have lower precedence than non-numeric identifiers.
-	//     thus setting the value to x.y.0-0 we are defining the very first patch - pre-releases within x.y minor release.
+	// NB. in semver patches number is a numeric, while prerelease is a string where numeric identifiers always have lower precedence than non-numeric identifiers.
+	//     thus setting the value to x.y.0-0 we are defining the very first patch - prereleases within x.y minor release.
 	firstUnsupportedVersion := versionutil.MustParseSemantic(fmt.Sprintf("%d.%d.%s", kadmVersion.Major(), kadmVersion.Minor()+1, "0-0"))
 	if k8sVersion.AtLeast(firstUnsupportedVersion) {
 		return []error{errors.Errorf("Kubernetes version is greater than kubeadm version. Please consider to upgrade kubeadm. Kubernetes version: %s. Kubeadm version: %d.%d.x", k8sVersion, kadmVersion.Components()[0], kadmVersion.Components()[1])}, nil
@@ -651,7 +655,7 @@ func (swc SwapCheck) Check() (warnings, errorList []er
 	}
 
 	if len(buf) > 1 {
-		return []error{errors.New("swap is supported for cgroup v2 only; the NodeSwap feature gate of the kubelet is beta but disabled by default")}, nil
+		return []error{errors.New("swap is enabled; production deployments should disable swap unless testing the NodeSwap feature gate of the kubelet")}, nil
 	}
 
 	return nil, nil
@@ -813,7 +817,6 @@ type ImagePullCheck struct {
 	imageList       []string
 	sandboxImage    string
 	imagePullPolicy v1.PullPolicy
-	imagePullSerial bool
 }
 
 // Name returns the label for ImagePullCheck
@@ -823,39 +826,22 @@ func (ImagePullCheck) Name() string {
 
 // Check pulls images required by kubeadm. This is a mutating check
 func (ipc ImagePullCheck) Check() (warnings, errorList []error) {
-	// Handle unsupported image pull policy and policy Never.
 	policy := ipc.imagePullPolicy
-	switch policy {
-	case v1.PullAlways, v1.PullIfNotPresent:
-		klog.V(1).Infof("using image pull policy: %s", policy)
-	case v1.PullNever:
-		klog.V(1).Infof("skipping the pull of all images due to policy: %s", policy)
-		return warnings, errorList
-	default:
-		errorList = append(errorList, errors.Errorf("unsupported pull policy %q", policy))
-		return warnings, errorList
-	}
-
-	// Handle CRI sandbox image warnings.
-	criSandboxImage, err := ipc.runtime.SandboxImage()
-	if err != nil {
-		klog.V(4).Infof("failed to detect the sandbox image for local container runtime, %v", err)
-	} else if criSandboxImage != ipc.sandboxImage {
-		klog.Warningf("detected that the sandbox image %q of the container runtime is inconsistent with that used by kubeadm."+
-			"It is recommended to use %q as the CRI sandbox image.", criSandboxImage, ipc.sandboxImage)
-	}
-
-	// Perform parallel pulls.
-	if !ipc.imagePullSerial {
-		if err := ipc.runtime.PullImagesInParallel(ipc.imageList, policy == v1.PullIfNotPresent); err != nil {
-			errorList = append(errorList, err)
-		}
-		return warnings, errorList
-	}
-
-	// Perform serial pulls.
+	klog.V(1).Infof("using image pull policy: %s", policy)
 	for _, image := range ipc.imageList {
+		if image == ipc.sandboxImage {
+			criSandboxImage, err := ipc.runtime.SandboxImage()
+			if err != nil {
+				klog.V(4).Infof("failed to detect the sandbox image for local container runtime, %v", err)
+			} else if criSandboxImage != ipc.sandboxImage {
+				klog.Warningf("detected that the sandbox image %q of the container runtime is inconsistent with that used by kubeadm. It is recommended that using %q as the CRI sandbox image.",
+					criSandboxImage, ipc.sandboxImage)
+			}
+		}
 		switch policy {
+		case v1.PullNever:
+			klog.V(1).Infof("skipping pull of image: %s", image)
+			continue
 		case v1.PullIfNotPresent:
 			ret, err := ipc.runtime.ImageExists(image)
 			if ret && err == nil {
@@ -869,11 +855,14 @@ func (ipc ImagePullCheck) Check() (warnings, errorList
 		case v1.PullAlways:
 			klog.V(1).Infof("pulling: %s", image)
 			if err := ipc.runtime.PullImage(image); err != nil {
-				errorList = append(errorList, errors.WithMessagef(err, "failed to pull image %s", image))
+				errorList = append(errorList, errors.Wrapf(err, "failed to pull image %s", image))
 			}
+		default:
+			// If the policy is unknown return early with an error
+			errorList = append(errorList, errors.Errorf("unsupported pull policy %q", policy))
+			return warnings, errorList
 		}
 	}
-
 	return warnings, errorList
 }
 
@@ -906,7 +895,6 @@ func (MemCheck) Name() string {
 	return "Mem"
 }
 
-// InitNodeChecks returns checks specific to "kubeadm init"
 func InitNodeChecks(execer utilsexec.Interface, cfg *kubeadmapi.InitConfiguration, ignorePreflightErrors sets.Set[string], isSecondaryControlPlane bool, downloadCerts bool) ([]Checker, error) {
 	if !isSecondaryControlPlane {
 		// First, check if we're root separately from the other preflight checks and fail fast
@@ -920,7 +908,8 @@ func InitNodeChecks(execer utilsexec.Interface, cfg *k
 		NumCPUCheck{NumCPU: kubeadmconstants.ControlPlaneNumCPU},
 		// Linux only
 		// TODO: support other OS, if control-plane is supported on it.
-		MemCheck{Mem: kubeadmconstants.ControlPlaneMem},
+		// On FreeBSD we will ignore
+		//MemCheck{Mem: kubeadmconstants.ControlPlaneMem},
 		KubernetesVersionCheck{KubernetesVersion: cfg.KubernetesVersion, KubeadmVersion: kubeadmversion.Get().GitVersion},
 		FirewalldCheck{ports: []int{int(cfg.LocalAPIEndpoint.BindPort), kubeadmconstants.KubeletPort}},
 		PortOpenCheck{port: int(cfg.LocalAPIEndpoint.BindPort)},
@@ -934,10 +923,10 @@ func InitNodeChecks(execer utilsexec.Interface, cfg *k
 	}
 
 	// File content check for IPV4 and IPV6 are needed if it is:
-	// (dual stack)  `--service-cidr` or `--pod-network-cidr` is set with an IPV4 and IPV6 CIDR, `--apiserver-advertise-address` is optional as it can be auto-detected.
+	// (dual stack)  `--service-cidr` or `--pod-network-cidr` is set with an IPV4 and IPV6 CIDR, `--apiserver-advertise-address` is optional as it can be auto detected.
 	// (single stack) which is decided by the `--apiserver-advertise-address`.
 	// Note that for the case of dual stack, user might only give IPV6 CIDR for `--service-cidr` and leave the `--apiserver-advertise-address` a default value which will be
-	// auto-detected and properly bound to an IPV4 address, this will make the cluster non-functional eventually. The case like this should be avoided by the validation instead,
+	// auto detected and properly bound to an IPV4 address, this will make the cluster non-functional eventually. The case like this should be avoided by the validation instead,
 	// i.e. We don't care whether the input values for those parameters are set correctly here but if it's an IPV4 scoped CIDR or address we will add the file content check for IPV4,
 	// as does the IPV6.
 	IPV4Check := false
@@ -1027,7 +1016,6 @@ func RunInitNodeChecks(execer utilsexec.Interface, cfg
 	return RunChecks(checks, os.Stderr, ignorePreflightErrors)
 }
 
-// JoinNodeChecks returns checks specific to "kubeadm join"
 func JoinNodeChecks(execer utilsexec.Interface, cfg *kubeadmapi.JoinConfiguration, ignorePreflightErrors sets.Set[string]) ([]Checker, error) {
 	// First, check if we're root separately from the other preflight checks and fail fast
 	if err := RunRootCheckOnly(ignorePreflightErrors); err != nil {
@@ -1109,24 +1097,18 @@ func RunPullImagesCheck(execer utilsexec.Interface, cf
 		return &Error{Msg: err.Error()}
 	}
 
-	serialPull := true
-	if cfg.NodeRegistration.ImagePullSerial != nil {
-		serialPull = *cfg.NodeRegistration.ImagePullSerial
-	}
-
 	checks := []Checker{
 		ImagePullCheck{
 			runtime:         containerRuntime,
 			imageList:       images.GetControlPlaneImages(&cfg.ClusterConfiguration),
 			sandboxImage:    images.GetPauseImage(&cfg.ClusterConfiguration),
 			imagePullPolicy: cfg.NodeRegistration.ImagePullPolicy,
-			imagePullSerial: serialPull,
 		},
 	}
 	return RunChecks(checks, os.Stderr, ignorePreflightErrors)
 }
 
-// RunChecks runs each check, displays its warnings/errors, and once all
+// RunChecks runs each check, displays it's warnings/errors, and once all
 // are processed will exit if any errors occurred.
 func RunChecks(checks []Checker, ww io.Writer, ignorePreflightErrors sets.Set[string]) error {
 	var errsBuffer bytes.Buffer
@@ -1154,7 +1136,7 @@ func RunChecks(checks []Checker, ww io.Writer, ignoreP
 	return nil
 }
 
-// setHasItemOrAll is helper function that return true if item is present in the set (case-insensitive) or special key 'all' is present
+// setHasItemOrAll is helper function that return true if item is present in the set (case insensitive) or special key 'all' is present
 func setHasItemOrAll(s sets.Set[string], item string) bool {
 	if s.Has("all") || s.Has(strings.ToLower(item)) {
 		return true
@@ -1163,7 +1145,7 @@ func setHasItemOrAll(s sets.Set[string], item string) 
 }
 
 // normalizeURLString returns the normalized string, or an error if it can't be parsed into an URL object.
-// It takes a URL string as input.
+// It takes an URL string as input.
 func normalizeURLString(s string) (string, error) {
 	u, err := url.Parse(s)
 	if err != nil {
@@ -1174,3 +1156,4 @@ func normalizeURLString(s string) (string, error) {
 	}
 	return u.String(), nil
 }
+
