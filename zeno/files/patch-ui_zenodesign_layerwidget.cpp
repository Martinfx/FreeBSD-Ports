--- ui/zenodesign/layerwidget.cpp.orig	2024-04-22 15:08:52 UTC
+++ ui/zenodesign/layerwidget.cpp
@@ -5,7 +5,7 @@
 #include "layertreeitemdelegate.h"
 #include "nodeswidget.h"
 #include "util.h"
-
+#include "zenostyle.h"
 
 NodesView* getCurrentView(QWidget* pWidget)
 {
@@ -88,4 +88,4 @@ void LayerWidget::resetModel()
         m_pLayer->setSelectionModel(selection);
         m_pLayer->expandAll();
     }
-}
\ No newline at end of file
+}
