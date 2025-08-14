--- python/GafferUI/Editor.py.orig	2025-03-12 17:53:38 UTC
+++ python/GafferUI/Editor.py
@@ -42,8 +42,8 @@ import GafferUI
 import Gaffer
 import GafferUI
 
-from Qt import QtCore
-from Qt import QtWidgets
+from PyQt5 import QtCore
+from PyQt5 import QtWidgets
 
 ## Base class for UI components which display or manipulate a ScriptNode
 # or its children. These make up the tabs in the UI layout.
