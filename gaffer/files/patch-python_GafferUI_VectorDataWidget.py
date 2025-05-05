--- python/GafferUI/VectorDataWidget.py.orig	2025-03-12 17:53:39 UTC
+++ python/GafferUI/VectorDataWidget.py
@@ -45,11 +45,11 @@ from ._TableView import _TableView
 from GafferUI.ColorSwatch import _Checker
 from ._TableView import _TableView
 
-from Qt import QtCore
-from Qt import QtGui
-from Qt import QtWidgets
-from Qt import QtCompat
-import Qt
+from PyQt5 import QtCore
+from PyQt5 import QtGui
+from PyQt5 import QtWidgets
+#from Qt import QtCompat
+import PyQt5
 
 ## The VectorDataWidget provides a table view for the contents of
 # one or more IECore VectorData instances.
@@ -99,7 +99,7 @@ class VectorDataWidget( GafferUI.Widget ) :
 		self.__tableView.horizontalHeader().setMinimumSectionSize( 70 )
 
 		self.__tableView.verticalHeader().setVisible( showIndices )
-		QtCompat.setSectionResizeMode( self.__tableView.verticalHeader(), QtWidgets.QHeaderView.Fixed )
+		#QtCompat.setSectionResizeMode( self.__tableView.verticalHeader(), QtWidgets.QHeaderView.Fixed )
 
 		self.__tableView.setHorizontalScrollBarPolicy( GafferUI.ScrollMode._toQt( horizontalScrollMode ) )
 		self.__tableView.setVerticalScrollBarPolicy( GafferUI.ScrollMode._toQt( verticalScrollMode ) )
@@ -241,10 +241,10 @@ class VectorDataWidget( GafferUI.Widget ) :
 					haveResizeableContents = haveResizeableContents or canStretch
 					columnIndex += 1
 
-			QtCompat.setSectionResizeMode(
-				self.__tableView.horizontalHeader(),
-				QtWidgets.QHeaderView.ResizeToContents if haveResizeableContents else QtWidgets.QHeaderView.Fixed
-			)
+			#QtCompat.setSectionResizeMode(
+			#	self.__tableView.horizontalHeader(),
+			#	QtWidgets.QHeaderView.ResizeToContents if haveResizeableContents else QtWidgets.QHeaderView.Fixed
+			#)
 
 			self.__tableView.horizontalHeader().setStretchLastSection( canStretch )
 			horizontalSizePolicy = QtWidgets.QSizePolicy.Expanding
