--- python/GafferUI/CompoundEditor.py.orig	2025-03-12 17:53:38 UTC
+++ python/GafferUI/CompoundEditor.py
@@ -47,9 +47,9 @@ import GafferUI
 import Gaffer
 import GafferUI
 
-from Qt import QtCore
-from Qt import QtGui
-from Qt import QtWidgets
+from PyQt5 import QtCore
+from PyQt5 import QtGui
+from PyQt5 import QtWidgets
 
 class CompoundEditor( GafferUI.Editor ) :
 
