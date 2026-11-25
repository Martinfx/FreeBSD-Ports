--- src/chrome/browser/extensions/api/runtime/chrome_runtime_api_delegate.cc.orig	2026-11-24 12:50:30 UTC
+++ src/chrome/browser/extensions/api/runtime/chrome_runtime_api_delegate.cc
@@ -343,7 +343,9 @@ bool ChromeRuntimeAPIDelegate::GetPlatfo
   } else if (os == "linux") {
     info->os = extensions::api::runtime::PlatformOs::kLinux;
   } else if (os == "openbsd") {
-    info->os = extensions::api::runtime::PlatformOs::kOpenbsd;
+    info->os = extensions::api::runtime::PlatformOs::kLinux;
+  } else if (os == "freebsd") {
+    info->os = extensions::api::runtime::PlatformOs::kLinux;
   } else if (os == "android") {
     info->os = extensions::api::runtime::PlatformOs::kAndroid;
   } else {
