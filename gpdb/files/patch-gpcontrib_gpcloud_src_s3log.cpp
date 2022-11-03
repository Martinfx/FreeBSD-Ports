--- gpcontrib/gpcloud/src/s3log.cpp.orig	2022-11-02 18:57:17 UTC
+++ gpcontrib/gpcloud/src/s3log.cpp
@@ -3,6 +3,7 @@
 #include "s3params.h"
 
 #include <arpa/inet.h>
+#include <netinet/in.h>
 
 #define MAX_MESSAGE_LINE_LENGTH 1024
 
