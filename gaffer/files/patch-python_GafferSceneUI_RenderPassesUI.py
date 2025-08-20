--- python/GafferSceneUI/RenderPassesUI.py.orig	2025-03-12 17:53:39 UTC
+++ python/GafferSceneUI/RenderPassesUI.py
@@ -41,7 +41,7 @@ import GafferSceneUI
 import GafferScene
 import GafferSceneUI
 
-from Qt import QtGui
+from PyQt5 import QtGui
 
 Gaffer.Metadata.registerNode(
 
