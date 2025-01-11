--- src/brave/build/commands/lib/config.js.orig	2025-01-08 18:29:45 UTC
+++ src/brave/build/commands/lib/config.js
@@ -115,6 +115,8 @@ const getHostOS = () => {
       return 'linux'
     case 'win32':
       return 'win'
+    case 'freebsd':
+      return 'freebsd'
     default:
       throw new Error(`Unsupported process.platform: ${process.platform}`)
   }
@@ -282,7 +284,8 @@ Config.prototype.enableCDMHostVerification = function 
 
 Config.prototype.enableCDMHostVerification = function () {
   const enable = this.buildConfig === 'Release' &&
-    process.platform !== 'linux' &&
+    process.platform !== 'linux' ||
+    process.platform !== 'freebsd' &&
     this.sign_widevine_cert !== "" &&
     this.sign_widevine_key !== "" &&
     this.sign_widevine_passwd !== "" &&
@@ -520,7 +523,8 @@ Config.prototype.buildArgs = function () {
   //    configuration. symbol_level = 2 cannot be used because of "relocation
   //    R_X86_64_32 out of range" errors.
   if (
-    this.getTargetOS() === 'linux' &&
+    this.getTargetOS() === 'linux' ||
+    this.getTargetOS() === 'freebsd' &&
     (this.targetArch === 'x86' ||
       (!this.isDebug() && !this.isComponentBuild() && !this.isReleaseBuild()))
   ) {
@@ -530,7 +534,7 @@ Config.prototype.buildArgs = function () {
   // For Linux Release builds, upstream doesn't want to use symbol_level = 2
   // unless use_debug_fission is set. However, they don't set it when a
   // cc_wrapper is used. Since we use cc_wrapper we need to set it manually.
-  if (this.getTargetOS() === 'linux' && this.isReleaseBuild()) {
+  if (this.getTargetOS() === 'linux' || this.getTargetOS() == 'freebsd'  && this.isReleaseBuild()) {
     args.use_debug_fission = true
   }
 
@@ -540,7 +544,7 @@ Config.prototype.buildArgs = function () {
       args.use_system_xcode = false
   }
 
-  if (this.getTargetOS() === 'linux') {
+  if (this.getTargetOS() === 'linux' || this.getTargetOS() === 'freebsd' ) {
     if (this.targetArch !== 'x86') {
       // Include vaapi support
       // TODO: Consider setting use_vaapi_x11 instead of use_vaapi. Also
@@ -865,7 +869,7 @@ Config.prototype.update = function (options) {
       this.targetOS = options.target_os;
     }
     assert(
-      ['android', 'ios', 'linux', 'mac', 'win'].includes(this.targetOS),
+      ['android', 'ios', 'linux', 'freebsd', 'mac', 'win'].includes(this.targetOS),
       `Unsupported target_os value: ${this.targetOS}`
     )
   }
@@ -1131,7 +1135,7 @@ Object.defineProperty(Config.prototype, 'defaultOption
       env.NINJA_SUMMARIZE_BUILD = 1
     }
 
-    if (process.platform === 'linux') {
+    if (process.platform === 'linux' || process.platform === 'freebsd') {
       env.LLVM_DOWNLOAD_GOLD_PLUGIN = '1'
     }
 
