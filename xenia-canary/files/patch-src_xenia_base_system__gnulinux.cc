--- src/xenia/base/system_gnulinux.cc.orig
+++ src/xenia/base/system_gnulinux.cc
@@ -7,7 +7,7 @@
  ******************************************************************************
  */
 
-#include <alloca.h>
+#include <stdlib.h>  // alloca()
 #include <dlfcn.h>
 #include <stdlib.h>
 
