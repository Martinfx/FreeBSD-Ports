--- physx/include/PxFoundation.h.orig	2024-07-05 09:07:21 UTC
+++ physx/include/PxFoundation.h
@@ -128,14 +128,14 @@ PxCreateFoundation(physx::PxU32 version, physx::PxAllo
 @see PxCreateFoundation()
 */
 #if PX_CLANG
-#if PX_LINUX
+#if PX_LINUX || PX_FREEBSD
 #pragma clang diagnostic push
 #pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
 #endif // PX_LINUX
 #endif // PX_CLANG
 PX_C_EXPORT PX_FOUNDATION_API physx::PxFoundation& PX_CALL_CONV PxGetFoundation();
 #if PX_CLANG
-#if PX_LINUX
+#if PX_LINUX || PX_FREEBSD
 #pragma clang diagnostic pop
 #endif // PX_LINUX
 #endif // PX_CLANG
