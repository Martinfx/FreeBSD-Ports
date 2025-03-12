--- python/GafferUI/PlugWidget.py.orig	2025-03-12 17:53:38 UTC
+++ python/GafferUI/PlugWidget.py
@@ -40,8 +40,8 @@ import GafferUI
 import Gaffer
 import GafferUI
 
-from Qt import QtCore
-from Qt import QtWidgets
+from PyQt5 import QtCore
+from PyQt5 import QtWidgets
 
 ## The PlugWidget combines a LabelPlugValueWidget with a second PlugValueWidget
 ## suitable for editing the plug.
