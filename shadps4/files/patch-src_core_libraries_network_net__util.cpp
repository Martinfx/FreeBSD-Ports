--- src/core/libraries/network/net_util.cpp.orig	2025-09-12 14:03:51 UTC
+++ src/core/libraries/network/net_util.cpp
@@ -8,7 +8,7 @@ typedef int socklen_t;
 #include <winsock2.h>
 typedef SOCKET net_socket;
 typedef int socklen_t;
-#else
+#elif __linux__
 #include <cerrno>
 #include <arpa/inet.h>
 #include <net/if.h>
@@ -19,6 +19,15 @@ typedef int net_socket;
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
 #include <ifaddrs.h>
@@ -70,6 +79,28 @@ bool NetUtilInternal::RetrieveEthernetAddr() {
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
@@ -107,4 +138,4 @@ bool NetUtilInternal::RetrieveEthernetAddr() {
 #endif
     return false;
 }
-} // namespace NetUtil
\ No newline at end of file
+} // namespace NetUtil
