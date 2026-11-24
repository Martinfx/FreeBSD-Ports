--- src/components/performance_manager/public/features.h.orig	2026-11-24 12:50:30 UTC
+++ src/components/performance_manager/public/features.h
@@ -19,7 +19,7 @@ namespace performance_manager::features
 
 #if !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #define URGENT_DISCARDING_FROM_PERFORMANCE_MANAGER() false
 #else
 #define URGENT_DISCARDING_FROM_PERFORMANCE_MANAGER() true
