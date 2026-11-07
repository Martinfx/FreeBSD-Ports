--- core/PdfFile/SrcWriter/Types.h.orig	2026-11-05 00:00:00 UTC
+++ core/PdfFile/SrcWriter/Types.h
@@ -52,7 +52,7 @@
 #include <vector>
 #include <cmath>
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #include <string.h>
 #include <limits>
 #endif
