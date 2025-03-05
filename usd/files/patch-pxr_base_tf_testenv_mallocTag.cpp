--- pxr/base/tf/testenv/mallocTag.cpp.orig	2025-02-04 21:22:17 UTC
+++ pxr/base/tf/testenv/mallocTag.cpp
@@ -19,7 +19,7 @@ PXR_NAMESPACE_USING_DIRECTIVE
 
 // The TfMallocTag code depends upon the Linux memory allocator, ptmalloc3.
 // Turning this test off for any other platforms for now.
-#if defined(ARCH_OS_LINUX)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD) || defined(ARCH_OS_FREEBSD)
 
 using std::vector;
 using std::string;
