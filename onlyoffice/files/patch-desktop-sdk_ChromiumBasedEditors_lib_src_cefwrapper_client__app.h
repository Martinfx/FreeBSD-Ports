--- desktop-sdk/ChromiumBasedEditors/lib/src/cefwrapper/client_app.h.orig	2026-09-28 09:50:15 UTC
+++ desktop-sdk/ChromiumBasedEditors/lib/src/cefwrapper/client_app.h
@@ -39,6 +39,7 @@
 #include "cefclient/common/client_app.h"
 #endif
 #include "include/cef_version.h"
+#include "cef_compat.h"
 
 #if defined(_LINUX) && !defined(_MAC)
 #include <X11/Xlib.h>
@@ -257,6 +258,11 @@ public:
 				}
 			}
 			command_line->AppendSwitchWithValue("--password-store", "basic");
+#ifdef CEF_VERSION_ABOVE_128
+			// The browsers are put in X11 windows of Qt, and Qt and GTK are
+			// made to use X11, but CEF can also take Wayland.
+			command_line->AppendSwitchWithValue("--ozone-platform", "x11");
+#endif
 #endif
 
 #ifndef ENABLE_CEF_EXTENSIONS
