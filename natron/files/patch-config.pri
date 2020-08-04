--- config.pri.orig	2020-08-03 21:35:42 UTC
+++ config.pri
@@ -0,0 +1,20 @@
+boost: LIBS += -lboost_serialization
+PKGCONFIG += expat
+PKGCONFIG += fontconfig
+cairo {
+        PKGCONFIG += cairo
+        LIBS -=  $$system(pkg-config --variable=libdir cairo)/libcairo.a
+}
+pyside {
+        PKGCONFIG -= pyside2
+        INCLUDEPATH += $$system(pkg-config --variable=includedir pyside2)
+        INCLUDEPATH += $$system(pkg-config --variable=includedir pyside2)/QtCore
+        INCLUDEPATH += $$system(pkg-config --variable=includedir pyside2)/QtGui
+        INCLUDEPATH += $$system(pkg-config --variable=includedir QtGui)
+        LIBS += -lpyside2.cpython-37m
+}
+shiboken {
+        PKGCONFIG -= shiboken2
+        INCLUDEPATH += $$system(pkg-config --variable=includedir shiboken2)
+        LIBS += -lshiboken2.cpython-37m
+}
