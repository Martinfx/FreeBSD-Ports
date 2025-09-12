--- src/video_core/buffer_cache/region_manager.h.orig	2025-07-06 18:24:57 UTC
+++ src/video_core/buffer_cache/region_manager.h
@@ -7,7 +7,7 @@
 #include "common/div_ceil.h"
 #include "common/logging/log.h"
 
-#ifdef __linux__
+#if defined ( __linux__) || defined(__FreeBSD__)
 #include "common/adaptive_mutex.h"
 #else
 #include "common/spin_lock.h"
