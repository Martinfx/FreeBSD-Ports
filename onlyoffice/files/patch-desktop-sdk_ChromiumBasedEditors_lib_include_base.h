--- desktop-sdk/ChromiumBasedEditors/lib/include/base.h.orig	2025-09-24 18:37:07 UTC
+++ desktop-sdk/ChromiumBasedEditors/lib/include/base.h
@@ -53,7 +53,7 @@
 
 #endif
 
-#if defined(_LINUX) && !defined(_MAC)
+#if defined(__FreeBSD__) && !defined(_MAC)
 
 //#include <X11/X.h>
 //typedef unsigned long XID;
