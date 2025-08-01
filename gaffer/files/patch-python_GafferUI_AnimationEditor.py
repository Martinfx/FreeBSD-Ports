--- python/GafferUI/AnimationEditor.py.orig	2025-03-12 17:53:38 UTC
+++ python/GafferUI/AnimationEditor.py
@@ -41,7 +41,7 @@ import imath
 
 import imath
 
-from Qt import QtWidgets
+from PyQt5 import QtWidgets
 
 # In order to have Widgets that depend on this filter update properly, we
 # conceptually treat all selected nodes as part of the filter. That makes sense
