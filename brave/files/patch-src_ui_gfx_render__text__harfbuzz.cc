--- src/ui/gfx/render_text_harfbuzz.cc.orig	2026-11-24 12:50:30 UTC
+++ src/ui/gfx/render_text_harfbuzz.cc
@@ -207,7 +207,7 @@ const char* GetPlatformColorEmojiFontNam
   return "Segoe UI Emoji";
 #elif BUILDFLAG(IS_APPLE)
   return "Apple Color Emoji";
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return "Noto Color Emoji";
 #else
   return nullptr;
