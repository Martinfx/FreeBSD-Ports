--- src/runtime/CPP/CPPScheduler.cpp.orig	2022-08-18 12:49:09 UTC
+++ src/runtime/CPP/CPPScheduler.cpp
@@ -104,12 +104,12 @@ void set_thread_affinity(int core_id)
         return;
     }
 
-#if !defined(_WIN64) && !defined(__APPLE__) && !defined(__OpenBSD__)
+#if !defined(_WIN64) && !defined(__APPLE__) && !defined(__OpenBSD__) && !defined(__FreeBSD__)
     cpu_set_t set;
     CPU_ZERO(&set);
     CPU_SET(core_id, &set);
     ARM_COMPUTE_EXIT_ON_MSG(sched_setaffinity(0, sizeof(set), &set), "Error setting thread affinity");
-#endif /* !defined(__APPLE__) && !defined(__OpenBSD__) */
+#endif /* !defined(__APPLE__) && !defined(__OpenBSD__) &&  !defined(__FreeBSD__) */
 }
 
 /** There are currently 2 scheduling modes supported by CPPScheduler
