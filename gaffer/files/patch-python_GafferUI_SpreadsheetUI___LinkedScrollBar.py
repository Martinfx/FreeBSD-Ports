--- python/GafferUI/SpreadsheetUI/_LinkedScrollBar.py.orig	2025-03-12 17:53:39 UTC
+++ python/GafferUI/SpreadsheetUI/_LinkedScrollBar.py
@@ -37,8 +37,9 @@ import GafferUI
 import Gaffer
 import GafferUI
 
-from Qt import QtCore
-from Qt import QtWidgets
+from PyQt5 import QtCore
+from PyQt5 import QtWidgets
+from PyQt5.QtCore import QObject, pyqtSignal
 
 # ScrolledContainer linking
 # =========================
@@ -136,7 +137,7 @@ class _StepsChangedScrollBar( QtWidgets.QScrollBar ) :
 # signal.
 class _StepsChangedScrollBar( QtWidgets.QScrollBar ) :
 
-	stepsChanged = QtCore.Signal( int, int )
+	stepsChanged = pyqtSignal( int, int )
 
 	def __init__( self, orientation, parent = None ) :
 
