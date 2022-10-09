--- maxutils/maxbase/src/filesystem.cc.orig	2022-10-08 19:19:13 UTC
+++ maxutils/maxbase/src/filesystem.cc
@@ -13,7 +13,8 @@
 
 #include <maxbase/filesystem.hh>
 
-#include <cstdio>
+#include <stdio.h>
+#include <stdlib.h>
 #include <unistd.h>
 #include <fcntl.h>
 #include <sys/stat.h>
