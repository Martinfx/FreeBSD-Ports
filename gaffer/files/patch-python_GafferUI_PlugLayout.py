--- python/GafferUI/PlugLayout.py.orig	2025-03-12 17:53:38 UTC
+++ python/GafferUI/PlugLayout.py
@@ -45,7 +45,7 @@ import GafferUI
 import Gaffer
 import GafferUI
 
-from Qt import QtWidgets
+from PyQt5 import QtWidgets
 
 ## A class for laying out widgets to represent all the plugs held on a particular parent.
 #
