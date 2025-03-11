--- src/IECorePythonModule/TBBBinding.cpp.orig	2025-02-25 10:37:21 UTC
+++ src/IECorePythonModule/TBBBinding.cpp
@@ -38,11 +38,10 @@
 
 #include "TBBBinding.h"
 
-#include "tbb/task_scheduler_init.h"
+//#include "tbb/task_scheduler_init.h"
+//#define TBB_PREVIEW_GLOBAL_CONTROL 1
+#include "oneapi/tbb/global_control.h"
 
-#define TBB_PREVIEW_GLOBAL_CONTROL 1
-#include "tbb/global_control.h"
-
 #include <thread>
 
 using namespace boost::python;
@@ -52,7 +51,8 @@ namespace
 
 // Wraps task_scheduler_init so it can be used as a python
 // context manager.
-class TaskSchedulerInitWrapper : public tbb::task_scheduler_init
+// tbb::task_scheduler_init was remove from onetbb
+/*class TaskSchedulerInitWrapper : public tbb::task_scheduler_init
 {
 
 	public :
@@ -82,47 +82,47 @@ class TaskSchedulerInitWrapper : public tbb::task_sche
 
 		int m_maxThreads;
 
-};
+};*/
 
 class GlobalControlWrapper : public boost::noncopyable
 {
+public:
+    GlobalControlWrapper(size_t max_threads)
+        : m_maxThreads(max_threads)
+    {
+        if (max_threads == 0)
+        {
+            PyErr_SetString(PyExc_ValueError, "max_threads must be a positive integer");
+            throw_error_already_set();
+        }
+    }
 
-	public :
+    void enter()
+    {
+        m_globalControl.reset(new tbb::global_control(tbb::global_control::max_allowed_parallelism, m_maxThreads));
+    }
 
-		GlobalControlWrapper( tbb::global_control::parameter parameter, size_t value )
-			:	m_parameter( parameter ), m_value( value )
-		{
-		}
+    bool exit(boost::python::object excType, boost::python::object excValue, boost::python::object excTraceBack)
+    {
+        m_globalControl.reset();
+        return false; // don't suppress exceptions
+    }
 
-		void enter()
-		{
-			m_globalControl.reset( new tbb::global_control( m_parameter, m_value ) );
-		}
-
-		bool exit( boost::python::object excType, boost::python::object excValue, boost::python::object excTraceBack )
-		{
-			m_globalControl.reset();
-			return false; // don't suppress exceptions
-		}
-
-	private :
-
-		const tbb::global_control::parameter m_parameter;
-		const size_t m_value;
-		std::unique_ptr<tbb::global_control> m_globalControl;
-
+private:
+    size_t m_maxThreads;
+    std::unique_ptr<tbb::global_control> m_globalControl;
 };
 
 } // namespace
 
 void IECorePythonModule::bindTBB()
 {
-	object tsi = class_<TaskSchedulerInitWrapper, boost::noncopyable>( "tbb_task_scheduler_init", no_init )
+	/*object tsi = class_<TaskSchedulerInitWrapper, boost::noncopyable>( "tbb_task_scheduler_init", no_init )
 		.def( init<int>( arg( "max_threads" ) = int( tbb::task_scheduler_init::automatic ) ) )
 		.def( "__enter__", &TaskSchedulerInitWrapper::enter, return_self<>() )
 		.def( "__exit__", &TaskSchedulerInitWrapper::exit )
 	;
-	tsi.attr( "automatic" ) = int( tbb::task_scheduler_init::automatic );
+	tsi.attr( "automatic" ) = int( tbb::task_scheduler_init::automatic );*/
 
 	class_<GlobalControlWrapper, boost::noncopyable> globalControl( "tbb_global_control", no_init );
 	{
