--- python/GafferUI/DeferredPathPreview.py.orig	2025-03-12 17:53:39 UTC
+++ python/GafferUI/DeferredPathPreview.py
@@ -43,7 +43,7 @@ import GafferUI
 
 import GafferUI
 
-from Qt import QtCore
+from PyQt5 import QtCore
 
 ## This abstract class provides a base for all PathPreviewWidgets which may
 # take some time in generating the preview, and would therefore like to do it
