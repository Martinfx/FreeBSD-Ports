--- src/xenia/base/platform.h.orig
+++ src/xenia/base/platform.h
@@ -37,6 +37,12 @@
 #elif defined(__gnu_linux__)
 #define XE_PLATFORM_GNU_LINUX 1
 #define XE_PLATFORM_LINUX 1
+#elif defined(__FreeBSD__)
+// FreeBSD shares the X11/GTK desktop code paths with GNU/Linux; the few
+// kernel-specific interfaces are guarded by XE_PLATFORM_FREEBSD.
+#define XE_PLATFORM_FREEBSD 1
+#define XE_PLATFORM_GNU_LINUX 1
+#define XE_PLATFORM_LINUX 1
 #else
 #error Unsupported target OS.
 #endif
