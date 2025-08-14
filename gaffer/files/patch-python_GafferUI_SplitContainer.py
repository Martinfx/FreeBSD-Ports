--- python/GafferUI/SplitContainer.py.orig	2025-03-12 17:53:38 UTC
+++ python/GafferUI/SplitContainer.py
@@ -39,8 +39,8 @@ import GafferUI
 
 import GafferUI
 
-from Qt import QtCore
-from Qt import QtWidgets
+from PyQt5 import QtCore
+from PyQt5 import QtWidgets
 
 ## \todo Support other list operations for child access
 class SplitContainer( GafferUI.ContainerWidget ) :
