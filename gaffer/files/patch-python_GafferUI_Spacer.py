--- python/GafferUI/Spacer.py.orig	2025-03-12 17:53:38 UTC
+++ python/GafferUI/Spacer.py
@@ -37,7 +37,7 @@ import GafferUI
 
 import GafferUI
 
-from Qt import QtWidgets
+from PyQt5 import QtWidgets
 
 ## \todo Size accessors
 class Spacer( GafferUI.Widget ) :
