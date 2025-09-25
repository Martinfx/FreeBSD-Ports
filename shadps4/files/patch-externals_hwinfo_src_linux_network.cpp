--- externals/hwinfo/src/linux/network.cpp.orig	2025-09-25 06:42:37 UTC
+++ externals/hwinfo/src/linux/network.cpp
@@ -3,9 +3,15 @@
 #ifdef HWINFO_UNIX
 #include <arpa/inet.h>
 #include <hwinfo/network.h>
-#include <ifaddrs.h>
-#include <net/if.h>
-#include <netpacket/packet.h>
+#if defined(__linux__)
+  #include <net/if.h>
+  #include <netpacket/packet.h>
+  #include <arpa/inet.h>
+#elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
+  #include <net/if.h>
+  #include <net/if_dl.h>          // sockaddr_dl, LLADDR()
+  #include <netinet/in.h>
+#endif
 #include <sys/ioctl.h>
 
 #include <cstring>
@@ -34,11 +40,15 @@ std::string getIp4(const std::string& interface) {
 
 std::string getIp4(const std::string& interface) {
   std::string ip4 = "<unknown>";
+#if defined(__linux__)
   struct ifaddrs* ifaddr;
   if (getifaddrs(&ifaddr) == -1) {
     return ip4;
   }
+#endif
+  return ip4;
 
+#if defined(__linux__)
   for (struct ifaddrs* ifa = ifaddr; ifa != nullptr; ifa = ifa->ifa_next) {
     if (ifa->ifa_addr == nullptr) continue;
     if (ifa->ifa_addr->sa_family == AF_INET && interface == ifa->ifa_name) {
@@ -50,15 +60,23 @@ std::string getIp4(const std::string& interface) {
   }
   freeifaddrs(ifaddr);
   return ip4;
+#endif
+
+  return ip4;
 }
 
 std::string getIp6(const std::string& interface) {
+
   std::string ip6 = "<unknown>";
+#if defined(__linux__)
   struct ifaddrs* ifaddr;
   if (getifaddrs(&ifaddr) == -1) {
     return ip6;
   }
+#endif
+  return ip6;
 
+#if defined(__linux__)
   for (struct ifaddrs* ifa = ifaddr; ifa != nullptr; ifa = ifa->ifa_next) {
     if (ifa->ifa_addr == nullptr) {
       continue;
@@ -74,6 +92,8 @@ std::string getIp6(const std::string& interface) {
   }
   freeifaddrs(ifaddr);
   return ip6;
+#endif
+ return ip6;
 }
 
 std::vector<Network> getAllNetworks() {
