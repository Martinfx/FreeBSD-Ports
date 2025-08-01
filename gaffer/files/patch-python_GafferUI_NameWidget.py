--- python/GafferUI/NameWidget.py.orig	2025-03-12 17:53:38 UTC
+++ python/GafferUI/NameWidget.py
@@ -40,8 +40,8 @@ import GafferUI
 import Gaffer
 import GafferUI
 
-from Qt import QtCore
-from Qt import QtGui
+from PyQt5 import QtCore
+from PyQt5 import QtGui
 
 class NameWidget( GafferUI.TextWidget ) :
 
