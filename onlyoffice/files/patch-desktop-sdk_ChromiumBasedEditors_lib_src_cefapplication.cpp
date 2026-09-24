--- desktop-sdk/ChromiumBasedEditors/lib/src/cefapplication.cpp.orig	2026-09-24 21:58:50 UTC
+++ desktop-sdk/ChromiumBasedEditors/lib/src/cefapplication.cpp
@@ -407,6 +407,13 @@ int CApplicationCEF::Init_CEF(CAscApplic
 	settings.no_sandbox = true;
 #endif
 
+#ifdef CEF_VERSION_ABOVE_128
+	// The editors are browsers with a native parent window in Alloy style, as
+	// with CEF 109.  Tell the cefclient code (MainContextImpl, ClientHandler).
+	command_line->AppendSwitch("use-native");
+	command_line->AppendSwitch("use-alloy-style");
+#endif
+
 	// Populate the settings based on command line arguments.
 #if defined(CEF_VERSION_ABOVE_102)
 	m_pInternal->context = std::make_unique<client::MainContextImpl>(command_line, false);
@@ -467,7 +474,12 @@ int CApplicationCEF::Init_CEF(CAscApplic
 	cef_string_t _cache_user;
 	memset(&_cache_user, 0, sizeof(_cache_user));
 	cef_string_from_wide(sCachePathUser.c_str(), sCachePathUser.length(), &_cache_user);
+#ifdef CEF_VERSION_ABOVE_128
+	// user_data_path is gone, the cache path has to be below root_cache_path
+	settings.root_cache_path = _cache_user;
+#else
 	settings.user_data_path = _cache_user;
+#endif
 
 	std::wstring sCachePathLog = sCachePath + L"/log.log";
 	cef_string_t _cache_log;
