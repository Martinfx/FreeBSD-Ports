--- physx/source/foundation/include/PsFPU.h.orig	2024-07-05 09:29:46 UTC
+++ physx/source/foundation/include/PsFPU.h
@@ -79,7 +79,7 @@ PX_FOUNDATION_API void disableFPExceptions();
 
 #if PX_WINDOWS_FAMILY || PX_XBOXONE || PX_XBOX_SERIES_X
 #include "windows/PsWindowsFPU.h"
-#elif (PX_LINUX && PX_SSE2) || PX_PS4 || PX_OSX
+#elif ((PX_LINUX || PX_FREEBSD) && PX_SSE2) || PX_PS4 || PX_OSX
 #include "unix/PsUnixFPU.h"
 #else
 PX_INLINE physx::shdfnd::SIMDGuard::SIMDGuard()
