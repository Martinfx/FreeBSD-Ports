--- pxr/base/arch/defines.h.orig	2025-02-04 21:22:17 UTC
+++ pxr/base/arch/defines.h
@@ -13,6 +13,8 @@
 
 #if defined(__linux__)
 #define ARCH_OS_LINUX
+#elif defined(__FreeBSD__)
+#define ARCH_OS_FREEBSD
 #elif defined(__APPLE__)
 #include "TargetConditionals.h"
 #define ARCH_OS_DARWIN
@@ -75,7 +77,7 @@
 //
 
 // Only use the GNU STL extensions on Linux when using gcc.
-#if defined(ARCH_OS_LINUX) && defined(ARCH_COMPILER_GCC)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD) && defined(ARCH_COMPILER_GCC)
 #define ARCH_HAS_GNU_STL_EXTENSIONS
 #endif
 
@@ -86,7 +88,7 @@
 #endif
 
 // The MAP_POPULATE flag for mmap calls only exists on Linux platforms.
-#if defined(ARCH_OS_LINUX)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD)
 #define ARCH_HAS_MMAP_MAP_POPULATE
 #endif
 
