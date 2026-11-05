--- desktop-apps/win-linux/src/defines.h.orig	2026-11-05 00:00:00 UTC
+++ desktop-apps/win-linux/src/defines.h
@@ -43,7 +43,7 @@
 
 #define APP_NAME "DesktopEditors"
 #define APP_TITLE "ONLYOFFICE"
-#ifdef __linux
+#if defined(__linux) || defined(__FreeBSD__)
 # define APP_DATA_PATH "/onlyoffice/desktopeditors"
 # define REG_GROUP_KEY "onlyoffice"
 # define APP_MUTEX_NAME "asc:editors"
@@ -95,7 +95,7 @@
 #define ADDON_ENTERPRISE_ID     "enterprise"
 #define ADDON_INSTALL_SUBDIR    "/addons"
 
-#ifdef __linux
+#if defined(__linux) || defined(__FreeBSD__)
 typedef unsigned char BYTE;
 #else
 # define UM_INSTALL_UPDATE      WM_USER+254
@@ -106,7 +106,7 @@
 #define TO_WSTR(str)            L ## str
 #define WSTR(str)               TO_WSTR(str)
 
-#ifdef __linux
+#if defined(__linux) || defined(__FreeBSD__)
 # define VK_F1 0x70
 # define VK_F4 0x73
 # define VK_TAB 0x09
