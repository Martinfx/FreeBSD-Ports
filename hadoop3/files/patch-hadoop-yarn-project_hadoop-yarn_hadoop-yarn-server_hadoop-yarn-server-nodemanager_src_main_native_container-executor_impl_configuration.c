--- hadoop-yarn-project/hadoop-yarn/hadoop-yarn-server/hadoop-yarn-server-nodemanager/src/main/native/container-executor/impl/configuration.c.orig	2018-10-18 18:38:40 UTC
+++ hadoop-yarn-project/hadoop-yarn/hadoop-yarn-server/hadoop-yarn-server-nodemanager/src/main/native/container-executor/impl/configuration.c
@@ -27,9 +27,11 @@
 #include <inttypes.h>
 #include <errno.h>
 #include <unistd.h>
+#include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <sys/stat.h>
+#include <sys/types.h>
 
 #define MAX_SIZE 10
 
