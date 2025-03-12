--- python/GafferUITest/WidgetTest.py.orig	2025-03-12 17:53:39 UTC
+++ python/GafferUITest/WidgetTest.py
@@ -49,9 +49,9 @@ import GafferUITest
 import GafferUI
 import GafferUITest
 
-from Qt import QtCore
-from Qt import QtGui
-from Qt import QtWidgets
+from PyQt5 import QtCore
+from PyQt5 import QtGui
+from PyQt5 import QtWidgets
 
 class TestWidget( GafferUI.Widget ) :
 
