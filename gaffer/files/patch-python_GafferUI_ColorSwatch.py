--- python/GafferUI/ColorSwatch.py.orig	2025-03-12 17:53:38 UTC
+++ python/GafferUI/ColorSwatch.py
@@ -42,9 +42,9 @@ import GafferUI
 import Gaffer
 import GafferUI
 
-from Qt import QtCore
-from Qt import QtGui
-from Qt import QtWidgets
+from PyQt5 import QtCore
+from PyQt5 import QtGui
+from PyQt5 import QtWidgets
 
 ## The ColorSwatch simply displays a flat patch of colour. The colour is assumed to
 # be in a linear space : use `Widget.setDisplayTransform()` to control how it is displayed.
