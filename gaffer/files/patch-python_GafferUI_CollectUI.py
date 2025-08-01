--- python/GafferUI/CollectUI.py.orig	2025-03-12 17:53:38 UTC
+++ python/GafferUI/CollectUI.py
@@ -45,7 +45,7 @@ from ._TableView import _TableView
 
 from ._TableView import _TableView
 
-from Qt import QtCore
+from PyQt5 import QtCore
 
 Gaffer.Metadata.registerNode(
 
