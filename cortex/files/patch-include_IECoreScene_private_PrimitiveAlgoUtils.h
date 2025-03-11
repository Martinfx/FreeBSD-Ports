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
@@ -174,121 +175,116 @@ template<typename T> struct IsDeletablePrimVar : boost
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
+	SplitTask(const std::vector<T>& segments, typename P::Ptr primitive, const S& splitter,
+               const std::string& primvarName, std::vector<typename P::Ptr>& outputPrimitives,
+               size_t offset, size_t depth, const IECore::Canceller* canceller,
+               oneapi::tbb::task_group& tg)
+		: m_segments(segments), m_primitive(primitive), m_splitter(splitter),
+          m_primvarName(primvarName), m_outputPrimitives(outputPrimitives),
+          m_offset(offset), m_depth(depth), m_canceller(canceller), m_tg(tg)
+    {
+    }
 
-			if ( numPrimitives ( m_primitive.get() ) == 0 && !m_segments.empty() )
-			{
-				m_outputPrimitives[m_offset] = m_primitive;
-				return nullptr;
-			}
+    if (numPrimitives(primitive.get()) == 0 && !segments.empty())
+    {
+        outputPrimitives[offset] = primitive;
+        return;
+    }
 
-			if ( m_segments.size () == 0 )
-			{
-				return nullptr;
-			}
+    if (segments.empty())
+    {
+        return;
+    }
 
-			size_t offset = m_segments.size() / 2;
-			typename std::vector<T>::iterator mid = m_segments.begin() + offset;
+    size_t midIndex = segments.size() / 2;
+    auto midIter = segments.begin() + midIndex;
 
-			IECoreScene::PrimitiveVariable segmentPrimVar = m_primitive->variables.find( m_primvarName )->second;
+    IECoreScene::PrimitiveVariable segmentPrimVar = primitive->variables.find(primvarName)->second;
 
-			std::vector<T> lowerSegments (m_segments.begin(), mid);
-			std::vector<T> upperSegments (mid, m_segments.end());
+    std::vector<T> lowerSegments(segments.begin(), midIter);
+    std::vector<T> upperSegments(midIter, segments.end());
 
-			std::set<T> lowerSegmentsSet ( m_segments.begin(), mid );
-			std::set<T> upperSegmentsSet (mid, m_segments.end());
+    std::set<T> lowerSegmentsSet(segments.begin(), midIter);
+    std::set<T> upperSegmentsSet(midIter, segments.end());
 
-			const auto &readable = IECore::runTimeCast<IECore::TypedData<std::vector<T> > >( segmentPrimVar.data )->readable();
+    const auto& readable = IECore::runTimeCast<IECore::TypedData<std::vector<T>>>(segmentPrimVar.data)->readable();
 
-			IECore::BoolVectorDataPtr deletionArrayLower = new IECore::BoolVectorData();
-			auto &writableLower = deletionArrayLower->writable();
+    auto deletionArrayLower = std::make_shared<IECore::BoolVectorData>();
+    auto& writableLower = deletionArrayLower->writable();
 
-			IECore::BoolVectorDataPtr deletionArrayUpper = new IECore::BoolVectorData();
-			auto &writableUpper = deletionArrayUpper->writable();
+    auto deletionArrayUpper = std::make_shared<IECore::BoolVectorData>();
+    auto& writableUpper = deletionArrayUpper->writable();
 
