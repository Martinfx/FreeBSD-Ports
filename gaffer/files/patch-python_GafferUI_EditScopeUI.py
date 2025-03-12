--- python/GafferUI/EditScopeUI.py.orig	2025-03-12 17:53:38 UTC
+++ python/GafferUI/EditScopeUI.py
@@ -46,8 +46,8 @@ from GafferUI._StyleSheet import _styleColors
 import GafferUI
 
 from GafferUI._StyleSheet import _styleColors
-from Qt import QtGui
-from Qt import QtWidgets
+from PyQt5 import QtGui
+from PyQt5 import QtWidgets
 
 Gaffer.Metadata.registerNode(
 
