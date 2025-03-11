--- include/IECoreScene/private/PrimitiveAlgoUtils.h.orig	2025-02-25 10:37:21 UTC
+++ include/IECoreScene/private/PrimitiveAlgoUtils.h
@@ -48,8 +48,9 @@
 
 #include "boost/format.hpp"
 
-#include "tbb/blocked_range.h"
-#include "tbb/parallel_for.h"
+#include <tbb/blocked_range.h>
+#include <tbb/parallel_for.h>
+#include <oneapi/tbb/task_group.h>
 
 #include <unordered_set>
 #include <type_traits>
@@ -174,22 +175,23 @@ template<typename T> struct IsDeletablePrimVar : boost
 /// Numeric & string like arrays, which contain elements which can be added to a std::set
 template<typename T> struct IsDeletablePrimVar : boost::mpl::or_< IECore::TypeTraits::IsStringVectorTypedData<T>, IECore::TypeTraits::IsNumericVectorTypedData<T> > {};
 
-
 template<typename T, typename S, typename P>
-class SplitTask : public tbb::task
+class SplitTask
 {
-	private:
-		typedef typename P::Ptr Ptr;
-	public:
-		SplitTask(const std::vector<T> &segments, typename P::Ptr primitive, const S& splitter, const std::string &primvarName, std::vector<Ptr> &outputPrimitives, size_t offset, size_t depth, const IECore::Canceller *canceller )
-			: m_segments(segments), m_primitive(primitive), m_splitter(splitter), m_primvarName(primvarName), m_outputPrimitives( outputPrimitives ), m_offset(offset), m_depth(depth), m_canceller( canceller )
-		{
-		}
+private:
+    typedef typename P::Ptr Ptr;
 
-		task *execute() override
-		{
-
-			if ( numPrimitives ( m_primitive.get() ) == 0 && !m_segments.empty() )
+public: 
+	SplitTask(const std::vector<T>& segments, typename P::Ptr primitive, const S& splitter,
+               const std::string& primvarName, std::vector<typename P::Ptr>& outputPrimitives,
+               size_t offset, size_t depth, const IECore::Canceller* canceller,
+               oneapi::tbb::task_group& tg)
+		: m_segments(segments), m_primitive(primitive), m_splitter(splitter),
+          m_primvarName(primvarName), m_outputPrimitives(outputPrimitives),
+          m_offset(offset), m_depth(depth), m_canceller(canceller), m_tg(tg)
+    {
+    
+    			if ( numPrimitives ( m_primitive.get() ) == 0 && !m_segments.empty() )
 			{
 				m_outputPrimitives[m_offset] = m_primitive;
 				return nullptr;
@@ -264,31 +266,28 @@ class SplitTask : public tbb::task
 
 			size_t numSplits = 2;
 
-			set_ref_count( 1 + numSplits);
+    		m_tg.run([=, &tg]() {
+        		SplitTask(lowerSegments, a, splitter, m_primvarName, m_outputPrimitives, m_offset, m_depth + 1, m_canceller, m_tg);
+    		});
 
-			SplitTask *tA = new( allocate_child() ) SplitTask( lowerSegments, a, m_splitter,  m_primvarName, m_outputPrimitives, m_offset, m_depth + 1, m_canceller);
-			spawn( *tA );
+    		m_tg.run([=, &tg]() {
+        		SplitTask(upperSegments, b, splitter, m_primvarName, m_outputPrimitives, m_offset + offset, m_depth + 1, m_canceller, m_tg);
+    		});
 
-			SplitTask *tB = new( allocate_child() ) SplitTask( upperSegments, b, m_splitter, m_primvarName, m_outputPrimitives, m_offset + offset, m_depth + 1, m_canceller );
-			spawn( *tB );
-
-			wait_for_all();
-
 			return nullptr;
-		}
 
-	private:
+private:
+    std::vector<T> m_segments;
+    typename P::Ptr m_primitive;
+    const S& m_splitter;
+    std::string m_primvarName;
+    std::vector<Ptr>& m_outputPrimitives;
+    size_t m_offset;
+    size_t m_depth;
+    const IECore::Canceller* m_canceller;
+	oneapi::tbb::task_group m_tg
+}
 
-		std::vector<T> m_segments;
-		typename P::Ptr m_primitive;
-		const S &m_splitter;
-		std::string m_primvarName;
-		std::vector<Ptr> &m_outputPrimitives;
-		size_t m_offset;
-		size_t m_depth;
-		const IECore::Canceller *m_canceller;
-};
-
 template<typename P, typename S>
 class TaskSegmenter
 {
@@ -322,18 +321,25 @@ class TaskSegmenter
 
 			ReturnType results( segmentsReadable.size() );
 
-			tbb::task_group_context taskGroupContext( tbb::task_group_context::isolated );
-			SplitTask<T, S, P> *task = new( tbb::task::allocate_root( taskGroupContext ) ) SplitTask<T, S, P>(
-				segmentsReadable,
-				const_cast<P *>(m_primitive),
-				m_splitter,
-				m_primVarName,
-				results,
-				0,
-				0,
-				m_canceller
-			);
-			tbb::task::spawn_root_and_wait( *task );
+			tbb::task_group_context taskGroupContext(tbb::task_group_context::isolated);
+			tbb::task_group tg;
+
+			tg.run(=, &tg] {
+    			typename SplitTask<T, S, P>::SplitTask task(
+        		segmentsReadable,
+        		const_cast<P*>(m_primitive),
+        		m_splitter,
+        		m_primVarName,
+        		results,
+        		0,
+        		0,
+        		m_canceller,
+				tg
+    		);
+    		task.execute();
+			});
+
+tg.wait();
 
 			return results;
 
