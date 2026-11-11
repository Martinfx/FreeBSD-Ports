--- src/brave/build/commands/lib/config.ts.orig	2026-11-02 23:22:33 UTC
+++ src/brave/build/commands/lib/config.ts
@@ -33,7 +33,14 @@ type UpdateOptions = buildOptions.BuildD
     lean_sync?: boolean | undefined
   }
 
-const validTargetOSValues = ['android', 'ios', 'linux', 'mac', 'win'] as const
+const validTargetOSValues = [
+  'android',
+  'freebsd',
+  'ios',
+  'linux',
+  'mac',
+  'win',
+] as const
 type TargetOS = (typeof validTargetOSValues)[number]
 
 const braveCoreDir = path.join(rootDir, 'src', 'brave')
@@ -340,7 +347,7 @@ export class Config {
   enableCDMHostVerification() {
     const enable =
       this.buildConfig === 'Release'
-      && process.platform !== 'linux'
+      && !['linux', 'freebsd'].includes(process.platform)
       && this.sign_widevine_cert !== ''
       && this.sign_widevine_key !== ''
       && this.sign_widevine_passwd !== ''
@@ -749,22 +756,30 @@ export class Config {
 
   get defaultOptions(): ExecOptions {
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
@@ -977,6 +992,8 @@ export class Config {
         return 'mac'
       case 'linux':
         return 'linux'
+      case 'freebsd':
+        return 'freebsd'
       case 'win32':
         return 'win'
       default:
