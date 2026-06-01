--- src/GafferModule/GafferModule.cpp.orig	2026-05-27 19:02:41 UTC
+++ src/GafferModule/GafferModule.cpp
@@ -95,6 +95,10 @@ static char **environ = *_NSGetEnviron();
 static char **environ = *_NSGetEnviron();
 #endif
 
+#ifdef __FreeBSD__
+extern char **environ;
+#endif
+
 using namespace boost::python;
 using namespace Gaffer;
 using namespace GafferModule;
