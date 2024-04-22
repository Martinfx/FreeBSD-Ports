--- ui/zenodesign/layertreeitemdelegate.cpp.orig	2024-04-22 15:07:50 UTC
+++ ui/zenodesign/layertreeitemdelegate.cpp
@@ -1,6 +1,7 @@
 #include "framework.h"
 #include "layerwidget.h"
 #include "layertreeitemdelegate.h"
+#include "zenostyle.h"
 
 LayerTreeitemDelegate::LayerTreeitemDelegate(QWidget* parent)
     : QStyledItemDelegate(parent), m_treeview(nullptr)
