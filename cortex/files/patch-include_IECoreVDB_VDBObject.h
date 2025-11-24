--- include/IECoreVDB/VDBObject.h.orig	2025-10-21 10:03:35 UTC
+++ include/IECoreVDB/VDBObject.h
@@ -53,7 +53,7 @@ IECORE_POP_DEFAULT_VISIBILITY
 #include "Imath/ImathBox.h"
 IECORE_POP_DEFAULT_VISIBILITY
 
-#include "tbb/recursive_mutex.h"
+#include <mutex>
 
 #include <unordered_map>
 
