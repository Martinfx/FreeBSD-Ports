--- build_tools/scripts/build_js.py.orig	2026-11-05 00:00:00 UTC
+++ build_tools/scripts/build_js.py
@@ -114,7 +114,7 @@
   return base.cmd_in_dir(directory, "npm", ["ci"])
 
 def _run_grunt(directory, params=[]):
-  return base.cmd_in_dir(directory, "grunt", params)
+  return base.cmd_in_dir(directory, "./node_modules/.bin/grunt", params)
 
 def _run_build_py(directory, params=[]):
   branding = config.option("branding-name")
