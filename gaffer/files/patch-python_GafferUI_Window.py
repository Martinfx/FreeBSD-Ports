--- python/GafferUI/Window.py.orig	2025-03-12 17:53:38 UTC
+++ python/GafferUI/Window.py
@@ -43,10 +43,10 @@ import Gaffer
 import GafferUI
 import Gaffer
 
-from Qt import QtCore
-from Qt import QtGui
-from Qt import QtWidgets
-import Qt
+from PyQt5 import QtCore
+from PyQt5 import QtGui
+from PyQt5 import QtWidgets
+import PyQt5
 
 class Window( GafferUI.ContainerWidget ) :
 
