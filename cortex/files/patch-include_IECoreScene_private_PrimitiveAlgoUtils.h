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
@@ -174,121 +175,104 @@ template<typename T> struct IsDeletablePrimVar : boost
 /// Numeric & string like arrays, which contain elements which can be added to a std::set
 template<typename T> struct IsDeletablePrimVar : boost::mpl::or_< IECore::TypeTraits::IsStringVectorTypedData<T>, IECore::TypeTraits::IsNumericVectorTypedData<T> > {};
 
-
 template<typename T, typename S, typename P>
-class SplitTask : public tbb::task
+void splitTask(const std::vector<T>& segments, typename P::Ptr primitive, const S& splitter,
+               const std::string& primvarName, std::vector<typename P::Ptr>& outputPrimitives,
+               size_t offset, size_t depth, const IECore::Canceller* canceller,
+               oneapi::tbb::task_group& tg)
 {
-	private:
-		typedef typename P::Ptr Ptr;
-	public:
-		SplitTask(const std::vector<T> &segments, typename P::Ptr primitive, const S& splitter, const std::string &primvarName, std::vector<Ptr> &outputPrimitives, size_t offset, size_t depth, const IECore::Canceller *canceller )
-			: m_segments(segments), m_primitive(primitive), m_splitter(splitter), m_primvarName(primvarName), m_outputPrimitives( outputPrimitives ), m_offset(offset), m_depth(depth), m_canceller( canceller )
-		{
-		}
+    if (numPrimitives(primitive.get()) == 0 && !segments.empty())
+    {
+        outputPrimitives[offset] = primitive;
+        return;
+    }
 
-		task *execute() override
-		{
+    if (segments.empty())
+    {
+        return;
+    }
 
-			if ( numPrimitives ( m_primitive.get() ) == 0 && !m_segments.empty() )
-			{
-				m_outputPrimitives[m_offset] = m_primitive;
-				return nullptr;
-			}
+    size_t midIndex = segments.size() / 2;
+    auto midIter = segments.begin() + midIndex;
 
-			if ( m_segments.size () == 0 )
-			{
-				return nullptr;
-			}
+    IECoreScene::PrimitiveVariable segmentPrimVar = primitive->variables.find(primvarName)->second;
 
-			size_t offset = m_segments.size() / 2;
-			typename std::vector<T>::iterator mid = m_segments.begin() + offset;
+    std::vector<T> lowerSegments(segments.begin(), midIter);
+    std::vector<T> upperSegments(midIter, segments.end());
 
-			IECoreScene::PrimitiveVariable segmentPrimVar = m_primitive->variables.find( m_primvarName )->second;
+    std::set<T> lowerSegmentsSet(segments.begin(), midIter);
+    std::set<T> upperSegmentsSet(midIter, segments.end());
 
-			std::vector<T> lowerSegments (m_segments.begin(), mid);
-			std::vector<T> upperSegments (mid, m_segments.end());
+    const auto& readable = IECore::runTimeCast<IECore::TypedData<std::vector<T>>>(segmentPrimVar.data)->readable();
 
-			std::set<T> lowerSegmentsSet ( m_segments.begin(), mid );
-			std::set<T> upperSegmentsSet (mid, m_segments.end());
+    auto deletionArrayLower = std::make_shared<IECore::BoolVectorData>();
+    auto& writableLower = deletionArrayLower->writable();
 
-			const auto &readable = IECore::runTimeCast<IECore::TypedData<std::vector<T> > >( segmentPrimVar.data )->readable();
+    auto deletionArrayUpper = std::make_shared<IECore::BoolVectorData>();
+    auto& writableUpper = deletionArrayUpper->writable();
 
-			IECore::BoolVectorDataPtr deletionArrayLower = new IECore::BoolVectorData();
-			auto &writableLower = deletionArrayLower->writable();
+    size_t deleteCount = 0;
+    if (segmentPrimVar.indices)
+    {
+        const auto& readableIndices = segmentPrimVar.indices->readable();
+        writableLower.resize(readableIndices.size());
+        writableUpper.resize(readableIndices.size());
 
-			IECore::BoolVectorDataPtr deletionArrayUpper = new IECore::BoolVectorData();
-			auto &writableUpper = deletionArrayUpper->writable();
+        for (size_t i = 0; i < readableIndices.size(); ++i)
+        {
+            size_t index = readableIndices[i];
+            writableLower[i] = lowerSegmentsSet.find(readable[index]) == lowerSegmentsSet.end();
+            writableUpper[i] = upperSegmentsSet.find(readable[index]) == upperSegmentsSet.end();
 
-			size_t deleteCount = 0;
-			if( segmentPrimVar.indices )
-			{
-				auto &readableIndices = segmentPrimVar.indices->readable();
-				writableLower.resize( readableIndices.size() );
-				writableUpper.resize( readableIndices.size() );
+            deleteCount += (writableLower[i] && !lowerSegments.empty()) || (writableUpper[i] && !upperSegments.empty()) ? 1 : 0;
+        }
+    }
+    else
+    {
+        writableLower.resize(readable.size());
+        writableUpper.resize(readable.size());
 
-				for( size_t i = 0; i < readableIndices.size(); ++i )
-				{
-					size_t index = readableIndices[i];
-					writableLower[i] = lowerSegmentsSet.find( readable[index] ) == lowerSegmentsSet.end();
-					writableUpper[i] = upperSegmentsSet.find( readable[index] ) == upperSegmentsSet.end();
+        for (size_t i = 0; i < readable.size(); ++i)
+        {
+            writableLower[i] = lowerSegmentsSet.find(readable[i]) == lowerSegmentsSet.end();
+            writableUpper[i] = upperSegmentsSet.find(readable[i]) == upperSegmentsSet.end();
+            deleteCount += (writableLower[i] && !lowerSegments.empty()) || (writableUpper[i] && !upperSegments.empty()) ? 1 : 0;
+        }
+    }
 
-					deleteCount += ( writableLower[i] && !lowerSegments.empty() ) || ( writableUpper[i] && !upperSegments.empty() ) ? 1 : 0;
-				}
-			}
-			else
-			{
-				writableLower.resize( readable.size() );
-				writableUpper.resize( readable.size() );
+    if (segments.size() == 1 && deleteCount == 0)
+    {
+        outputPrimitives[offset] = primitive;
+        return;
+    }
 
-				for( size_t i = 0; i < readable.size(); ++i )
-				{
-					writableLower[i] = lowerSegmentsSet.find( readable[i] ) == lowerSegmentsSet.end();
-					writableUpper[i] = upperSegmentsSet.find( readable[i] ) == upperSegmentsSet.end();
-					deleteCount += ( writableLower[i] && !lowerSegments.empty() ) || ( writableUpper[i] && !upperSegments.empty() ) ? 1 : 0;
-				}
-			}
+    IECoreScene::PrimitiveVariable::Interpolation interpolation = splitPrimvarInterpolation(primitive.get());
 
-			if ( m_segments.size() == 1 && deleteCount == 0)
-			{
-				m_outputPrimitives[m_offset] = m_primitive;
-				return nullptr;
-			}
+    IECoreScene::PrimitiveVariable delPrimVarLower(interpolation, deletionArrayLower);
+    auto a = splitter(primitive.get(), delPrimVarLower, false, canceller);
 
-			IECoreScene::PrimitiveVariable::Interpolation i = splitPrimvarInterpolation( m_primitive.get() );
+    IECoreScene::PrimitiveVariable delPrimVarUpper(interpolation, deletionArrayUpper);
+    auto b = splitter(primitive.get(), delPrimVarUpper, false, canceller);
 
-			IECoreScene::PrimitiveVariable delPrimVarLower( i, deletionArrayLower );
-			Ptr a = m_splitter( m_primitive.get(), delPrimVarLower, false, m_canceller ) ;
+    tg.run([=, &tg]() {
+        splitTask(lowerSegments, a, splitter, primvarName, outputPrimitives, offset, depth + 1, canceller, tg);
+    });
 
-			IECoreScene::PrimitiveVariable delPrimVarUpper( i, deletionArrayUpper);
-			Ptr b = m_splitter( m_primitive.get(), delPrimVarUpper, false, m_canceller ) ;
+    tg.run([=, &tg]() {
+        splitTask(upperSegments, b, splitter, primvarName, outputPrimitives, offset + midIndex, depth + 1, canceller, tg);
+    });
 
-			size_t numSplits = 2;
+private:
+    std::vector<T> m_segments;
+    typename P::Ptr m_primitive;
+    const S& m_splitter;
+    std::string m_primvarName;
+    std::vector<Ptr>& m_outputPrimitives;
+    size_t m_offset;
+    size_t m_depth;
+    const IECore::Canceller* m_canceller;
+}
 
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
-};
-
 template<typename P, typename S>
 class TaskSegmenter
 {
@@ -322,18 +306,24 @@ class TaskSegmenter
 
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
+			tg.run([&] {
+    			SplitTask<T, S, P> task(
+        		segmentsReadable,
+        		const_cast<P*>(m_primitive),
+        		m_splitter,
+        		m_primVarName,
+        		results,
+        		0,
+        		0,
+        		m_canceller
+    		);
+    		task.execute();
+			});
+
+			tg.wait();
 
 			return results;
 
