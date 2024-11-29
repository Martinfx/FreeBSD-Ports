--- src/core/NEON/kernels/arm_gemm/interleave_indirect.cpp.orig	2022-10-17 14:40:08 UTC
+++ src/core/NEON/kernels/arm_gemm/interleave_indirect.cpp
@@ -28,9 +28,9 @@
 #include "interleave_indirect.hpp"
 #include "bfloat.hpp"
 
-#if !defined(_WIN64) && !defined(__OpenBSD__)
+#if !defined(_WIN64) && !defined(__OpenBSD__) && !defined(__FreeBSD__)
 #include <alloca.h>
-#endif /* !defined(_WIN64) && !defined(__OpenBSD__) */
+#endif /* !defined(_WIN64) && !defined(__OpenBSD__) && !defined(__FreeBSD__) */
 
 #include <algorithm>
 #include <cstddef>
