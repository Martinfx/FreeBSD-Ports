--- python/GafferUI/MultiLineTextWidget.py.orig	2025-03-12 17:53:38 UTC
+++ python/GafferUI/MultiLineTextWidget.py
@@ -46,9 +46,9 @@ from ._StyleSheet import _styleColors
 import GafferUI
 from ._StyleSheet import _styleColors
 
-from Qt import QtGui
-from Qt import QtWidgets
-from Qt import QtCore
+from PyQt5 import QtGui
+from PyQt5 import QtWidgets
+from PyQt5 import QtCore
 
 class MultiLineTextWidget( GafferUI.Widget ) :
 
