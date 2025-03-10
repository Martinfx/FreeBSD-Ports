--- include/IECoreVDB/VDBObject.h.orig	2024-12-04 20:58:04 UTC
+++ include/IECoreVDB/VDBObject.h
@@ -58,8 +58,7 @@ IECORE_POP_DEFAULT_VISIBILITY
 #endif
 IECORE_POP_DEFAULT_VISIBILITY
 
-#include "tbb/recursive_mutex.h"
-
+#include <mutex>
 #include <unordered_map>
 
 namespace IECoreVDB
