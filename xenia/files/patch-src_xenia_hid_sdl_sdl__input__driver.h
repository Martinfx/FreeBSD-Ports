--- src/xenia/hid/sdl/sdl_input_driver.h.orig	2025-03-06 15:36:53 UTC
+++ src/xenia/hid/sdl/sdl_input_driver.h
@@ -15,7 +15,7 @@
 #include <mutex>
 #include <optional>
 
-#include "SDL.h"
+#include "SDL2/SDL.h"
 #include "xenia/hid/input_driver.h"
 
 #define HID_SDL_USER_COUNT 4
