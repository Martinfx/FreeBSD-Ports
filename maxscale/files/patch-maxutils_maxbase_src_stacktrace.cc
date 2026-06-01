--- maxutils/maxbase/src/stacktrace.cc.orig	2022-09-12 06:23:56 UTC
+++ maxutils/maxbase/src/stacktrace.cc
@@ -19,7 +19,13 @@
 #include <cstdarg>
 #include <climits>
 
+#ifdef __FreeBSD__
+#include <sys/wait.h>  /* For WIF.. */
+#endif
+
+#ifdef __linux__
 #include <sys/prctl.h>
+#endif
 
 #ifdef HAVE_GLIBC
 #include <execinfo.h>
@@ -234,8 +240,16 @@ void emergency_stacktrace(void (* handler)(const char*
     // We can't dump stacktraces on non-GLIBC systems
 }
 
+void emergency_stacktrace()
+{
+/*    void* addrs[128];
+    int count = backtrace(addrs, 128);
+    backtrace_symbols_fd(addrs, count, STDOUT_FILENO); */
+}
+
 #endif
 
+#ifdef __linux__
 void dump_gdb_stacktrace(void (* handler)(const char*))
 {
     prctl(PR_SET_PTRACER, PR_SET_PTRACER_ANY);
@@ -245,6 +259,12 @@ void dump_gdb_stacktrace(void (* handler)(const char*)
         getpid());
     prctl(PR_SET_PTRACER, 0);
 }
+#else
+void dump_gdb_stacktrace(void (* handler)(const char*))
+{
+
+}
+#endif
 
 bool have_gdb()
 {
