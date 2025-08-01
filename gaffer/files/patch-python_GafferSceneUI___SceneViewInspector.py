--- python/GafferSceneUI/_SceneViewInspector.py.orig	2025-03-12 17:53:39 UTC
+++ python/GafferSceneUI/_SceneViewInspector.py
@@ -47,7 +47,7 @@ import GafferSceneUI
 import GafferUI
 import GafferSceneUI
 
-from Qt import QtWidgets
+from PyQt5 import QtWidgets
 
 # Conceptually this is an embedded context-sensitive SceneInspector for the
 # SceneView. In practice it is implemented completely separately from the
