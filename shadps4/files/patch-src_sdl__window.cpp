--- src/sdl_window.cpp.orig	2025-03-27 20:40:40 UTC
+++ src/sdl_window.cpp
@@ -307,7 +307,7 @@ WindowSDL::WindowSDL(s32 width_, s32 height_, Input::G
     window_info.type = WindowSystemType::Windows;
     window_info.render_surface = SDL_GetPointerProperty(SDL_GetWindowProperties(window),
                                                         SDL_PROP_WINDOW_WIN32_HWND_POINTER, NULL);
-#elif defined(SDL_PLATFORM_LINUX)
+#elif defined(SDL_PLATFORM_LINUX) || defined(SDL_PLATFORM_FREEBSD)
     if (SDL_strcmp(SDL_GetCurrentVideoDriver(), "x11") == 0) {
         window_info.type = WindowSystemType::X11;
         window_info.display_connection = SDL_GetPointerProperty(
