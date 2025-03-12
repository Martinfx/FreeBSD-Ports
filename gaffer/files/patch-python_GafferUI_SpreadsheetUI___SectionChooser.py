--- python/GafferUI/SpreadsheetUI/_SectionChooser.py.orig	2025-03-12 17:53:39 UTC
+++ python/GafferUI/SpreadsheetUI/_SectionChooser.py
@@ -43,8 +43,8 @@ import GafferUI
 import Gaffer
 import GafferUI
 
-from Qt import QtCore
-from Qt import QtWidgets
+from PyQt5 import QtCore
+from PyQt5 import QtWidgets
 
 class _SectionChooser( GafferUI.Widget ) :
 
