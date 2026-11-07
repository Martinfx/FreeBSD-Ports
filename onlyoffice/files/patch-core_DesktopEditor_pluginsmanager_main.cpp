--- core/DesktopEditor/pluginsmanager/main.cpp.orig	2026-11-05 00:00:00 UTC
+++ core/DesktopEditor/pluginsmanager/main.cpp
@@ -55,7 +55,7 @@
 #undef GetTempPath
 #endif
 
-#ifdef LINUX
+#if defined(LINUX) || defined(__FreeBSD__)
 #include <unistd.h>
 #include <stdio.h>
 #endif
@@ -275,7 +275,7 @@
 
 		m_sSettingsDir = NSSystemUtils::GetAppDataDir() + L"/pluginsmanager";
 
-#ifdef LINUX
+#if defined(LINUX) || defined(__FreeBSD__)
 		// GetAppDataDir creates folder with ONLYOFFICE on Linux
 		// as result - two folders in lower/upper case, working with the correct folder
 		NSStringUtils::string_replace(m_sSettingsDir, L"ONLYOFFICE", L"onlyoffice");
