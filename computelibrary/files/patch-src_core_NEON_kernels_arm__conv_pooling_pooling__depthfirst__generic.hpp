--- src/core/NEON/kernels/arm_conv/pooling/pooling_depthfirst_generic.hpp.orig	2022-10-17 14:34:43 UTC
+++ src/core/NEON/kernels/arm_conv/pooling/pooling_depthfirst_generic.hpp
@@ -27,9 +27,9 @@
 #include "arm_compute/core/Error.h"
 #include "depthfirst_driver.hpp"
 #include "utils.hpp"
-#if !defined(_WIN64) && !defined(__OpenBSD__)
+#if !defined(_WIN64) && !defined(__OpenBSD__) && !defined(__FreeBSD__)
 #include <alloca.h>
-#endif /* !defined(_WIN64) && !defined(__OpenBSD__) */
+#endif /* !defined(_WIN64) && !defined(__OpenBSD__) && !defined(FreeBSD) */
 
 namespace arm_conv {
 namespace pooling {
