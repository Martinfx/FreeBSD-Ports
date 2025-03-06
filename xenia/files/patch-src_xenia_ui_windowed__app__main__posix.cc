--- src/xenia/ui/windowed_app_main_posix.cc.orig	2025-03-06 15:44:33 UTC
+++ src/xenia/ui/windowed_app_main_posix.cc
@@ -7,7 +7,11 @@
  ******************************************************************************
  */
 
+#if defined(__FreeBSD__)
+#include <gtk-3.0/gtk/gtk.h>
+#else
 #include <gtk/gtk.h>
+#endif
 #include <cstdio>
 #include <cstdlib>
 #include <memory>
