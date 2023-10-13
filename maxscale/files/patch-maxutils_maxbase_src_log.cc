--- maxutils/maxbase/src/log.cc.orig	2023-09-22 06:15:26 UTC
+++ maxutils/maxbase/src/log.cc
@@ -497,7 +497,7 @@ bool mxb_log_init(const char* ident,
         if (!filename)
         {
 #ifdef __GNUC__
-            suffix = program_invocation_short_name;
+            suffix = getprogname();
 #else
             suffix = "messages";
 #endif
