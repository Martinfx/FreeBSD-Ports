--- src/xenia/base/debugging_posix.cc.orig	2024-05-25 13:31:50 UTC
+++ src/xenia/base/debugging_posix.cc
@@ -15,17 +15,46 @@
 #include <iostream>
 #include <mutex>
 #include <sstream>
-
+#include <string>
 #include "xenia/base/string_buffer.h"
 
+#if defined(__FreeBSD__)
+#include <sys/types.h>
+#include <sys/user.h>
+#include <sys/sysctl.h>
+#include <unistd.h>
+#endif
+
 namespace xe {
 namespace debugging {
 
 bool IsDebuggerAttached() {
+#if defined(__linux__)
   std::ifstream proc_status_stream("/proc/self/status");
   if (!proc_status_stream.is_open()) {
     return false;
   }
+#elif defined(__FreeBSD__)
+  int mib[4];
+  size_t length;
+  struct kinfo_proc info;
+  mib[0] = CTL_KERN;
+  mib[1] = KERN_PROC;
+  mib[2] = KERN_PROC_PID;
+  mib[3] = getpid();
+
+  if (sysctl(mib, 4, &info, &length, nullptr, 0) == -1) {
+    return false;
+  }
+
+  std::ostringstream stream;
+  stream << "TracerPid: " << ((info.ki_flag & P_TRACED) ? 1 : 0);
+  std::string proc_status_string = stream.str();
+  std::istringstream proc_status_stream(proc_status_string);
+#else
+#error "Unsupported platform"
+#endif
+
   std::string line;
   while (std::getline(proc_status_stream, line)) {
     std::istringstream line_stream(line);
