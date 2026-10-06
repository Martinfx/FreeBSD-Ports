--- external/CppCommon/source/cpu.cpp.orig	2026-10-06 04:21:17 UTC
+++ external/CppCommon/source/cpu.cpp
@@ -11,6 +11,10 @@
 
 #if defined(__APPLE__)
 #include <sys/sysctl.h>
+#elif defined(__FreeBSD__)
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#include <unistd.h>
 #elif defined(unix) || defined(__unix) || defined(__unix__)
 #include <fstream>
 #include <regex>
@@ -53,6 +57,13 @@ std::string CPU::Architecture() {
         return result;
 
     return "<unknown>";
+#elif defined(__FreeBSD__)
+    char result[1024];
+    size_t size = sizeof(result);
+    if (sysctlbyname("hw.model", result, &size, nullptr, 0) == 0)
+        return result;
+
+    return "<unknown>";
 #elif defined(unix) || defined(__unix) || defined(__unix__)
     static std::regex pattern("model name(.*): (.*)");
 
@@ -192,6 +203,13 @@ int64_t CPU::ClockSpeed() {
         return frequency;
 
     return -1;
+#elif defined(__FreeBSD__)
+    int frequency = 0;
+    size_t size = sizeof(frequency);
+    if (sysctlbyname("hw.clockrate", &frequency, &size, nullptr, 0) == 0)
+        return frequency;
+
+    return -1;
 #elif defined(unix) || defined(__unix) || defined(__unix__)
     static std::regex pattern("cpu MHz(.*): (.*)");
 
