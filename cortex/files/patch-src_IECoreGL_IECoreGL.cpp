--- src/IECoreGL/IECoreGL.cpp.orig	2026-09-10 21:49:58 UTC
+++ src/IECoreGL/IECoreGL.cpp
@@ -46,7 +46,7 @@
 
 #if defined( __APPLE__ )
 #include <OpenGL/OpenGL.h>
-#elif defined( __linux__ )
+#elif defined( __linux__ ) || defined( __FreeBSD__ )
 #include "GL/glx.h"
 #elif defined( _MSC_VER )
 #include <windows.h>
@@ -139,11 +139,22 @@
 
 			CGLSetCurrentContext( context );
 
-#elif defined( __linux__ )
+#elif defined( __linux__ ) || defined( __FreeBSD__ )
 
 			int numFBConfigs = 0;
 			Display *display = XOpenDisplay( NULL );
+			if( !display )
+			{
+				IECore::msg( IECore::Msg::Error, "IECoreGL::init", "Failed to open X display." );
+				return;
+			}
+
 			GLXFBConfig *fbConfigs = glXChooseFBConfig( display, DefaultScreen( display ), NULL, &numFBConfigs );
+			if( !fbConfigs || !numFBConfigs )
+			{
+				IECore::msg( IECore::Msg::Error, "IECoreGL::init", "No compatible framebuffer configurations available." );
+				return;
+			}
 
 			int contextAttribs[] =
 			{
@@ -335,13 +346,16 @@
 		const GLenum initStatus = glewInit();
 		if( initStatus!=GLEW_OK )
 		{
-			IECore::msg( IECore::Msg::Error, "IECoreGL::init", "GLEW initialisation failed ({}).", *glewGetErrorString( initStatus ) );
+			IECore::msg( IECore::Msg::Error, "IECoreGL::init", "GLEW initialisation failed ({}).", (const char *)glewGetErrorString( initStatus ) );
 		}
 		init = true;
 
 		const char *s = (const char *)glGetString( GL_SHADING_LANGUAGE_VERSION );
 		int major = 0; int minor = 0;
-		sscanf( s, "%d.%d", &major, &minor );
+		if( s )
+		{
+			sscanf( s, "%d.%d", &major, &minor );
+		}
 		g_glslVersion = major * 100 + minor;
 
 #if defined( __APPLE__ )
