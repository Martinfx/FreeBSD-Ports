--- build/Helpers.lua.orig	2024-06-08 16:26:43 UTC
+++ build/Helpers.lua
@@ -280,7 +280,8 @@ function WriteConfigForMSBuild()
   writeProperty("Configuration", _OPTIONS["configuration"])
   writeBooleanProperty("IsWindows", os.istarget("windows"))
   writeBooleanProperty("IsLinux", os.istarget("linux"))
-  writeBooleanProperty("IsMacOSX", os.istarget("macosx")) 
+  writeBooleanProperty("IsMacOSX", os.istarget("macosx"))
+  writeBooleanProperty("IsFreeBSD", os.istarget("freebsd")) 
   writeBooleanProperty("CI", os.getenv("CI") == "true")
   writeBooleanProperty("GenerateBuildConfig", generate_build_config == true)
   writeBooleanProperty("UseCXX11ABI", UseCxx11ABI())
