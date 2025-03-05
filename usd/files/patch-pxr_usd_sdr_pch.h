--- pxr/usd/sdr/pch.h.orig	2025-03-05 13:53:34 UTC
+++ pxr/usd/sdr/pch.h
@@ -13,7 +13,7 @@
 #if defined(ARCH_OS_DARWIN)
 #include <mach/mach_time.h>
 #endif
-#if defined(ARCH_OS_LINUX)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD)
 #include <unistd.h>
 #include <x86intrin.h>
 #endif
