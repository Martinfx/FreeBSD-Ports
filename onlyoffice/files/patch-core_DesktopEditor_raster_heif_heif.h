--- core/DesktopEditor/raster/heif/heif.h.orig	2026-11-05 00:00:00 UTC
+++ core/DesktopEditor/raster/heif/heif.h
@@ -34,7 +34,7 @@
  */
 
 #include "../BgraFrame.h"
-#include "../../Common/3dParty/heif/libheif/libheif/api/libheif/heif.h"
+#include <heif.h>
 #include "../../UnicodeConverter/UnicodeConverter.h"
 
 namespace NSHeif {
