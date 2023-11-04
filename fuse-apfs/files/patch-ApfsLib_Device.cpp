--- ApfsLib/Device.cpp.orig	2023-11-01 20:28:01 UTC
+++ ApfsLib/Device.cpp
@@ -25,6 +25,7 @@
 #include "DeviceWinPhys.h"
 #include "DeviceLinux.h"
 #include "DeviceMac.h"
+#include "DeviceBSD.h"
 #include "DeviceDMG.h"
 #include "DeviceSparseImage.h"
 #include "DeviceVDI.h"
@@ -96,6 +97,9 @@ Device * Device::OpenDevice(const char * name)
 #endif
 #ifdef __APPLE__
 		dev = new DeviceMac();
+#endif
+#ifdef __FreeBSD__
+		dev = new DeviceBSD();
 #endif
 		rc = dev->Open(name);
 
