--- physx/source/foundation/include/unix/PsUnixFPU.h.orig	2024-07-05 09:37:38 UTC
+++ physx/source/foundation/include/unix/PsUnixFPU.h
@@ -32,7 +32,7 @@
 
 #include "foundation/PxPreprocessor.h"
 
-#if PX_LINUX || PX_PS4 || PX_OSX
+#if PX_LINUX || PX_PS4 || PX_OSX || PX_FREEBSD
 
 #if PX_X86 || PX_X64
 #if PX_EMSCRIPTEN
