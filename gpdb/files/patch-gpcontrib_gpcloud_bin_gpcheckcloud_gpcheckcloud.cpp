--- gpcontrib/gpcloud/bin/gpcheckcloud/gpcheckcloud.cpp.orig	2022-11-02 19:41:16 UTC
+++ gpcontrib/gpcloud/bin/gpcheckcloud/gpcheckcloud.cpp
@@ -1,4 +1,5 @@
 #include "gpcheckcloud.h"
+#include "unistd.h"
 
 bool hasHeader;
 
