--- python/GafferUI/LabelPlugValueWidget.py.orig	2025-03-12 17:53:39 UTC
+++ python/GafferUI/LabelPlugValueWidget.py
@@ -37,7 +37,7 @@ import GafferUI
 import Gaffer
 import GafferUI
 
-from Qt import QtWidgets
+from PyQt5 import QtWidgets
 
 ## A simple PlugValueWidget which just displays the name of the plug,
 # with the popup action menu for the plug.
