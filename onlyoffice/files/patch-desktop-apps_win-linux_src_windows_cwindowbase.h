--- desktop-apps/win-linux/src/windows/cwindowbase.h.orig	2026-11-05 00:00:00 UTC
+++ desktop-apps/win-linux/src/windows/cwindowbase.h
@@ -88,7 +88,7 @@
 
 protected:
     friend class CAscApplicationManagerWrapper;
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     friend class AscMainPanel;
 #endif
     enum BtnType {
