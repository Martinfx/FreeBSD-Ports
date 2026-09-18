--- src/brave/build/commands/lib/util.js.orig	2026-01-05 00:00:00 UTC
+++ src/brave/build/commands/lib/util.js
@@ -159,7 +159,7 @@
       return 'android_clang_x86'
     }
   } else if (
-    (process.platform === 'darwin' || process.platform === 'linux') &&
+    ['darwin', 'freebsd', 'linux'].includes(process.platform) &&
     config.targetArch === 'arm64'
   ) {
     return 'clang_x64_v8_arm64'
@@ -736,7 +736,10 @@
         await util.runAsync('gn', ['clean', outputDir], options)
       }
       buildGuard.markStarted()
-      await util.runAsync('autoninja', ninjaOpts, options)
+      // autoninja is a depot_tools wrapper that also pulls in siso/reclient.
+      // depot_tools is not used on FreeBSD, so run ninja from ports directly.
+      const ninjaCmd = process.platform === 'freebsd' ? 'ninja' : 'autoninja'
+      await util.runAsync(ninjaCmd, ninjaOpts, options)
       buildGuard.markFinished()
     } catch (e) {
       // Display siso_output on CI after a build failure.
