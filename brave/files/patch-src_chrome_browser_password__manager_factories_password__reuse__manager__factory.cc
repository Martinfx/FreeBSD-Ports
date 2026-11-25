--- src/chrome/browser/password_manager/factories/password_reuse_manager_factory.cc.orig	2026-11-24 12:50:30 UTC
+++ src/chrome/browser/password_manager/factories/password_reuse_manager_factory.cc
@@ -125,7 +125,7 @@ PasswordReuseManagerFactory::BuildServic
   // Prepare password hash data for reuse detection.
   reuse_manager->PreparePasswordHashData(GetSignInStateForMetrics(profile));
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::unique_ptr<password_manager::PasswordReuseManagerSigninNotifier>
       notifier = std::make_unique<
           password_manager::PasswordReuseManagerSigninNotifierImpl>(
