--- desktop-sdk/ChromiumBasedEditors/lib/src/cef/freebsd/tests/shared/browser/client_app_browser.h.orig	2026-09-24 21:58:50 UTC
+++ desktop-sdk/ChromiumBasedEditors/lib/src/cef/freebsd/tests/shared/browser/client_app_browser.h
@@ -56,7 +56,7 @@ class ClientAppBrowser : public ClientAp
   static void PopulateSettings(CefRefPtr<CefCommandLine> command_line,
                                CefSettings& settings);
 
- private:
+ protected:
   // Registers cookieable schemes. Implemented by cefclient in
   // client_app_delegates_browser.cc
   static void RegisterCookieableSchemes(
