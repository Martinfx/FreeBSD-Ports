--- desktop-apps/win-linux/src/cthemes.cpp.orig	2026-09-24 22:04:11 UTC
+++ desktop-apps/win-linux/src/cthemes.cpp
@@ -1,8 +1,12 @@
 
 #include "cthemes.h"
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
+// GLib has struct members called "signals", a Qt keyword macro
+# pragma push_macro("signals")
+# undef signals
 # include <gio/gio.h>
 # include <glib.h>
+# pragma pop_macro("signals")
 #endif
 #include "defines.h"
 #include "utils.h"
