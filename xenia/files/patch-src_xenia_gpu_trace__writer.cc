--- src/xenia/gpu/trace_writer.cc.orig	2025-03-06 14:24:23 UTC
+++ src/xenia/gpu/trace_writer.cc
@@ -15,7 +15,7 @@
 #include "third_party/snappy/snappy-sinksource.h"
 #include "third_party/snappy/snappy.h"
 
-#include "build/version.h"
+#define  XE_BUILD_COMMIT "3d30b2eec3ab1f83140b09745bee881fb5d5dde2"
 #include "xenia/base/assert.h"
 #include "xenia/base/filesystem.h"
 #include "xenia/base/logging.h"
