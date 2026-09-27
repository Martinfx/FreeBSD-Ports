--- pxr/base/work/workTBB/dispatcher_impl.h.orig	2026-04-24 18:55:54 UTC
+++ pxr/base/work/workTBB/dispatcher_impl.h
@@ -13,6 +13,11 @@
 // Blocked range is not used in this file, but this header happens to pull in
 // the TBB version header in a way that works in all TBB versions.
 #include <tbb/blocked_range.h>
+// Newer oneTBB releases (e.g. 2023.x) no longer pull in the version header
+// through blocked_range.h, which silently selects the pre-oneTBB code below.
+#if __has_include(<tbb/version.h>)
+#include <tbb/version.h>
+#endif
 #include <tbb/concurrent_vector.h>
 #if TBB_INTERFACE_VERSION_MAJOR >= 12
 #include <tbb/task_group.h>
