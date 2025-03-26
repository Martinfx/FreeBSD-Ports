--- python/GafferUI/PlugPopup.py.orig	2025-03-12 17:53:38 UTC
+++ python/GafferUI/PlugPopup.py
@@ -41,9 +41,9 @@ from GafferUI.PlugValueWidget import sole
 
 from GafferUI.PlugValueWidget import sole
 
-from Qt import QtCore
-from Qt import QtGui
-from Qt import QtWidgets
+from PyQt5 import QtCore
+from PyQt5 import QtGui
+from PyQt5 import QtWidgets
 
 class PlugPopup( GafferUI.PopupWindow ) :
 
