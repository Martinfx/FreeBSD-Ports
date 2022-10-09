--- maxutils/maxbase/src/stacktrace.cc.orig	2022-09-12 06:23:56 UTC
+++ maxutils/maxbase/src/stacktrace.cc
@@ -19,7 +19,9 @@
 #include <cstdarg>
 #include <climits>
 
+#ifdef __linux__
 #include <sys/prctl.h>
+#endif
 
 #ifdef HAVE_GLIBC
 #include <execinfo.h>
@@ -236,6 +238,7 @@ void emergency_stacktrace(void (* handler)(const char*
 
 #endif
 
+#ifdef __linux__
 void dump_gdb_stacktrace(void (* handler)(const char*))
 {
     prctl(PR_SET_PTRACER, PR_SET_PTRACER_ANY);
@@ -245,6 +248,12 @@ void dump_gdb_stacktrace(void (* handler)(const char*)
         getpid());
     prctl(PR_SET_PTRACER, 0);
 }
+#else
+void dump_gdb_stacktrace(void (* handler)(const char*))
+{
+      // we can not use prctl on FreeBSD
+}
+#endif
 
 bool have_gdb()
 {
