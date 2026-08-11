--- physx/source/foundation/include/unix/PsUnixIntrinsics.h.orig	2024-07-05 09:38:49 UTC
+++ physx/source/foundation/include/unix/PsUnixIntrinsics.h
@@ -45,7 +45,7 @@
 // this file is for internal intrinsics - that is, intrinsics that are used in
 // cross platform code but do not appear in the API
 
-#if !(PX_LINUX || PX_ANDROID || PX_PS4 || PX_APPLE_FAMILY)
+#if !(PX_LINUX || PX_ANDROID || PX_PS4 || PX_APPLE_FAMILY || PX_FREEBSD)
 #error "This file should only be included by unix builds!!"
 #endif
 
