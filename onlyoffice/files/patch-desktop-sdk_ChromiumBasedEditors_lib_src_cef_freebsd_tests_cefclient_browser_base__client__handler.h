--- desktop-sdk/ChromiumBasedEditors/lib/src/cef/freebsd/tests/cefclient/browser/base_client_handler.h.orig	2026-09-24 21:58:50 UTC
+++ desktop-sdk/ChromiumBasedEditors/lib/src/cef/freebsd/tests/cefclient/browser/base_client_handler.h
@@ -123,7 +123,7 @@ class BaseClientHandler : public CefClie
 
   void set_track_as_other_browser(bool val) { track_as_other_browser_ = val; }
 
- private:
+ protected:
   // True if this handler should call
   // RootWindowManager::OtherBrowser[Created|Closed].
   bool track_as_other_browser_ = true;
