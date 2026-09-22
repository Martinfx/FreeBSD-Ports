--- vita3k/io/src/io.cpp.orig	2025-04-27 08:20:15 UTC
+++ vita3k/io/src/io.cpp
@@ -41,7 +41,9 @@
 #include <iterator>
 #include <string>
 
-#if defined(__aarch64__) && defined(__APPLE__)
+#if defined(__aarch64__) && defined(__APPLE__) 
+#define stat64 stat
+#else
 #define stat64 stat
 #endif
 
