--- include/IECoreScene/private/PrimitiveAlgoUtils.h.orig	2025-03-12 06:42:11 UTC
+++ include/IECoreScene/private/PrimitiveAlgoUtils.h
@@ -48,8 +48,9 @@
 
 #include "boost/format.hpp"
 
-#include "tbb/blocked_range.h"
-#include "tbb/parallel_for.h"
+#include <oneapi/tbb/blocked_range.h>
+#include <oneapi/tbb/parallel_for.h>
+#include <oneapi/tbb/task_group.h>
 
 #include <unordered_set>
 #include <type_traits>
@@ -176,7 +177,7 @@ template<typename T, typename S, typename P>
 
 
 template<typename T, typename S, typename P>
-class SplitTask : public tbb::task
+class SplitTask
 {
 	private:
 		typedef typename P::Ptr Ptr;
@@ -186,7 +187,7 @@ class SplitTask : public tbb::task
 		{
 		}
 
-		task *execute() override
+		void execute()
 		{
 
 			if ( numPrimitives ( m_primitive.get() ) == 0 && !m_segments.empty() )
@@ -264,17 +265,16 @@ class SplitTask : public tbb::task
 
 			size_t numSplits = 2;
 
-			set_ref_count( 1 + numSplits);
-
-			SplitTask *tA = new( allocate_child() ) SplitTask( lowerSegments, a, m_splitter,  m_primvarName, m_outputPrimitives, m_offset, m_depth + 1, m_canceller);
-			spawn( *tA );
-
-			SplitTask *tB = new( allocate_child() ) SplitTask( upperSegments, b, m_splitter, m_primvarName, m_outputPrimitives, m_offset + offset, m_depth + 1, m_canceller );
-			spawn( *tB );
-
-			wait_for_all();
-
-			return nullptr;
+			oneapi::tbb::task_group tg;
+			tg.run([=] {
+	           	SplitTask lowerTask(lowerSegments, a, m_splitter, m_primvarName, m_outputPrimitives, m_offset, m_depth + 1, m_canceller);
+            	lowerTask.execute();
+        	});
+			tg.run([=] {
+            	SplitTask upperTask(upperSegments, b, m_splitter, m_primvarName, m_outputPrimitives, m_offset + offset, m_depth + 1, m_canceller);
+           	 	upperTask.execute();
+	        });
+			tg.wait();	
 		}
 
 	private:
@@ -322,8 +322,10 @@ class TaskSegmenter
 
 			ReturnType results( segmentsReadable.size() );
 
-			tbb::task_group_context taskGroupContext( tbb::task_group_context::isolated );
-			SplitTask<T, S, P> *task = new( tbb::task::allocate_root( taskGroupContext ) ) SplitTask<T, S, P>(
+			oneapi::tbb::task_group_context taskGroupContext( tbb::task_group_context::isolated );
+			oneapi::tbb::task_group tg(taskGroupContext);
+			tg.run([&] {
+				SplitTask<T, S, P> task(
 				segmentsReadable,
 				const_cast<P *>(m_primitive),
 				m_splitter,
@@ -332,8 +334,10 @@ class TaskSegmenter
 				0,
 				0,
 				m_canceller
-			);
-			tbb::task::spawn_root_and_wait( *task );
+				);
+				task.execute();	
+			});
+			tg.wait();
 
 			return results;
 
