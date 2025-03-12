--- python/GafferUI/Slider.py.orig	2025-03-12 17:53:39 UTC
+++ python/GafferUI/Slider.py
@@ -43,9 +43,9 @@ import GafferUI
 import Gaffer
 import GafferUI
 
-from Qt import QtCore
-from Qt import QtGui
-from Qt import QtWidgets
+from PyQt5 import QtCore
+from PyQt5 import QtGui
+from PyQt5 import QtWidgets
 
 class Slider( GafferUI.Widget ) :
 
