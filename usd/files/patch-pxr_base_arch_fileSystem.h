--- pxr/base/arch/fileSystem.h.orig	2025-02-04 21:22:17 UTC
+++ pxr/base/arch/fileSystem.h
@@ -24,9 +24,8 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 
-#if defined(ARCH_OS_LINUX)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD) || defined(ARCH_OS_FREEBSD)
 #include <unistd.h>
-#include <sys/statfs.h>
 #include <glob.h>
 #elif defined(ARCH_OS_DARWIN)
 #include <unistd.h>
