--- pxr/imaging/garch/glPlatformDebugWindowGLX.cpp.orig	2026-04-24 18:55:54 UTC
+++ pxr/imaging/garch/glPlatformDebugWindowGLX.cpp
@@ -40,7 +40,9 @@ Garch_GLPlatformDebugWindow::Init(const
         GLX_BLUE_SIZE, 8,
         GLX_DEPTH_SIZE, 24,
         GLX_SAMPLE_BUFFERS, (nSamples > 1 ? 1 : 0),
-        GLX_SAMPLES, nSamples,
+        // GLX_SAMPLES is a minimum, and without multisampling a value of 1
+        // excludes all the configs without sample buffers (e.g. Mesa's).
+        GLX_SAMPLES, (nSamples > 1 ? nSamples : 0),
         None
     };
 
