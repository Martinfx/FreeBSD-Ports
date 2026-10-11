--- src/utils/xrMiscMath/vector.cpp.orig	2026-10-01 00:00:00 UTC
+++ src/utils/xrMiscMath/vector.cpp
@@ -140,7 +140,7 @@
 	return src;
 }
 
-double rsqrt(double v) noexcept { return 1.0 / _sqrt(v); }
+double xr_rsqrt(double v) noexcept { return 1.0 / _sqrt(v); }
 
 //////////////////////////////////////////////////////////////////
 
