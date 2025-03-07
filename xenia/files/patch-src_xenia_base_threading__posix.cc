--- src/xenia/base/threading_posix.cc.orig	2025-03-07 07:40:50 UTC
+++ src/xenia/base/threading_posix.cc
@@ -34,7 +34,7 @@
 #include "xenia/base/string_util.h"
 #endif
 
-#if XE_PLATFORM_LINUX
+#if XE_PLATFORM_LINUX || XE_PLATFORM_FREEBSD
 // SIGEV_THREAD_ID in timer_create(...) is a Linux extension
 #define XE_HAS_SIGEV_THREAD_ID 1
 #ifdef __GLIBC__
