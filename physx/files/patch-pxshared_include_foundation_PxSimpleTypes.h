--- pxshared/include/foundation/PxSimpleTypes.h.orig	2024-07-05 10:07:58 UTC
+++ pxshared/include/foundation/PxSimpleTypes.h
@@ -44,7 +44,7 @@
 // header
 #endif
 
-#if PX_LINUX
+#if PX_LINUX || PX_FREEBSD
 #define __STDC_LIMIT_MACROS
 #endif
 
