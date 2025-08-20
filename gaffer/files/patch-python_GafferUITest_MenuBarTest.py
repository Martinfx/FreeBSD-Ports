--- python/GafferUITest/MenuBarTest.py.orig	2025-03-12 17:53:39 UTC
+++ python/GafferUITest/MenuBarTest.py
@@ -45,9 +45,9 @@ import Qt
 import GafferUITest
 
 import Qt
-from Qt import QtCore
-from Qt import QtGui
-from Qt import QtWidgets
+from PyQt5 import QtCore
+from PyQt5 import QtGui
+from PyQt5 import QtWidgets
 
 class MenuBarTest( GafferUITest.TestCase ) :
 
