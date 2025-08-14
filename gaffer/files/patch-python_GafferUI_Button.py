--- python/GafferUI/Button.py.orig	2025-03-12 17:53:38 UTC
+++ python/GafferUI/Button.py
@@ -40,9 +40,9 @@ import GafferUI
 import Gaffer
 import GafferUI
 
-from Qt import QtGui
-from Qt import QtWidgets
-from Qt import QtCore
+from PyQt5 import QtGui
+from PyQt5 import QtWidgets
+from PyQt5 import QtCore
 
 class Button( GafferUI.Widget ) :
 
