--- include/IECoreScene/private/PrimitiveAlgoUtils.h.orig	2025-02-25 10:37:21 UTC
+++ include/IECoreScene/private/PrimitiveAlgoUtils.h
@@ -175,6 +175,7 @@ template<typename T> struct IsDeletablePrimVar : boost
 template<typename T> struct IsDeletablePrimVar : boost::mpl::or_< IECore::TypeTraits::IsStringVectorTypedData<T>, IECore::TypeTraits::IsNumericVectorTypedData<T> > {};
 
 
+/*
 template<typename T, typename S, typename P>
 class SplitTask : public tbb::task
 {
@@ -288,6 +289,7 @@ class SplitTask : public tbb::task
 		size_t m_depth;
 		const IECore::Canceller *m_canceller;
 };
+*/
 
 template<typename P, typename S>
 class TaskSegmenter
@@ -322,6 +324,7 @@ class TaskSegmenter
 
 			ReturnType results( segmentsReadable.size() );
 
+/*
 			tbb::task_group_context taskGroupContext( tbb::task_group_context::isolated );
 			SplitTask<T, S, P> *task = new( tbb::task::allocate_root( taskGroupContext ) ) SplitTask<T, S, P>(
 				segmentsReadable,
@@ -334,6 +337,7 @@ class TaskSegmenter
 				m_canceller
 			);
 			tbb::task::spawn_root_and_wait( *task );
+*/ 
 
 			return results;
 
