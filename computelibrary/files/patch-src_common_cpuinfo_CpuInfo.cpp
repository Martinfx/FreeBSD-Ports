--- src/common/cpuinfo/CpuInfo.cpp.orig	2026-03-29 06:31:24 UTC
+++ src/common/cpuinfo/CpuInfo.cpp
@@ -57,7 +57,7 @@
     !defined(__QNX__) && (defined(__arm__) || defined(__aarch64__))
 #include <asm/hwcap.h> /* Get HWCAP bits from asm/hwcap.h */
 #include <sys/auxv.h>
-#elif (defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__APPLE__)) && defined(__aarch64__)
+#elif (defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__APPLE__)) && defined(__aarch64__) || defined(__amd64__)
 #include <sys/sysctl.h>
 #include <sys/types.h>
 #endif /* defined(__APPLE__) && defined(__aarch64__)) */
