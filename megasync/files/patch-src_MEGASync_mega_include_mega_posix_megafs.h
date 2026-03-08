--- src/MEGASync/mega/include/mega/posix/megafs.h.orig	2026-03-03 11:02:16 UTC
+++ src/MEGASync/mega/include/mega/posix/megafs.h
@@ -206,7 +206,7 @@ class MEGA_API PosixFileAccess : public FileAccess (pr
     bool mFollowSymLinks = true;
 };
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 
 #ifndef __ANDROID__
 #define FSACCESS_CLASS LinuxFileSystemAccess
