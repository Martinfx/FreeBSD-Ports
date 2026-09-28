--- desktop-apps/win-linux/extras/update-daemon/src/classes/csocket.cpp.orig	2026-09-28 08:45:35 UTC
+++ desktop-apps/win-linux/extras/update-daemon/src/classes/csocket.cpp
@@ -273,8 +273,10 @@ bool CSocket::sendMessage(void *data, si
     memcpy(client_arg, data, size);
 #ifdef _WIN32
     int ret_data = send(pimpl->sender_fd, client_arg, BUFFSIZE, 0); // Send the string
-#else
+#elif defined(MSG_CONFIRM)
     int ret_data =(int)send(pimpl->sender_fd, client_arg, BUFFSIZE, MSG_CONFIRM);
+#else
+    int ret_data =(int)send(pimpl->sender_fd, client_arg, BUFFSIZE, 0);
 #endif
     if (ret_data != BUFFSIZE) {
         if (ret_data < 0) {
