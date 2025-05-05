--- python/GafferDispatchUI/DispatcherUI.py.orig	2025-03-12 17:53:38 UTC
+++ python/GafferDispatchUI/DispatcherUI.py
@@ -46,7 +46,7 @@ from GafferUI._StyleSheet import _styleColors
 
 from GafferUI._StyleSheet import _styleColors
 
-from Qt import QtGui
+from PyQt5 import QtGui
 
 Gaffer.Metadata.registerNode(
 
