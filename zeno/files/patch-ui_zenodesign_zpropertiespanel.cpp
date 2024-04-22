--- ui/zenodesign/zpropertiespanel.cpp.orig	2024-04-22 15:11:05 UTC
+++ ui/zenodesign/zpropertiespanel.cpp
@@ -5,7 +5,7 @@
 #include "styletabwidget.h"
 #include "nodesview.h"
 #include "nodeswidget.h"
-
+#include "zenostyle.h"
 
 DesignerMainWin* getMainWindow(QWidget* pWidget)
 {
@@ -564,4 +564,4 @@ ZElementPropPanel::ZElementPropPanel(QWidget* parent)
     pVBoxLayout->addStretch();
     
     setLayout(pVBoxLayout);
-}
\ No newline at end of file
+}
