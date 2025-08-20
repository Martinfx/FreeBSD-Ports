--- python/GafferImageUI/ImageViewUI.py.orig	2025-03-12 17:53:39 UTC
+++ python/GafferImageUI/ImageViewUI.py
@@ -47,9 +47,9 @@ from GafferUI.PlugValueWidget import sole
 
 from GafferUI.PlugValueWidget import sole
 
-from Qt import QtGui
-from Qt import QtWidgets
-from Qt import QtCore
+from PyQt5 import QtGui
+from PyQt5 import QtWidgets
+from PyQt5 import QtCore
 
 ##########################################################################
 # Metadata registration.
