--- src/base/profiler/stack_sampling_profiler_unittest.cc.orig	2026-11-24 12:50:30 UTC
+++ src/base/profiler/stack_sampling_profiler_unittest.cc
@@ -46,7 +46,7 @@
 
 #include <intrin.h>
 #include <malloc.h>
-#else
+#elif !BUILDFLAG(IS_BSD)
 #include <alloca.h>
 #endif
 
