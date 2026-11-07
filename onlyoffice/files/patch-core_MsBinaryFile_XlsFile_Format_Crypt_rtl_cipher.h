--- core/MsBinaryFile/XlsFile/Format/Crypt/rtl/cipher.h.orig	2026-11-05 00:00:00 UTC
+++ core/MsBinaryFile/XlsFile/Format/Crypt/rtl/cipher.h
@@ -36,7 +36,7 @@
 
 #include <stddef.h>
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     #include <inttypes.h>
 #endif
 
