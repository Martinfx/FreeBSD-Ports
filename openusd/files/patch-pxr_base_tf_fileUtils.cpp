--- pxr/base/tf/fileUtils.cpp.orig	2026-04-24 18:55:54 UTC
+++ pxr/base/tf/fileUtils.cpp
@@ -230,7 +230,7 @@ TfIsLink(string const& path)
 bool
 TfIsWritable(string const& path)
 {
-#if defined(ARCH_OS_LINUX)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD)
     // faccessat accounts for mount read-only status. For maintaining legacy
     // behavior, use faccessat instead of access so we can use the effective
     // UID instead of the real UID. 
