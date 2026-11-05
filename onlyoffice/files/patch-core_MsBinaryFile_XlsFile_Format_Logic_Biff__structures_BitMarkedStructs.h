--- core/MsBinaryFile/XlsFile/Format/Logic/Biff_structures/BitMarkedStructs.h.orig	2026-11-05 00:00:00 UTC
+++ core/MsBinaryFile/XlsFile/Format/Logic/Biff_structures/BitMarkedStructs.h
@@ -34,7 +34,7 @@
  */
 #pragma once
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     #include <inttypes.h>
 #endif
 
