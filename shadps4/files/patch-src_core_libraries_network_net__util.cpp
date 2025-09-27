--- src/core/libraries/network/net_util.cpp.orig	2025-09-26 23:09:32 UTC
+++ src/core/libraries/network/net_util.cpp
@@ -29,12 +29,17 @@ typedef int net_socket;
 #include <array>
 #include <algorithm>
 #include <cstring>
+#include <net/if.h>
+#include <net/route.h>
+#include <netinet/in.h>
+#include <arpa/inet.h>
+#include <unistd.h>
 #endif
 #if defined(__APPLE__)
 #include <net/if_dl.h>
 #include <net/route.h>
 #endif
-#if __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #include <fstream>
 #include <iostream>
 #include <sstream>
@@ -147,11 +152,12 @@ bool NetUtilInternal::RetrieveEthernetAddr() {
     return false;
 }
 } // namespace NetUtil
-const std::string& NetUtilInternal::GetDefaultGateway() const {
+
+const std::string& NetUtil::NetUtilInternal::GetDefaultGateway() const {
     return default_gateway;
 }
 
-bool NetUtilInternal::RetrieveDefaultGateway() {
+bool NetUtil::NetUtilInternal::RetrieveDefaultGateway() {
     std::scoped_lock lock{m_mutex};
 
 #ifdef _WIN32
@@ -253,7 +259,9 @@ bool NetUtilInternal::RetrieveDefaultGateway() {
     this->default_gateway = str;
     return true;
 
-#else
+#elif defined(__FreeBSD__)
+   return true;
+#elif defined(__linux__)
     std::ifstream route{"/proc/net/route"};
     std::string line;
 
@@ -283,11 +291,11 @@ bool NetUtilInternal::RetrieveDefaultGateway() {
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
@@ -353,11 +361,11 @@ bool NetUtilInternal::RetrieveNetmask() {
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
@@ -398,4 +406,3 @@ bool NetUtilInternal::RetrieveIp() {
     return true;
 }
 
-} // namespace NetUtil
\ No newline at end of file
