--- vita3k/renderer/src/texture/cache.cpp.orig	2025-04-27 13:07:41 UTC
+++ vita3k/renderer/src/texture/cache.cpp
@@ -29,7 +29,7 @@
 #include <algorithm>
 #include <cstring>
 #include <numeric>
-#if defined(__x86_64__) && !defined(__APPLE__)
+#if defined(__x86_64__) && !defined(__APPLE__) && !defined(__FreeBSD__)
 #include <xxh_x86dispatch.h>
 #else
 #define XXH_INLINE_ALL
