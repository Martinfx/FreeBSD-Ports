--- python/GafferUI/SpreadsheetUI/_RowsPlugValueWidget.py.orig	2025-03-12 17:53:39 UTC
+++ python/GafferUI/SpreadsheetUI/_RowsPlugValueWidget.py
@@ -44,8 +44,8 @@ import GafferUI
 import Gaffer
 import GafferUI
 
-from Qt import QtCore
-from Qt import QtWidgets
+from PyQt5 import QtCore
+from PyQt5 import QtWidgets
 
 from . import _Algo
 from ._LinkedScrollBar import _LinkedScrollBar
