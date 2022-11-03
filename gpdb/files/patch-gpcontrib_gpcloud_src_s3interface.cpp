--- gpcontrib/gpcloud/src/s3interface.cpp.orig	2022-11-02 19:37:11 UTC
+++ gpcontrib/gpcloud/src/s3interface.cpp
@@ -1,5 +1,5 @@
 #include "s3interface.h"
-
+#include <unistd.h>
 // use destructor ~XMLContextHolder() to do the cleanup
 class XMLContextHolder {
    public:
