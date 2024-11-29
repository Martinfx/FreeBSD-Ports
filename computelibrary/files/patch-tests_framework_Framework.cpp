--- tests/framework/Framework.cpp.orig	2023-03-05 10:51:48 UTC
+++ tests/framework/Framework.cpp
@@ -26,6 +26,8 @@
 #include "arm_compute/runtime/Scheduler.h"
 #include "tests/framework/ParametersLibrary.h"
 #include "tests/framework/TestFilter.h"
+#include "tests/framework/instruments/OpenCLTimer.h"
+#include "tests/framework/instruments/OpenCLMemoryUsage.h"
 
 #ifdef ARM_COMPUTE_CL
 #include "arm_compute/runtime/CL/CLRuntimeContext.h"
