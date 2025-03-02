--- src/GafferUIModule/GLWidgetBinding.cpp.orig	2025-03-02 20:21:30 UTC
+++ src/GafferUIModule/GLWidgetBinding.cpp
@@ -40,8 +40,7 @@
 
 #include "IECore/Exception.h"
 #include "IECore/MessageHandler.h"
-
-#include "QtOpenGL/QGLWidget"
+#include <QtOpenGL/QGLWidget>
 
 #if defined( __linux__ )
 #include "GL/glx.h" // Must come after Qt!
