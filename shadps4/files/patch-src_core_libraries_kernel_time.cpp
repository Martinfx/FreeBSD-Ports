--- src/core/libraries/kernel/time.cpp.orig	2025-09-26 23:03:58 UTC
+++ src/core/libraries/kernel/time.cpp
@@ -16,14 +16,14 @@
 #include <windows.h>
 #include "common/ntapi.h"
 #else
-#ifdef __APPLE__
 #include <date/tz.h>
+#include <ctime>
+#include <memory>
 #endif
 #include <ctime>
 #include <sys/resource.h>
 #include <sys/time.h>
 #include <unistd.h>
-#endif
 
 namespace Libraries::Kernel {
 
@@ -485,7 +485,7 @@ s32 PS4_SYSV_ABI sceKernelConvertUtcToLocaltime(time_t
 s32 PS4_SYSV_ABI sceKernelConvertUtcToLocaltime(time_t time, time_t* local_time,
                                                 struct OrbisTimesec* st, u64* dst_sec) {
     LOG_TRACE(Kernel, "Called");
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
     // std::chrono::current_zone() not available yet.
     const auto* time_zone = date::current_zone();
 #else
