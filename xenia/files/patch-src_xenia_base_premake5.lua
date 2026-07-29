--- src/xenia/base/premake5.lua.orig	2024-05-25 13:31:50 UTC
+++ src/xenia/base/premake5.lua
@@ -9,6 +9,7 @@ project("xenia-base")
     "fmt",
   })
   defines({
+  "FMT_WERROR=0",
   })
   local_platform_files()
   removefiles({"console_app_main_*.cc"})
