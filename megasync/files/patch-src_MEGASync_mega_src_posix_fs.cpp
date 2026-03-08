--- src/MEGASync/mega/src/posix/fs.cpp.orig	2026-01-13 01:44:33 UTC
+++ src/MEGASync/mega/src/posix/fs.cpp
@@ -22,9 +22,9 @@
  * You should have received a copy of the license along with this
  * program.
  */
-#ifndef __APPLE__
-#include <mntent.h>
-#endif // ! __APPLE__
+#ifdef __linux__
+#include <sys/mntent.h>
+#endif
 
 #include "mega.h"
 #include "mega/scoped_helpers.h"
@@ -50,15 +50,15 @@ extern jclass fileWrapper;
 #include <uuid/uuid.h>
 #endif
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 
-#ifndef __ANDROID__
+#ifdef __linux__
 #include <linux/magic.h>
-#endif /* ! __ANDROID__ */
-
 #include <sys/sysmacros.h>
-#include <sys/vfs.h>
+#endif
 
+#include <sys/mount.h>
+
 #ifndef FUSEBLK_SUPER_MAGIC
 #define FUSEBLK_SUPER_MAGIC 0x65735546ul
 #endif /* ! FUSEBLK_SUPER_MAGIC */
@@ -109,7 +109,7 @@ extern jclass fileWrapper;
 
 #endif /* __linux__ */
 
-#if defined(__APPLE__) || defined(USE_IOS)
+#if defined(__APPLE__) || defined(USE_IOS) || defined(__FreeBSD__)
 #include <sys/mount.h>
 #include <sys/param.h>
 #endif /* __APPLE__ || USE_IOS */
@@ -915,7 +915,7 @@ PosixFileSystemAccess::PosixFileSystemAccess()
     defaultfolderpermissions = 0700;
 }
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #ifdef ENABLE_SYNC
 
 bool LinuxFileSystemAccess::initFilesystemNotificationSystem()
@@ -975,7 +975,7 @@ bool PosixFileSystemAccess::cwd_static(LocalPath& path
 
 // wake up from filesystem updates
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 void LinuxFileSystemAccess::addevents([[maybe_unused]] Waiter* waiter, int /*flags*/)
 {
 #ifdef ENABLE_SYNC
@@ -1451,7 +1451,7 @@ bool PosixFileSystemAccess::expanselocalpath(const Loc
     return true;
 }
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 string &ltrimEtcProperty(string &s, const char &c)
 {
     size_t pos = s.find_first_not_of(c);
@@ -1760,7 +1760,7 @@ void PosixFileSystemAccess::statsid(string *id) const
 }
 
 #if defined(ENABLE_SYNC)
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 
 LinuxDirNotify::LinuxDirNotify(LinuxFileSystemAccess& owner,
                                LocalNode& /*root*/,
@@ -1916,7 +1916,7 @@ class UnixStreamAccess (private)
     // open with O_NOATIME if possible
     int open(const char *path)
     {
-#ifdef TARGET_OS_IPHONE
+#if defined(TARGET_OS_IPHONE) || defined(__FreeBSD__)
         // building for iOS, there is no O_NOATIME flag
         int fd = ::open(path, O_RDONLY) ;
 #else
@@ -2166,7 +2166,7 @@ ScanResult PosixFileSystemAccess::directoryScan(const 
     return SCAN_SUCCESS;
 }
 
-#ifndef __APPLE__
+#if defined(__linux__) || defined(__FreeBSD__)
 
 // Determine which device contains the specified path.
 static std::string deviceOf(const std::string& database,
