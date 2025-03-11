--- include/IECoreScene/private/PrimitiveAlgoUtils.h.orig	2025-02-25 10:37:21 UTC
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
@@ -174,119 +175,117 @@ template<typename T> struct IsDeletablePrimVar : boost
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
+public:
+    SplitTask(const std::vector<T>& segments, typename P::Ptr primitive, const S& splitter, const std::string& primvarName, std::vector<Ptr>& outputPrimitives, size_t offset, size_t depth, const IECore::Canceller* canceller)
+        : m_segments(segments), m_primitive(primitive), m_splitter(splitter), m_primvarName(primvarName), m_outputPrimitives(outputPrimitives), m_offset(offset), m_depth(depth), m_canceller(canceller)
+    {
+    }
 
-			if ( numPrimitives ( m_primitive.get() ) == 0 && !m_segments.empty() )
-			{
-				m_outputPrimitives[m_offset] = m_primitive;
-				return nullptr;
-			}
+    void execute()
+    {
+        if (numPrimitives(m_primitive.get()) == 0 && !m_segments.empty())
+        {
+            m_outputPrimitives[m_offset] = m_primitive;
+            return;
+        }
 
-			if ( m_segments.size () == 0 )
-			{
-				return nullptr;
-			}
+        if (m_segments.empty())
+        {
+            return;
+        }
 
-			size_t offset = m_segments.size() / 2;
-			typename std::vector<T>::iterator mid = m_segments.begin() + offset;
+        size_t offset = m_segments.size() / 2;
+        typename std::vector<T>::iterator mid = m_segments.begin() + offset;
 
-			IECoreScene::PrimitiveVariable segmentPrimVar = m_primitive->variables.find( m_primvarName )->second;
+        IECoreScene::PrimitiveVariable segmentPrimVar = m_primitive->variables.find(m_primvarName)->second;
 
-			std::vector<T> lowerSegments (m_segments.begin(), mid);
-			std::vector<T> upperSegments (mid, m_segments.end());
+        std::vector<T> lowerSegments(m_segments.begin(), mid);
+        std::vector<T> upperSegments(mid, m_segments.end());
 
-			std::set<T> lowerSegmentsSet ( m_segments.begin(), mid );
-			std::set<T> upperSegmentsSet (mid, m_segments.end());
+        std::set<T> lowerSegmentsSet(m_segments.begin(), mid);
+        std::set<T> upperSegmentsSet(mid, m_segments.end());
 
-			const auto &readable = IECore::runTimeCast<IECore::TypedData<std::vector<T> > >( segmentPrimVar.data )->readable();
+        const auto& readable = IECore::runTimeCast<IECore::TypedData<std::vector<T>>>(segmentPrimVar.data)->readable();
 
-			IECore::BoolVectorDataPtr deletionArrayLower = new IECore::BoolVectorData();
-			auto &writableLower = deletionArrayLower->writable();
+        IECore::BoolVectorDataPtr deletionArrayLower = new IECore::BoolVectorData();
+        auto& writableLower = deletionArrayLower->writable();
 
-			IECore::BoolVectorDataPtr deletionArrayUpper = new IECore::BoolVectorData();
-			auto &writableUpper = deletionArrayUpper->writable();
+        IECore::BoolVectorDataPtr deletionArrayUpper = new IECore::BoolVectorData();
+        auto& writableUpper = deletionArrayUpper->writable();
 
-			size_t deleteCount = 0;
-			if( segmentPrimVar.indices )
-			{
-				auto &readableIndices = segmentPrimVar.indices->readable();
-				writableLower.resize( readableIndices.size() );
-				writableUpper.resize( readableIndices.size() );
+        size_t deleteCount = 0;
+        if (segmentPrimVar.indices)
+        {
+            auto& readableIndices = segmentPrimVar.indices->readable();
+            writableLower.resize(readableIndices.size());
+            writableUpper.resize(readableIndices.size());
 
-				for( size_t i = 0; i < readableIndices.size(); ++i )
-				{
-					size_t index = readableIndices[i];
-					writableLower[i] = lowerSegmentsSet.find( readable[index] ) == lowerSegmentsSet.end();
-					writableUpper[i] = upperSegmentsSet.find( readable[index] ) == upperSegmentsSet.end();
+            for (size_t i = 0; i < readableIndices.size(); ++i)
+            {
+                size_t index = readableIndices[i];
+                writableLower[i] = lowerSegmentsSet.find(readable[index]) == lowerSegmentsSet.end();
+                writableUpper[i] = upperSegmentsSet.find(readable[index]) == upperSegmentsSet.end();
 
-					deleteCount += ( writableLower[i] && !lowerSegments.empty() ) || ( writableUpper[i] && !upperSegments.empty() ) ? 1 : 0;
-				}
-			}
-			else
-			{
-				writableLower.resize( readable.size() );
-				writableUpper.resize( readable.size() );
+                deleteCount += (writableLower[i] && !lowerSegments.empty()) || (writableUpper[i] && !upperSegments.empty()) ? 1 : 0;
+            }
+        }
+        else
+        {
+            writableLower.resize(readable.size());
+            writableUpper.resize(readable.size());
 
-				for( size_t i = 0; i < readable.size(); ++i )
-				{
-					writableLower[i] = lowerSegmentsSet.find( readable[i] ) == lowerSegmentsSet.end();
-					writableUpper[i] = upperSegmentsSet.find( readable[i] ) == upperSegmentsSet.end();
-					deleteCount += ( writableLower[i] && !lowerSegments.empty() ) || ( writableUpper[i] && !upperSegments.empty() ) ? 1 : 0;
-				}
-			}
+            for (size_t i = 0; i < readable.size(); ++i)
+            {
+                writableLower[i] = lowerSegmentsSet.find(readable[i]) == lowerSegmentsSet.end();
+                writableUpper[i] = upperSegmentsSet.find(readable[i]) == upperSegmentsSet.end();
+                deleteCount += (writableLower[i] && !lowerSegments.empty()) || (writableUpper[i] && !upperSegments.empty()) ? 1 : 0;
+            }
+        }
 
-			if ( m_segments.size() == 1 && deleteCount == 0)
-			{
-				m_outputPrimitives[m_offset] = m_primitive;
-				return nullptr;
-			}
+        if (m_segments.size() == 1 && deleteCount == 0)
+        {
+            m_outputPrimitives[m_offset] = m_primitive;
+            return;
+        }
 
-			IECoreScene::PrimitiveVariable::Interpolation i = splitPrimvarInterpolation( m_primitive.get() );
+        IECoreScene::PrimitiveVariable::Interpolation i = splitPrimvarInterpolation(m_primitive.get());
 
-			IECoreScene::PrimitiveVariable delPrimVarLower( i, deletionArrayLower );
-			Ptr a = m_splitter( m_primitive.get(), delPrimVarLower, false, m_canceller ) ;
+        IECoreScene::PrimitiveVariable delPrimVarLower(i, deletionArrayLower);
+        Ptr a = m_splitter(m_primitive.get(), delPrimVarLower, false, m_canceller);
 
-			IECoreScene::PrimitiveVariable delPrimVarUpper( i, deletionArrayUpper);
-			Ptr b = m_splitter( m_primitive.get(), delPrimVarUpper, false, m_canceller ) ;
+        IECoreScene::PrimitiveVariable delPrimVarUpper(i, deletionArrayUpper);
+        Ptr b = m_splitter(m_primitive.get(), delPrimVarUpper, false, m_canceller);
 
-			size_t numSplits = 2;
+        oneapi::tbb::task_group tg;
 
-			set_ref_count( 1 + numSplits);
+        tg.run([=] {
+            SplitTask lowerTask(lowerSegments, a, m_splitter, m_primvarName, m_outputPrimitives, m_offset, m_depth + 1, m_canceller);
+            lowerTask.execute();
+        });
 
-			SplitTask *tA = new( allocate_child() ) SplitTask( lowerSegments, a, m_splitter,  m_primvarName, m_outputPrimitives, m_offset, m_depth + 1, m_canceller);
-			spawn( *tA );
+        tg.run([=] {
+            SplitTask upperTask(upperSegments, b, m_splitter, m_primvarName, m_outputPrimitives, m_offset + offset, m_depth + 1, m_canceller);
+            upperTask.execute();
+        });
 
-			SplitTask *tB = new( allocate_child() ) SplitTask( upperSegments, b, m_splitter, m_primvarName, m_outputPrimitives, m_offset + offset, m_depth + 1, m_canceller );
-			spawn( *tB );
+        tg.wait();
+    }
 
