--- src/brave/build/commands/lib/config.ts.orig	2026-06-01 00:00:00 UTC
+++ src/brave/build/commands/lib/config.ts
@@ -22,7 +22,14 @@
   onStdErrLine?: (line: string) => void
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
@@ -254,7 +261,12 @@
     this.braveAndroidPkcs11Alias = ''
     this.nativeRedirectCCDir = path.join(this.srcDir, 'out', 'redirect_cc')
     this.useRemoteExec = envConfig.getBoolean(['use_remoteexec'], false)
-    this.useSiso = envConfig.getBoolean(['use_siso'], true)
+    // siso is fetched with CIPD via depot_tools, which is not used on
+    // FreeBSD: build with ninja from ports instead.
+    this.useSiso = envConfig.getBoolean(
+      ['use_siso'],
+      process.platform !== 'freebsd',
+    )
     this.useReclient = envConfig.getBoolean(
       ['use_reclient'],
       this.useRemoteExec && !this.useSiso,
@@ -327,7 +339,7 @@
   enableCDMHostVerification() {
     const enable =
       this.buildConfig === 'Release'
-      && process.platform !== 'linux'
+      && !['linux', 'freebsd'].includes(process.platform)
       && this.sign_widevine_cert !== ''
       && this.sign_widevine_key !== ''
       && this.sign_widevine_passwd !== ''
@@ -719,22 +731,30 @@
 
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
@@ -950,6 +970,8 @@
         return 'mac'
       case 'linux':
         return 'linux'
+      case 'freebsd':
+        return 'freebsd'
       case 'win32':
         return 'win'
       default:
