--- pxr/base/arch/fileSystem.cpp.orig	2025-02-04 21:22:17 UTC
+++ pxr/base/arch/fileSystem.cpp
@@ -35,12 +35,24 @@
 #include <Windows.h>
 #include <WinIoCtl.h>
 #else
+#if !defined(ARCH_OS_FREEBSD)
 #include <alloca.h>
+#else
+#include <stdlib.h>
+#endif
 #include <sys/mman.h>
 #include <sys/file.h>
 #include <unistd.h>
 #endif
 
+#if defined(ARCH_OS_FREEBSD)
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#include <unistd.h>
+#include <stdlib.h>
+#include <sys/user.h>
+#endif
+
 PXR_NAMESPACE_OPEN_SCOPE
 
 using std::pair;
@@ -143,7 +155,7 @@ ArchStatIsWritable(const ArchStatType *st)
 bool
 ArchStatIsWritable(const ArchStatType *st)
 {
-#if defined(ARCH_OS_LINUX) || defined (ARCH_OS_DARWIN)
+#if defined(ARCH_OS_LINUX) || defined (ARCH_OS_DARWIN) || defined(ARCH_OS_FREEBSD) 
     if (st) {
         return (st->st_mode & S_IWOTH) || 
             ((getegid() == st->st_gid) && (st->st_mode & S_IWGRP)) ||
@@ -180,7 +192,7 @@ ArchGetModificationTime(const ArchStatType& st)
 double
 ArchGetModificationTime(const ArchStatType& st)
 {
-#if defined(ARCH_OS_LINUX)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD)
     return st.st_mtim.tv_sec + 1e-9*st.st_mtim.tv_nsec;
 #elif defined(ARCH_OS_DARWIN)
     return st.st_mtimespec.tv_sec + 1e-9*st.st_mtimespec.tv_nsec;
@@ -432,7 +444,7 @@ ArchGetAccessTime(const struct stat& st)
 double
 ArchGetAccessTime(const struct stat& st)
 {
-#if defined(ARCH_OS_LINUX)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD)
     return st.st_atim.tv_sec + 1e-9*st.st_atim.tv_nsec;
 #elif defined(ARCH_OS_DARWIN)
     return st.st_atimespec.tv_sec + 1e-9*st.st_atimespec.tv_nsec;
@@ -447,7 +459,7 @@ ArchGetStatusChangeTime(const struct stat& st)
 double
 ArchGetStatusChangeTime(const struct stat& st)
 {
-#if defined(ARCH_OS_LINUX)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD)
     return st.st_ctim.tv_sec + 1e-9*st.st_ctim.tv_nsec;
 #elif defined(ARCH_OS_DARWIN)
     return st.st_ctimespec.tv_sec + 1e-9*st.st_ctimespec.tv_nsec;
@@ -477,12 +489,13 @@ ArchGetFileLength(FILE *file)
 {
     if (!file)
         return -1;
-#if defined (ARCH_OS_LINUX) || defined (ARCH_OS_DARWIN)
+#if defined (ARCH_OS_LINUX) || defined (ARCH_OS_DARWIN) || defined (ARCH_OS_FREEBSD)
     struct stat buf;
     return fstat(fileno(file), &buf) < 0 ? -1 :
         static_cast<int64_t>(buf.st_size);
 #elif defined (ARCH_OS_WINDOWS)
     return _GetFileLength(_FileToWinHANDLE(file));
+
 #else
 #error Unknown system architecture
 #endif
@@ -491,7 +504,7 @@ ArchGetFileLength(const char* fileName)
 int64_t
 ArchGetFileLength(const char* fileName)
 {
-#if defined (ARCH_OS_LINUX) || defined (ARCH_OS_DARWIN)
+#if defined (ARCH_OS_LINUX) || defined (ARCH_OS_DARWIN) || defined (ARCH_OS_FREEBSD)
     struct stat buf;
     return stat(fileName, &buf) < 0 ? -1 : static_cast<int64_t>(buf.st_size);
 #elif defined (ARCH_OS_WINDOWS)
@@ -562,7 +575,49 @@ ArchGetFileName(FILE *file)
         auto canonicalPath = std::filesystem::canonical(result);
         result = canonicalPath.string();
     }
-    return result;                                        
+    return result;
+#elif defined (ARCH_OS_FREEBSD)
+    int mib[4];
+    size_t i, len;
+    char *buffer = NULL;
+    struct kinfo_file *kf;
+    string path;
+
+    mib[0] = CTL_KERN;
+    mib[1] = KERN_PROC;
+    mib[2] = KERN_PROC_FILEDESC;
+    mib[3] = getpid();
+    len = 0;
+    if (sysctl( mib, sizeof(mib)/sizeof(mib[0]), NULL, &len, NULL, 0 ))
+        goto end;
+    len *= 2;
+    buffer = (char*)malloc( len );
+    if (!buffer)
+        goto end;
+    if (sysctl( mib, sizeof(mib)/sizeof(mib[0]), buffer, &len, NULL, 0 ))
+        goto end;
+
+    for (i = 0; i < len; )
+    {
+        kf = (struct kinfo_file*) &buffer[i];
+        if (kf->kf_structsize == 0)
+            break;
+        i += kf->kf_structsize;
+
+        if (kf->kf_fd == fileno(file))
+        {
+            if (kf->kf_path[0])
+            {
+                path.resize(strlen(kf->kf_path) + 1);
+                sprintf(&path[0], "%s", kf->kf_path);
+            }
+            break;
+        }
+    }
+
+end:
+    free( buffer );
+    return path;                                     
 #else
 #error Unknown system architecture
 #endif
@@ -924,6 +979,9 @@ ArchQueryMappedMemoryResidency(
     int ret = mincore(
         reinterpret_cast<caddr_t>(const_cast<void *>(addr)), len,
         reinterpret_cast<char *>(pageMap));
+    return ret == 0;
+#elif defined(ARCH_OS_FREEBSD)
+    int ret = mincore(const_cast<const void *>(addr), len, (char *)(pageMap));
     return ret == 0;
 #endif
     // XXX: Not implemented for other platforms yet.
