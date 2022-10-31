--- src/backend/gporca/libgpos/include/gpos/io/CFileReader.h.orig	2022-10-24 12:34:08 UTC
+++ src/backend/gporca/libgpos/include/gpos/io/CFileReader.h
@@ -13,6 +13,8 @@
 #define GPOS_CFileReader_H
 
 #include <fcntl.h>
+#include <sys/types.h>
+#include <sys/stat.h>
 
 #include "gpos/io/CFileDescriptor.h"
 
