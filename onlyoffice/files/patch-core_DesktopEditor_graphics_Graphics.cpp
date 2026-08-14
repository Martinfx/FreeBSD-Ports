--- core/DesktopEditor/graphics/Graphics.cpp.orig	2025-09-24 06:05:50 UTC
+++ core/DesktopEditor/graphics/Graphics.cpp
@@ -61,7 +61,7 @@ namespace Aggplus
 		m_bSwapRGB = false;
 		m_bIsDarkMode = false;
 
-#if defined (_LINUX) || defined (_QT)
+#if defined (_LINUX) || defined (_QT) || defined(__FreeBSD__)
 		m_bSwapRGB = true;
 #endif
 
@@ -100,7 +100,7 @@ namespace Aggplus
 
 		m_bSwapRGB = false;
 
-#if defined (_LINUX) || defined (_QT)
+#if defined (_LINUX) || defined (_QT) || defined(__FreeBSD__)
 		m_bSwapRGB = true;
 #endif
 
@@ -144,7 +144,7 @@ namespace Aggplus
 
 		m_bSwapRGB = false;
 
-#if defined (_LINUX) || defined (_QT)
+#if defined (_LINUX) || defined (_QT) || defined(__FreeBSD__)
 		m_bSwapRGB = true;
 #endif
 
