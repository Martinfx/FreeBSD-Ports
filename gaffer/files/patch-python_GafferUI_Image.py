--- python/GafferUI/Image.py.orig	2025-03-12 17:53:38 UTC
+++ python/GafferUI/Image.py
@@ -42,9 +42,9 @@ import GafferUI
 
 import GafferUI
 
-from Qt import QtCore
-from Qt import QtGui
-from Qt import QtWidgets
+from PyQt5 import QtCore
+from PyQt5 import QtGui
+from PyQt5 import QtWidgets
 
 ## The Image widget displays an image. This can be specified
 # as either a filename or an IECore.ImagePrimitive.
