--- python/GafferUI/RampPlugValueWidget.py.orig	2025-03-12 17:53:39 UTC
+++ python/GafferUI/RampPlugValueWidget.py
@@ -39,8 +39,8 @@ import IECore
 import imath
 import IECore
 
-from Qt import QtCore
-from Qt import QtGui
+from PyQt5 import QtCore
+from PyQt5 import QtGui
 
 class RampPlugValueWidget( GafferUI.PlugValueWidget ) :
 
