--- apfsfuse/ApfsFuse.cpp.orig	2023-03-11 23:26:37 UTC
+++ apfsfuse/ApfsFuse.cpp
@@ -37,6 +37,11 @@
 #include <fuse/fuse.h>
 #include <fuse/fuse_lowlevel.h>
 #endif
+#ifdef __FreeBSD__
+#include <fuse/fuse.h>
+#include <fuse/fuse_lowlevel.h>
+#include <unistd.h>
+#endif
 
 #include <getopt.h>
 
