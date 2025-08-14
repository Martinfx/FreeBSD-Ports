--- python/GafferUI/Frame.py.orig	2025-03-12 17:53:38 UTC
+++ python/GafferUI/Frame.py
@@ -39,7 +39,7 @@ import GafferUI
 
 import GafferUI
 
-from Qt import QtWidgets
+from PyQt5 import QtWidgets
 
 class Frame( GafferUI.ContainerWidget ) :
 
