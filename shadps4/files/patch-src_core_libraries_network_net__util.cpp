--- src/core/libraries/network/net_util.cpp.orig	2025-09-18 06:54:56 UTC
+++ src/core/libraries/network/net_util.cpp
@@ -8,7 +8,7 @@ typedef int socklen_t;
 #include <winsock2.h>
 typedef SOCKET net_socket;
 typedef int socklen_t;
-#else
+#elif __linux__
 #include <cerrno>
 #include <arpa/inet.h>
 #include <ifaddrs.h>
@@ -20,6 +20,15 @@ typedef int net_socket;
 #include <sys/socket.h>
 #include <unistd.h>
 typedef int net_socket;
+#elif __FreeBSD__
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <ifaddrs.h>
+#include <net/if_dl.h>
+#include <net/if_types.h>
+#include <array>
+#include <algorithm>
+#include <cstring>
 #endif
 #if defined(__APPLE__)
 #include <net/if_dl.h>
@@ -76,6 +85,28 @@ bool NetUtilInternal::RetrieveEthernetAddr() {
         }
         freeifaddrs(ifap);
     }
+#elif defined __FreeBSD__
+    ifaddrs* ifap = nullptr;
+    if (getifaddrs(&ifap) != 0 || !ifap) {
+        return false;
+    }
+
+    for (ifaddrs* p = ifap; p; p = p->ifa_next) {
+        if (!p->ifa_addr) continue;
+        if (p->ifa_addr->sa_family != AF_LINK) continue;
+
+        auto* sdl = reinterpret_cast<sockaddr_dl*>(p->ifa_addr);
+        if (sdl->sdl_type != IFT_ETHER) continue;
+        if (sdl->sdl_alen < 6) continue;
+
+        const uint8_t* mac = reinterpret_cast<const uint8_t*>(LLADDR(sdl));
+        std::copy(mac, mac + 6, ether_address.begin());
+        freeifaddrs(ifap);
+        return true;
+    }
+    freeifaddrs(ifap);
+    return false;
+
 #else
     ifreq ifr;
     ifconf ifc;
@@ -115,7 +146,7 @@ bool NetUtilInternal::RetrieveEthernetAddr() {
 #endif
     return false;
 }
-
+} // namespace NetUtil
 const std::string& NetUtilInternal::GetDefaultGateway() const {
     return default_gateway;
 }
