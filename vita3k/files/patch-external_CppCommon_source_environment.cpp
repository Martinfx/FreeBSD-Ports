--- external/CppCommon/source/environment.cpp.orig	2025-04-23 21:22:30 UTC
+++ external/CppCommon/source/environment.cpp
@@ -12,7 +12,7 @@
 #include <codecvt>
 #include <sstream>
 
-#if defined(__APPLE__)
+#if defined(__APPLE__) || defined(__FreeBSD__)
 #include <sys/sysctl.h>
 extern char **environ;
 #elif defined(unix) || defined(__unix) || defined(__unix__)
@@ -34,7 +34,7 @@ std::string Environment::OSVersion() {
 namespace CppCommon {
 
 std::string Environment::OSVersion() {
-#if defined(__APPLE__)
+#if defined(__APPLE__) || defined(__FreeBSD__)
     char result[1024];
     size_t size = sizeof(result);
     if (sysctlbyname("kern.osrelease", result, &size, nullptr, 0) == 0)
