--- include/IECoreScene/private/PrimitiveAlgoUtils.h.orig	2024-11-20 16:12:36 UTC
+++ include/IECoreScene/private/PrimitiveAlgoUtils.h
@@ -174,7 +174,7 @@ template<typename T> struct IsDeletablePrimVar : boost
 /// Numeric & string like arrays, which contain elements which can be added to a std::set
 template<typename T> struct IsDeletablePrimVar : boost::mpl::or_< IECore::TypeTraits::IsStringVectorTypedData<T>, IECore::TypeTraits::IsNumericVectorTypedData<T> > {};
 
-
+/*
 template<typename T, typename S, typename P>
 class SplitTask : public tbb::task
 {
@@ -186,7 +186,7 @@ class SplitTask : public tbb::task
 		{
 		}
 
-		task *execute() override
+        task *execute() override
 		{
 
 			if ( numPrimitives ( m_primitive.get() ) == 0 && !m_segments.empty() )
@@ -287,7 +287,7 @@ class SplitTask : public tbb::task
 		size_t m_offset;
 		size_t m_depth;
 		const IECore::Canceller *m_canceller;
-};
+};*/
 
 template<typename P, typename S>
 class TaskSegmenter
@@ -321,7 +321,7 @@ class TaskSegmenter
 			const auto &segmentsReadable = segments->readable();
 
 			ReturnType results( segmentsReadable.size() );
-
+/*
 			tbb::task_group_context taskGroupContext( tbb::task_group_context::isolated );
 			SplitTask<T, S, P> *task = new( tbb::task::allocate_root( taskGroupContext ) ) SplitTask<T, S, P>(
 				segmentsReadable,
@@ -333,7 +333,7 @@ class TaskSegmenter
 				0,
 				m_canceller
 			);
-			tbb::task::spawn_root_and_wait( *task );
+			tbb::task::spawn_root_and_wait( *task ); */
 
 			return results;
 
