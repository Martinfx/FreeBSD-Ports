--- core/DesktopEditor/doctrenderer/docbuilder_p.h.orig	2026-11-05 00:00:00 UTC
+++ core/DesktopEditor/doctrenderer/docbuilder_p.h
@@ -52,7 +52,7 @@
 #include "embed/NativeControlEmbed.h"
 #include "embed/GraphicsEmbed.h"
 #include "embed/Default.h"
-#ifdef LINUX
+#if defined(LINUX) || defined(__FreeBSD__)
 #include <unistd.h>
 #include <sys/wait.h>
 #include <stdio.h>
@@ -812,7 +812,7 @@
 
 #endif
 
-#ifdef LINUX
+#if defined(LINUX) || defined(__FreeBSD__)
 			pid_t pid = fork(); // create child process
 			int status;
 
@@ -1355,7 +1355,7 @@
 
 #endif
 
-#ifdef LINUX
+#if defined(LINUX) || defined(__FreeBSD__)
 			pid_t pid = fork(); // create child process
 			int status;
 
