--- src/device/vr/openxr/openxr_extension_helper.cc.orig	2026-11-24 12:50:30 UTC
+++ src/device/vr/openxr/openxr_extension_helper.cc
@@ -227,7 +227,7 @@ bool OpenXrExtensionHelper::IsFeatureSup
       return IsExtensionSupported(
           XR_MSFT_SECONDARY_VIEW_CONFIGURATION_EXTENSION_NAME);
     case device::mojom::XRSessionFeature::LAYERS:
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       // Few Linux runtimes support all of these, so the graphics binding
       // refuses the layer types it cannot create instead.
       return true;
