--- src/video_core/page_manager.h.orig	2025-04-06 13:16:45 UTC
+++ src/video_core/page_manager.h
@@ -5,7 +5,7 @@
 
 #include <memory>
 #include <boost/icl/interval_map.hpp>
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #include "common/adaptive_mutex.h"
 #endif
 #include "common/spin_lock.h"
