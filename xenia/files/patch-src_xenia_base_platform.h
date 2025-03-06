--- src/xenia/base/platform.h.orig	2025-03-06 13:17:31 UTC
+++ src/xenia/base/platform.h
@@ -37,6 +37,8 @@
 #elif defined(__gnu_linux__)
 #define XE_PLATFORM_GNU_LINUX 1
 #define XE_PLATFORM_LINUX 1
+#elif defined(__FreeBSD__)
+#define XE_PLATFORM_FREEBSD 1
 #else
 #error Unsupported target OS.
 #endif
