--- desktop-sdk/ChromiumBasedEditors/lib/src/cef/freebsd/tests/shared/renderer/client_app_renderer.h.orig	2026-09-24 21:58:50 UTC
+++ desktop-sdk/ChromiumBasedEditors/lib/src/cef/freebsd/tests/shared/renderer/client_app_renderer.h
@@ -77,7 +77,7 @@ class ClientAppRenderer : public ClientA
   ClientAppRenderer(const ClientAppRenderer&) = delete;
   ClientAppRenderer& operator=(const ClientAppRenderer&) = delete;
 
- private:
+ protected:
   // Creates all of the Delegate objects. Implemented by cefclient in
   // client_app_delegates_renderer.cc
   static void CreateDelegates(DelegateSet& delegates);
@@ -112,7 +112,7 @@ class ClientAppRenderer : public ClientA
                                 CefProcessId source_process,
                                 CefRefPtr<CefProcessMessage> message) override;
 
- private:
+ protected:
   // Set of supported Delegates.
   DelegateSet delegates_;
 
