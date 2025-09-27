--- src/core/libraries/network/net_util.cpp.orig	2025-09-22 18:34:11 UTC
+++ src/core/libraries/network/net_util.cpp
@@ -8,7 +8,7 @@ typedef int socklen_t;
 #include <winsock2.h>
 typedef SOCKET net_socket;
 typedef int socklen_t;
-#else
+#elif defined(__FreeBSD__)
 #include <cerrno>
 #include <arpa/inet.h>
 #include <ifaddrs.h>
@@ -19,13 +19,16 @@ typedef int socklen_t;
 #include <sys/ioctl.h>
 #include <sys/socket.h>
 #include <unistd.h>
+#include <net/if.h>
+#include <net/route.h>
+#include <unistd.h>
 typedef int net_socket;
 #endif
 #if defined(__APPLE__)
 #include <net/if_dl.h>
 #include <net/route.h>
 #endif
-#if __linux__
+#if __linux__ || __FreeBSD__
 #include <fstream>
 #include <iostream>
 #include <sstream>
@@ -222,7 +225,9 @@ bool NetUtilInternal::RetrieveDefaultGateway() {
     this->default_gateway = str;
     return true;
 
-#else
+#elif defined(__FreeBSD__)
+   return true;
+#elif defined(__linux__)
     std::ifstream route{"/proc/net/route"};
     std::string line;
 
@@ -252,11 +257,11 @@ bool NetUtilInternal::RetrieveDefaultGateway() {
     return false;
 }
 
-const std::string& NetUtilInternal::GetNetmask() const {
+const std::string& NetUtil::NetUtilInternal::GetNetmask() const {
     return netmask;
 }
 
-bool NetUtilInternal::RetrieveNetmask() {
+bool NetUtil::NetUtilInternal::RetrieveNetmask() {
     std::scoped_lock lock{m_mutex};
     char netmaskStr[INET_ADDRSTRLEN];
     auto success = false;
@@ -322,11 +327,11 @@ bool NetUtilInternal::RetrieveNetmask() {
     return success;
 }
 
-const std::string& NetUtilInternal::GetIp() const {
+const std::string& NetUtil::NetUtilInternal::GetIp() const {
     return ip;
 }
 
-bool NetUtilInternal::RetrieveIp() {
+bool NetUtil::NetUtilInternal::RetrieveIp() {
     std::scoped_lock lock{m_mutex};
 
     auto sockfd = socket(AF_INET, SOCK_STREAM, 0);
@@ -367,4 +372,3 @@ bool NetUtilInternal::RetrieveIp() {
     return true;
 }
 
-} // namespace NetUtil
\ No newline at end of file
