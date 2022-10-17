--- src/core/NEON/kernels/arm_conv/pooling/pooling_depthfirst.hpp.orig	2022-10-17 14:31:04 UTC
+++ src/core/NEON/kernels/arm_conv/pooling/pooling_depthfirst.hpp
@@ -27,9 +27,9 @@
 #include "depthfirst_driver.hpp"
 #include "src/core/NEON/kernels/arm_conv/addressing.hpp"
 #include "utils.hpp"
-#if !defined(_WIN64) && !defined(__OpenBSD__)
+#if !defined(_WIN64) && !defined(__OpenBSD__) && !defined(__FreeBSD__)
 #include <alloca.h>
-#endif /* !defined(_WIN64) && !defined(__OpenBSD__) */
+#endif /* !defined(_WIN64) && !defined(__OpenBSD__) && !defined(__FreeBSD__) */
 #include <limits>
 
 namespace arm_conv {
