--- lib/util.js.orig	2018-12-11 10:26:15 UTC
+++ lib/util.js
@@ -201,8 +201,8 @@ const util = {
     options = mergeWithDefault(options)
     util.run('git', ['submodule', 'sync'], options)
     util.run('git', ['submodule', 'update', '--init', '--recursive'], options)
-    util.run('git', ['-C', config.depotToolsDir, 'clean', '-fxd'], options)
-    util.run('git', ['-C', config.depotToolsDir, 'reset', '--hard', 'HEAD'], options)
+//    util.run('git', ['-C', config.depotToolsDir, 'clean', '-fxd'], options)
+//    util.run('git', ['-C', config.depotToolsDir, 'reset', '--hard', 'HEAD'], options)
   },
 
   gclientSync: (options = {}) => {
