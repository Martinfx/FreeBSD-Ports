--- python/GafferUI/SpreadsheetUI/_PlugTableView.py.orig	2025-03-12 17:53:39 UTC
+++ python/GafferUI/SpreadsheetUI/_PlugTableView.py
@@ -46,9 +46,9 @@ from GafferUI.PlugValueWidget import sole
 
 from GafferUI.PlugValueWidget import sole
 
-from Qt import QtCore
-from Qt import QtWidgets
-from Qt import QtCompat
+from PyQt5 import QtCore
+from PyQt5 import QtWidgets
+#from PyQt5 import QtCompat
 
 from . import _Algo
 from . import _ClipboardAlgo
@@ -74,7 +74,7 @@ class _PlugTableView( GafferUI.Widget ) :
 
 		# Headers and column sizing
 
-		QtCompat.setSectionResizeMode( tableView.verticalHeader(), QtWidgets.QHeaderView.Fixed )
+		#QtCompat.setSectionResizeMode( tableView.verticalHeader(), QtWidgets.QHeaderView.Fixed )
 		tableView.verticalHeader().setDefaultSectionSize( 25 )
 		tableView.verticalHeader().setVisible( False )
 		tableView.setAlternatingRowColors( True )
@@ -316,10 +316,10 @@ class _PlugTableView( GafferUI.Widget ) :
 		if self.__mode in ( self.Mode.Cells, self.Mode.Defaults ) :
 
 			self._qtWidget().horizontalHeader().setSectionsMovable( not readOnly )
-			QtCompat.setSectionResizeMode(
-				self._qtWidget().horizontalHeader(),
-				QtWidgets.QHeaderView.Fixed if readOnly else QtWidgets.QHeaderView.Interactive
-			)
+			#QtCompat.setSectionResizeMode(
+			#	self._qtWidget().horizontalHeader(),
+			#	QtWidgets.QHeaderView.Fixed if readOnly else QtWidgets.QHeaderView.Interactive
+			#)
 
 		else :
 
