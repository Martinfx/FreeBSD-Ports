--- desktop-apps/win-linux/src/utils.h.orig	2026-09-24 21:58:50 UTC
+++ desktop-apps/win-linux/src/utils.h
@@ -139,7 +139,7 @@ public:
 };
 
 namespace WindowHelper {
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
     class CParentDisable
     {
         QWidget* m_pChild = nullptr;
