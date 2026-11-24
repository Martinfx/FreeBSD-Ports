--- src/chrome/browser/ui/webui/history/history_identity_state_watcher.cc.orig	2026-11-24 12:50:30 UTC
+++ src/chrome/browser/ui/webui/history/history_identity_state_watcher.cc
@@ -122,7 +122,7 @@ HistoryIdentityStateWatcher::GetSyncStat
   }
   const signin_util::SignedInState signed_in_state =
       signin_util::GetSignedInState(identity_manager_);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // if the promo is related to history type, we need to check if any of the
   // History-related types is explicitly disabled via the toggles.
   if (type == syncer::UserSelectableType::kHistory &&
