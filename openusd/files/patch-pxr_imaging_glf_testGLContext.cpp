--- pxr/imaging/glf/testGLContext.cpp.orig	2026-04-24 18:55:54 UTC
+++ pxr/imaging/glf/testGLContext.cpp
@@ -62,6 +62,14 @@ Glf_TestGLContextPrivate::Glf_TestGLCont
     int n;
     GLXFBConfig * fbConfigs = glXChooseFBConfig( _dpy, 
         DefaultScreen(_dpy), attribs, &n );
+    // Not every implementation has multisampled configs (e.g. Mesa's
+    // llvmpipe with Xvfb), so fall back to one without multisampling.
+    if (!fbConfigs || n == 0) {
+        static int attribsNoMS[] = { GLX_DOUBLEBUFFER, True,
+            GLX_RED_SIZE, 8, GLX_GREEN_SIZE, 8, GLX_BLUE_SIZE, 8, None };
+        fbConfigs = glXChooseFBConfig( _dpy,
+            DefaultScreen(_dpy), attribsNoMS, &n );
+    }
 
     GLXContext share = other ? other->_context : 0;
 
