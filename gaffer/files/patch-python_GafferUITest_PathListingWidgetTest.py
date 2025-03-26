--- python/GafferUITest/PathListingWidgetTest.py.orig	2025-03-12 17:53:39 UTC
+++ python/GafferUITest/PathListingWidgetTest.py
@@ -51,7 +51,7 @@ import GafferUITest
 from GafferUI import _GafferUI
 import GafferUITest
 
-from Qt import QtCore, QtWidgets
+from PyQt5 import QtCore, QtWidgets
 
 class PathListingWidgetTest( GafferUITest.TestCase ) :
 
