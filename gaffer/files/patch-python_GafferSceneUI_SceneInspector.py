--- python/GafferSceneUI/SceneInspector.py.orig	2025-03-12 17:53:39 UTC
+++ python/GafferSceneUI/SceneInspector.py
@@ -1246,7 +1246,7 @@ class _SectionWindow( GafferUI.Window ) :
 # Inheritance section
 ##########################################################################
 
-from Qt import QtWidgets
+from PyQt5 import QtWidgets
 
 class _Rail( GafferUI.ListContainer ) :
 
