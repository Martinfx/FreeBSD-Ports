--- third_party/SDL2.lua.orig	2025-03-07 11:41:14 UTC
+++ third_party/SDL2.lua
@@ -30,7 +30,7 @@ function sdl2_include()
     includedirs({
       path.getrelative(".", third_party_path) .. "/SDL2/include",
     })
-  filter("platforms:Linux or platforms:Mac")
+  filter("platforms:Linux or platforms:Mac or platforms:FreeBSD")
     includedirs(sdl2_sys_includedirs)
   filter({})
 end
