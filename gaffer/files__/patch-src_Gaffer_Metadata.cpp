--- src/Gaffer/Metadata.cpp.orig	2025-10-10 20:24:55 UTC
+++ src/Gaffer/Metadata.cpp
@@ -50,16 +50,18 @@
 #include "boost/multi_index/sequenced_index.hpp"
 #include "boost/multi_index_container.hpp"
 
-#include "tbb/concurrent_hash_map.h"
-#include "tbb/recursive_mutex.h"
+#include "oneapi/tbb/concurrent_hash_map.h"
 
 #include <unordered_map>
+#include <memory>
+#include <vector>
+#include <mutex>
 
-using namespace std;
 using namespace boost;
 using namespace tbb;
 using namespace IECore;
 using namespace Gaffer;
+using namespace std;
 
 //////////////////////////////////////////////////////////////////////////
 // Internal implementation details
@@ -119,8 +121,8 @@ struct NodeSignals
 	Metadata::PlugValueChangedSignal plugSignal;
 };
 
-using SignalsMap = std::unordered_map<Node *, unique_ptr<NodeSignals>>;
-using SignalsMapLock = tbb::recursive_mutex::scoped_lock;
+using SignalsMap = std::unordered_map<Node *, std::unique_ptr<NodeSignals>>;
+using SignalsMapLock = std::unique_lock<std::recursive_mutex>;
 
 // Access to the signals requires the passing of a scoped_lock that
 // will be locked for you automatically, and must remain locked while
@@ -128,8 +130,11 @@ SignalsMap &signalsMap( SignalsMapLock &lock )
 SignalsMap &signalsMap( SignalsMapLock &lock )
 {
 	static SignalsMap *g_signalsMap = new SignalsMap;
-	static tbb::recursive_mutex g_signalsMapMutex;
-	lock.acquire( g_signalsMapMutex );
+	static std::recursive_mutex g_signalsMapMutex;
+    	if (!lock.owns_lock())
+    	{
+        	lock = SignalsMapLock(g_signalsMapMutex);
+	}
 	return *g_signalsMap;
 }
 
