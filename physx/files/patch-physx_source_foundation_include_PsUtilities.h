--- physx/source/foundation/include/PsUtilities.h.orig	2024-07-05 09:36:09 UTC
+++ physx/source/foundation/include/PsUtilities.h
@@ -122,7 +122,7 @@ PX_CUDA_CALLABLE PX_FORCE_INLINE void order(T& x, T& y
 	}
 }
 
-#if PX_GCC_FAMILY && !PX_EMSCRIPTEN  && !PX_LINUX
+#if PX_GCC_FAMILY && !PX_EMSCRIPTEN  && !PX_LINUX && !PX_FREEBSD
 __attribute__((noreturn))
 #endif
     PX_INLINE void debugBreak()
@@ -131,7 +131,7 @@ __attribute__((noreturn))
 	__debugbreak();
 #elif PX_ANDROID
 	raise(SIGTRAP); // works better than __builtin_trap. Proper call stack and can be continued.
-#elif PX_LINUX
+#elif PX_LINUX || PX_FREEBSD
 	asm("int $3");
 #elif PX_GCC_FAMILY
 	__builtin_trap();
