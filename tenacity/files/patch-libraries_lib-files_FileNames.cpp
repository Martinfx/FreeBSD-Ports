--- libraries/lib-files/FileNames.cpp.orig	2026-10-16 17:51:47 UTC
+++ libraries/lib-files/FileNames.cpp
@@ -737,6 +737,8 @@
    return 0 == strcmp(fs.f_fstypename, "msdos");
 }
 #elif defined(__FreeBSD__)
+#include <sys/param.h>
+#include <sys/mount.h>
 bool FileNames::IsOnFATFileSystem(const FilePath &path)
 {
    struct statfs fs;
