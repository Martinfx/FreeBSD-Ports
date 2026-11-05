--- desktop-sdk/ChromiumBasedEditors/lib/src/applicationmanager_p.h.orig	2026-11-05 00:00:00 UTC
+++ desktop-sdk/ChromiumBasedEditors/lib/src/applicationmanager_p.h
@@ -37,6 +37,7 @@
 #define APPLICATION_MANAGER_PRIVATE_H
 
 #include "../include/applicationmanager.h"
+#include "./cefwrapper/cef_compat.h"
 #include <map>
 
 #include "../../../../core/DesktopEditor/graphics/TemporaryCS.h"
