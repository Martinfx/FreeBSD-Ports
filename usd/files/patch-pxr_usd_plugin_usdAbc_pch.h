--- pxr/usd/plugin/usdAbc/pch.h.orig	2025-03-05 13:52:21 UTC
+++ pxr/usd/plugin/usdAbc/pch.h
@@ -18,11 +18,10 @@
 #include <unistd.h>
 #include <mach/mach_time.h>
 #endif
-#if defined(ARCH_OS_LINUX)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD)
 #include <glob.h>
 #include <limits.h>
 #include <sys/param.h>
-#include <sys/statfs.h>
 #include <unistd.h>
 #include <x86intrin.h>
 #endif
