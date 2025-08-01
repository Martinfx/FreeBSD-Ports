--- python/GafferUI/ProgressBar.py.orig	2025-03-12 17:53:39 UTC
+++ python/GafferUI/ProgressBar.py
@@ -36,7 +36,7 @@ import GafferUI
 
 import GafferUI
 
-from Qt import QtWidgets
+from PyQt5 import QtWidgets
 
 class ProgressBar( GafferUI.Widget ) :
 
