--- python/GafferUI/CodeWidget.py.orig	2025-03-12 17:53:38 UTC
+++ python/GafferUI/CodeWidget.py
@@ -51,7 +51,7 @@ import GafferUI
 import Gaffer
 import GafferUI
 
-from Qt import QtGui
+from PyQt5 import QtGui
 
 class CodeWidget( GafferUI.MultiLineTextWidget ) :
 
