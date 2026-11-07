--- core/DesktopEditor/graphics/Graphics.cpp.orig	2026-11-05 00:00:00 UTC
+++ core/DesktopEditor/graphics/Graphics.cpp
@@ -64,7 +64,7 @@
 		m_bSwapRGB = false;
 		m_bIsDarkMode = false;
 
-#if defined (_LINUX) || defined (_QT)
+#if defined (_LINUX) || defined (_QT) || defined(__FreeBSD__)
 		m_bSwapRGB = true;
 #endif
 
@@ -103,7 +103,7 @@
 
 		m_bSwapRGB = false;
 
-#if defined (_LINUX) || defined (_QT)
+#if defined (_LINUX) || defined (_QT) || defined(__FreeBSD__)
 		m_bSwapRGB = true;
 #endif
 
@@ -147,7 +147,7 @@
 
 		m_bSwapRGB = false;
 
-#if defined (_LINUX) || defined (_QT)
+#if defined (_LINUX) || defined (_QT) || defined(__FreeBSD__)
 		m_bSwapRGB = true;
 #endif
 
