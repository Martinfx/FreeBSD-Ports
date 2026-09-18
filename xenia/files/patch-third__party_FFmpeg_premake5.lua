--- third_party/FFmpeg/premake5.lua.orig	2021-10-29 20:46:08 UTC
+++ third_party/FFmpeg/premake5.lua
@@ -37,5 +37,7 @@ end
   filter({})
 end
 
+includedirs { "/usr/local/include" }
+
 include("libavcodec/premake5.lua")
 include("libavutil/premake5.lua")
