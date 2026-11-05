--- core/OOXML/Base/Types_32.h.orig	2026-11-05 00:00:00 UTC
+++ core/OOXML/Base/Types_32.h
@@ -41,7 +41,7 @@
 	typedef unsigned __int16	_UINT16;
 	typedef unsigned __int32	_UINT32;
 	typedef unsigned __int64	_UINT64;
-#elif __linux__
+#elif defined(__linux__) || defined(__FreeBSD__)
 #include "stdint.h"
         typedef int16_t             _INT16;
         typedef int32_t             _INT32;
