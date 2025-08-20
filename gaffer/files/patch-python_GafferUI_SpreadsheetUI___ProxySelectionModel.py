--- python/GafferUI/SpreadsheetUI/_ProxySelectionModel.py.orig	2025-03-12 17:53:39 UTC
+++ python/GafferUI/SpreadsheetUI/_ProxySelectionModel.py
@@ -34,7 +34,7 @@
 #
 ##########################################################################
 
-from Qt import QtCore
+from PyQt5 import QtCore
 
 class _ProxySelectionModel( QtCore.QItemSelectionModel ) :
 
