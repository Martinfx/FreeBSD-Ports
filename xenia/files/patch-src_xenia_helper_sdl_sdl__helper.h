--- src/xenia/helper/sdl/sdl_helper.h.orig	2025-03-06 15:33:34 UTC
+++ src/xenia/helper/sdl/sdl_helper.h
@@ -10,7 +10,7 @@
 #ifndef XENIA_HELPER_SDL_SDL_HELPER_H_
 #define XENIA_HELPER_SDL_SDL_HELPER_H_
 
-#include "SDL.h"
+#include "SDL2/SDL.h"
 
 namespace xe {
 namespace helper {
@@ -35,4 +35,4 @@ class SDLHelper {
 }  // namespace helper
 }  // namespace xe
 
-#endif  // XENIA_HELPER_SDL_SDL_HELPER_H_
\ No newline at end of file
+#endif  // XENIA_HELPER_SDL_SDL_HELPER_H_
