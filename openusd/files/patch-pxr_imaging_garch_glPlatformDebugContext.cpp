--- pxr/imaging/garch/glPlatformDebugContext.cpp.orig	2026-02-23 22:54:59 UTC
+++ pxr/imaging/garch/glPlatformDebugContext.cpp
@@ -34,7 +34,7 @@ GarchGLPlatformDebugContext::IsEnabledCo
 PXR_NAMESPACE_CLOSE_SCOPE
 
 ////////////////////////////////////////////////////////////
-#if defined(ARCH_OS_LINUX)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD)
 
 #include <GL/glx.h>
 #include <GL/glxtokens.h>
