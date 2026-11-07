--- core/DesktopEditor/agg-2.4/include/agg_span_gradient.h.orig	2026-11-05 00:00:00 UTC
+++ core/DesktopEditor/agg-2.4/include/agg_span_gradient.h
@@ -20,7 +20,7 @@
 namespace agg
 {
     
-#if !defined(_LINUX) && !(defined(_WIN32) || defined (_WIN64)) && !defined(__APPLE__)
+#if !defined(_LINUX) && !defined(__FreeBSD__) && !(defined(_WIN32) || defined (_WIN64)) && !defined(__APPLE__)
     double _hypot(double x, double y)
     {
         return sqrt(x*x + y*y);
