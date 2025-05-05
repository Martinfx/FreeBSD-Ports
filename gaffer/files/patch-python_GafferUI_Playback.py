--- python/GafferUI/Playback.py.orig	2025-03-12 17:53:39 UTC
+++ python/GafferUI/Playback.py
@@ -40,7 +40,7 @@ import GafferUI
 import Gaffer
 import GafferUI
 
-from Qt import QtCore
+from PyQt5 import QtCore
 
 ## The Playback class controls a Context to facilitate animation
 # playback. It provides methods for starting and stopping playback,
