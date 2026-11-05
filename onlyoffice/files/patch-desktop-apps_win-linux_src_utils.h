--- desktop-apps/win-linux/src/utils.h.orig	2026-11-05 00:00:00 UTC
+++ desktop-apps/win-linux/src/utils.h
@@ -145,7 +145,7 @@
 };
 
 namespace WindowHelper {
-#ifdef Q_OS_LINUX
+#if (defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)) || defined(Q_OS_FREEBSD)
     class CParentDisable
     {
         QWidget* m_parent = nullptr;
