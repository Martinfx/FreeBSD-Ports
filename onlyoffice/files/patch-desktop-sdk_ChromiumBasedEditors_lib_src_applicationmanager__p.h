--- desktop-sdk/ChromiumBasedEditors/lib/src/applicationmanager_p.h.orig	2026-09-24 21:58:50 UTC
+++ desktop-sdk/ChromiumBasedEditors/lib/src/applicationmanager_p.h
@@ -34,6 +34,7 @@
 #define APPLICATION_MANAGER_PRIVATE_H
 
 #include "../include/applicationmanager.h"
+#include "./cefwrapper/cef_compat.h"
 #include <map>
 
 #include "../../../../core/DesktopEditor/graphics/TemporaryCS.h"
