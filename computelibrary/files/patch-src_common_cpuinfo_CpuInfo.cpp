--- src/common/cpuinfo/CpuInfo.cpp.orig	2025-07-01 09:33:23 UTC
+++ src/common/cpuinfo/CpuInfo.cpp
@@ -70,7 +70,7 @@ namespace
 {
 namespace
 {
-#if !defined(_WIN64) && !defined(BARE_METAL) && !defined(__APPLE__) && !defined(__OpenBSD__) && !defined(__QNX__) && \
+#if !defined(_WIN64) && !defined(BARE_METAL) && !defined(__APPLE__) && !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__QNX__) && \
     (defined(__arm__) || defined(__aarch64__))
 /** Extract MIDR using CPUID information that are exposed to user-space
  *
@@ -352,7 +352,7 @@ CpuInfo CpuInfo::build()
 
 CpuInfo CpuInfo::build()
 {
-#if !defined(_WIN64) && !defined(BARE_METAL) && !defined(__APPLE__) && !defined(__OpenBSD__) && !defined(__QNX__) && \
+#if !defined(_WIN64) && !defined(BARE_METAL) && !defined(__APPLE__) && !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__QNX__) && \
     (defined(__arm__) || defined(__aarch64__))
     const uint32_t hwcaps   = getauxval(AT_HWCAP);
     const uint32_t hwcaps2  = getauxval(AT_HWCAP2);
@@ -383,7 +383,7 @@ CpuInfo CpuInfo::build()
 
     CpuInfo info(isa, cpus_model);
     return info;
-#elif defined(__OpenBSD__)
+#elif defined(__OpenBSD__) || defined(__FreeBSD__) 
     int    mib[2] = {0, 0};
     int    ncpu   = {1};
     size_t len    = sizeof(ncpu);
@@ -466,7 +466,7 @@ CpuModel CpuInfo::cpu_model() const
 
 CpuModel CpuInfo::cpu_model() const
 {
-#if defined(_WIN64) || defined(BARE_METAL) || defined(__APPLE__) || defined(__OpenBSD__) || defined(__QNX__) || \
+#if defined(_WIN64) || defined(BARE_METAL) || defined(__APPLE__) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__QNX__) || \
     (!defined(__arm__) && !defined(__aarch64__))
     return cpu_model(0);
 #else /* defined(BARE_METAL) || defined(__APPLE__) || defined(__OpenBSD__) || defined(__QNX__) || (!defined(__arm__) && !defined(__aarch64__)) */
