--- python/GafferUI/_StyleSheet.py.orig	2025-03-12 17:53:38 UTC
+++ python/GafferUI/_StyleSheet.py
@@ -38,8 +38,8 @@ import string
 import os
 import string
 
-from Qt import QtCore
-from Qt import QtGui
+from PyQt5 import QtCore
+from PyQt5 import QtGui
 
 # Load resource file containing all the files referenced by the stylesheet. In
 # an ideal world we'd be able to trust Qt to load regular `.png` files directly
