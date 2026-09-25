--- pxr/imaging/garch/glPlatformContext.h.orig	2026-02-23 22:54:59 UTC
+++ pxr/imaging/garch/glPlatformContext.h
@@ -15,7 +15,7 @@
 #include <cstddef>
 #include <functional>
 
-#if defined(ARCH_OS_LINUX)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD)
 
 #include "pxr/imaging/garch/glPlatformContextGLX.h"
 
