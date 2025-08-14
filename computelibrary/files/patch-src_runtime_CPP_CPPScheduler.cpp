--- src/runtime/CPP/CPPScheduler.cpp.orig	2025-07-01 09:33:23 UTC
+++ src/runtime/CPP/CPPScheduler.cpp
@@ -103,7 +103,7 @@ void set_thread_affinity(int core_id)
         return;
     }
 
-#if !defined(_WIN64) && !defined(__APPLE__) && !defined(__OpenBSD__) && !defined(__QNX__)
+#if !defined(_WIN64) && !defined(__APPLE__) && !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__QNX__)
     cpu_set_t set;
     CPU_ZERO(&set);
     CPU_SET(core_id, &set);
