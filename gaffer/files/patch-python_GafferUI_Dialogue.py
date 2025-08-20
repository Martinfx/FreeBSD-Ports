--- python/GafferUI/Dialogue.py.orig	2025-03-12 17:53:38 UTC
+++ python/GafferUI/Dialogue.py
@@ -38,7 +38,7 @@ import GafferUI
 import Gaffer
 import GafferUI
 
-from Qt import QtCore
+from PyQt5 import QtCore
 
 class Dialogue( GafferUI.Window ) :
 
