--- pxr/base/tf/diagnosticHelper.h.orig	2026-02-23 22:54:59 UTC
+++ pxr/base/tf/diagnosticHelper.h
@@ -21,7 +21,7 @@
 
 // Follow up changes should more tightly scope these to just where it's needed
 // in pxr.
-#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_DARWIN)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD) || defined(ARCH_OS_DARWIN)
 // Include <unistd.h> to provide _exit for tf/debugger.cpp and dependencies
 // that were previously transitively getting this from boost
 #include <unistd.h>
