--- python/GafferCortexUI/DateTimeParameterValueWidget.py.orig	2025-03-12 17:53:38 UTC
+++ python/GafferCortexUI/DateTimeParameterValueWidget.py
@@ -45,9 +45,9 @@ from GafferUI.PlugValueWidget import sole
 
 from GafferUI.PlugValueWidget import sole
 
-from Qt import QtCore
-from Qt import QtGui
-from Qt import QtWidgets
+from PyQt5 import QtCore
+from PyQt5 import QtGui
+from PyQt5 import QtWidgets
 
 class DateTimeParameterValueWidget( GafferCortexUI.ParameterValueWidget ) :
 
