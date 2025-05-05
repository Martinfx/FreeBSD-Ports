--- python/GafferUI/PathWidget.py.orig	2025-03-12 17:53:38 UTC
+++ python/GafferUI/PathWidget.py
@@ -45,7 +45,7 @@ import GafferUI
 import Gaffer
 import GafferUI
 
-from Qt import QtCore
+from PyQt5 import QtCore
 
 class PathWidget( GafferUI.TextWidget ) :
 
