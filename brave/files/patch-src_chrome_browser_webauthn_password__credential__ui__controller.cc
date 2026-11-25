--- src/chrome/browser/webauthn/password_credential_ui_controller.cc.orig	2026-11-24 12:50:30 UTC
+++ src/chrome/browser/webauthn/password_credential_ui_controller.cc
@@ -26,7 +26,7 @@ using content::WebContents;
 namespace {
 
 std::u16string GetAuthenticationMessage(std::string_view rp_id) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return u"";
 #else
   return l10n_util::GetStringFUTF16(IDS_PASSWORD_MANAGER_FILLING_REAUTH,
