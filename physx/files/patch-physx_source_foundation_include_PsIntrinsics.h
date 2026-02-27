--- physx/source/foundation/include/PsIntrinsics.h.orig	2024-07-05 09:32:08 UTC
+++ physx/source/foundation/include/PsIntrinsics.h
@@ -34,7 +34,7 @@
 
 #if PX_WINDOWS_FAMILY
 #include "windows/PsWindowsIntrinsics.h"
-#elif(PX_LINUX || PX_ANDROID || PX_APPLE_FAMILY || PX_PS4)
+#elif(PX_LINUX || PX_ANDROID || PX_APPLE_FAMILY || PX_PS4 || PX_FREEBSD)
 #include "unix/PsUnixIntrinsics.h"
 #elif PX_XBOXONE
 #include "XboxOne/PsXboxOneIntrinsics.h"
