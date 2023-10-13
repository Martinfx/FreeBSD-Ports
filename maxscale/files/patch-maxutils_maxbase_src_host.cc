--- maxutils/maxbase/src/host.cc.orig	2023-09-22 06:15:26 UTC
+++ maxutils/maxbase/src/host.cc
@@ -17,6 +17,8 @@
 #include <vector>
 #include <algorithm>
 #include <arpa/inet.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
 #include <netdb.h>
 #include <maxbase/assert.hh>
 #include <maxbase/format.hh>
