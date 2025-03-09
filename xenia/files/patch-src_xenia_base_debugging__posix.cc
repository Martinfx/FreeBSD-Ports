--- src/xenia/base/debugging_posix.cc.orig	2024-05-25 13:31:50 UTC
+++ src/xenia/base/debugging_posix.cc
@@ -22,10 +22,32 @@ bool IsDebuggerAttached() {
 namespace debugging {
 
 bool IsDebuggerAttached() {
+#if defined(__linux__)
   std::ifstream proc_status_stream("/proc/self/status");
   if (!proc_status_stream.is_open()) {
     return false;
   }
+#elif defined(__FreeBSD__)
+  int mib[4];
+  struct kinfo_proc info;
+  size_t size = sizeof(info);
+
+  mib[0] = CTL_KERN;
+  mib[1] = KERN_PROC;
+  mib[2] = KERN_PROC_PID;
+  mib[3] = getpid();
+
+  if (sysctl(mib, 4, &info, &size, nullptr, 0) == -1) {
+    return false;
+  }
+
+  // Simulace čtení "TracerPid" jako v Linuxovém /proc/self/status
+  std::ostringstream proc_status_stream;
+  proc_status_stream << "TracerPid: " << ((info.ki_flag & P_TRACED) ? 1 : 0);
+#else
+#error "Unsupported platform"
+#endif
+
   std::string line;
   while (std::getline(proc_status_stream, line)) {
     std::istringstream line_stream(line);