-			size_t deleteCount = 0;
-			if( segmentPrimVar.indices )
-			{
-				auto &readableIndices = segmentPrimVar.indices->readable();
-				writableLower.resize( readableIndices.size() );
-				writableUpper.resize( readableIndices.size() );
+    size_t deleteCount = 0;
+    if (segmentPrimVar.indices)
+    {
+        const auto& readableIndices = segmentPrimVar.indices->readable();
+        writableLower.resize(readableIndices.size());
+        writableUpper.resize(readableIndices.size());
 
-				for( size_t i = 0; i < readableIndices.size(); ++i )
-				{
-					size_t index = readableIndices[i];
-					writableLower[i] = lowerSegmentsSet.find( readable[index] ) == lowerSegmentsSet.end();
-					writableUpper[i] = upperSegmentsSet.find( readable[index] ) == upperSegmentsSet.end();
+        for (size_t i = 0; i < readableIndices.size(); ++i)
+        {
+            size_t index = readableIndices[i];
+            writableLower[i] = lowerSegmentsSet.find(readable[index]) == lowerSegmentsSet.end();
+            writableUpper[i] = upperSegmentsSet.find(readable[index]) == upperSegmentsSet.end();
 
-					deleteCount += ( writableLower[i] && !lowerSegments.empty() ) || ( writableUpper[i] && !upperSegments.empty() ) ? 1 : 0;
-				}
-			}
-			else
-			{
-				writableLower.resize( readable.size() );
-				writableUpper.resize( readable.size() );
+            deleteCount += (writableLower[i] && !lowerSegments.empty()) || (writableUpper[i] && !upperSegments.empty()) ? 1 : 0;
+        }
+    }
+    else
+    {
+        writableLower.resize(readable.size());
+        writableUpper.resize(readable.size());
 
-				for( size_t i = 0; i < readable.size(); ++i )
-				{
-					writableLower[i] = lowerSegmentsSet.find( readable[i] ) == lowerSegmentsSet.end();
-					writableUpper[i] = upperSegmentsSet.find( readable[i] ) == upperSegmentsSet.end();
-					deleteCount += ( writableLower[i] && !lowerSegments.empty() ) || ( writableUpper[i] && !upperSegments.empty() ) ? 1 : 0;
-				}
-			}
+        for (size_t i = 0; i < readable.size(); ++i)
+        {
+            writableLower[i] = lowerSegmentsSet.find(readable[i]) == lowerSegmentsSet.end();
+            writableUpper[i] = upperSegmentsSet.find(readable[i]) == upperSegmentsSet.end();
+            deleteCount += (writableLower[i] && !lowerSegments.empty()) || (writableUpper[i] && !upperSegments.empty()) ? 1 : 0;
+        }
+    }
 
-			if ( m_segments.size() == 1 && deleteCount == 0)
-			{
-				m_outputPrimitives[m_offset] = m_primitive;
-				return nullptr;
-			}
+    if (segments.size() == 1 && deleteCount == 0)
+    {
+        outputPrimitives[offset] = primitive;
+        return;
+    }
 
-			IECoreScene::PrimitiveVariable::Interpolation i = splitPrimvarInterpolation( m_primitive.get() );
+    IECoreScene::PrimitiveVariable::Interpolation interpolation = splitPrimvarInterpolation(primitive.get());
 
-			IECoreScene::PrimitiveVariable delPrimVarLower( i, deletionArrayLower );
-			Ptr a = m_splitter( m_primitive.get(), delPrimVarLower, false, m_canceller ) ;
+    IECoreScene::PrimitiveVariable delPrimVarLower(interpolation, deletionArrayLower);
+    auto a = splitter(primitive.get(), delPrimVarLower, false, canceller);
 
-			IECoreScene::PrimitiveVariable delPrimVarUpper( i, deletionArrayUpper);
-			Ptr b = m_splitter( m_primitive.get(), delPrimVarUpper, false, m_canceller ) ;
+    IECoreScene::PrimitiveVariable delPrimVarUpper(interpolation, deletionArrayUpper);
+    auto b = splitter(primitive.get(), delPrimVarUpper, false, canceller);
 
-			size_t numSplits = 2;
+    m_tg.run([=, &tg]() {
+        SplitTask(lowerSegments, a, splitter, primvarName, outputPrimitives, offset, depth + 1, canceller, tg);
+    });
 
-			set_ref_count( 1 + numSplits);
+    m_tg.run([=, &tg]() {
+        SplitTask(upperSegments, b, splitter, primvarName, outputPrimitives, offset + midIndex, depth + 1, canceller, tg);
+    });
 
-			SplitTask *tA = new( allocate_child() ) SplitTask( lowerSegments, a, m_splitter,  m_primvarName, m_outputPrimitives, m_offset, m_depth + 1, m_canceller);
-			spawn( *tA );
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
@@ -322,18 +318,24 @@ class TaskSegmenter
 
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
+    			typename SplitTask<T, S, P>::SplitTask task(
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
+tg.wait();
 
 			return results;
 
