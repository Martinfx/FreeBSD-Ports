--- third_party/renderdoc/renderdoc_app.h.orig	2025-03-06 14:08:35 UTC
+++ third_party/renderdoc/renderdoc_app.h
@@ -32,6 +32,8 @@
 	#define RENDERDOC_CC __cdecl
 #elif defined(__linux__)
 	#define RENDERDOC_CC
+#elif defined(__FreeBSD__)
+	#define RENDERDOC_CC
 #else
 	#error "Unknown platform"
 #endif
