--- pxr/imaging/garch/glPlatformContext.h.orig	2026-04-24 18:55:54 UTC
+++ pxr/imaging/garch/glPlatformContext.h
@@ -15,7 +15,7 @@
 #include <cstddef>
 #include <functional>
 
-#if defined(ARCH_OS_LINUX)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD)
 
 #include "pxr/imaging/garch/glPlatformContextGLX.h"
 
