--- python/GafferUI/Collapsible.py.orig	2025-03-12 17:53:39 UTC
+++ python/GafferUI/Collapsible.py
@@ -38,7 +38,7 @@ import GafferUI
 import Gaffer
 import GafferUI
 
-from Qt import QtWidgets
+from PyQt5 import QtWidgets
 
 ## The Collapsible container provides an easy means of controlling the
 # visibility of a child Widget. A labelled heading is always visible
