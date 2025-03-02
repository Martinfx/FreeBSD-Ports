--- src/GafferUIModule/GLWidgetBinding.cpp.orig	2025-03-02 20:21:30 UTC
+++ src/GafferUIModule/GLWidgetBinding.cpp
@@ -41,7 +41,12 @@
 #include "IECore/Exception.h"
 #include "IECore/MessageHandler.h"
 
-#include "QtOpenGL/QGLWidget"
+#include <QtCore/QtGlobal>
+#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
+#include <QtOpenGLWidgets/QOpenGLWidget>
+#else
+#include <QtOpenGL/QGLWidget>
+#endif
 
 #if defined( __linux__ )
 #include "GL/glx.h" // Must come after Qt!
