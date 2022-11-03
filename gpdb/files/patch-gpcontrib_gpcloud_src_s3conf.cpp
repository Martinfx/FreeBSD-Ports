--- gpcontrib/gpcloud/src/s3conf.cpp.orig	2022-11-02 18:54:09 UTC
+++ gpcontrib/gpcloud/src/s3conf.cpp
@@ -3,6 +3,7 @@
 #include "s3params.h"
 
 #include <arpa/inet.h>
+#include <netinet/in.h>
 
 #ifndef S3_STANDALONE
 extern "C" {
