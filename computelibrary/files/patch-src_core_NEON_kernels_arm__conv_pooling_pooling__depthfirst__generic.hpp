--- src/core/NEON/kernels/arm_conv/pooling/pooling_depthfirst_generic.hpp.orig	2025-07-01 09:33:23 UTC
+++ src/core/NEON/kernels/arm_conv/pooling/pooling_depthfirst_generic.hpp
@@ -26,9 +26,9 @@
 
 #include "depthfirst_driver.hpp"
 #include "utils.hpp"
-#if !defined(_WIN64) && !defined(__OpenBSD__)
+#if !defined(_WIN64) && !defined(__OpenBSD__) && !defined(__FreeBSD__)
 #include <alloca.h>
-#endif /* !defined(_WIN64) && !defined(__OpenBSD__) */
+#endif /* !defined(_WIN64) && !defined(__OpenBSD__) && !defined(FreeBSD) */
 
 namespace arm_conv {
 namespace pooling {
