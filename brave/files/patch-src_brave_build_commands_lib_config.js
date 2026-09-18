--- src/brave/build/commands/lib/config.js.orig	2026-01-05 00:00:00 UTC
+++ src/brave/build/commands/lib/config.js
@@ -167,6 +167,8 @@
       return 'mac'
     case 'linux':
       return 'linux'
+    case 'freebsd':
+      return 'freebsd'
     case 'win32':
       return 'win'
     default:
@@ -174,6 +176,13 @@
   }
 }
 
+// FreeBSD is built with the Chromium Linux configuration: the FreeBSD Chromium
+// port patches build/config/BUILDCONFIG.gn so that target_os="freebsd" turns on
+// is_linux (and is_bsd) in GN.
+const isLinuxLike = (targetOS) => {
+  return targetOS === 'linux' || targetOS === 'freebsd'
+}
+
 const Config = function () {
   this.isTeamcity = process.env.TEAMCITY_VERSION !== undefined
   this.isCI = process.env.BUILD_ID !== undefined || this.isTeamcity
@@ -395,7 +404,7 @@
 Config.prototype.enableCDMHostVerification = function () {
   const enable =
     this.buildConfig === 'Release'
-    && process.platform !== 'linux'
+    && !['linux', 'freebsd'].includes(process.platform)
     && this.sign_widevine_cert !== ''
     && this.sign_widevine_key !== ''
     && this.sign_widevine_passwd !== ''
@@ -591,7 +600,7 @@
   //    configuration. symbol_level = 2 cannot be used because of "relocation
   //    R_X86_64_32 out of range" errors.
   if (
-    this.targetOS === 'linux'
+    isLinuxLike(this.targetOS)
     && (this.targetArch === 'x86'
       || (!this.isDebug()
         && !this.isComponentBuild()
@@ -609,7 +618,7 @@
   // For Linux Release builds, upstream doesn't want to use symbol_level = 2
   // unless use_debug_fission is set. However, they don't set it when a
   // cc_wrapper is used. Since we use cc_wrapper we need to set it manually.
-  if (this.targetOS === 'linux' && this.isReleaseBuild()) {
+  if (isLinuxLike(this.targetOS) && this.isReleaseBuild()) {
     args.use_debug_fission = true
   }
 
@@ -639,7 +648,22 @@
     }
   }
 
-  if (['android', 'linux', 'mac'].includes(this.targetOS)) {
+  if (this.targetOS === 'freebsd') {
+    // Nothing is downloaded on FreeBSD: there is no hermetic toolchain, no
+    // sysroot, no PGO profile and no depot_tools, so the build has to rely on
+    // the compiler and the libraries installed from ports.
+    args.use_sysroot = false
+    args.clang_use_chrome_plugins = false
+    args.enable_nacl = false
+    args.chrome_pgo_phase = 0
+    args.use_remoteexec = false
+    args.use_reclient = false
+    args.use_siso = false
+    args.treat_warnings_as_errors = false
+    args.fatal_linker_warnings = false
+  }
+
+  if (['android', 'freebsd', 'linux', 'mac'].includes(this.targetOS)) {
     // LSAN only works with ASAN and has very low overhead.
     args.is_lsan = args.is_asan
   }
@@ -1096,7 +1120,7 @@
   set: function (value) {
     this._targetOS = value
     if (this._targetOS) {
-      const supportedOS = ['android', 'ios', 'linux', 'mac', 'win']
+      const supportedOS = ['android', 'freebsd', 'ios', 'linux', 'mac', 'win']
       assert(
         supportedOS.includes(this._targetOS),
         `Unsupported target_os value: ${
@@ -1126,22 +1150,30 @@
 Object.defineProperty(Config.prototype, 'defaultOptions', {
   get: function () {
     let env = Object.assign({}, process.env)
-    env = this.addPathToEnv(
-      env,
-      path.join(this.depotToolsDir, 'python-bin'),
-      true,
-    )
-    env = this.addPathToEnv(
-      env,
-      path.join(this.depotToolsDir, 'python2-bin'),
-      true,
-    )
+    // FreeBSD does not use depot_tools at all: gn, ninja, python and node are
+    // installed from ports and must not be shadowed by depot_tools wrappers,
+    // which would try to fetch binaries that do not exist for this platform.
+    const useDepotTools = process.platform !== 'freebsd'
+    if (useDepotTools) {
+      env = this.addPathToEnv(
+        env,
+        path.join(this.depotToolsDir, 'python-bin'),
+        true,
+      )
+      env = this.addPathToEnv(
+        env,
+        path.join(this.depotToolsDir, 'python2-bin'),
+        true,
+      )
+    }
     env = this.addPathToEnv(
       env,
       path.join(this.srcDir, 'third_party', 'rust-toolchain', 'bin'),
       true,
     )
-    env = this.addPathToEnv(env, this.depotToolsDir, true)
+    if (useDepotTools) {
+      env = this.addPathToEnv(env, this.depotToolsDir, true)
+    }
     if (this.targetOS === 'mac' && process.platform !== 'darwin') {
       const crossCompilePath = path.join(
         this.srcDir,
@@ -1344,6 +1376,11 @@
 
 Object.defineProperty(Config.prototype, 'useSiso', {
   get: function () {
+    if (process.platform === 'freebsd') {
+      // siso is fetched with CIPD via depot_tools, which is not used on
+      // FreeBSD. Always build with ninja from ports instead.
+      return false
+    }
     return getEnvConfig(
       ['use_siso'],
       // * iOS fails in siso+reproxy mode because of incorrect handling of
