--- pxr/base/arch/fileSystem.h.orig	2025-10-24 16:21:56 UTC
+++ pxr/base/arch/fileSystem.h
@@ -24,9 +24,8 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 
-#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_WASM_VM)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_WASM_VM) || defined(ARCH_OS_FREEBSD)
 #include <unistd.h>
-#include <sys/statfs.h>
 #include <glob.h>
 #elif defined(ARCH_OS_DARWIN)
 #include <unistd.h>
