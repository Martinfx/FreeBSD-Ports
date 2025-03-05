--- pxr/base/work/dispatcher.cpp.orig	2025-03-05 14:06:27 UTC
+++ pxr/base/work/dispatcher.cpp
@@ -32,9 +32,9 @@ WorkDispatcher::WorkDispatcher()
 }
 
 #if TBB_INTERFACE_VERSION_MAJOR >= 12
-inline tbb::detail::d1::wait_context& 
+inline tbb::detail::d1::wait_context_vertex& 
 WorkDispatcher::_TaskGroup::_GetInternalWaitContext() {
-    return m_wait_ctx;
+	return m_wait_vertex;
 }
 #endif
 
@@ -55,7 +55,7 @@ WorkDispatcher::Wait()
     // The native task_group::wait() has a comment saying its call to the
     // context reset method is not thread safe. So we do our own
     // synchronization to ensure it is called once.
-    tbb::detail::d1::wait(_taskGroup._GetInternalWaitContext(), _context);
+    tbb::detail::d1::wait(_taskGroup._GetInternalWaitContext().get_context(), _context);
 #else
     _rootTask->wait_for_all();
 #endif
