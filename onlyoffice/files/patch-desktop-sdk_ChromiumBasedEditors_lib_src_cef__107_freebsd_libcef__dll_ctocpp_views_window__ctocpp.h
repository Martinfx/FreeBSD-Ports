--- desktop-sdk/ChromiumBasedEditors/lib/src/cef_107/freebsd/libcef_dll/ctocpp/views/window_ctocpp.h.orig	2025-09-26 15:39:50 UTC
+++ desktop-sdk/ChromiumBasedEditors/lib/src/cef_107/freebsd/libcef_dll/ctocpp/views/window_ctocpp.h
@@ -21,6 +21,7 @@
 #endif
 
 #include <vector>
+#include "include/internal/cef_freebsd.h"
 #include "include/capi/views/cef_window_capi.h"
 #include "include/views/cef_window.h"
 #include "libcef_dll/ctocpp/ctocpp_ref_counted.h"
