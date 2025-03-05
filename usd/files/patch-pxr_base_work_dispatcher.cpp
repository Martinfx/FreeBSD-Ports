--- pxr/base/work/dispatcher.cpp.orig	2025-03-05 14:06:27 UTC
+++ pxr/base/work/dispatcher.cpp
@@ -34,7 +34,7 @@ WorkDispatcher::_TaskGroup::_GetInternalWaitContext() 
 #if TBB_INTERFACE_VERSION_MAJOR >= 12
 inline tbb::detail::d1::wait_context& 
 WorkDispatcher::_TaskGroup::_GetInternalWaitContext() {
-    return m_wait_ctx;
+    return m_wait_vertex;
 }
 #endif
 
