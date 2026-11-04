--- src/xenia/base/clock_posix.cc.orig
+++ src/xenia/base/clock_posix.cc
@@ -12,6 +12,11 @@
 #include <mach/mach_time.h>
 #endif
 
+#if defined(__FreeBSD__) && !defined(CLOCK_MONOTONIC_RAW)
+// FreeBSD has no CLOCK_MONOTONIC_RAW, its CLOCK_MONOTONIC is never stepped.
+#define CLOCK_MONOTONIC_RAW CLOCK_MONOTONIC
+#endif
+
 #include "xenia/base/assert.h"
 #include "xenia/base/clock.h"
 
