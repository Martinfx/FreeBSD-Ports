--- src/third_party/webrtc/rtc_base/network.cc.orig	2026-11-24 12:50:30 UTC
+++ src/third_party/webrtc/rtc_base/network.cc
@@ -314,7 +314,12 @@ AdapterType GetAdapterTypeFromName(absl:
   }
 #endif
 
+#if defined(WEBRTC_BSD)
+  // Treat all other network interface names as ethernet on BSD
+  return webrtc::ADAPTER_TYPE_ETHERNET;
+#else
   return ADAPTER_TYPE_UNKNOWN;
+#endif
 }
 
 NetworkManager::EnumerationPermission NetworkManager::enumeration_permission()
