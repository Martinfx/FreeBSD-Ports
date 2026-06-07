--- desktop-sdk/ChromiumBasedEditors/lib/src/cef/freebsd/include/cef_base.h.orig	2025-09-24 16:35:05 UTC
+++ desktop-sdk/ChromiumBasedEditors/lib/src/cef/freebsd/include/cef_base.h
@@ -45,6 +45,8 @@
 #include "include/internal/cef_mac.h"
 #elif defined(OS_LINUX)
 #include "include/internal/cef_linux.h"
+#elif defined(OS_FREEBSD)
+#include "include/internal/cef_freebsd.h"
 #endif
 
 ///
