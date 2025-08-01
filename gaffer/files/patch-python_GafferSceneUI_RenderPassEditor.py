--- python/GafferSceneUI/RenderPassEditor.py.orig	2025-03-12 17:53:39 UTC
+++ python/GafferSceneUI/RenderPassEditor.py
@@ -52,7 +52,7 @@ from . import _GafferSceneUI
 
 from . import _GafferSceneUI
 
-from Qt import QtWidgets
+from PyQt5 import QtWidgets
 
 class RenderPassEditor( GafferSceneUI.SceneEditor ) :
 
