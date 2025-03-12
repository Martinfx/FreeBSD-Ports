--- python/GafferUI/BackgroundTaskDialogue.py.orig	2025-03-12 17:53:39 UTC
+++ python/GafferUI/BackgroundTaskDialogue.py
@@ -45,7 +45,7 @@ import GafferUI
 import Gaffer
 import GafferUI
 
-from Qt import QtCore
+from PyQt5 import QtCore
 
 class BackgroundTaskDialogue( GafferUI.Dialogue ) :
 
