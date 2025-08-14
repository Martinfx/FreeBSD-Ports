--- python/GafferUITest/EventLoopTest.py.orig	2025-03-12 17:53:39 UTC
+++ python/GafferUITest/EventLoopTest.py
@@ -46,8 +46,8 @@ import GafferUITest
 import GafferUI
 import GafferUITest
 
-from Qt import QtCore
-from Qt import QtWidgets
+from PyQt5 import QtCore
+from PyQt5 import QtWidgets
 
 class EventLoopTest( GafferUITest.TestCase ) :
 
