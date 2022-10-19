--- tests/framework/instruments/Instruments.h.orig	2022-08-18 12:49:09 UTC
+++ tests/framework/instruments/Instruments.h
@@ -24,12 +24,12 @@
 #ifndef ARM_COMPUTE_TEST_INSTRUMENTS
 #define ARM_COMPUTE_TEST_INSTRUMENTS
 
-#if !defined(_WIN64) && !defined(BARE_METAL) && !defined(__APPLE__) && !defined(__OpenBSD__)
+#if !defined(_WIN64) && !defined(BARE_METAL) && !defined(__APPLE__) && !defined(__OpenBSD__) && !defined(__FreeBSD__)
 #include "MaliCounter.h"
 #include "OpenCLMemoryUsage.h"
 #include "OpenCLTimer.h"
 #include "PMUCounter.h"
-#endif /* !defined(_WIN64) && !defined(BARE_METAL) && !defined(__APPLE__) && !defined(__OpenBSD__) */
+#endif /* !defined(_WIN64) && !defined(BARE_METAL) && !defined(__APPLE__) && !defined(__OpenBSD__) && !defined(__FreeBSD__) */
 #include "SchedulerTimer.h"
 #include "WallClockTimer.h"
 
