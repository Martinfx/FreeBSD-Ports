--- physx/source/foundation/src/unix/PsUnixFPU.cpp.orig	2024-07-05 09:40:29 UTC
+++ physx/source/foundation/src/unix/PsUnixFPU.cpp
@@ -89,7 +89,7 @@ physx::shdfnd::FPUGuard::~FPUGuard()
 
 PX_FOUNDATION_API void physx::shdfnd::enableFPExceptions()
 {
-#if PX_LINUX && !defined(__EMSCRIPTEN__)
+#if (PX_LINUX || PX_FREEBSD) && !defined(__EMSCRIPTEN__)
 	feclearexcept(FE_ALL_EXCEPT);
 	feenableexcept(FE_INVALID | FE_DIVBYZERO | FE_OVERFLOW);
 #elif PX_OSX
@@ -106,7 +106,7 @@ PX_FOUNDATION_API void physx::shdfnd::enableFPExceptio
 
 PX_FOUNDATION_API void physx::shdfnd::disableFPExceptions()
 {
-#if PX_LINUX && !defined(__EMSCRIPTEN__)
+#if (PX_LINUX || PX_FREEBSD) && !defined(__EMSCRIPTEN__)
 	fedisableexcept(FE_ALL_EXCEPT);
 #elif PX_OSX
 	// clear any pending exceptions
