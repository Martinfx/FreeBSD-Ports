--- python/GafferUI/ColorPlugValueWidget.py.orig	2025-03-12 17:53:39 UTC
+++ python/GafferUI/ColorPlugValueWidget.py
@@ -42,7 +42,7 @@ from GafferUI.PlugValueWidget import sole
 
 from GafferUI.PlugValueWidget import sole
 
-from Qt import QtCore
+from PyQt5 import QtCore
 
 class ColorPlugValueWidget( GafferUI.PlugValueWidget ) :
 
