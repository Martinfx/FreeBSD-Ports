--- Engine/NatronEngine/natronengine_python.h.orig	2020-12-09 21:16:43 UTC
+++ Engine/NatronEngine/natronengine_python.h
@@ -4,22 +4,12 @@
 #define SBK_NATRONENGINE_PYTHON_H
 
 #include <sbkpython.h>
-#include <conversions.h>
 #include <sbkenum.h>
 #include <basewrapper.h>
 #include <bindingmanager.h>
 #include <memory>
 
 #include <pysidesignal.h>
-// Module Includes
-CLANG_DIAG_OFF(deprecated)
-CLANG_DIAG_OFF(uninitialized)
-CLANG_DIAG_OFF(keyword-macro)
-#include <pyside_qtcore_python.h> // produces warnings
-CLANG_DIAG_ON(deprecated)
-CLANG_DIAG_ON(uninitialized)
-CLANG_DIAG_ON(keyword-macro)
-
 // Binded library includes
 #include <Enums.h>
 #include <RectD.h>
@@ -35,7 +25,6 @@ CLANG_DIAG_ON(keyword-macro)
 // Conversion Includes - Primitive Types
 #include <QString>
 #include <signalmanager.h>
-#include <typeresolver.h>
 #include <QtConcurrentFilter>
 #include <QStringList>
 #include <qabstractitemmodel.h>
@@ -48,7 +37,6 @@ CLANG_DIAG_ON(keyword-macro)
 #include <map>
 #include <QVector>
 #include <QPair>
-#include <pysideconversions.h>
 #include <QSet>
 #include <vector>
 #include <QQueue>
