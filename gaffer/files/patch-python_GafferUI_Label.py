--- python/GafferUI/Label.py.orig	2025-03-12 17:53:39 UTC
+++ python/GafferUI/Label.py
@@ -38,8 +38,8 @@ import GafferUI
 import Gaffer
 import GafferUI
 
-from Qt import QtWidgets
-from Qt import QtCore
+from PyQt5 import QtWidgets
+from PyQt5 import QtCore
 
 class Label( GafferUI.Widget ) :
 
