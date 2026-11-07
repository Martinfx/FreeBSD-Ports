--- core/DesktopEditor/doctrenderer/app_builder/main.cpp.orig	2026-11-05 00:00:00 UTC
+++ core/DesktopEditor/doctrenderer/app_builder/main.cpp
@@ -38,7 +38,7 @@
 #include "../../common/File.h"
 #include "../../common/SystemUtils.h"
 
-#ifdef LINUX
+#if defined(LINUX) || defined(__FreeBSD__)
 #include "../../../DesktopEditor/common/File.h"
 #endif
 
