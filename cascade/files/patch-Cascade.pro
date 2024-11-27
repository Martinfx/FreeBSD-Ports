--- Cascade.pro.orig	2023-12-18 06:18:32 UTC
+++ Cascade.pro
@@ -336,6 +336,25 @@ linux-g++ {
     CONFIG(release, debug|release): DESTDIR = $$OUT_PWD/release
 }
 
+equals(QMAKE_CXX, clang++)
+{	
+	INCLUDEPATH+= -I/usr/local/include	
+	LIBS += -L/usr/local/lib -lOpenImageIO -lOpenImageIO_Util
+    LIBS += -lSPIRV \
+    -lSPIRV-Tools-opt \
+    -lSPIRV-Tools \
+    -lMachineIndependent \
+    -lglslang \
+    -lglslang-default-resource-limits \
+    -lOSDependent \
+    -lOGLCompiler \
+    -lGenericCodeGen \
+	-ltbb
+    
+    CONFIG(debug, debug|release): DESTDIR = $$OUT_PWD/debug
+    CONFIG(release, debug|release): DESTDIR = $$OUT_PWD/release
+}
+
 win32-msvc* {
     DEPENDENCY_ROOT = vcpkg_installed/x64-windows
     LIB_ROOT = ../vcpkg_installed/x64-windows
