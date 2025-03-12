--- python/GafferUI/PathListingWidget.py.orig	2025-03-12 17:53:38 UTC
+++ python/GafferUI/PathListingWidget.py
@@ -49,10 +49,10 @@ import GafferUI
 from ._StyleSheet import _styleColors
 import GafferUI
 
-import Qt
-from Qt import QtCore
-from Qt import QtGui
-from Qt import QtWidgets
+import PyQt5
+from PyQt5 import QtCore
+from PyQt5 import QtGui
+from PyQt5 import QtWidgets
 
 ## The PathListingWidget displays the contents of a Path, updating the Path to represent the
 # current directory as the user navigates around. It supports both a list and a tree view,
