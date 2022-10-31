--- src/include/utils/inet.h.orig	2022-10-24 12:27:47 UTC
+++ src/include/utils/inet.h
@@ -14,6 +14,7 @@
 #ifndef INET_H
 #define INET_H
 
+#include <sys/socket.h>
 #include "fmgr.h"
 
 /*
