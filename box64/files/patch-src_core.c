--- src/core.c.orig	2025-04-11 14:34:57 UTC
+++ src/core.c
@@ -11,7 +11,12 @@
 #include <sys/syscall.h>
 #include <sys/mman.h>
 #include <pthread.h>
+#if __FreeBSD__
+#include <sys/procctl.h>
+#include <unistd.h>
+#else
 #include <sys/prctl.h>
+#endif
 #include <stdarg.h>
 #ifdef DYNAREC
 #ifdef ARM64
@@ -1415,10 +1420,17 @@ int initialize(int argc, const char **argv, char** env
             ++p;
         else
             p = my_context->fullpath;
-        if(prctl(PR_SET_NAME, p)==-1)
-            printf_log(LOG_NONE, "Error setting process name (%s)\n", strerror(errno));
-        else
-            printf_log(LOG_INFO, "Rename process to \"%s\"\n", p);
+
+#if __FreeBSD__
+    setproctitle("process name %s", p);
+    printf_log(LOG_INFO, "Rename process to \"%s\"\n", p);
+#else
+    if (prctl(PR_SET_NAME, p) == -1) {
+        printf_log(LOG_NONE, "Error setting process name (%s)\n", strerror(errno));
+    } else {
+        printf_log(LOG_INFO, "Rename process to \"%s\"\n", p);
+    }
+#endif
         if (strcmp(box64_guest_name, p)) {
             ApplyEnvFileEntry(p);
         }
