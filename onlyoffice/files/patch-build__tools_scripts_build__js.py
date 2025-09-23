--- build_tools/scripts/build_js.py.orig	2025-09-23 21:37:40 UTC
+++ build_tools/scripts/build_js.py
@@ -121,7 +121,7 @@ def _run_grunt(directory, params=[]):
   return base.cmd_in_dir(directory, "npm", ["install", "-g", "grunt-cli"])
 
 def _run_grunt(directory, params=[]):
-  return base.cmd_in_dir(directory, "grunt", params)
+  return base.cmd_in_dir(directory, "%%WRKSRC%%/sdkjs/node_modules/.bin/grunt", params)
 
 def build_interface(directory):
   _run_npm(directory)
