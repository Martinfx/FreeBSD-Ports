--- cmake/macros/Private.cmake.orig	2026-04-24 18:55:54 UTC
+++ cmake/macros/Private.cmake
@@ -1189,7 +1189,8 @@ function(_pxr_library NAME)
         _get_install_dir("plugin" pluginInstallPrefix)
         if (NOT PXR_INSTALL_SUBDIR)
             # XXX --- Why this difference?
-            _get_install_dir("plugin/usd" pluginInstallPrefix)
+            # FreeBSD: keep the plugins under lib/ instead of ${PREFIX}/plugin
+            _get_install_dir("lib/usd/plugin" pluginInstallPrefix)
         endif()
     else()
         _get_install_dir("lib/usd" pluginInstallPrefix)
@@ -1358,7 +1359,7 @@ function(_pxr_library NAME)
             MFB_ALT_PACKAGE_NAME=${PXR_PACKAGE}
             MFB_PACKAGE_MODULE=${pythonModuleName}
             PXR_BUILD_LOCATION=usd
-            PXR_PLUGIN_BUILD_LOCATION=../plugin/usd
+            PXR_PLUGIN_BUILD_LOCATION=usd/plugin
             ${pxrInstallLocation}
             ${apiPrivate}
     )
