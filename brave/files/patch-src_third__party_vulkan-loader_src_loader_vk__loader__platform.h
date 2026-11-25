--- src/third_party/vulkan-loader/src/loader/vk_loader_platform.h.orig	2026-11-24 12:50:30 UTC
+++ src/third_party/vulkan-loader/src/loader/vk_loader_platform.h
@@ -29,6 +29,7 @@
 #if defined(__FreeBSD__) || defined(__OpenBSD__)
 #include <sys/types.h>
 #include <sys/select.h>
+#include <sys/param.h>
 #endif
 
 #include <assert.h>
