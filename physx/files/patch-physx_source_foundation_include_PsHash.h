--- physx/source/foundation/include/PsHash.h.orig	2024-07-05 09:31:14 UTC
+++ physx/source/foundation/include/PsHash.h
@@ -38,7 +38,7 @@
 #pragma warning(disable : 4302)
 #endif
 
-#if PX_LINUX
+#if PX_LINUX || PX_FREEBSD
 #include "foundation/PxSimpleTypes.h"
 #endif
 
