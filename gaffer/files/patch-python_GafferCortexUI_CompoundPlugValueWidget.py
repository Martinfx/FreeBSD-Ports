--- python/GafferCortexUI/CompoundPlugValueWidget.py.orig	2025-03-12 17:53:38 UTC
+++ python/GafferCortexUI/CompoundPlugValueWidget.py
@@ -40,7 +40,7 @@ import GafferUI
 import Gaffer
 import GafferUI
 
-from Qt import QtWidgets
+from PyQt5 import QtWidgets
 
 # This was the predecessor to the far superior GafferUI.PlugLayout
 # class that we now use. It survives here as a relic because it is
