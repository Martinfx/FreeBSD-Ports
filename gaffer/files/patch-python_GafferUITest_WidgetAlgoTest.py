--- python/GafferUITest/WidgetAlgoTest.py.orig	2025-03-12 17:53:39 UTC
+++ python/GafferUITest/WidgetAlgoTest.py
@@ -47,7 +47,7 @@ import Qt
 import GafferUITest
 
 import Qt
-from Qt import QtWidgets
+from PyQt5 import QtWidgets
 
 class WidgetAlgoTest( GafferUITest.TestCase ) :
 
