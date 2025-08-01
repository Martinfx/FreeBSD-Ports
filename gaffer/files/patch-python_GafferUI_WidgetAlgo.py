--- python/GafferUI/WidgetAlgo.py.orig	2025-03-12 17:53:38 UTC
+++ python/GafferUI/WidgetAlgo.py
@@ -40,10 +40,10 @@ import GafferUI
 
 import GafferUI
 
-import Qt
-from Qt import QtCore
-from Qt import QtGui
-from Qt import QtWidgets
+import PyQt5
+from PyQt5 import QtCore
+from PyQt5 import QtGui
+from PyQt5 import QtWidgets
 
 def joinEdges( widgets, orientation = None ) :
 
