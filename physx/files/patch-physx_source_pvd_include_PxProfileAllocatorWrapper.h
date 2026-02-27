--- physx/source/pvd/include/PxProfileAllocatorWrapper.h.orig	2024-07-05 10:00:28 UTC
+++ physx/source/pvd/include/PxProfileAllocatorWrapper.h
@@ -74,7 +74,7 @@ namespace physx { namespace profile {
 	{
 		static const char* getName()
 		{
-#if PX_LINUX || PX_ANDROID || PX_PS4 || PX_IOS || PX_OSX || PX_EMSCRIPTEN || PX_SWITCH
+#if PX_LINUX || PX_FREEBSD || PX_ANDROID || PX_PS4 || PX_IOS || PX_OSX || PX_EMSCRIPTEN || PX_SWITCH
 			return __PRETTY_FUNCTION__;
 #else
 			return typeid(T).name();
