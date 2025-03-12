--- python/GafferUI/_TableView.py.orig	2025-03-12 17:53:38 UTC
+++ python/GafferUI/_TableView.py
@@ -35,8 +35,8 @@
 #
 ##########################################################################
 
-from Qt import QtCore
-from Qt import QtWidgets
+from PyQt5 import QtCore
+from PyQt5 import QtWidgets
 
 # A QTableView derived class with custom size behaviours we want for
 # GafferUI. This is not part of the public API.
