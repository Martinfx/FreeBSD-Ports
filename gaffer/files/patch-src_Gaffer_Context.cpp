--- src/Gaffer/Context.cpp.orig	2024-12-04 06:15:43 UTC
+++ src/Gaffer/Context.cpp
@@ -48,6 +48,9 @@ static char **environ = *_NSGetEnviron();
 #ifdef __APPLE__
 #include <crt_externs.h>
 static char **environ = *_NSGetEnviron();
+#elif defined(__FreeBSD__)
+#include <unistd.h>
+extern char **environ;
 #endif
 
 using namespace Gaffer;
