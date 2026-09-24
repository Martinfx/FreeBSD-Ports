--- src/GafferModule/GafferModule.cpp.orig	2026-09-24 19:41:12 UTC
+++ src/GafferModule/GafferModule.cpp
@@ -94,6 +94,9 @@
 #ifdef __APPLE__
 #include <crt_externs.h>
 #define environ (*_NSGetEnviron())
+#elif defined( __FreeBSD__ )
+// FreeBSD doesn't declare `environ` in any header.
+extern char **environ;
 #endif
 
 using namespace boost::python;
