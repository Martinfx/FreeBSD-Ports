--- pxr/base/arch/timing.h.orig	2025-02-04 21:22:17 UTC
+++ pxr/base/arch/timing.h
@@ -19,7 +19,7 @@
 /// \addtogroup group_arch_SystemFunctions
 ///@{
 
-#if defined(ARCH_OS_LINUX) && defined(ARCH_CPU_INTEL)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD) || defined(ARCH_OS_FREEBSD) && defined(ARCH_CPU_INTEL)
 #include <x86intrin.h>
 #elif defined(ARCH_OS_DARWIN)
 #include <mach/mach_time.h>
