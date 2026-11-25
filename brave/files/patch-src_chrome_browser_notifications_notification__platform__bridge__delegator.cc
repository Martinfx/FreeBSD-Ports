--- src/chrome/browser/notifications/notification_platform_bridge_delegator.cc.orig	2026-11-24 12:50:30 UTC
+++ src/chrome/browser/notifications/notification_platform_bridge_delegator.cc
@@ -55,7 +55,7 @@ bool SystemNotificationsEnabled(Profile*
 #elif BUILDFLAG(IS_WIN)
   return NotificationPlatformBridgeWin::SystemNotificationEnabled();
 #else
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (profile) {
     // Prefs take precedence over flags.
     PrefService* prefs = profile->GetPrefs();
