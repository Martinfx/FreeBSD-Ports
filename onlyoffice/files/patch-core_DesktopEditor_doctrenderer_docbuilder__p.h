--- core/DesktopEditor/doctrenderer/docbuilder_p.h.orig	2025-09-24 06:04:08 UTC
+++ core/DesktopEditor/doctrenderer/docbuilder_p.h
@@ -48,7 +48,7 @@
 #include "embed/NativeControlEmbed.h"
 #include "embed/GraphicsEmbed.h"
 #include "embed/Default.h"
-#ifdef LINUX
+#if defined(LINUX) || defined(__FreeBSD__)
 #include <unistd.h>
 #include <sys/wait.h>
 #include <stdio.h>
@@ -814,7 +814,7 @@ namespace NSDoctRenderer
 
 #endif
 
-#ifdef LINUX
+#if defined(LINUX) || defined(__FreeBSD__)
 			pid_t pid = fork(); // create child process
 			int status;
 
@@ -1149,7 +1149,7 @@ namespace NSDoctRenderer
 
 #endif
 
-#ifdef LINUX
+#if defined(LINUX) || defined(__FreeBSD__)
 			pid_t pid = fork(); // create child process
 			int status;
 
