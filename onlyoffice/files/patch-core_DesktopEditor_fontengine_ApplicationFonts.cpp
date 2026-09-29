--- core/DesktopEditor/fontengine/ApplicationFonts.cpp.orig	2025-09-24 06:04:09 UTC
+++ core/DesktopEditor/fontengine/ApplicationFonts.cpp
@@ -1649,6 +1649,8 @@ void CApplicationFonts::Initialize(bool bIsCheckSelect
 
 #if defined(_LINUX) && !defined(_MAC) && !defined(__ANDROID__)
 	m_oList.LoadFromFolder(L"/usr/share/fonts");
+#elif defined(__FreeBSD__)
+    m_oList.LoadFromFolder(L"%%LOCALBASE%%/share/fonts");
 #endif
 
 #if defined(_MAC) && !defined(_IOS)
@@ -1837,6 +1839,9 @@ std::vector<std::wstring> CApplicationFonts::GetSetupF
 	NSDirectory::GetFiles2(L"/usr/share/X11/fonts", _array, true);
 	NSDirectory::GetFiles2(L"/usr/X11R6/lib/X11/fonts", _array, true);
 	NSDirectory::GetFiles2(L"/run/host/fonts", _array, true);
+#elif defined(__FreeBSD__)
+     std::vector<std::wstring> _array = NSDirectory::GetFiles(L"/usr/share/fonts", true);
+     NSDirectory::GetFiles2(L"%%LOCALBASE%%/share/fonts", _array, true);
 
 	if (bIsUseUserFonts)
 		NSDirectory::GetFiles2(L"/usr/local/share/fonts", _array, true);
