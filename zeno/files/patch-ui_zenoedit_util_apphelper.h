--- ui/zenoedit/util/apphelper.h.orig	2024-04-26 16:22:35 UTC
+++ ui/zenoedit/util/apphelper.h
@@ -2,19 +2,16 @@
 #define __ZENOEDIT_HELPER__
 
 #include <zenomodel/include/igraphsmodel.h>
-#include "zenoapplication.h"
 #include <zenomodel/include/graphsmanagment.h>
 #include <zenomodel/include/igraphsmodel.h>
-#include "zenomainwindow.h"
 #include <zenovis/ObjectsManager.h>
 #include <zeno/types/UserData.h>
-#include <zenoui/comctrl/gv/zveceditoritem.h>
-#include <viewport/viewportwidget.h>
 #include "launch/corelaunch.h"
 #include "settings/zsettings.h"
 #include "viewport/recordvideomgr.h"
 #include "panel/zenospreadsheet.h"
-
+class ZVecEditorItem;
+class ViewPortWidget;
 class AppHelper
 {
 public:
@@ -37,4 +34,4 @@ class AppHelper (public)
 };
 
 
-#endif
\ No newline at end of file
+#endif
