--- core/DesktopEditor/allthemesgen/main.cpp.orig	2026-11-05 00:00:00 UTC
+++ core/DesktopEditor/allthemesgen/main.cpp
@@ -51,7 +51,7 @@
 #undef CreateDirectory
 #endif
 
-#ifdef LINUX
+#if defined(LINUX) || defined (__FreeBSD__)
 #include <unistd.h>
 #include <sys/wait.h>
 #include <stdio.h>
@@ -182,7 +182,7 @@
 
 #endif
 
-#ifdef LINUX
+#if defined(LINUX) || defined (__FreeBSD__)
         pid_t pid = fork(); // create child process
         int status;
 
