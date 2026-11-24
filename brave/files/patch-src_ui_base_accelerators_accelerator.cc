--- src/ui/base/accelerators/accelerator.cc.orig	2026-11-24 12:50:30 UTC
+++ src/ui/base/accelerators/accelerator.cc
@@ -403,7 +403,7 @@ std::vector<std::u16string> Accelerator:
     modifiers.push_back(l10n_util::GetStringUTF16(IDS_APP_SEARCH_KEY));
 #elif BUILDFLAG(IS_WIN)
     modifiers.push_back(l10n_util::GetStringUTF16(IDS_APP_WINDOWS_KEY));
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     modifiers.push_back(l10n_util::GetStringUTF16(IDS_APP_SUPER_KEY));
 #else
     NOTREACHED();
