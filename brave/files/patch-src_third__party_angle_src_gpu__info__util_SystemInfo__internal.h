--- src/third_party/angle/src/gpu_info_util/SystemInfo_internal.h.orig	2026-11-24 12:50:30 UTC
+++ src/third_party/angle/src/gpu_info_util/SystemInfo_internal.h
@@ -15,6 +15,13 @@
 namespace angle
 {
 
+#if defined(__OpenBSD__) || defined(__FreeBSD__)
+bool CollectMesaCardInfo(std::vector<GPUDeviceInfo> *devices);                
+#if defined(__FreeBSD__)
+bool GetPCIDevicesFreeBSD(std::vector<GPUDeviceInfo> *devices);
+#endif
+#endif
+
 // Defined in SystemInfo_libpci when GPU_INFO_USE_LIBPCI is defined.
 bool GetPCIDevicesWithLibPCI(std::vector<GPUDeviceInfo> *devices);
 // Defined in SystemInfo_x11 when GPU_INFO_USE_X11 is defined.
