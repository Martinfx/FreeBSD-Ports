--- third_party/renderman-26/plugin/rmanArgsParser/pch.h.orig	2025-03-05 13:58:33 UTC
+++ third_party/renderman-26/plugin/rmanArgsParser/pch.h
@@ -13,7 +13,7 @@
 #if defined(ARCH_OS_DARWIN)
 #include <mach/mach_time.h>
 #endif
-#if defined(ARCH_OS_LINUX)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD)
 #include <x86intrin.h>
 #endif
 #if defined(ARCH_OS_WINDOWS)
