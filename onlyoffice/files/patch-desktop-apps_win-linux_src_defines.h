--- desktop-apps/win-linux/src/defines.h.orig	2026-09-28 08:45:35 UTC
+++ desktop-apps/win-linux/src/defines.h
@@ -44,7 +44,7 @@
 
 #define APP_NAME "DesktopEditors"
 #define APP_TITLE "ONLYOFFICE"
-#ifdef __linux
+#if defined(__linux) || defined(__FreeBSD__)
 # define APP_DATA_PATH "/onlyoffice/desktopeditors"
 # define REG_GROUP_KEY "onlyoffice"
 # define APP_MUTEX_NAME "asc:editors"
@@ -88,7 +88,7 @@
 #define DOWNLOAD_PAGE "https://www.onlyoffice.com/en/download-desktop.aspx"
 #define RELEASE_NOTES "https://github.com/ONLYOFFICE/DesktopEditors/blob/master/CHANGELOG.md"
 
-#ifdef __linux
+#if defined(__linux) || defined(__FreeBSD__)
 typedef unsigned char BYTE;
 #else
 # define UM_INSTALL_UPDATE      WM_USER+254
@@ -112,7 +112,7 @@ typedef unsigned char BYTE;
 #define TO_WSTR(str)            L ## str
 #define WSTR(str)               TO_WSTR(str)
 
-#ifdef __linux
+#if defined(__linux) || defined(__FreeBSD__)
 # define VK_F1 0x70
 # define VK_F4 0x73
 # define VK_TAB 0x09
