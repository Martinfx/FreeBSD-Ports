--- core/DesktopEditor/agg-2.4/include/agg_math.h.orig	2025-09-23 22:51:20 UTC
+++ core/DesktopEditor/agg-2.4/include/agg_math.h
@@ -431,7 +431,7 @@ namespace agg
         }
     }
 
-#if defined(_LINUX) || defined(__APPLE__)
+#if defined(_LINUX) || defined(__APPLE__) || defined(__FreeBSD__)
     inline double _hypot(const double& x, const double& y)
     {
         return sqrt(x * x + y * y);
