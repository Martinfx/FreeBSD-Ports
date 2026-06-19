--- pxshared/include/foundation/PxIntrinsics.h.orig	2024-07-05 10:01:14 UTC
+++ pxshared/include/foundation/PxIntrinsics.h
@@ -34,7 +34,7 @@
 
 #if PX_WINDOWS_FAMILY
 #include "foundation/windows/PxWindowsIntrinsics.h"
-#elif(PX_LINUX || PX_ANDROID || PX_APPLE_FAMILY || PX_PS4)
+#elif(PX_LINUX || PX_ANDROID || PX_APPLE_FAMILY || PX_PS4 || PX_FREEBSD)
 #include "foundation/unix/PxUnixIntrinsics.h"
 #elif PX_XBOXONE
 #include "foundation/XboxOne/PxXboxOneIntrinsics.h"
