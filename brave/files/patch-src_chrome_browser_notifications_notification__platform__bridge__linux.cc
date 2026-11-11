--- src/chrome/browser/notifications/notification_platform_bridge_linux.cc.orig	2026-11-02 23:22:33 UTC
+++ src/chrome/browser/notifications/notification_platform_bridge_linux.cc
@@ -366,6 +366,8 @@ NotificationResources WriteNotificationR
   result.has_logo = WriteImageFile(logo, dir_path.Append("logo.png"));
   result.has_icon = WriteImageFile(icon, dir_path.Append("icon.png"));
   result.has_image = WriteImageFile(image, dir_path.Append("image.png"));
+  // XXX
+#if !BUILDFLAG(IS_OPENBSD)
   if (result.has_icon) {
     result.icon_bytes = icon;
     if (icon && icon->size() > 0) {
@@ -384,6 +386,7 @@ NotificationResources WriteNotificationR
       }
     }
   }
+#endif
 
   result.dir_path = dir_path;
   result.dir = base::SequenceBound<base::ScopedTempDir>(
