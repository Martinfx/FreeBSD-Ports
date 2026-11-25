--- src/base/threading/platform_thread.h.orig	2026-11-24 12:50:30 UTC
+++ src/base/threading/platform_thread.h
@@ -66,6 +66,8 @@ class BASE_EXPORT PlatformThreadId {
   using UnderlyingType = zx_koid_t;
 #elif BUILDFLAG(IS_APPLE)
   using UnderlyingType = uint64_t;
+#elif BUILDFLAG(IS_BSD)
+  using UnderlyingType = uint64_t;
 #elif BUILDFLAG(IS_POSIX)
   using UnderlyingType = pid_t;
 #endif
