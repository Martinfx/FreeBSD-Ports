--- python/GafferUI/PythonEditor.py.orig	2025-03-12 17:53:38 UTC
+++ python/GafferUI/PythonEditor.py
@@ -48,8 +48,8 @@ import GafferUI
 import Gaffer
 import GafferUI
 
-from Qt import QtWidgets
-from Qt import QtCore
+from PyQt5 import QtWidgets
+from PyQt5 import QtCore
 
 ## \todo Custom right click menu with script load, save, execute file, undo, redo etc.
 ## \todo Standard way for users to customise all menus
