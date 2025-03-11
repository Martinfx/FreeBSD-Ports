--- include/IECoreVDB/VDBObject.h.orig	2025-02-25 10:37:21 UTC
+++ include/IECoreVDB/VDBObject.h
@@ -58,7 +58,7 @@ IECORE_POP_DEFAULT_VISIBILITY
 #endif
 IECORE_POP_DEFAULT_VISIBILITY
 
-#include "tbb/recursive_mutex.h"
+#include <mutex>
 
 #include <unordered_map>
 
