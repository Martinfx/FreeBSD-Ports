--- desktop-sdk/ChromiumBasedEditors/lib/src/cefwrapper/client_app.h.orig	2026-09-24 21:58:50 UTC
+++ desktop-sdk/ChromiumBasedEditors/lib/src/cefwrapper/client_app.h
@@ -39,6 +39,7 @@
 #include "cefclient/common/client_app.h"
 #endif
 #include "include/cef_version.h"
+#include "cef_compat.h"
 
 #if defined(_LINUX) && !defined(_MAC)
 #include <X11/Xlib.h>
