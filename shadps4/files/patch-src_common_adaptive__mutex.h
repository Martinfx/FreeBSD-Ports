--- src/common/adaptive_mutex.h.orig	2025-04-06 13:15:49 UTC
+++ src/common/adaptive_mutex.h
@@ -3,7 +3,7 @@
 
 #pragma once
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #include <pthread.h>
 #endif
 
