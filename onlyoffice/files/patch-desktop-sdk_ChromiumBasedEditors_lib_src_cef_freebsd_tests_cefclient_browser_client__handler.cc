--- desktop-sdk/ChromiumBasedEditors/lib/src/cef/freebsd/tests/cefclient/browser/client_handler.cc.orig	2026-09-24 21:58:50 UTC
+++ desktop-sdk/ChromiumBasedEditors/lib/src/cef/freebsd/tests/cefclient/browser/client_handler.cc
@@ -567,7 +567,8 @@ ClientHandler::ClientHandler(Delegate* d
     if (use_client_dialogs || require_client_dialogs) {
       file_dialog_handler_ = js_dialog_handler_ ? js_dialog_handler_
                                                 : new ClientDialogHandlerGtk();
-      print_handler_ = new ClientPrintHandlerGtk();
+      // ONLYOFFICE: printing is done by the application, not with GTK.
+      // print_handler_ = new ClientPrintHandlerGtk();
     }
   }
 #endif  // defined(OS_LINUX)
