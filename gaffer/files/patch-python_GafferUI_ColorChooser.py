--- python/GafferUI/ColorChooser.py.orig	2025-03-12 17:53:38 UTC
+++ python/GafferUI/ColorChooser.py
@@ -48,9 +48,9 @@ import GafferUI
 import Gaffer
 import GafferUI
 
-from Qt import QtCore
-from Qt import QtGui
-from Qt import QtWidgets
+from PyQt5 import QtCore
+from PyQt5 import QtGui
+from PyQt5 import QtWidgets
 
 __tmiToRGBMatrix = imath.M33f(
 	-1.0 / 2.0, 0.0, 1.0 / 2.0,
