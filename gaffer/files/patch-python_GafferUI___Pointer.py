--- python/GafferUI/_Pointer.py.orig	2025-03-12 17:53:38 UTC
+++ python/GafferUI/_Pointer.py
@@ -36,8 +36,8 @@ import GafferUI
 
 import GafferUI
 
-from Qt import QtGui
-from Qt import QtWidgets
+from PyQt5 import QtGui
+from PyQt5 import QtWidgets
 
 # The pointer is specified via the C++ Pointer class, but to actually change
 # the qt pointer we use this python code which is triggered by Pointer::changedSignal().
