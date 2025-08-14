--- python/GafferUI/TextWidget.py.orig	2025-03-12 17:53:38 UTC
+++ python/GafferUI/TextWidget.py
@@ -41,9 +41,9 @@ import GafferUI
 import Gaffer
 import GafferUI
 
-from Qt import QtCore
-from Qt import QtGui
-from Qt import QtWidgets
+from PyQt5 import QtCore
+from PyQt5 import QtGui
+from PyQt5 import QtWidgets
 
 class TextWidget( GafferUI.Widget ) :
 
