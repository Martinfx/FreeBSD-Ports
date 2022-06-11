--- global.pri.orig	2022-06-11 08:19:02 UTC
+++ global.pri
@@ -416,7 +416,7 @@ unix {
      # User may specify an alternate python2-config from the command-line,
      # as in "qmake PYTHON_CONFIG=python2.7-config"
      isEmpty(PYTHON_CONFIG) {
-         PYTHON_CONFIG = python2-config
+         PYTHON_CONFIG = python2.7-config
      }
      python {
           #PKGCONFIG += python
@@ -428,9 +428,9 @@ unix {
      }
 
      equals(QT_MAJOR_VERSION, 5) {
-         shiboken:  INCLUDEPATH += $$system(python2 -c \"from distutils.sysconfig import get_python_lib; print(get_python_lib())\")/PySide2/include/shiboken
-    	 pyside:    INCLUDEPATH += $$system(python2 -c \"from distutils.sysconfig import get_python_lib; print(get_python_lib())\")/PySide2/include/PySide2
-   	 pyside:    INCLUDEPATH += $$system(python2 -c \"from distutils.sysconfig import get_python_lib; print(get_python_lib())\")/PySide2/include/PySide2/QtCore
+         shiboken:  INCLUDEPATH += $$system(python2.7 -c \"from distutils.sysconfig import get_python_lib; print(get_python_lib())\")/PySide2/include/shiboken
+         pyside:    INCLUDEPATH += $$system(python2.7 -c \"from distutils.sysconfig import get_python_lib; print(get_python_lib())\")/PySide2/include/PySide2
+         pyside:    INCLUDEPATH += $$system(python2.7 -c \"from distutils.sysconfig import get_python_lib; print(get_python_lib())\")/PySide2/include/PySide2/QtCore
      }
 
      equals(QT_MAJOR_VERSION, 4) {
