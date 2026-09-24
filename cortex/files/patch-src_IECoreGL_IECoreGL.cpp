--- src/IECoreGL/IECoreGL.cpp.orig	2026-09-24 18:05:26 UTC
+++ src/IECoreGL/IECoreGL.cpp
@@ -46,7 +46,7 @@
 
 #if defined( __APPLE__ )
 #include <OpenGL/OpenGL.h>
-#elif defined( __linux__ )
+#elif defined( __linux__ ) || defined( __FreeBSD__ )
 #include "GL/glx.h"
 #elif defined( _MSC_VER )
 #include <windows.h>
@@ -139,7 +139,7 @@ void IECoreGL::init( bool glAlreadyIniti
 
 			CGLSetCurrentContext( context );
 
-#elif defined( __linux__ )
+#elif defined( __linux__ ) || defined( __FreeBSD__ )
 
 			int numFBConfigs = 0;
 			Display *display = XOpenDisplay( NULL );
