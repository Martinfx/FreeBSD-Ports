--- src/IECoreScene/SceneAlgo.cpp.orig	2024-12-04 19:36:02 UTC
+++ src/IECoreScene/SceneAlgo.cpp
@@ -1,4 +1,4 @@
-//////////////////////////////////////////////////////////////////////////
+////////////////////////////////////////////////////////////////////////////
 //
 //  Copyright (c) 2018, Image Engine Design Inc. All rights reserved.
 //
@@ -39,7 +39,8 @@
 #include "IECoreScene/PointsPrimitive.h"
 #include "IECoreScene/SceneInterface.h"
 
-#include "tbb/task.h"
+//#include "tbb/task.h"
+#include "oneapi/tbb/task_group.h"
 
 #include <atomic>
 
@@ -50,7 +51,7 @@ template<typename LocationFn>
 {
 
 template<typename LocationFn>
-class Task : public tbb::task
+class Task
 {
 
 	public :
@@ -64,7 +65,7 @@ class Task : public tbb::task
 		~Task() override
 		{
 		}
-
+/*
 		task *execute() override
 		{
 			m_locationFn( m_src, m_dst, m_time, m_flags );
@@ -97,7 +98,7 @@ class Task : public tbb::task
 			wait_for_all();
 
 			return nullptr;
-		}
+		}*/
 
 	private :
 
@@ -257,13 +258,23 @@ SceneStats parallelReadAll( const SceneInterface *src,
 		copyInfos.pointCount += copyInfo.pointCount;
 	};
 
+	   // Create a TBB task group for parallel processing
+/*    	oneapi::tbb::task_group taskGroup;
 	for( int f = startFrame; f <= endFrame; ++f )
 	{
 		double time = f / frameRate;
-		tbb::task_group_context taskGroupContext( tbb::task_group_context::isolated );
-		Task<decltype( locationFn )> *task = new( tbb::task::allocate_root( taskGroupContext ) ) Task<decltype( locationFn )>( src, nullptr, locationFn, time, flags );
-		tbb::task::spawn_root_and_wait( *task );
+		//oneapi::tbb::task_group_context taskGroupContext( oneapi::tbb::task_group_context::isolated );
+		//Task<decltype( locationFn )> *task = new( taskGroupContext ) Task<decltype( locationFn )>( src, nullptr, locationFn, time, flags );
+		//oneapi::tbb::task::spawn_root_and_wait( *task );
+		taskGroup.run([=, &locationFn]() {
+           	// Create and execute a task for each frame
+           	Task<decltype(locationFn)> task(src, locationFn, time, flags);
+            	task.execute();
+        	});
 	}
+
+	// Wait for all tasks to complete
+    	taskGroup.wait();*/
 
 	SceneStats stats;
 	stats["locations"] = locationCount;
@@ -293,4 +304,4 @@ void copy( const SceneInterface *src, SceneInterface *
 
 } // SceneAlgo
 
-} // IECoreScene
\ No newline at end of file
+} // IECoreScene
