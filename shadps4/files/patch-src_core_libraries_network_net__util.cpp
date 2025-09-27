--- src/core/libraries/network/net_util.cpp.orig	2025-09-22 18:46:43 UTC
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
@@ -19,13 +19,14 @@ typedef int socklen_t;
 #include <sys/ioctl.h>
 #include <sys/socket.h>
 #include <unistd.h>
+#include <net/route.h>
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
@@ -76,7 +77,7 @@ bool NetUtilInternal::RetrieveEthernetAddr() {
         }
         freeifaddrs(ifap);
     }
-#else
+#elif defined(__linux__)
     ifreq ifr;
     ifconf ifc;
     char buf[1024];
@@ -222,7 +223,9 @@ bool NetUtilInternal::RetrieveDefaultGateway() {
     this->default_gateway = str;
     return true;
 
-#else
+#elif defined(__FreeBSD__)
+   return true;
+#elif defined(__linux__)
     std::ifstream route{"/proc/net/route"};
     std::string line;
 
@@ -252,11 +255,11 @@ bool NetUtilInternal::RetrieveDefaultGateway() {
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
@@ -322,11 +325,11 @@ bool NetUtilInternal::RetrieveNetmask() {
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
@@ -367,4 +370,4 @@ bool NetUtilInternal::RetrieveIp() {
     return true;
 }
 
-} // namespace NetUtil
\ No newline at end of file
+}
\ No newline at end of file
