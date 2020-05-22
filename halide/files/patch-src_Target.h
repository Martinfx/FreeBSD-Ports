--- src/Target.h.orig	2019-10-20 19:04:00 UTC
+++ src/Target.h
@@ -24,6 +24,7 @@ struct Target {
      * Corresponds to os_name_map in Target.cpp. */
     enum OS {
         OSUnknown = 0,
+        BSD,
         Linux,
         Windows,
         OSX,
