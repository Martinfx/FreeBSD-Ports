--- physx/source/foundation/include/PsTime.h.orig	2024-07-05 09:34:42 UTC
+++ physx/source/foundation/include/PsTime.h
@@ -33,7 +33,7 @@
 #include "Ps.h"
 #include "foundation/PxFoundationConfig.h"
 
-#if PX_LINUX || PX_ANDROID
+#if PX_LINUX || PX_ANDROID || PX_FREEBSD
 #include <time.h>
 #endif
 
@@ -84,7 +84,7 @@ class PX_FOUNDATION_API Time
 	Second getLastTime() const;
 
   private:
-#if PX_LINUX || PX_ANDROID || PX_APPLE_FAMILY || PX_PS4
+#if PX_LINUX || PX_ANDROID || PX_APPLE_FAMILY || PX_PS4 || PX_FREEBSD
 	Second mLastTime;
 #else
 	int64_t mTickCount;
