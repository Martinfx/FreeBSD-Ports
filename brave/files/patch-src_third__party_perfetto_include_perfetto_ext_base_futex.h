--- src/third_party/perfetto/include/perfetto/ext/base/futex.h.orig	2026-11-02 23:22:33 UTC
+++ src/third_party/perfetto/include/perfetto/ext/base/futex.h
@@ -24,8 +24,9 @@
 // Whether this build implements FutexWait() and FutexWake(). It does not check
 // runtime restrictions, such as a sandbox that blocks the system call.
 // TODO(rsavitski): Add support for other platforms.
-#define PERFETTO_HAS_FUTEX()                            \
-  (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) || \
+#define PERFETTO_HAS_FUTEX()                             \
+  ((PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)) ||         \
    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID))
 
 namespace perfetto::base {
