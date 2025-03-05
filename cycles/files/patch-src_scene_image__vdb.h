--- src/scene/image_vdb.h.orig	2025-03-05 18:30:28 UTC
+++ src/scene/image_vdb.h
@@ -9,7 +9,7 @@
 #  include <openvdb/openvdb.h>
 #endif
 #ifdef WITH_NANOVDB
-#  include <nanovdb/util/GridHandle.h>
+#  include <nanovdb/GridHandle.h>
 #endif
 
 #include "scene/image.h"
