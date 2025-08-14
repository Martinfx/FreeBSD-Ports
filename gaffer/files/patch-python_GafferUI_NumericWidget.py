--- python/GafferUI/NumericWidget.py.orig	2025-03-12 17:53:38 UTC
+++ python/GafferUI/NumericWidget.py
@@ -45,7 +45,7 @@ import GafferUI
 import Gaffer
 import GafferUI
 
-from Qt import QtGui
+from PyQt5 import QtGui
 
 ## \todo Fix bug when pressing up arrow with cursor to left of minus sign
 class NumericWidget( GafferUI.TextWidget ) :
