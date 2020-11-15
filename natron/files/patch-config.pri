--- config.pri.orig	2020-11-15 00:39:50 UTC
+++ config.pri
@@ -0,0 +1,13 @@
+pyside {
+        PKGCONFIG -= pyside2
+        INCLUDEPATH += $$system(pkg-config --variable=includedir pyside2)
+        INCLUDEPATH += $$system(pkg-config --variable=includedir pyside2)/QtCore
+        INCLUDEPATH += $$system(pkg-config --variable=includedir pyside2)/QtGui
+        INCLUDEPATH += $$system(pkg-config --variable=includedir QtGui)
+        LIBS += -lpyside-python3.7
+}
+shiboken {
+        PKGCONFIG -= shiboken2
+        INCLUDEPATH += $$system(pkg-config --variable=includedir shiboken2)
+        LIBS += -lshiboken-python3.7
+}
