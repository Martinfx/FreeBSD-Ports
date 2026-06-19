--- maxutils/maxbase/src/host.cc.orig	2022-10-09 10:59:31 UTC
+++ maxutils/maxbase/src/host.cc
@@ -16,6 +16,8 @@
 #include <vector>
 #include <algorithm>
 #include <arpa/inet.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
 #include <netdb.h>
 #include <maxbase/assert.hh>
 #include <maxbase/format.hh>
