--- desktop-sdk/ChromiumBasedEditors/lib/src/cef/freebsd/tests/cefclient/browser/client_handler.h.orig	2026-09-24 21:58:50 UTC
+++ desktop-sdk/ChromiumBasedEditors/lib/src/cef/freebsd/tests/cefclient/browser/client_handler.h
@@ -338,7 +338,7 @@ class ClientHandler : public BaseClientH
     download_favicon_images_ = allow;
   }
 
- private:
+ protected:
   friend class ClientDownloadImageCallback;
 
   // Create a new popup window using the specified information. |is_devtools|
