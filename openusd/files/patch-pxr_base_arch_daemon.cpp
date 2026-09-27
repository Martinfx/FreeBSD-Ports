--- pxr/base/arch/daemon.cpp.orig	2026-04-24 18:55:54 UTC
+++ pxr/base/arch/daemon.cpp
@@ -28,7 +28,7 @@ PXR_NAMESPACE_OPEN_SCOPE
 int
 ArchCloseAllFiles(int nExcept, const int* exceptFds)
 {
-#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_DARWIN)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD) || defined(ARCH_OS_DARWIN)
 
     int status, retStatus, retErrno;
     int i, j, maxfd, maxExcept = -1;
