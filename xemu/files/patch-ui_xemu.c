--- ui/xemu.c.orig	2020-12-08 02:25:48 UTC
+++ ui/xemu.c
@@ -745,12 +745,23 @@ static void sdl_cleanup(void)
 }
 #endif
 
+static const DisplayChangeListenerOps dcl_2d_ops = {
+    .dpy_name             = "sdl2-2d",
+    .dpy_gfx_update       = sdl2_2d_update,
+    .dpy_gfx_switch       = sdl2_2d_switch,
+    .dpy_gfx_check_format = sdl2_2d_check_format,
+    .dpy_refresh          = sdl2_2d_refresh,
+    .dpy_mouse_set        = sdl_mouse_warp,
+    .dpy_cursor_define    = sdl_mouse_define,
+};
+
+#ifdef CONFIG_OPENGL
 static const DisplayChangeListenerOps dcl_gl_ops = {
     .dpy_name                = "sdl2-gl",
     .dpy_gfx_update          = sdl2_gl_update,
     .dpy_gfx_switch          = sdl2_gl_switch,
     .dpy_gfx_check_format    = console_gl_check_format,
-    // .dpy_refresh             = sdl2_gl_refresh,
+    .dpy_refresh             = sdl2_gl_refresh,
     .dpy_mouse_set           = sdl_mouse_warp,
     .dpy_cursor_define       = sdl_mouse_define,
 
@@ -762,6 +773,7 @@ static const DisplayChangeListenerOps dcl_gl_ops = {
     .dpy_gl_scanout_texture  = sdl2_gl_scanout_texture,
     .dpy_gl_update           = sdl2_gl_scanout_flush,
 };
+#endif
 
 static void sdl2_display_very_early_init(DisplayOptions *o)
 {
@@ -901,8 +913,13 @@ static void sdl2_display_init(DisplayState *ds, Displa
         }
         sdl2_console[i].idx = i;
         sdl2_console[i].opts = o;
-        sdl2_console[i].opengl = 1;
-        sdl2_console[i].dcl.ops = &dcl_gl_ops;
+#ifdef CONFIG_OPENGL
+        sdl2_console[i].opengl = display_opengl;
+        sdl2_console[i].dcl.ops = display_opengl ? &dcl_gl_ops : &dcl_2d_ops;
+#else
+        sdl2_console[i].opengl = 0;
+        sdl2_console[i].dcl.ops = &dcl_2d_ops;
+#endif
         sdl2_console[i].dcl.con = con;
         sdl2_console[i].kbd = qkbd_state_init(con);
         register_displaychangelistener(&sdl2_console[i].dcl);
@@ -916,6 +933,7 @@ static void sdl2_display_init(DisplayState *ds, Displa
 #endif
         }
 #endif
+
     }
 
     gui_grab = 0;
@@ -955,17 +973,17 @@ void xb_surface_gl_create_texture(DisplaySurface *surf
     switch (surface->format) {
     case PIXMAN_BE_b8g8r8x8:
     case PIXMAN_BE_b8g8r8a8:
-        surface->glformat = GL_BGRA_EXT;
-        surface->gltype = GL_UNSIGNED_BYTE;
+        surface->format = GL_BGRA_EXT;
+//        surface->gltype = GL_UNSIGNED_BYTE;
         break;
     case PIXMAN_BE_x8r8g8b8:
     case PIXMAN_BE_a8r8g8b8:
-        surface->glformat = GL_RGBA;
-        surface->gltype = GL_UNSIGNED_BYTE;
+        surface->format = GL_RGBA;
+//        surface->gltype = GL_UNSIGNED_BYTE;
         break;
     case PIXMAN_r5g6b5:
-        surface->glformat = GL_RGB;
-        surface->gltype = GL_UNSIGNED_SHORT_5_6_5;
+        surface->format = GL_RGB;
+//        surface->gltype = GL_UNSIGNED_SHORT_5_6_5;
         break;
     default:
         g_assert_not_reached();
@@ -979,7 +997,7 @@ void xb_surface_gl_create_texture(DisplaySurface *surf
     glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                  surface_width(surface),
                  surface_height(surface),
-                 0, surface->glformat, surface->gltype,
+                 0, surface->format, surface->gltype,
                  surface_data(surface));
     glPixelStorei(GL_UNPACK_ROW_LENGTH_EXT, 0);
 
@@ -998,7 +1016,7 @@ void xb_surface_gl_update_texture(DisplaySurface *surf
                       / surface_bytes_per_pixel(surface));
         glTexSubImage2D(GL_TEXTURE_2D, 0,
                         x, y, w, h,
-                        surface->glformat, surface->gltype,
+                        surface->format, surface->gltype,
                         data + surface_stride(surface) * y
                         + surface_bytes_per_pixel(surface) * x);
         glPixelStorei(GL_UNPACK_ROW_LENGTH_EXT, 0);
