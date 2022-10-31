--- gpMgmt/bin/ifaddrs/main.c.orig	2022-10-31 18:57:21 UTC
+++ gpMgmt/bin/ifaddrs/main.c
@@ -14,6 +14,7 @@
 #include <sys/socket.h>
 #include <net/if.h>
 #include <c.h>
+#include <netinet/in.h>
 
 int main(int argc, char *argv[])
 {
