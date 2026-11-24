--- src/chrome/browser/supervised_user/supervised_user_extensions_delegate_impl.cc.orig	2026-11-24 12:50:30 UTC
+++ src/chrome/browser/supervised_user/supervised_user_extensions_delegate_impl.cc
@@ -249,7 +249,7 @@ void SupervisedUserExtensionsDelegateImp
       return;
     }
   }
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   CHECK(contents.value());
   content::WebContents* web_contents = contents.value().get();
   // Always invoke the parent permission dialog.
