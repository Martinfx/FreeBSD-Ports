--- python/GafferUITest/WindowTest.py.orig	2025-03-12 17:53:39 UTC
+++ python/GafferUITest/WindowTest.py
@@ -50,8 +50,8 @@ import GafferUITest
 import GafferUI
 import GafferUITest
 
-from Qt import QtGui
-from Qt import QtWidgets
+from PyQt5 import QtGui
+from PyQt5 import QtWidgets
 
 class TestWidget( GafferUI.Widget ) :
 
