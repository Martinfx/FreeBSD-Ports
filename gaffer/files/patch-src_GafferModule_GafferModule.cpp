--- src/GafferModule/GafferModule.cpp.orig	2025-10-29 19:40:56 UTC
+++ src/GafferModule/GafferModule.cpp
@@ -98,6 +98,10 @@ static char **environ = *_NSGetEnviron();
 static char **environ = *_NSGetEnviron();
 #endif
 
+#ifdef __FreeBSD__
+extern char **environ;
+#endif
+
 #ifdef _MSC_VER
 #include "IECore/MessageHandler.h"
 
