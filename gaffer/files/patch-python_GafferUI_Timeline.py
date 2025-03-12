--- python/GafferUI/Timeline.py.orig	2025-03-12 17:53:38 UTC
+++ python/GafferUI/Timeline.py
@@ -40,9 +40,9 @@ import GafferUI
 import Gaffer
 import GafferUI
 
-from Qt import QtCore
-from Qt import QtGui
-from Qt import QtWidgets
+from PyQt5 import QtCore
+from PyQt5 import QtGui
+from PyQt5 import QtWidgets
 
 ## The Timeline presents a time slider which edits the frame
 # entry of a context.
