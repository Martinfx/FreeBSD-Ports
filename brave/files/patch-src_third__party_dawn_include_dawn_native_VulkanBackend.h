--- src/third_party/dawn/include/dawn/native/VulkanBackend.h.orig	2026-11-02 23:22:33 UTC
+++ src/third_party/dawn/include/dawn/native/VulkanBackend.h
@@ -99,7 +99,7 @@ struct ExternalImageExportInfoVk : Exter
 };
 
 // Can't use DAWN_PLATFORM_IS(LINUX) since header included in both Dawn and Chrome
-#if defined(__linux__) || defined(__Fuchsia__)
+#if defined(__linux__) || defined(__Fuchsia__) || defined(__OpenBSD__) || defined(__FreeBSD__)
 
 // Common properties of external images represented by FDs. On successful import the file
 // descriptor's ownership is transferred to the Dawn implementation and they shouldn't be
