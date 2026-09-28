--- intern/libmv/libmv/tracking/track_region.cc.orig	2026-09-28 10:00:00 UTC
+++ intern/libmv/libmv/tracking/track_region.cc
@@ -940,7 +940,7 @@ struct AffineWarp {
     }
 
     // TODO(keir): Check solution quality.
-    Vec4 a = Q1.jacobiSvd<Eigen::ComputeThinU | Eigen::ComputeThinV>().solve(Q2);
+    Vec4 a = Q1.jacobiSvd(Eigen::ComputeThinU | Eigen::ComputeThinV).solve(Q2);
     parameters[2] = a[0];
     parameters[3] = a[1];
     parameters[4] = a[2];
