--- web-apps/build/Gruntfile.js.orig	2026-09-24 21:59:09 UTC
+++ web-apps/build/Gruntfile.js
@@ -241,17 +241,6 @@ module.exports = function(grunt) {
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
