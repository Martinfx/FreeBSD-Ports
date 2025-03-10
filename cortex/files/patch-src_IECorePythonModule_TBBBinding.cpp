--- src/IECorePythonModule/TBBBinding.cpp.orig	2024-12-04 15:09:44 UTC
+++ src/IECorePythonModule/TBBBinding.cpp
@@ -38,10 +38,10 @@
 
 #include "TBBBinding.h"
 
-#include "tbb/task_scheduler_init.h"
+//#include "tbb/task_scheduler_init.h"
 
-#define TBB_PREVIEW_GLOBAL_CONTROL 1
-#include "tbb/global_control.h"
+//#define TBB_PREVIEW_GLOBAL_CONTROL 1
+//#include "tbb/global_control.h"
 
 #include <thread>
 
@@ -49,7 +49,7 @@ namespace
 
 namespace
 {
-
+/*
 // Wraps task_scheduler_init so it can be used as a python
 // context manager.
 class TaskSchedulerInitWrapper : public tbb::task_scheduler_init
@@ -111,10 +111,10 @@ class GlobalControlWrapper : public boost::noncopyable
 		const size_t m_value;
 		std::unique_ptr<tbb::global_control> m_globalControl;
 
-};
+};*/
 
 } // namespace
-
+/*
 void IECorePythonModule::bindTBB()
 {
 	object tsi = class_<TaskSchedulerInitWrapper, boost::noncopyable>( "tbb_task_scheduler_init", no_init )
@@ -143,4 +143,4 @@ void IECorePythonModule::bindTBB()
 	def( "hardwareConcurrency", &std::thread::hardware_concurrency );
 
 }
-
+*/
