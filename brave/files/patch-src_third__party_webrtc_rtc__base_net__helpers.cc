--- src/third_party/webrtc/rtc_base/net_helpers.cc.orig	2026-11-24 12:50:30 UTC
+++ src/third_party/webrtc/rtc_base/net_helpers.cc
@@ -20,6 +20,7 @@
 #endif
 #if defined(WEBRTC_POSIX)
 #include <arpa/inet.h>
+#include <sys/socket.h>
 #endif  // defined(WEBRTC_POSIX)
 
 namespace webrtc {
