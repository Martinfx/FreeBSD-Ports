--- src/core/NEON/kernels/arm_gemm/transform.cpp.orig	2022-10-17 14:20:58 UTC
+++ src/core/NEON/kernels/arm_gemm/transform.cpp
@@ -25,9 +25,9 @@
 
 #include "bfloat.hpp"
 
-#if !defined(_WIN64) && !defined(__OpenBSD__)
+#if !defined(_WIN64) && !defined(__OpenBSD__) && !defined(__FreeBSD__)
 #include <alloca.h>
-#endif /* !defined(_WIN64) && !defined(__OpenBSD__) */
+#endif /* !defined(_WIN64) && !defined(__OpenBSD__) && !defined(__FreeBSD__) */
 
 namespace arm_gemm {
 
