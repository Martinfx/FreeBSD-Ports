--- python/GafferUI/Enums.py.orig	2025-03-12 17:37:19 UTC
+++ python/GafferUI/Enums.py
@@ -38,7 +38,7 @@ import GafferUI
 
 import GafferUI
 
-from Qt import QtCore
+from PyQt5 import QtCore
 
 ## \todo Move other enums here - ListContainer.Orientation for instance.
 __all__ = [ "HorizontalAlignment", "VerticalAlignment", "Edge", "ScrollMode" ]
