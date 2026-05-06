--- plugins/usb/usb-helpers.cpp.orig	2026-01-09 03:51:17 UTC
+++ plugins/usb/usb-helpers.cpp
@@ -141,21 +141,33 @@ static std::vector<USBDeviceInfo> getHotplugBasedDevic
 	static bool hotplugSetupDone = false;
 
 	if (!hotplugSetupDone) {
-		hotplugSetupDone = true;
-		devices = pollUSBDevices();
+    	hotplugSetupDone = true;
+    	devices = pollUSBDevices();
 
-		int ret = libusb_hotplug_register_callback(
-			nullptr,
-			LIBUSB_HOTPLUG_EVENT_DEVICE_ARRIVED |
-				LIBUSB_HOTPLUG_EVENT_DEVICE_LEFT,
-			0, LIBUSB_HOTPLUG_MATCH_ANY, LIBUSB_HOTPLUG_MATCH_ANY,
-			LIBUSB_HOTPLUG_MATCH_ANY, hotplugCallback, &devices,
-			nullptr);
-		if (ret != LIBUSB_SUCCESS) {
-			hotplugsAreSupported = false;
-		} else {
-			blog(LOG_WARNING, LOG_PREFIX "hotplug supported!");
-		}
+    	if (libusb_has_capability(LIBUSB_CAP_HAS_HOTPLUG)) {
+        	libusb_hotplug_callback_handle callback_handle;
+
+        	int ret = libusb_hotplug_register_callback(
+            	nullptr,
+            	static_cast<libusb_hotplug_event>(
+                LIBUSB_HOTPLUG_EVENT_DEVICE_ARRIVED |
+                LIBUSB_HOTPLUG_EVENT_DEVICE_LEFT),
+            	LIBUSB_HOTPLUG_NO_FLAGS,
+            	LIBUSB_HOTPLUG_MATCH_ANY,
+            	LIBUSB_HOTPLUG_MATCH_ANY,
+            	LIBUSB_HOTPLUG_MATCH_ANY,
+            	hotplugCallback,
+            	&devices,
+            	&callback_handle);
+
+        if (ret != LIBUSB_SUCCESS) {
+            hotplugsAreSupported = false;
+        } else {
+            blog(LOG_WARNING, LOG_PREFIX "hotplug supported!");
+        }
+    	} else {
+        	hotplugsAreSupported = false;
+    	}
 	}
 
 	std::lock_guard<std::mutex> lock(mutex);
