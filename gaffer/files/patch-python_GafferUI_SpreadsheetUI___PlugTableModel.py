--- python/GafferUI/SpreadsheetUI/_PlugTableModel.py.orig	2025-03-12 17:53:39 UTC
+++ python/GafferUI/SpreadsheetUI/_PlugTableModel.py
@@ -41,8 +41,8 @@ import GafferUI
 import Gaffer
 import GafferUI
 
-from Qt import QtCore
-from Qt import QtGui
+from PyQt5 import QtCore
+from PyQt5 import QtGui
 
 from . import _Formatting
 
