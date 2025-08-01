--- python/GafferUI/Widget.py.orig	2025-03-12 17:53:38 UTC
+++ python/GafferUI/Widget.py
@@ -46,9 +46,9 @@ from ._StyleSheet import _styleSheet
 import GafferUI
 from ._StyleSheet import _styleSheet
 
-from Qt import QtCore
-from Qt import QtGui
-from Qt import QtWidgets
+from PyQt5 import QtCore
+from PyQt5 import QtGui
+from PyQt5 import QtWidgets
 
 class _WidgetMetaclass( Gaffer.Signals.Trackable.__class__ ) :
 
