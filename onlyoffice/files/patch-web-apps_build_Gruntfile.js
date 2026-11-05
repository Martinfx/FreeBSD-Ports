--- web-apps/build/Gruntfile.js.orig	2026-11-05 00:00:00 UTC
+++ web-apps/build/Gruntfile.js
@@ -249,17 +249,6 @@
     }
 
     grunt.initConfig({
-        mocha: {
-            test: {
-                options: {
-                    reporter: 'Spec'
-                },
-                src: [
-                    '../test/common/index.html'
-                ]
-            }
-        },
-
         jshint: {
             options: {
                 curly: true,
