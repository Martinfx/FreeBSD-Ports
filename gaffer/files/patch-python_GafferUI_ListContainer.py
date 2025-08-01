--- python/GafferUI/ListContainer.py.orig	2025-03-12 17:53:38 UTC
+++ python/GafferUI/ListContainer.py
@@ -42,8 +42,8 @@ import GafferUI
 import IECore
 import GafferUI
 
-from Qt import QtWidgets
-from Qt import QtCore
+from PyQt5 import QtWidgets
+from PyQt5 import QtCore
 
 class _WidgetItem( QtWidgets.QWidgetItem ) :
 	# A customized `QWidgetItem` to return a `maximumSize()` without taking
