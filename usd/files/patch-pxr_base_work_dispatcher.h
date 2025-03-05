--- pxr/base/work/dispatcher.h.orig	2025-03-05 14:19:22 UTC
+++ pxr/base/work/dispatcher.h
@@ -203,7 +203,7 @@ class WorkDispatcher (private)
     class _TaskGroup : public tbb::task_group {
     public:
         _TaskGroup(tbb::task_group_context& ctx) : tbb::task_group(ctx) {}
-         inline tbb::detail::d1::wait_context& _GetInternalWaitContext();
+         inline tbb::detail::d1::wait_context_vertex& _GetInternalWaitContext();
     };
 
     _TaskGroup _taskGroup;
@@ -260,4 +260,4 @@ PXR_NAMESPACE_CLOSE_SCOPE
 
 PXR_NAMESPACE_CLOSE_SCOPE
 
-#endif // PXR_BASE_WORK_DISPATCHER_H
\ No newline at end of file
+#endif // PXR_BASE_WORK_DISPATCHER_H
