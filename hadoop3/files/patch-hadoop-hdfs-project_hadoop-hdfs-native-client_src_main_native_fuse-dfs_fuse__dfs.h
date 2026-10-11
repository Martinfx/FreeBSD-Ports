--- hadoop-hdfs-project/hadoop-hdfs-native-client/src/main/native/fuse-dfs/fuse_dfs.h.orig	2026-02-24 00:10:13 UTC
+++ hadoop-hdfs-project/hadoop-hdfs-native-client/src/main/native/fuse-dfs/fuse_dfs.h
@@ -28,9 +28,13 @@
 #include <syslog.h>
 
 #include <fuse.h>
-#include <fuse/fuse_opt.h>
+/* pkg-config puts include/fuse on the path, both for libfuse on Linux and for
+ * fusefs-libs on FreeBSD, whose headers are not otherwise reachable as fuse/. */
+#include <fuse_opt.h>
 
+#ifdef __linux__
 #include <sys/xattr.h>
+#endif
 
 #include "config.h"
 
