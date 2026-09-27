--- pxr/base/arch/defines.h.orig	2026-04-24 18:55:54 UTC
+++ pxr/base/arch/defines.h
@@ -14,6 +14,8 @@
 #define ARCH_OS_WASM_VM
 #elif defined(__linux__)
 #define ARCH_OS_LINUX
+#elif defined(__FreeBSD__)
+#define ARCH_OS_FREEBSD
 #elif defined(__APPLE__)
 #include "TargetConditionals.h"
 #define ARCH_OS_DARWIN
@@ -79,8 +81,9 @@
 // Features
 //
 
-// Only use the GNU STL extensions on Linux when using gcc.
-#if defined(ARCH_OS_LINUX) && defined(ARCH_COMPILER_GCC)
+// Only use the GNU STL extensions on Linux and FreeBSD when using gcc.
+#if (defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD)) && \
+    defined(ARCH_COMPILER_GCC)
 #define ARCH_HAS_GNU_STL_EXTENSIONS
 #endif
 
