--- python/GafferUI/NodeEditor.py.orig	2025-03-12 17:53:39 UTC
+++ python/GafferUI/NodeEditor.py
@@ -44,7 +44,7 @@ import GafferUI
 import Gaffer
 import GafferUI
 
-from Qt import QtWidgets
+from PyQt5 import QtWidgets
 
 class NodeEditor( GafferUI.NodeSetEditor ) :
 
