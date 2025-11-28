--- src/core/NEON/kernels/arm_gemm/interleave-8way.cpp.orig	2025-11-26 08:35:44 UTC
+++ src/core/NEON/kernels/arm_gemm/interleave-8way.cpp
@@ -25,9 +25,9 @@
 
 #include <arm_neon.h>
 
-#if !defined(_WIN64) && !defined(__OpenBSD__)
+#if !defined(_WIN64) && !defined(__OpenBSD__) && !defined(__FreeBSD__)
 #include <alloca.h>
-#endif /* !defined(_WIN64) && !defined(__OpenBSD__) */
+#endif /* !defined(_WIN64) && !defined(__OpenBSD__) && !defined(__FreeBSD__) */
 
 #include <cstring>
 
