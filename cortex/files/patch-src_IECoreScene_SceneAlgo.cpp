--- src/IECoreScene/SceneAlgo.cpp.orig	2025-03-11 12:19:05 UTC
+++ src/IECoreScene/SceneAlgo.cpp
@@ -39,7 +39,7 @@
 #include "IECoreScene/PointsPrimitive.h"
 #include "IECoreScene/SceneInterface.h"
 
-#include "tbb/task.h"
+#include <oneapi/tbb/task_group.h>
 
 #include <atomic>
 
@@ -50,7 +50,7 @@ template<typename LocationFn>
 {
 
 template<typename LocationFn>
-class Task : public tbb::task
+class Task
 {
 
 	public :
@@ -61,44 +61,41 @@ class Task : public tbb::task
 		{
 		}
 
-		~Task() override
+		~Task()
 		{
 		}
 
-		task *execute() override
-		{
-			m_locationFn( m_src, m_dst, m_time, m_flags );
+        	void operator()() const
+        	{
+            		m_locationFn(m_src, m_dst, m_time, m_flags);
 
-			SceneInterface::NameList childNames;
-			m_src->childNames( childNames );
+            		SceneInterface::NameList childNames;
+            		m_src->childNames(childNames);
 
-			set_ref_count( 1 + childNames.size() );
+            		std::vector<SceneInterfacePtr> childSceneInterfaces;
+            		childSceneInterfaces.reserve(childNames.size());
 
-			std::vector<SceneInterfacePtr> childSceneInterfaces;
-			childSceneInterfaces.reserve( childNames.size() );
+            		std::vector<ConstSceneInterfacePtr> srcChildSceneInterfaces;
+            		srcChildSceneInterfaces.reserve(childNames.size());
 
-			std::vector<ConstSceneInterfacePtr> srcChildSceneInterfaces;
-			srcChildSceneInterfaces.reserve( childNames.size() );
+            		oneapi::tbb::task_group tg;
+            		for (const auto& childName : childNames)
+            		{
+                		SceneInterfacePtr dstChild = m_dst ? m_dst->child(childName, SceneInterface::CreateIfMissing) : nullptr;
+                		if (dstChild)
+                		{
+                    			childSceneInterfaces.push_back(dstChild);
+                	}
 
-			for( const auto &childName : childNames )
-			{
-				SceneInterfacePtr dstChild = m_dst ? m_dst->child( childName, SceneInterface::CreateIfMissing ) : nullptr;
-				if( dstChild )
-				{
-					childSceneInterfaces.push_back( dstChild );
-				}
+                	ConstSceneInterfacePtr srcChild = m_src->child(childName);
+                	srcChildSceneInterfaces.push_back(srcChild);
 
-				ConstSceneInterfacePtr srcChild = m_src->child( childName );
-				srcChildSceneInterfaces.push_back( srcChild );
+                	tg.run(Task(srcChild.get(), dstChild.get(), m_locationFn, m_time, m_flags));
+            	}
 
-				Task *t = new( allocate_child() ) Task( srcChild.get(), dstChild.get(), m_locationFn, m_time, m_flags );
-				spawn( *t );
-			}
-			wait_for_all();
+            	tg.wait();
+        }
 
-			return nullptr;
-		}
-
 	private :
 
 		const SceneInterface *m_src;
@@ -257,12 +254,18 @@ SceneStats parallelReadAll( const SceneInterface *src,
 		copyInfos.pointCount += copyInfo.pointCount;
 	};
 
-	for( int f = startFrame; f <= endFrame; ++f )
+	for (int f = startFrame; f <= endFrame; ++f)
 	{
-		double time = f / frameRate;
-		tbb::task_group_context taskGroupContext( tbb::task_group_context::isolated );
-		Task<decltype( locationFn )> *task = new( tbb::task::allocate_root( taskGroupContext ) ) Task<decltype( locationFn )>( src, nullptr, locationFn, time, flags );
-		tbb::task::spawn_root_and_wait( *task );
+    	double time = f / frameRate;
+  	  	oneapi::tbb::task_group_context taskGroupContext(oneapi::tbb::task_group_context::isolated);
+    	oneapi::tbb::task_group tg(taskGroupContext);
+
+    	tg.run([=, &locationFn]() {
+        	Task<decltype(locationFn)> task(src, nullptr, locationFn, time, flags);
+       	 	task();
+    	});
+
+    	tg.wait();
 	}
 
 	SceneStats stats;
@@ -293,4 +296,4 @@ void copy( const SceneInterface *src, SceneInterface *
 
 } // SceneAlgo
 
-} // IECoreScene
\ No newline at end of file
+} // IECoreScene
