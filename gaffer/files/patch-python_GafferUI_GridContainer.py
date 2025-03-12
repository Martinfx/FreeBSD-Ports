--- python/GafferUI/GridContainer.py.orig	2025-03-12 17:53:39 UTC
+++ python/GafferUI/GridContainer.py
@@ -40,8 +40,8 @@ import GafferUI
 
 import GafferUI
 
-from Qt import QtCore
-from Qt import QtWidgets
+from PyQt5 import QtCore
+from PyQt5 import QtWidgets
 
 ## The GridContainer holds a series of Widgets in a grid format, and provides
 # indexing using python's multidimensional array syntax to complement the list
