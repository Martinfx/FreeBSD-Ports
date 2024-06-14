--- src/core/NEON/kernels/arm_gemm/gemm_hybrid_indirect.hpp.orig	2022-10-17 14:18:51 UTC
+++ src/core/NEON/kernels/arm_gemm/gemm_hybrid_indirect.hpp
@@ -23,9 +23,9 @@
  */
 #pragma once
 
-#if !defined(_WIN64) && !defined(__OpenBSD__)
+#if !defined(_WIN64) && !defined(__OpenBSD__) && !defined(__FreeBSD__)
 #include <alloca.h>
-#endif /* !defined(_WIN64) && !defined(__OpenBSD__) */
+#endif /* !defined(_WIN64) && !defined(__OpenBSD__) && !defined(__FreeBSD__) */
 
 #include <algorithm>
 #include <cassert>
