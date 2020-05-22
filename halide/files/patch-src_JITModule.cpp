--- src/JITModule.cpp.orig	2019-10-20 19:53:51 UTC
+++ src/JITModule.cpp
@@ -105,6 +105,17 @@ void load_opengl() {    
         llvm::sys::DynamicLibrary::LoadLibraryPermanently("/System/Library/Frameworks/OpenGL.framework/OpenGL", &error);
         user_assert(error.empty()) << "Could not find OpenGL.framework\n";
     }
+#elif defined(__FreeBSD__)|| defined(__OpenBSD__) || defined( __NetBSD__) || defined(__DragonFly__)
+    if (have_symbol("glXGetCurrentContext") && have_symbol("glDeleteTextures")) {
+        debug(1) << "OpenGL support code already linked in...\n";
+    } else {
+        debug(1) << "Looking for OpenGL support code...\n";
+        string error;
+        llvm::sys::DynamicLibrary::LoadLibraryPermanently("libGL.so.1", &error);
+        user_assert(error.empty()) << "Could not find libGL.so\n";
+        llvm::sys::DynamicLibrary::LoadLibraryPermanently("libX11.so", &error);
+        user_assert(error.empty()) << "Could not find libX11.so\n";
+    }
 #else
     internal_error << "JIT support for OpenGL on anything other than linux or OS X not yet implemented\n";
 #endif
