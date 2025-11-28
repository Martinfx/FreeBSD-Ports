--- src/core/NEON/kernels/arm_gemm/transform-bf16.cpp.orig	2025-11-26 08:40:05 UTC
+++ src/core/NEON/kernels/arm_gemm/transform-bf16.cpp
@@ -26,9 +26,9 @@
 #include "src/core/NEON/wrapper/intrinsics/intrinsics.h"
 #include "bfloat.hpp"
 
-#if !defined(_WIN64) && !defined(__OpenBSD__)
+#if !defined(_WIN64) && !defined(__OpenBSD__) && !defined(__FreeBSD__)
 #include <alloca.h>
-#endif /* !defined(_WIN64) && !defined(__OpenBSD__) */
+#endif /* !defined(_WIN64) && !defined(__OpenBSD__) && !defined(__FreeBSD__) */
 
 namespace arm_gemm {
 