-			wait_for_all();
-
-			return nullptr;
-		}
-
-	private:
-
-		std::vector<T> m_segments;
-		typename P::Ptr m_primitive;
-		const S &m_splitter;
-		std::string m_primvarName;
-		std::vector<Ptr> &m_outputPrimitives;
-		size_t m_offset;
-		size_t m_depth;
-		const IECore::Canceller *m_canceller;
+private:
+    std::vector<T> m_segments;
+    typename P::Ptr m_primitive;
+    const S& m_splitter;
+    std::string m_primvarName;
+    std::vector<Ptr>& m_outputPrimitives;
+    size_t m_offset;
+    size_t m_depth;
+    const IECore::Canceller* m_canceller;
 };
 
 template<typename P, typename S>
@@ -322,19 +321,24 @@ class TaskSegmenter
 
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
+    		oneapi::tbb::task_group_context taskGroupContext(oneapi::tbb::task_group_context::isolated);
+    		oneapi::tbb::task_group tg(taskGroupContext);
 
+    		tg.run([&] {
+        		SplitTask<T, S, P> task(
+            		segmentsReadable,
+            		const_cast<P*>(m_primitive),
+            		m_splitter,
+            		m_primVarName,
+            		results,
+            		0,
+            		0,
+            		m_canceller
+        		);
+        		task.execute();
+    		});
+
+   	 		tg.wait();
 			return results;
 
 		}
