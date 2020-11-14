--- global.pri.orig	2020-09-28 11:02:17.128045000 +0200
+++ global.pri	2020-09-28 11:04:49.615442000 +0200
@@ -37,7 +37,7 @@
 } else {
     # from <https://docs.python.org/3/c-api/intro.html#include-files>:
     # "Since Python may define some pre-processor definitions which affect the standard headers on some systems, you must include Python.h before any standard headers are included."
-    CONFIG += python
+    CONFIG += python3
-    QMAKE_CFLAGS += -include Python.h
+    #QMAKE_CFLAGS += -include Python.h
-    QMAKE_CXXFLAGS += -include Python.h
+    #QMAKE_CXXFLAGS += -include Python.h
 }
@@ -415,7 +415,7 @@
      # User may specify an alternate python2-config from the command-line,
      # as in "qmake PYTHON_CONFIG=python2.7-config"
      isEmpty(PYTHON_CONFIG) {
-         PYTHON_CONFIG = python2-config
+         PYTHON_CONFIG = python3-config
      }
      python {
           #PKGCONFIG += python
@@ -427,9 +427,9 @@
      }
 
      equals(QT_MAJOR_VERSION, 5) {
-         shiboken:  INCLUDEPATH += $$system(python2 -c \"from distutils.sysconfig import get_python_lib; print(get_python_lib())\")/PySide2/include/shiboken
-    	 pyside:    INCLUDEPATH += $$system(python2 -c \"from distutils.sysconfig import get_python_lib; print(get_python_lib())\")/PySide2/include/PySide2
-   	 pyside:    INCLUDEPATH += $$system(python2 -c \"from distutils.sysconfig import get_python_lib; print(get_python_lib())\")/PySide2/include/PySide2/QtCore
+         shiboken:  INCLUDEPATH += $$system(python3 -c \"from distutils.sysconfig import get_python_lib; print(get_python_lib())\")/PySide2/include/shiboken
+    	 pyside:    INCLUDEPATH += $$system(python3 -c \"from distutils.sysconfig import get_python_lib; print(get_python_lib())\")/PySide2/include/PySide2
+   	 pyside:    INCLUDEPATH += $$system(python3 -c \"from distutils.sysconfig import get_python_lib; print(get_python_lib())\")/PySide2/include/PySide2/QtCore
      }
 
      equals(QT_MAJOR_VERSION, 4) {

