--- python/GafferUI/MessageWidget.py.orig	2026-09-24 19:41:12 UTC
+++ python/GafferUI/MessageWidget.py
@@ -1335,8 +1335,15 @@ class _MessageTableFilterModel( QtCore.Q
 
 	def setLevel( self, level ) :
 
-		self.__maxLevel = level
-		self.invalidateFilter()
+		# Qt 6.10 deprecates `invalidateFilter()` in favour of
+		# `beginFilterChange()` and `endFilterChange()`.
+		if hasattr( self, "beginFilterChange" ) :
+			self.beginFilterChange()
+			self.__maxLevel = level
+			self.endFilterChange( QtCore.QSortFilterProxyModel.Direction.Rows )
+		else :
+			self.__maxLevel = level
+			self.invalidateFilter()
 
 	def getLevel( self ) :
 
