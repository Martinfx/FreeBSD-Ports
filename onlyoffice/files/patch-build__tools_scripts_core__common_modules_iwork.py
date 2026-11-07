--- build_tools/scripts/core_common/modules/iwork.py.orig	2026-11-05 00:00:00 UTC
+++ build_tools/scripts/core_common/modules/iwork.py
@@ -30,7 +30,7 @@
   if use_gperf:
     cmd_args.append("--gperf")
 
-  base.cmd_in_dir(base_dir, "python", cmd_args)
+#  base.cmd_in_dir(base_dir, "python", cmd_args)
   return
 
 if __name__ == '__main__':
