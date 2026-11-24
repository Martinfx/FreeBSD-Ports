--- src/brave/build/commands/lib/util.ts.orig	2026-11-24 12:50:30 UTC
+++ src/brave/build/commands/lib/util.ts
@@ -191,7 +191,7 @@ function getAdditionalGenLocation() {
       return 'android_clang_x86'
     }
   } else if (
-    (process.platform === 'darwin' || process.platform === 'linux')
+    ['darwin', 'freebsd', 'linux'].includes(process.platform)
     && config.targetArch === 'arm64'
   ) {
     return 'clang_x64_v8_arm64'
@@ -766,7 +766,10 @@ const util = {
         }, 10 * 1000)
       }
 
-      await util.runAsync('autoninja', ninjaOpts, autoninjaOptions)
+      // autoninja is a depot_tools wrapper that also pulls in siso/reclient.
+      // depot_tools is not used on FreeBSD, so run ninja from ports directly.
+      const ninjaCmd = process.platform === 'freebsd' ? 'ninja' : 'autoninja'
+      await util.runAsync(ninjaCmd, ninjaOpts, autoninjaOptions)
       clearBuildIdleWatchdog()
       buildGuard.markFinished()
     } catch (e) {
