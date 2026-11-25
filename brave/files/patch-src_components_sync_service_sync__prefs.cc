--- src/components/sync/service/sync_prefs.cc.orig	2026-11-24 12:50:30 UTC
+++ src/components/sync/service/sync_prefs.cc
@@ -188,7 +188,7 @@ void SyncPrefs::RegisterProfilePrefs(Pre
       prefs::internal::kMigrateExtensionsFromLocalToAccount, false);
   registry->RegisterBooleanPref(
       prefs::internal::kMigrateThemeFromLocalToAccount, false);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   registry->RegisterBooleanPref(
       prefs::internal::kReadingListPrefMigratedToAccount, false);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
@@ -866,7 +866,7 @@ bool SyncPrefs::MaybeMigratePrefsForSync
           update_selected_types_dict->EnsureDict(
               signin::GaiaIdHash::FromGaiaId(gaia_id).ToBase64());
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       // Preserve the user's existing enabled state for Bookmarks, Reading List,
       // and Preferences. Otherwise, use the default value, which will be true
       // after `kReplaceSyncPromosWithSignInPromos`.
@@ -1034,7 +1034,7 @@ void SyncPrefs::MigrateGlobalDataTypePre
                         saved_tab_groups_enabled);
   account_settings->Set(GetPrefNameForType(UserSelectableType::kExtensions),
                         extensions_enabled);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Record that this migration now covers the Reading List toggle, to be able
   // to identify users who were migrated before it did (crbug.com/568406887).
   pref_service->SetBoolean(prefs::internal::kReadingListPrefMigratedToAccount,
