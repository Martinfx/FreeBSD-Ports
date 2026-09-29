--- desktop-sdk/ChromiumBasedEditors/lib/src/cef/freebsd/tests/cefclient/browser/main_context_impl.cc.orig	2026-09-28 10:49:51 UTC
+++ desktop-sdk/ChromiumBasedEditors/lib/src/cef/freebsd/tests/cefclient/browser/main_context_impl.cc
@@ -126,12 +126,9 @@ MainContextImpl::MainContextImpl(CefRefP
     browser_background_color_ = background_color_;
   }
 
-  // Log the current configuration.
-  LOG(WARNING) << "Using " << (use_alloy_style_ ? "Alloy" : "Chrome")
-               << " style; " << (use_views_ ? "Views" : "Native")
-               << "-hosted window; "
-               << (use_windowless_rendering_ ? "Windowless" : "Windowed")
-               << " rendering (not a warning)";
+  // ONLYOFFICE: no logging of the current configuration.  This runs before
+  // CefInitialize, and the first log message before it hangs in libcef of
+  // www/cef (in a pthread_once that is entered again while it runs).
 }
 
 MainContextImpl::~MainContextImpl() {
