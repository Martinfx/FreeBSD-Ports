--- src/xenia/kernel/xsocket.cc.orig	2025-03-06 15:22:30 UTC
+++ src/xenia/kernel/xsocket.cc
@@ -28,6 +28,7 @@
 #include <netinet/ip.h>
 #include <sys/socket.h>
 #include <unistd.h>
+#undef IPPROTO_UDP
 #endif
 
 namespace xe {
@@ -62,7 +63,7 @@ X_STATUS XSocket::Close() {
 X_STATUS XSocket::Close() {
 #if XE_PLATFORM_WIN32
   int ret = closesocket(native_handle_);
-#elif XE_PLATFORM_LINUX
+#elif XE_PLATFORM_LINUX || XE_PLATFORM_FREEBSD
   int ret = close(native_handle_);
 #endif
 
@@ -105,7 +106,7 @@ X_STATUS XSocket::IOControl(uint32_t cmd, uint8_t* arg
   }
 
   return X_STATUS_SUCCESS;
-#elif XE_PLATFORM_LINUX
+#elif XE_PLATFORM_LINUX || XE_PLATFORM_FREEBSD
   return X_STATUS_UNSUCCESSFUL;
 #endif
 }
@@ -258,4 +259,4 @@ bool XSocket::QueuePacket(uint32_t src_ip, uint16_t sr
 }
 
 }  // namespace kernel
-}  // namespace xe
\ No newline at end of file
+}  // namespace xe
