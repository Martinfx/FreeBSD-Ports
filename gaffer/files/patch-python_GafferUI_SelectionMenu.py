--- python/GafferUI/SelectionMenu.py.orig	2025-03-12 17:53:38 UTC
+++ python/GafferUI/SelectionMenu.py
@@ -39,9 +39,9 @@ import GafferUI
 import Gaffer
 import GafferUI
 
-from Qt import QtCore
-from Qt import QtGui
-from Qt import QtWidgets
+from PyQt5 import QtCore
+from PyQt5 import QtGui
+from PyQt5 import QtWidgets
 
 ## \todo Support cascading menus using "/" in labels. Rework API to
 # better match the rest of GafferUI - ditch index based methods, and
