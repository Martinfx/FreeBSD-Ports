--- python/GafferUI/BusyWidget.py.orig	2025-03-12 17:53:39 UTC
+++ python/GafferUI/BusyWidget.py
@@ -39,9 +39,9 @@ import GafferUI
 
 import GafferUI
 
-from Qt import QtCore
-from Qt import QtGui
-from Qt import QtWidgets
+from PyQt5 import QtCore
+from PyQt5 import QtGui
+from PyQt5 import QtWidgets
 
 class BusyWidget( GafferUI.Widget ) :
 
