--- src/third_party/webrtc/rtc_base/byte_order.h.orig	2026-11-24 12:50:30 UTC
+++ src/third_party/webrtc/rtc_base/byte_order.h
@@ -84,6 +84,8 @@
 #error WEBRTC_ARCH_BIG_ENDIAN or WEBRTC_ARCH_LITTLE_ENDIAN must be defined.
 #endif  // defined(WEBRTC_ARCH_LITTLE_ENDIAN)
 
+#elif defined(WEBRTC_BSD)
+#include <sys/endian.h>
 #elif defined(WEBRTC_POSIX)
 #include <endian.h>
 #else
