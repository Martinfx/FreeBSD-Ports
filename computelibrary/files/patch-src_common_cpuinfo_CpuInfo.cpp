--- src/common/cpuinfo/CpuInfo.cpp.orig	2026-03-18 08:43:09 UTC
+++ src/common/cpuinfo/CpuInfo.cpp
@@ -57,11 +57,16 @@
     !defined(__QNX__) && (defined(__arm__) || defined(__aarch64__))
 #include <asm/hwcap.h> /* Get HWCAP bits from asm/hwcap.h */
 #include <sys/auxv.h>
-#elif (defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__APPLE__)) && defined(__aarch64__)
+#elif (defined(__APPLE__)) && defined(__aarch64__)
 #include <sys/sysctl.h>
 #include <sys/types.h>
-#endif /* defined(__APPLE__) && defined(__aarch64__)) */
-#endif /* !defined(BARE_METAL) && !defined(__APPLE__) && !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__QNX__) && (defined(__arm__) || defined(__aarch64__)) */
+#elif (defined(__OpenBSD__) || defined(__FreeBSD__))
+#include <sys/auxv.h>
+#include <sys/sysctl.h>
+#include <sys/types.h>
+#include <unistd.h>
+#endif /* #elif (defined(OpenBSD) || defined(FreeBSD)) && defined(aarch64) */
+#endif /* #elif (defined(__APPLE__)) && defined(__aarch64__) */
 
 #define ARM_COMPUTE_CPU_FEATURE_HWCAP_CPUID    (1 << 11)
 #define ARM_COMPUTE_GET_FEATURE_REG(var, freg) __asm __volatile("MRS %0, " #freg : "=r"(var))
@@ -435,8 +440,32 @@ CpuInfo CpuInfo::build()
     std::vector<CpuModel> cpus_model(1, midr_to_model(midr));
     CpuInfo               info(isa, cpus_model);
     return info;
-#elif defined(__aarch64__) && (defined(__OpenBSD__) || defined(__FreeBSD__) || \
-                               defined(__APPLE__)) /* #elif(BARE_METAL) && defined(__aarch64__) */
+
+#elif defined(__aarch64__) && (defined(__OpenBSD__) || defined(__FreeBSD__))
+    int ncpus = sysconf(_SC_NPROCESSORS_ONLN);
+
+    unsigned long hwcap = 0, hwcap2 = 0;
+    elf_aux_info(AT_HWCAP, &hwcap, sizeof(hwcap));
+    elf_aux_info(AT_HWCAP2, &hwcap2, sizeof(hwcap2));
+
+    CpuIsaInfo            isainfo;
+    std::vector<CpuModel> cpus_model(ncpus);
+
+    isainfo.neon       = (hwcap & HWCAP_ASIMD) != 0;
+    isainfo.fp16       = (hwcap & HWCAP_FPHP) != 0;
+    isainfo.dot        = (hwcap & HWCAP_ASIMDDP) != 0;
+    isainfo.bf16       = (hwcap2 & HWCAP2_BF16) != 0;
+    isainfo.i8mm       = (hwcap2 & HWCAP2_I8MM) != 0;
+    isainfo.sme        = (hwcap2 & HWCAP2_SME) != 0;
+    isainfo.sme2       = (hwcap2 & HWCAP2_SME2) != 0;
+    isainfo.sme_f32f32 = (hwcap2 & HWCAP2_SME_F32F32) != 0;
+    isainfo.sme_i8i32  = (hwcap2 & HWCAP2_SME_I8I32) != 0;
+    isainfo.sme_f16f32 = (hwcap2 & HWCAP2_SME_F16F32) != 0;
+    isainfo.sme_b16f32 = (hwcap2 & HWCAP2_SME_B16F32) != 0;
+    CpuInfo info(isainfo, cpus_model);
+    return info;
+
+#elif defined(__aarch64__) && defined(__APPLE__) /* #elif defined(__aarch64__) && (defined(__OpenBSD__) || defined(__FreeBSD__)) */
     int                   ncpus = get_hw_capability("hw.perflevel0.logicalcpu");
     CpuIsaInfo            isainfo;
     std::vector<CpuModel> cpus_model(ncpus);
@@ -453,7 +482,7 @@ CpuInfo CpuInfo::build()
     isainfo.sme2       = get_hw_capability("hw.optional.arm.FEAT_SME2");
     CpuInfo info(isainfo, cpus_model);
     return info;
-#elif defined(__aarch64__) && defined(_WIN64)      /* #elif defined(__aarch64__) && defined(__APPLE__) */
+#elif defined(__aarch64__) && defined(_WIN64) /* #elif defined(__aarch64__) && defined(__APPLE__) */
     CpuIsaInfo isainfo;
 
     isainfo.neon = IsProcessorFeaturePresent(PF_ARM_NEON_INSTRUCTIONS_AVAILABLE);
@@ -485,7 +514,7 @@ CpuInfo CpuInfo::build()
     std::vector<CpuModel> cpus_model(ncpus);
     CpuInfo               info(isainfo, cpus_model);
     return info;
-#else                                              /* #elif defined(__aarch64__) && defined(_WIN64) */
+#else                                         /* #elif defined(__aarch64__) && defined(_WIN64) */
     CpuInfo info(CpuIsaInfo(), {CpuModel::GENERIC});
     return info;
 #endif /* !defined(BARE_METAL) && !defined(__APPLE__) && !defined(__OpenBSD__) && (defined(__arm__) || defined(__aarch64__)) */
