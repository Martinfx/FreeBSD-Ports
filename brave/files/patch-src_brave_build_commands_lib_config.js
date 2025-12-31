--- src/brave/build/commands/lib/config.js.orig	2025-12-31 00:03:24 UTC
+++ src/brave/build/commands/lib/config.js
@@ -169,6 +169,8 @@ const getHostOS = () => {
       return 'linux'
     case 'win32':
       return 'win'
+    case 'freebsd':
+      return 'freebsd'
     default:
       throw new Error(`Unsupported process.platform: ${process.platform}`)
   }
@@ -395,7 +397,7 @@ Config.prototype.enableCDMHostVerification = function 
 Config.prototype.enableCDMHostVerification = function () {
   const enable =
     this.buildConfig === 'Release'
-    && process.platform !== 'linux'
+    && process.platform !== 'freebsd'
     && this.sign_widevine_cert !== ''
     && this.sign_widevine_key !== ''
     && this.sign_widevine_passwd !== ''
@@ -591,7 +593,7 @@ Config.prototype.buildArgs = function () {
   //    configuration. symbol_level = 2 cannot be used because of "relocation
   //    R_X86_64_32 out of range" errors.
   if (
-    this.targetOS === 'linux'
+    this.targetOS === 'freebsd'
     && (this.targetArch === 'x86'
       || (!this.isDebug()
         && !this.isComponentBuild()
@@ -609,7 +611,7 @@ Config.prototype.buildArgs = function () {
   // For Linux Release builds, upstream doesn't want to use symbol_level = 2
   // unless use_debug_fission is set. However, they don't set it when a
   // cc_wrapper is used. Since we use cc_wrapper we need to set it manually.
-  if (this.targetOS === 'linux' && this.isReleaseBuild()) {
+  if (this.targetOS === 'freebsd' && this.isReleaseBuild()) {
     args.use_debug_fission = true
   }
 
@@ -629,7 +631,7 @@ Config.prototype.buildArgs = function () {
     args.use_system_xcode = false
   }
 
-  if (this.targetOS === 'linux') {
+  if (this.targetOS === 'freebsd') {
     if (this.targetArch !== 'x86') {
       // Include vaapi support
       // TODO: Consider setting use_vaapi_x11 instead of use_vaapi. Also
@@ -639,7 +641,7 @@ Config.prototype.buildArgs = function () {
     }
   }
 
-  if (['android', 'linux', 'mac'].includes(this.targetOS)) {
+  if (['android', 'freebsd', 'mac'].includes(this.targetOS)) {
     // LSAN only works with ASAN and has very low overhead.
     args.is_lsan = args.is_asan
   }
@@ -1096,7 +1098,7 @@ Object.defineProperty(Config.prototype, 'targetOS', {
   set: function (value) {
     this._targetOS = value
     if (this._targetOS) {
-      const supportedOS = ['android', 'ios', 'linux', 'mac', 'win']
+      const supportedOS = ['android', 'ios', 'freebsd', 'linux', 'mac', 'win']
       assert(
         supportedOS.includes(this._targetOS),
         `Unsupported target_os value: ${
@@ -1273,7 +1275,7 @@ Object.defineProperty(Config.prototype, 'defaultOption
       env.NINJA_SUMMARIZE_BUILD = 1
     }
 
-    if (process.platform === 'linux') {
+    if (process.platform === 'linux' || process.platform === 'freebsd') {
       env.LLVM_DOWNLOAD_GOLD_PLUGIN = '1'
     }
 
