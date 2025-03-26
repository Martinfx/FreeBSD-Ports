--- python/GafferSceneUI/AttributeEditor.py.orig	2025-03-12 17:53:39 UTC
+++ python/GafferSceneUI/AttributeEditor.py
@@ -47,7 +47,7 @@ from . import _GafferSceneUI
 
 from . import _GafferSceneUI
 
-from Qt import QtWidgets
+from PyQt5 import QtWidgets
 
 class AttributeEditor( GafferSceneUI.SceneEditor ) :
 
