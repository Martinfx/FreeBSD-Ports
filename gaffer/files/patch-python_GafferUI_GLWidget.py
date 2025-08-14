--- python/GafferUI/GLWidget.py.orig	2025-03-12 17:53:38 UTC
+++ python/GafferUI/GLWidget.py
@@ -55,8 +55,8 @@ import OpenGL.GL as GL
 
 import OpenGL.GL as GL
 
-import Qt
-from Qt import QtCore
+import PyQt5
+from PyQt5 import QtCore
 
 # Importing directly rather than via Qt.py because Qt.py won't expose the
 # Qt-5-only QOpenGLWidget and QSurfaceFormat classes that we need. Their mantra
@@ -67,7 +67,7 @@ from PySide2 import QtWidgets
 # if we can coax the project into bridging Qt 5/6 instead of 4/5?
 from PySide2 import QtGui
 from PySide2 import QtWidgets
-from Qt import QtOpenGL
+from PyQt5 import QtOpenGL
 
 ## The GLWidget is a base class for all widgets which wish to draw using OpenGL.
 # Derived classes override the _draw() method to achieve this.
