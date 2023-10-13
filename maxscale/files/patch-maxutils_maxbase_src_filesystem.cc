--- maxutils/maxbase/src/filesystem.cc.orig	2023-09-22 06:15:26 UTC
+++ maxutils/maxbase/src/filesystem.cc
@@ -14,7 +14,8 @@
 
 #include <maxbase/filesystem.hh>
 
-#include <cstdio>
+#include <stdio.h>
+#include <stdlib.h>
 #include <unistd.h>
 #include <fcntl.h>
 #include <sys/stat.h>
