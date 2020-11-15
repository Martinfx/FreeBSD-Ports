--- global.pri.orig	2020-10-30 05:13:34 UTC
+++ global.pri
@@ -38,9 +38,9 @@ run-without-python {
 } else {
     # from <https://docs.python.org/3/c-api/intro.html#include-files>:
     # "Since Python may define some pre-processor definitions which affect the standard headers on some systems, you must include Python.h before any standard headers are included."
-    CONFIG += python
-    QMAKE_CFLAGS += -include Python.h
-    QMAKE_CXXFLAGS += -include Python.h
+    CONFIG += python3
+    #QMAKE_CFLAGS += -include Python.h
+    #QMAKE_CXXFLAGS += -include Python.h
 }
 
 *g++* | *clang* | *xcode* {
@@ -416,7 +416,7 @@ unix {
      # User may specify an alternate python2-config from the command-line,
      # as in "qmake PYTHON_CONFIG=python2.7-config"
      isEmpty(PYTHON_CONFIG) {
-         PYTHON_CONFIG = python2-config
+         PYTHON_CONFIG = python3.7-config
      }
      python {
           #PKGCONFIG += python
@@ -428,9 +428,9 @@ unix {
      }
 
      equals(QT_MAJOR_VERSION, 5) {
-         shiboken:  INCLUDEPATH += $$system(python2 -c \"from distutils.sysconfig import get_python_lib; print(get_python_lib())\")/PySide2/include/shiboken
-    	 pyside:    INCLUDEPATH += $$system(python2 -c \"from distutils.sysconfig import get_python_lib; print(get_python_lib())\")/PySide2/include/PySide2
-   	 pyside:    INCLUDEPATH += $$system(python2 -c \"from distutils.sysconfig import get_python_lib; print(get_python_lib())\")/PySide2/include/PySide2/QtCore
+         shiboken:  INCLUDEPATH += $$system(python3 -c \"from distutils.sysconfig import get_python_lib; print(get_python_lib())\")/include/shiboken2
+    	 pyside:    INCLUDEPATH += $$system(python3 -c \"from distutils.sysconfig import get_python_lib; print(get_python_lib())\")/PySide2/include/PySide2
+   	 pyside:    INCLUDEPATH += $$system(python3 -c \"from distutils.sysconfig import get_python_lib; print(get_python_lib())\")/PySide2/include/PySide2/QtCore
      }
 
      equals(QT_MAJOR_VERSION, 4) {
