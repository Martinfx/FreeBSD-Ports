--- tests/framework/instruments/Instruments.h.orig	2025-07-01 09:33:23 UTC
+++ tests/framework/instruments/Instruments.h
@@ -24,12 +24,12 @@
 #ifndef ACL_TESTS_FRAMEWORK_INSTRUMENTS_INSTRUMENTS_H
 #define ACL_TESTS_FRAMEWORK_INSTRUMENTS_INSTRUMENTS_H
 
-#if !defined(_WIN64) && !defined(BARE_METAL) && !defined(__APPLE__) && !defined(__OpenBSD__) && !defined(__QNX__)
+#if !defined(_WIN64) && !defined(BARE_METAL) && !defined(__APPLE__) && !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__QNX__)
 #include "MaliCounter.h"
 #include "OpenCLMemoryUsage.h"
 #include "OpenCLTimer.h"
 #include "PMUCounter.h"
-#endif /* !defined(_WIN64) && !defined(BARE_METAL) && !defined(__APPLE__) && !defined(__OpenBSD__) && !defined(__QNX__) */
+#endif /* !defined(_WIN64) && !defined(BARE_METAL) && !defined(__APPLE__) && !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__QNX__) */
 #include "SchedulerTimer.h"
 #include "WallClockTimer.h"
 
