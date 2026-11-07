--- core/Common/3dParty/brotli/make.py.orig	2026-11-05 00:00:00 UTC
+++ core/Common/3dParty/brotli/make.py
@@ -10,7 +10,7 @@
     base.delete_dir_with_access_error("brotli")
   return
 
-base.check_module_version("1", clear_module)
+#base.check_module_version("1", clear_module)
 
 # fetch harfbuzz
 if not base.is_dir("brotli"):
