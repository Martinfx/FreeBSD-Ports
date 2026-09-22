--- pxshared/include/foundation/unix/PxUnixIntrinsics.h.orig	2024-07-05 10:09:10 UTC
+++ pxshared/include/foundation/unix/PxUnixIntrinsics.h
@@ -33,11 +33,11 @@
 #include "foundation/Px.h"
 #include "foundation/PxSharedAssert.h"
 
-#if !(PX_LINUX || PX_ANDROID || PX_PS4 || PX_APPLE_FAMILY)
+#if !(PX_LINUX || PX_ANDROID || PX_PS4 || PX_APPLE_FAMILY || PX_FREEBSD)
 #error "This file should only be included by Unix builds!!"
 #endif
 
-#if (PX_LINUX || PX_ANDROID) && !defined(__CUDACC__) && !PX_EMSCRIPTEN
+#if (PX_LINUX || PX_ANDROID || PX_FREEBSD) && !defined(__CUDACC__) && !PX_EMSCRIPTEN
     // Linux/android and CUDA compilation does not work with std::isfnite, as it is not marked as CUDA callable
     #include <cmath>
     #ifndef isfinite
