--- src/chrome/browser/extensions/api/passwords_private/passwords_private_delegate_impl.cc.orig	2026-11-24 12:50:30 UTC
+++ src/chrome/browser/extensions/api/passwords_private/passwords_private_delegate_impl.cc
@@ -606,7 +606,7 @@ void PasswordsPrivateDelegateImpl::OnFet
 }
 
 void PasswordsPrivateDelegateImpl::OsReauthTimeoutCall() {
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (event_router_) {
     event_router_->OnPasswordManagerAuthTimeout();
   }
