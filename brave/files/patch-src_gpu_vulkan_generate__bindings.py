--- src/gpu/vulkan/generate_bindings.py.orig	2026-11-02 23:22:33 UTC
+++ src/gpu/vulkan/generate_bindings.py
@@ -275,7 +275,7 @@ VULKAN_DEVICE_FUNCTIONS = [
     ],
   },
   {
-    'ifdef': 'BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)',
+    'ifdef': 'BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)',
     'extension': 'VK_EXT_IMAGE_DRM_FORMAT_MODIFIER_EXTENSION_NAME',
     'functions': [
       'vkGetImageDrmFormatModifierPropertiesEXT',
