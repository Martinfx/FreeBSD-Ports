--- src/common/cpuinfo/CpuInfo.cpp.orig	2025-07-01 09:33:23 UTC
+++ src/common/cpuinfo/CpuInfo.cpp
@@ -31,6 +31,8 @@
 
 #include <map>
 #include <sstream>
+#include <sys/types.h>
+#include <sys/sysctl.h>
 
 #if !defined(BARE_METAL)
 #include <algorithm>
@@ -70,7 +72,7 @@ namespace
 {
 namespace
 {
-#if !defined(_WIN64) && !defined(BARE_METAL) && !defined(__APPLE__) && !defined(__OpenBSD__) && !defined(__QNX__) && \
+#if !defined(_WIN64) && !defined(BARE_METAL) && !defined(__APPLE__) && !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__QNX__) && \
     (defined(__arm__) || defined(__aarch64__))
 /** Extract MIDR using CPUID information that are exposed to user-space
  *
@@ -352,7 +354,7 @@ CpuInfo CpuInfo::build()
 
 CpuInfo CpuInfo::build()
 {
-#if !defined(_WIN64) && !defined(BARE_METAL) && !defined(__APPLE__) && !defined(__OpenBSD__) && !defined(__QNX__) && \
+#if !defined(_WIN64) && !defined(BARE_METAL) && !defined(__APPLE__) && !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__QNX__) && \
     (defined(__arm__) || defined(__aarch64__))
     const uint32_t hwcaps   = getauxval(AT_HWCAP);
     const uint32_t hwcaps2  = getauxval(AT_HWCAP2);
@@ -383,7 +385,7 @@ CpuInfo CpuInfo::build()
 
     CpuInfo info(isa, cpus_model);
     return info;
-#elif defined(__OpenBSD__)
+#elif defined(__OpenBSD__) || defined(__FreeBSD__)
     int    mib[2] = {0, 0};
     int    ncpu   = {1};
     size_t len    = sizeof(ncpu);
@@ -420,7 +422,7 @@ CpuInfo CpuInfo::build()
     CpuInfo               info(isa, cpus_model);
     return info;
 #elif defined(__aarch64__) && \
-    (defined(__OpenBSD__) || defined(__APPLE__)) /* #elif(BARE_METAL) && defined(__aarch64__) */
+    (defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__APPLE__)) /* #elif(BARE_METAL) && defined(__aarch64__) */
     int                   ncpus = get_hw_capability("hw.perflevel0.logicalcpu");
     CpuIsaInfo            isainfo;
     std::vector<CpuModel> cpus_model(ncpus);
@@ -466,7 +468,7 @@ CpuModel CpuInfo::cpu_model() const
 
 CpuModel CpuInfo::cpu_model() const
 {
-#if defined(_WIN64) || defined(BARE_METAL) || defined(__APPLE__) || defined(__OpenBSD__) || defined(__QNX__) || \
+#if defined(_WIN64) || defined(BARE_METAL) || defined(__APPLE__) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__QNX__) || \
     (!defined(__arm__) && !defined(__aarch64__))
     return cpu_model(0);
 #else /* defined(BARE_METAL) || defined(__APPLE__) || defined(__OpenBSD__) || defined(__QNX__) || (!defined(__arm__) && !defined(__aarch64__)) */
