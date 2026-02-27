--- src/xenia/base/atomic.h.orig	2025-03-06 13:19:21 UTC
+++ src/xenia/base/atomic.h
@@ -55,7 +55,7 @@ inline bool atomic_cas(int64_t old_value, int64_t new_
              old_value) == old_value;
 }
 
-#elif XE_PLATFORM_LINUX || XE_PLATFORM_MAC
+#elif XE_PLATFORM_LINUX || XE_PLATFORM_MAC || XE_PLATFORM_FREEBSD
 
 inline int32_t atomic_inc(volatile int32_t* value) {
   return __sync_add_and_fetch(value, 1);
