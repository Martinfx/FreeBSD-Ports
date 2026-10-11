--- hadoop-hdfs-project/hadoop-hdfs-native-client/src/main/native/fuse-dfs/fuse_dfs.h.orig	2026-02-24 00:10:13 UTC
+++ hadoop-hdfs-project/hadoop-hdfs-native-client/src/main/native/fuse-dfs/fuse_dfs.h
@@ -30,7 +30,9 @@
 #include <fuse.h>
 #include <fuse/fuse_opt.h>
 
+#ifdef __linux__
 #include <sys/xattr.h>
+#endif
 
 #include "config.h"
 
