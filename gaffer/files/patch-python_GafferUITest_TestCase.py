--- python/GafferUITest/TestCase.py.orig	2025-03-12 17:53:39 UTC
+++ python/GafferUITest/TestCase.py
@@ -41,8 +41,8 @@ import weakref
 import inspect
 import weakref
 
-from Qt import QtCore
-from Qt import QtCompat
+from PyQt5 import QtCore
+from PyQt5 import QtCompat
 
 import IECore
 
