--- third_party/FFmpeg/libavutil/premake5.lua.orig	2025-03-06 13:13:29 UTC
+++ third_party/FFmpeg/libavutil/premake5.lua
@@ -210,7 +210,7 @@ project("libavutil")
 
   -- libavutil/x86/Makefile:
   --   OBJS:
-  filter({"platforms:Android-x86_64 or platforms:Linux or platforms:Windows"})
+  filter({"platforms:Android-x86_64 or platforms:Linux or platforms:FreeBSD or platforms:Windows"})
   files({
     "x86/cpu.c",
     "x86/fixed_dsp_init.c",
@@ -219,3 +219,5 @@ project("libavutil")
     "x86/lls_init.c",
   })
   filter({})
+
+  includedirs { "/usr/local/include" }
