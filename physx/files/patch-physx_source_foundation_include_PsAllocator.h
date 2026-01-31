--- physx/source/foundation/include/PsAllocator.h.orig	2024-07-05 09:19:06 UTC
+++ physx/source/foundation/include/PsAllocator.h
@@ -100,7 +100,7 @@
 #if PX_WINDOWS_FAMILY
 	#include <malloc.h>
 	#define PxAlloca(x) _alloca(x)
-#elif PX_LINUX || PX_ANDROID
+#elif PX_LINUX || PX_ANDROID || PX_FREEBSD
 	#include <malloc.h>
 	#define PxAlloca(x) alloca(x)
 #elif PX_APPLE_FAMILY
