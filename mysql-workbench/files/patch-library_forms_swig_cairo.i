--- library/forms/swig/cairo.i.orig	2024-05-19 04:40:40 UTC
+++ library/forms/swig/cairo.i
@@ -177,7 +177,7 @@
 }
 
 
-%include <cairo/cairo.h>
+#include <cairo/cairo.h>
 cairo_surface_t *cairo_image_surface_create_from_png_stream(PyObject *reader)
 {
   return cairo_image_surface_create_from_png_stream(py_read_func, reader);
