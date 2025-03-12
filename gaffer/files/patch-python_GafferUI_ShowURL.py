--- python/GafferUI/ShowURL.py.orig	2025-03-12 17:53:38 UTC
+++ python/GafferUI/ShowURL.py
@@ -41,8 +41,8 @@ import GafferUI
 
 import GafferUI
 
-from Qt import QtCore
-from Qt import QtGui
+from PyQt5 import QtCore
+from PyQt5 import QtGui
 
 def showURL( url ) :
 
