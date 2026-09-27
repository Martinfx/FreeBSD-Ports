--- pxr/base/arch/fileSystem.cpp.orig	2026-04-24 18:55:54 UTC
+++ pxr/base/arch/fileSystem.cpp
@@ -35,12 +35,18 @@
 #include <Windows.h>
 #include <WinIoCtl.h>
 #else
+#if !defined(ARCH_OS_FREEBSD)
 #include <alloca.h>
+#endif
 #include <sys/mman.h>
 #include <sys/file.h>
 #include <unistd.h>
 #endif
 
+#if defined(ARCH_OS_FREEBSD)
+#include <sys/user.h>
+#endif
+
 #if defined(ARCH_OS_DARWIN)
 #include "pxr/base/arch/darwin.h"
 #endif
@@ -148,7 +154,7 @@ bool
 ArchStatIsWritable(const ArchStatType *st)
 {
 #if defined(ARCH_OS_LINUX) || defined (ARCH_OS_DARWIN) || \
-    defined(ARCH_OS_WASM_VM)
+    defined(ARCH_OS_WASM_VM) || defined(ARCH_OS_FREEBSD)
     if (st) {
         return (st->st_mode & S_IWOTH) || 
             ((getegid() == st->st_gid) && (st->st_mode & S_IWGRP)) ||
@@ -185,7 +191,8 @@ ArchGetModificationTime(const char* path
 double
 ArchGetModificationTime(const ArchStatType& st)
 {
-#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_WASM_VM)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD) || \
+    defined(ARCH_OS_WASM_VM)
     return st.st_mtim.tv_sec + 1e-9*st.st_mtim.tv_nsec;
 #elif defined(ARCH_OS_DARWIN)
     return st.st_mtimespec.tv_sec + 1e-9*st.st_mtimespec.tv_nsec;
@@ -437,7 +444,8 @@ ArchGetStatMode(const char *pathname, in
 double
 ArchGetAccessTime(const struct stat& st)
 {
-#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_WASM_VM)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD) || \
+    defined(ARCH_OS_WASM_VM)
     return st.st_atim.tv_sec + 1e-9*st.st_atim.tv_nsec;
 #elif defined(ARCH_OS_DARWIN)
     return st.st_atimespec.tv_sec + 1e-9*st.st_atimespec.tv_nsec;
@@ -452,7 +460,8 @@ ArchGetAccessTime(const struct stat& st)
 double
 ArchGetStatusChangeTime(const struct stat& st)
 {
-#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_WASM_VM)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD) || \
+    defined(ARCH_OS_WASM_VM)
     return st.st_ctim.tv_sec + 1e-9*st.st_ctim.tv_nsec;
 #elif defined(ARCH_OS_DARWIN)
     return st.st_ctimespec.tv_sec + 1e-9*st.st_ctimespec.tv_nsec;
@@ -483,7 +492,7 @@ ArchGetFileLength(FILE *file)
     if (!file)
         return -1;
 #if defined (ARCH_OS_LINUX) || defined (ARCH_OS_DARWIN) || \
-    defined(ARCH_OS_WASM_VM)
+    defined(ARCH_OS_WASM_VM) || defined(ARCH_OS_FREEBSD)
     struct stat buf;
     return fstat(fileno(file), &buf) < 0 ? -1 :
         static_cast<int64_t>(buf.st_size);
@@ -498,7 +507,7 @@ int64_t
 ArchGetFileLength(const char* fileName)
 {
 #if defined (ARCH_OS_LINUX) || defined (ARCH_OS_DARWIN) || \
-    defined(ARCH_OS_WASM_VM)
+    defined(ARCH_OS_WASM_VM) || defined(ARCH_OS_FREEBSD)
     struct stat buf;
     return stat(fileName, &buf) < 0 ? -1 : static_cast<int64_t>(buf.st_size);
 #elif defined (ARCH_OS_WINDOWS)
@@ -539,6 +548,15 @@ ArchGetFileName(FILE *file)
         result = buf;
     }
     return result;
+#elif defined (ARCH_OS_FREEBSD)
+    // F_KINFO does not need procfs (unlike /proc/self/fd on Linux).
+    string result;
+    struct kinfo_file kif;
+    kif.kf_structsize = sizeof(kif);
+    if (fcntl(fileno(file), F_KINFO, &kif) != -1) {
+        result = kif.kf_path;
+    }
+    return result;
 #elif defined (ARCH_OS_WINDOWS)
     string result;
     std::vector<WCHAR> filePath(MAX_PATH);
@@ -926,6 +944,10 @@ ArchQueryMappedMemoryResidency(
         reinterpret_cast<caddr_t>(const_cast<void *>(addr)), len,
         reinterpret_cast<char *>(pageMap));
     return ret == 0;
+#elif defined (ARCH_OS_FREEBSD)
+    // On FreeBSD the vec param is 'char *'.
+    int ret = mincore(addr, len, reinterpret_cast<char *>(pageMap));
+    return ret == 0;
 #endif
     // XXX: Not implemented for other platforms yet.
     return false;
