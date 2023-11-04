--- ApfsLib/Endian.h.orig	2023-10-29 13:17:41 UTC
+++ ApfsLib/Endian.h
@@ -58,6 +58,12 @@ Also helps making the driver run on big-endian archite
 #include <byteswap.h>
 #include <endian.h>
 #endif
+#ifdef __FreeBSD__
+#include <sys/endian.h>
+#define bswap_16(x) bswap16(x)
+#define bswap_32(x) bswap32(x)
+#define bswap_64(x) bswap64(x)
+#endif
 #ifdef __APPLE__
 // Definitions for macOS
 #include <libkern/OSByteOrder.h>
