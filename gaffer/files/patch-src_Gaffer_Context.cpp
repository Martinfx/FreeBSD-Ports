--- src/Gaffer/Context.cpp.orig	2026-09-24 19:41:12 UTC
+++ src/Gaffer/Context.cpp
@@ -48,6 +48,9 @@
 #ifdef __APPLE__
 #include <crt_externs.h>
 static char **environ = *_NSGetEnviron();
+#elif defined( __FreeBSD__ )
+// FreeBSD doesn't declare `environ` in any header.
+extern char **environ;
 #endif
 
 using namespace Gaffer;
