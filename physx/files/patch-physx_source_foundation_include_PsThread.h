--- physx/source/foundation/include/PsThread.h.orig	2024-07-05 09:33:28 UTC
+++ physx/source/foundation/include/PsThread.h
@@ -41,7 +41,7 @@
 
 #if PX_WINDOWS_FAMILY || PX_XBOXONE || PX_XBOX_SERIES_X
 #define PxSpinLockPause() __asm pause
-#elif PX_LINUX || PX_ANDROID || PX_PS4 || PX_APPLE_FAMILY || PX_SWITCH
+#elif PX_LINUX || PX_ANDROID || PX_PS4 || PX_APPLE_FAMILY || PX_SWITCH || PX_FREEBSD
 #define PxSpinLockPause() asm("nop")
 #else
 #error "Platform not supported!"
