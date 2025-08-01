--- python/GafferUI/GadgetWidget.py.orig	2025-03-12 17:53:38 UTC
+++ python/GafferUI/GadgetWidget.py
@@ -45,8 +45,8 @@ import OpenGL.GL as GL
 
 import OpenGL.GL as GL
 
-from Qt import QtCore
-from Qt import QtWidgets
+from PyQt5 import QtCore
+from PyQt5 import QtWidgets
 
 ## The GadgetWidget class provides a means of
 # hosting a Gadget within a Widget based interface.
