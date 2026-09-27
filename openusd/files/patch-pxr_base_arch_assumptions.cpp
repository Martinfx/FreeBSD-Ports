--- pxr/base/arch/assumptions.cpp.orig	2026-04-24 18:55:54 UTC
+++ pxr/base/arch/assumptions.cpp
@@ -20,6 +20,8 @@
 
 #if defined(ARCH_OS_LINUX)
 #include <unistd.h>
+#elif defined(ARCH_OS_FREEBSD)
+#include <sys/param.h>
 #elif defined(ARCH_OS_DARWIN)
 #include <sys/sysctl.h>
 #include <mach-o/arch.h>
@@ -35,6 +37,18 @@ Arch_ObtainCacheLineSize()
 {
 #if defined(ARCH_OS_LINUX)
     return sysconf(_SC_LEVEL1_DCACHE_LINESIZE);
+#elif defined(ARCH_OS_FREEBSD)
+#if defined(__aarch64__)
+    // CACHE_LINE_SIZE is only an upper bound (128) on arm64, so query the
+    // hardware instead.  CTR_EL0.DminLine is log2 of the number of 4-byte
+    // words in the smallest data cache line; FreeBSD allows (or emulates)
+    // reading CTR_EL0 from userland.
+    uint64_t ctr;
+    __asm__ __volatile__("mrs %0, ctr_el0" : "=r"(ctr));
+    return size_t(4) << ((ctr >> 16) & 0xf);
+#else
+    return CACHE_LINE_SIZE;
+#endif
 #elif defined(ARCH_OS_WASM_VM)
     return 64;
 #elif defined(ARCH_OS_DARWIN)
