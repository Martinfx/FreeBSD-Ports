--- src/chrome/browser/sync/test/integration/sync_service_impl_harness.cc.orig	2026-11-24 12:50:30 UTC
+++ src/chrome/browser/sync/test/integration/sync_service_impl_harness.cc
@@ -482,7 +482,7 @@ bool SyncServiceImplHarness::EnableHisto
   // Tabs and history are bundled together in the same toggle.
   service()->GetUserSettings()->SetSelectedType(
       syncer::UserSelectableType::kTabs, true);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On desktop platforms, kSavedTabGroups are not merged to kTabs yet, but
   // they're enabled together.
   service()->GetUserSettings()->SetSelectedType(
