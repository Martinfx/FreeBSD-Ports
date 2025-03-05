--- pxr/imaging/plugin/hioOiio/pch.h.orig	2025-03-05 13:45:44 UTC
+++ pxr/imaging/plugin/hioOiio/pch.h
@@ -10,7 +10,7 @@
 #define TF_MAX_ARITY 7
 #include "pxr/pxr.h"
 #include "pxr/base/arch/defines.h"
-#if defined(ARCH_OS_LINUX)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD)
 #include <unistd.h>
 #endif
 #include <algorithm>
