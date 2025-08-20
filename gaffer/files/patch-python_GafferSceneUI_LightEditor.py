--- python/GafferSceneUI/LightEditor.py.orig	2025-03-12 17:53:39 UTC
+++ python/GafferSceneUI/LightEditor.py
@@ -49,7 +49,7 @@ from . import _GafferSceneUI
 
 from . import _GafferSceneUI
 
-from Qt import QtWidgets
+from PyQt5 import QtWidgets
 
 class LightEditor( GafferSceneUI.SceneEditor ) :
 
