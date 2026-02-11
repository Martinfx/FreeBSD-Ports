--- test/common/cpu_info.cpp.orig	2026-02-03 14:10:32 UTC
+++ test/common/cpu_info.cpp
@@ -13,16 +13,16 @@
 
 #include "kai/kai_common.h"
 
-#if defined(__aarch64__) && defined(__linux__)
+#if defined(__aarch64__) && defined(__FreeBSD__)
 #include <sys/auxv.h>
-#endif  // defined(__aarch64__) && defined(__linux__)
+#endif  // defined(__aarch64__) && defined(__FreeBSD__)
 
-#if defined(__aarch64__) && defined(__APPLE__)
+#if defined(__aarch64__) && defined(__FreeBSD__)
 #include <sys/sysctl.h>
 #include <sys/types.h>
 
 #include <string_view>
-#endif  // defined(__aarch64__) && defined(__APPLE__)
+#endif  // defined(__aarch64__) && defined(__FreeBSD__)
 
 #if (defined(__aarch64__) && defined(_WIN64)) || defined(_M_ARM64)
 #include <Windows.h>
@@ -48,7 +48,7 @@ enum CpuFeatures {
     LAST_ELEMENT  // This should be last element, please add new CPU capabilities before it
 };
 
-#if defined(__aarch64__) && defined(__linux__)
+#if defined(__aarch64__) && defined(__FreeBSD__)
 /// Define CPU capabilities not available in toolchain definitions
 #ifndef HWCAP_ASIMD
 constexpr uint64_t HWCAP_ASIMD = 1UL << 1;
@@ -100,7 +100,10 @@ bool get_cap_support(CpuFeatures feature) {
     // Make sure CPU feature is correctly initialized
     KAI_ASSERT_ALWAYS(feature == cpu_feature);
 
-    const uint64_t hwcaps = getauxval(cap_id);
+    unsigned long  hwcaps = 0;
+    if (elf_aux_info(cap_id, &hwcaps, sizeof(hwcaps)) != 0) {
+       return false;
+    }
 
     return (hwcaps & cap_bits) == cap_bits;
 }
