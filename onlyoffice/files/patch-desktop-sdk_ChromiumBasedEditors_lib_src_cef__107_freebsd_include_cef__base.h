--- desktop-sdk/ChromiumBasedEditors/lib/src/cef_107/freebsd/include/cef_base.h.orig	2025-09-26 19:04:10 UTC
+++ desktop-sdk/ChromiumBasedEditors/lib/src/cef_107/freebsd/include/cef_base.h
@@ -47,6 +47,8 @@
 #include "include/internal/cef_linux.h"
 #endif
 
+#include "include/internal/cef_freebsd.h"
+
 ///
 /// All ref-counted framework classes must extend this class.
 ///
