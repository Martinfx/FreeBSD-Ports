--- core/DesktopEditor/doctrenderer/app_builder/main.cpp.orig	2025-09-24 06:04:08 UTC
+++ core/DesktopEditor/doctrenderer/app_builder/main.cpp
@@ -35,7 +35,7 @@
 #include "../../common/File.h"
 #include "../../common/SystemUtils.h"
 
-#ifdef LINUX
+#if defined(LINUX) || defined(__FreeBSD__)
 #include "../../../DesktopEditor/common/File.h"
 #endif
 
