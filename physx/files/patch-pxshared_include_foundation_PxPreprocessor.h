--- pxshared/include/foundation/PxPreprocessor.h.orig	2024-07-05 10:01:57 UTC
+++ pxshared/include/foundation/PxPreprocessor.h
@@ -100,6 +100,8 @@ Operating system defines, see http://sourceforge.net/p
 #define PX_ANDROID 1
 #elif defined(__linux__) || defined (__EMSCRIPTEN__) // note: __ANDROID__ implies __linux__
 #define PX_LINUX 1
+#elif defined(__FreeBSD__)
+#define PX_FREEBSD 1
 #elif defined(__APPLE__) && (defined(__arm__) || defined(__arm64__))
 #define PX_IOS 1
 #elif defined(__APPLE__)
@@ -174,6 +176,9 @@ define anything not defined on this platform to 0
 #ifndef PX_LINUX
 #define PX_LINUX 0
 #endif
+#ifndef PX_FREEBSD
+#define PX_FREEBSD 0
+#endif
 #ifndef PX_IOS
 #define PX_IOS 0
 #endif
@@ -244,9 +249,9 @@ family shortcuts
 // os
 #define PX_WINDOWS_FAMILY (PX_WIN32 || PX_WIN64 || PX_UWP)
 #define PX_MICROSOFT_FAMILY (PX_XBOXONE || PX_WINDOWS_FAMILY || PX_XBOX_SERIES_X)
-#define PX_LINUX_FAMILY (PX_LINUX || PX_ANDROID)
+#define PX_LINUX_FAMILY (PX_LINUX || PX_ANDROID  || PX_FREEBSD)
 #define PX_APPLE_FAMILY (PX_IOS || PX_OSX)                  // equivalent to #if __APPLE__
-#define PX_UNIX_FAMILY (PX_LINUX_FAMILY || PX_APPLE_FAMILY) // shortcut for unix/posix platforms
+#define PX_UNIX_FAMILY (PX_LINUX_FAMILY || PX_APPLE_FAMILY  || PX_FREEBSD) // shortcut for unix/posix platforms
 #if defined(__EMSCRIPTEN__)
 #define PX_EMSCRIPTEN 1
 #else
@@ -284,7 +289,7 @@ Assert macro
 DLL export macros
 */
 #ifndef PX_C_EXPORT
-#if PX_WINDOWS_FAMILY || PX_LINUX
+#if PX_WINDOWS_FAMILY || PX_LINUX  || PX_FREEBSD
 #define PX_C_EXPORT extern "C"
 #else
 #define PX_C_EXPORT
@@ -523,7 +528,7 @@ PX_COMPILE_TIME_ASSERT(PX_OFFSET_OF(PxPackValidation, 
 
 #ifndef DISABLE_CUDA_PHYSX
 //CUDA is currently supported only on windows 
-#define PX_SUPPORT_GPU_PHYSX ((PX_WINDOWS_FAMILY) || (PX_LINUX && PX_X64))
+#define PX_SUPPORT_GPU_PHYSX ((PX_WINDOWS_FAMILY) || ((PX_LINUX || PX_FREEBSD) && PX_X64))
 #else
 #define PX_SUPPORT_GPU_PHYSX 0
 #endif
