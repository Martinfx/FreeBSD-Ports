--- src/common/cpuinfo/CpuInfo.cpp.orig	2023-02-16 15:41:23 UTC
+++ src/common/cpuinfo/CpuInfo.cpp
@@ -44,14 +44,14 @@
 #endif /* !defined(BARE_METAL) */
 
 #if !defined(_WIN64)
-#if !defined(BARE_METAL) && !defined(__APPLE__) && !defined(__OpenBSD__) && (defined(__arm__) || defined(__aarch64__))
+#if !defined(BARE_METAL) && !defined(__APPLE__) && !defined(__OpenBSD__) && !defined(__FreeBSD__) && (defined(__arm__) || defined(__aarch64__))
 #include <asm/hwcap.h> /* Get HWCAP bits from asm/hwcap.h */
 #include <sys/auxv.h>
 #elif defined(__APPLE__) && defined(__aarch64__)
 #include <sys/sysctl.h>
 #include <sys/types.h>
 #endif /* defined(__APPLE__) && defined(__aarch64__)) */
-#endif /* !defined(BARE_METAL) && !defined(__APPLE__) && !defined(__OpenBSD__) && (defined(__arm__) || defined(__aarch64__)) */
+#endif /* !defined(BARE_METAL) && !defined(__APPLE__) && !defined(__OpenBSD__) && !defined(__FreeBSD__) && (defined(__arm__) || defined(__aarch64__)) */
 
 #define ARM_COMPUTE_CPU_FEATURE_HWCAP_CPUID (1 << 11)
 #define ARM_COMPUTE_GET_FEATURE_REG(var, freg) __asm __volatile("MRS %0, " #freg \
@@ -62,7 +62,7 @@ namespace cpuinfo
 {
 namespace
 {
-#if !defined(_WIN64) && !defined(BARE_METAL) && !defined(__APPLE__) && !defined(__OpenBSD__) && (defined(__arm__) || defined(__aarch64__))
+#if !defined(_WIN64) && !defined(BARE_METAL) && !defined(__APPLE__) && !defined(__OpenBSD__) && !defined(__FreeBSD__) && (defined(__arm__) || defined(__aarch64__))
 /** Extract MIDR using CPUID information that are exposed to user-space
  *
  * @param[in] max_num_cpus Maximum number of possible CPUs
@@ -278,7 +278,7 @@ int get_hw_capability(const std::string &cap)
     sysctlbyname(cap.c_str(), &result, &size, NULL, 0);
     return result;
 }
-#endif                                           /* !defined(BARE_METAL) && !defined(__APPLE__) && !defined(__OpenBSD__) && (defined(__arm__) || defined(__aarch64__)) */
+#endif                                           /* !defined(BARE_METAL) && !defined(__APPLE__) && !defined(__OpenBSD__) && !defined(__FreeBSD__) && (defined(__arm__) || defined(__aarch64__)) */
 
 #if defined(BARE_METAL) && defined(__aarch64__)
 uint64_t get_sve_feature_reg()
@@ -302,7 +302,7 @@ CpuInfo::CpuInfo(CpuIsaInfo isa, std::vector<CpuModel>
 
 CpuInfo CpuInfo::build()
 {
-#if !defined(_WIN64) && !defined(BARE_METAL) && !defined(__APPLE__) && !defined(__OpenBSD__) && (defined(__arm__) || defined(__aarch64__))
+#if !defined(_WIN64) && !defined(BARE_METAL) && !defined(__APPLE__) && !defined(__OpenBSD__) && !defined(__FreeBSD__) && (defined(__arm__) || defined(__aarch64__))
     const uint32_t hwcaps   = getauxval(AT_HWCAP);
     const uint32_t hwcaps2  = getauxval(AT_HWCAP2);
     const uint32_t max_cpus = get_max_cpus();
@@ -333,7 +333,7 @@ CpuInfo CpuInfo::build()
     CpuInfo info(isa, cpus_model);
     return info;
 
-#elif(BARE_METAL) && defined(__aarch64__)        /* !defined(BARE_METAL) && !defined(__APPLE__) && !defined(__OpenBSD__) && (defined(__arm__) || defined(__aarch64__)) */
+#elif(BARE_METAL) && defined(__aarch64__)        /* !defined(BARE_METAL) && !defined(__APPLE__) && !defined(__OpenBSD__) && !defined(__FreeBSD__) && (defined(__arm__) || defined(__aarch64__)) */
 
     // Assume single CPU in bare metal mode.  Just read the ID register and feature bits directly.
     uint64_t isar0 = 0, isar1 = 0, pfr0 = 0, pfr1 = 0, svefr0 = 0, midr = 0;
@@ -363,7 +363,7 @@ CpuInfo CpuInfo::build()
 #else                                            /* #elif defined(__aarch64__) && defined(__APPLE__) */
     CpuInfo info(CpuIsaInfo(), { CpuModel::GENERIC });
     return info;
-#endif                                           /* !defined(BARE_METAL) && !defined(__APPLE__) && !defined(__OpenBSD__) && (defined(__arm__) || defined(__aarch64__)) */
+#endif                                           /* !defined(BARE_METAL) && !defined(__APPLE__) && !defined(__OpenBSD__) && !defined(__FreeBSD__)  && (defined(__arm__) || defined(__aarch64__)) */
 }
 
 CpuModel CpuInfo::cpu_model(uint32_t cpuid) const
@@ -377,11 +377,11 @@ CpuModel CpuInfo::cpu_model(uint32_t cpuid) const
 
 CpuModel CpuInfo::cpu_model() const
 {
-#if defined(_WIN64) || defined(BARE_METAL) || defined(__APPLE__) || defined(__OpenBSD__) || (!defined(__arm__) && !defined(__aarch64__))
+#if defined(_WIN64) || defined(BARE_METAL) || defined(__APPLE__) || defined(__OpenBSD__) || defined(__FreeBSD__) || (!defined(__arm__) && !defined(__aarch64__))
     return cpu_model(0);
-#else  /* defined(BARE_METAL) || defined(__APPLE__) || defined(__OpenBSD__) || (!defined(__arm__) && !defined(__aarch64__)) */
+#else  /* defined(BARE_METAL) || defined(__APPLE__) || defined(__OpenBSD__) || defined(__FreeBSD__) || (!defined(__arm__) && !defined(__aarch64__)) */
     return cpu_model(sched_getcpu());
-#endif /* defined(BARE_METAL) || defined(__APPLE__) || defined(__OpenBSD__) || (!defined(__arm__) && !defined(__aarch64__)) */
+#endif /* defined(BARE_METAL) || defined(__APPLE__) || defined(__OpenBSD__) || defined(__FreeBSD__) || (!defined(__arm__) && !defined(__aarch64__)) */
 }
 
 uint32_t CpuInfo::num_cpus() const
