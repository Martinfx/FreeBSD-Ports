--- src/util/stats.h.orig	2025-03-04 15:23:02 UTC
+++ src/util/stats.h
@@ -5,6 +5,7 @@
 #ifndef __UTIL_STATS_H__
 #define __UTIL_STATS_H__
 
+#include "../../third_party/atomic/atomic_ops.h"
 #include "util/atomic.h"
 #include "util/profiling.h"
 
