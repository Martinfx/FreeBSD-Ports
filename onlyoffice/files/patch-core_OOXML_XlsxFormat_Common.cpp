--- core/OOXML/XlsxFormat/Common.cpp.orig	2026-11-05 00:00:00 UTC
+++ core/OOXML/XlsxFormat/Common.cpp
@@ -51,6 +51,10 @@
 #define _gcvt gcvt
 #endif
 
+#ifdef __FreeBSD__
+#define _gcvt(x,n,b) sprintf(b, "%.17g", x)
+#endif
+
 #define DBL_MAX 15
 #define DBL_MAXDIG10 17
 
