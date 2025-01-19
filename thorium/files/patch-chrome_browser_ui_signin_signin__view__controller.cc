--- chrome/browser/ui/signin/signin_view_controller.cc.orig	2024-08-26 12:06:38 UTC
+++ chrome/browser/ui/signin/signin_view_controller.cc
@@ -492,7 +492,7 @@ void SigninViewController::ShowModalManagedUserNoticeD
     signin::SigninChoiceCallbackVariant process_user_choice_callback,
     base::OnceClosure done_callback) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_LACROS)
+    BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   CloseModalSignin();
   dialog_ = std::make_unique<SigninModalDialogImpl>(
       SigninViewControllerDelegate::CreateManagedUserNoticeDelegate(
