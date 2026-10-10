--- src/xenia/app/premake5.lua.orig	2024-05-25 13:31:50 UTC
+++ src/xenia/app/premake5.lua
@@ -43,6 +43,7 @@ project("xenia-app")
   files({
     "../base/main_init_"..platform_suffix..".cc",
     "../ui/windowed_app_main_"..platform_suffix..".cc",
+    "../base/debugging_"..platform_suffix..".cc",
   })
 
   resincludedirs({
@@ -57,6 +58,7 @@ project("xenia-app")
       "xenia-gpu-vulkan-trace-viewer",
       "xenia-hid-demo",
       "xenia-ui-window-vulkan-demo",
+      "xenia-base",
     })
   filter(NOT_SINGLE_LIBRARY_FILTER)
     kind("WindowedApp")
@@ -94,6 +96,7 @@ project("xenia-app")
       "xenia-debug-ui",
       "xenia-helper-sdl",
       "xenia-hid-sdl",
+      "xenia-base",
     })
 
   filter("platforms:Linux")
