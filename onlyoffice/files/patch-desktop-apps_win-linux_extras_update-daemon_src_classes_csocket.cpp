--- desktop-apps/win-linux/extras/update-daemon/src/classes/csocket.cpp.orig	2026-09-28 09:50:15 UTC
+++ desktop-apps/win-linux/extras/update-daemon/src/classes/csocket.cpp
@@ -78,6 +78,18 @@ static unsigned long inetAddrFromUserId(
 #endif
 }
 
+#ifdef __FreeBSD__
+// The loopback interface of Linux has all of 127.0.0.0/8, and every user gets
+// an address of its own there.  FreeBSD only has 127.0.0.1, binding to the
+// address of a user fails and the application takes that for another instance
+// running, so every user gets a port of its own instead.
+static u_short portFromUserId(u_short port)
+{
+    u_short off = u_short(getuid() % 1000);
+    return port > 65535 - off ? port - off : port + off;
+}
+#endif
+
 static bool initSocket(u_short port, SOCKET &tmpd, SockAddr &addr, int &ret, std::string &error, bool use_unique_addr)
 {
 #ifdef _WIN32
@@ -99,8 +111,13 @@ static bool initSocket(u_short port, SOC
     }
     memset(&addr, 0, sizeof(SockAddr));
     addr.sin_family = AF_INET;
+#ifdef __FreeBSD__
+    addr.sin_addr.s_addr = inet_addr(INADDR);
+    addr.sin_port = htons(use_unique_addr ? portFromUserId(port) : port);
+#else
     addr.sin_addr.s_addr = use_unique_addr ? inetAddrFromUserId() : inet_addr(INADDR);
     addr.sin_port = htons(port);
+#endif
     ret = ::bind(tmpd, (struct sockaddr*)&addr, sizeof(addr));
     return true;
 }
@@ -273,8 +290,10 @@ bool CSocket::sendMessage(void *data, si
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
