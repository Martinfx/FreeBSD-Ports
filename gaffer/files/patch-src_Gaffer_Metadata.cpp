--- src/Gaffer/Metadata.cpp.orig	2024-12-04 08:23:08 UTC
+++ src/Gaffer/Metadata.cpp
@@ -50,12 +50,14 @@
 #include "boost/multi_index/sequenced_index.hpp"
 #include "boost/multi_index_container.hpp"
 
-#include "tbb/concurrent_hash_map.h"
-#include "tbb/recursive_mutex.h"
+#include "oneapi/tbb/concurrent_hash_map.h"
+//#include "oneapi/tbb/mutex.h"
 
 #include <unordered_map>
+#include <mutex>
+#include <memory>
+#include <vector>
 
-using namespace std;
 using namespace boost;
 using namespace tbb;
 using namespace IECore;
@@ -86,8 +88,8 @@ struct NodeSignals
 	Metadata::PlugValueChangedSignal plugSignal;
 };
 
-using SignalsMap = std::unordered_map<Node *, unique_ptr<NodeSignals>>;
-using SignalsMapLock = tbb::recursive_mutex::scoped_lock;
+using SignalsMap = std::unordered_map<Node *, std::unique_ptr<NodeSignals>>;
+using SignalsMapLock = std::scoped_lock;
 
 // Access to the signals requires the passing of a scoped_lock that
 // will be locked for you automatically, and must remain locked while
@@ -95,8 +97,8 @@ SignalsMap &signalsMap( SignalsMapLock &lock )
 SignalsMap &signalsMap( SignalsMapLock &lock )
 {
 	static SignalsMap *g_signalsMap = new SignalsMap;
-	static tbb::recursive_mutex g_signalsMapMutex;
-	lock.acquire( g_signalsMapMutex );
+    static std::recursive_mutex g_signalsMapMutex;
+    lock.lock( g_signalsMapMutex );
 	return *g_signalsMap;
 }
 
