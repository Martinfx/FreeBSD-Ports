--- gpcontrib/gpcloud/src/gpwriter.cpp.orig	2022-10-31 18:53:14 UTC
+++ gpcontrib/gpcloud/src/gpwriter.cpp
@@ -1,6 +1,6 @@
 #include "gpwriter.h"
 #include "s3memory_mgmt.h"
-
+#include <unistd.h>
 GPWriter::GPWriter(const S3Params& params, string fmt)
     : format(fmt), params(params), restfulService(this->params), s3InterfaceService(this->params) {
     restfulServicePtr = &restfulService;
