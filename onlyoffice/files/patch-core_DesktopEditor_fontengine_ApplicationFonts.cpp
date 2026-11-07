--- core/DesktopEditor/fontengine/ApplicationFonts.cpp.orig	2026-11-05 00:00:00 UTC
+++ core/DesktopEditor/fontengine/ApplicationFonts.cpp
@@ -1651,6 +1651,8 @@
 
 #if defined(_LINUX) && !defined(_MAC) && !defined(__ANDROID__)
 	m_oList.LoadFromFolder(L"/usr/share/fonts");
+#elif defined(__FreeBSD__)
+    m_oList.LoadFromFolder(L"%%LOCALBASE%%/share/fonts");
 #endif
 
 #if defined(_MAC) && !defined(_IOS)
@@ -1839,6 +1841,9 @@
 	NSDirectory::GetFiles2(L"/usr/share/X11/fonts", _array, true);
 	NSDirectory::GetFiles2(L"/usr/X11R6/lib/X11/fonts", _array, true);
 	NSDirectory::GetFiles2(L"/run/host/fonts", _array, true);
+#elif defined(__FreeBSD__)
+     std::vector<std::wstring> _array = NSDirectory::GetFiles(L"/usr/share/fonts", true);
+     NSDirectory::GetFiles2(L"%%LOCALBASE%%/share/fonts", _array, true);
 
 	if (bIsUseUserFonts)
 		NSDirectory::GetFiles2(L"/usr/local/share/fonts", _array, true);
