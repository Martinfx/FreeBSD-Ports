--- vita3k/modules/SceGxm/SceGxm.cpp.orig	2025-04-27 11:46:04 UTC
+++ vita3k/modules/SceGxm/SceGxm.cpp
@@ -21,7 +21,7 @@
 
 #include <span>
 #include <stack>
-#if defined(__x86_64__) && !defined(__APPLE__)
+#if defined(__x86_64__) && !defined(__APPLE__) && !defined(__FreeBSD__)
 #include <xxh_x86dispatch.h>
 #else
 #define XXH_INLINE_ALL
