--- python/GafferUI/_Variant.py.orig	2025-03-12 17:53:38 UTC
+++ python/GafferUI/_Variant.py
@@ -37,7 +37,7 @@ import GafferUI
 
 import GafferUI
 
-from Qt import QtCore
+from PyQt5 import QtCore
 
 ## PyQt and PySide differ in their bindings of functions using the
 # QVariant type. PySide doesn't expose QVariant and instead uses
