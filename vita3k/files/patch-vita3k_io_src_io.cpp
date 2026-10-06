--- vita3k/io/src/io.cpp.orig	2026-10-06 04:21:17 UTC
+++ vita3k/io/src/io.cpp
@@ -41,7 +41,7 @@
 #include <iterator>
 #include <string>
 
-#if defined(__aarch64__) && defined(__APPLE__)
+#if (defined(__aarch64__) && defined(__APPLE__)) || defined(__FreeBSD__)
 #define stat64 stat
 #endif
 
