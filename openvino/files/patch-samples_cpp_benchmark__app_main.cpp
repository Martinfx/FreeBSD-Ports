--- samples/cpp/benchmark_app/main.cpp.orig	2026-04-10 09:44:43 UTC
+++ samples/cpp/benchmark_app/main.cpp
@@ -39,7 +39,7 @@
 #if defined(_WIN32)
 #include <windows.h>
 #include <psapi.h>
-#elif defined(__APPLE__)
+#elif defined(__APPLE__) || defined(__FreeBSD__)
 #include <sys/resource.h>
 #elif defined(__linux__)
 #include <fstream>
@@ -75,7 +75,7 @@
     return static_cast<int64_t>(std::round(mem_counters.PeakWorkingSetSize / bytes_in_kilobyte));
 }
 
-#elif defined(__APPLE__)
+#elif defined(__APPLE__) || defined(__FreeBSD__)
 
 int64_t get_peak_memory_usage() {
     struct rusage usage;
