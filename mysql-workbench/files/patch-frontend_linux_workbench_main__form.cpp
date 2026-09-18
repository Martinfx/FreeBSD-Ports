--- frontend/linux/workbench/main_form.cpp.orig	2024-05-20 10:47:24 UTC
+++ frontend/linux/workbench/main_form.cpp
@@ -29,7 +29,7 @@
 #include <gtkmm/main.h>
 #include <atkmm.h>
 #include "main_form.h"
-#include "active_label.h"
+#include "gtk/src/active_label.h"
 // the rest, backend, etc ...
 #include "workbench/wb_context_ui.h"
 #include "workbench/wb_context.h"
