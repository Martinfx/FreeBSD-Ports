--- cef/include/internal/cef_types.h.orig	2026-11-19 22:04:44 UTC
+++ cef/include/internal/cef_types.h
@@ -47,7 +47,7 @@
 #include "include/internal/cef_types_win.h"
 #elif defined(OS_MAC)
 #include "include/internal/cef_types_mac.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "include/internal/cef_types_linux.h"
 #endif
 
