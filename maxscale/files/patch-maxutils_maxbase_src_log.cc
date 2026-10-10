--- maxutils/maxbase/src/log.cc.orig	2022-10-18 19:57:28 UTC
+++ maxutils/maxbase/src/log.cc
@@ -487,7 +487,7 @@ bool mxb_log_init(const char* ident,
         if (!filename)
         {
 #ifdef __GNUC__
-            suffix = program_invocation_short_name;
+            suffix = getprogname();
 #else
             suffix = "messages";
 #endif
