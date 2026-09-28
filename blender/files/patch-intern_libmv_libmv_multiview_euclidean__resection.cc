--- intern/libmv/libmv/multiview/euclidean_resection.cc.orig	2026-09-28 10:00:00 UTC
+++ intern/libmv/libmv/multiview/euclidean_resection.cc
@@ -107,7 +107,7 @@ void AbsoluteOrientation(const Mat3X& X,
 
   // Find the unit quaternion q that maximizes qNq. It is the eigenvector
   // corresponding to the lagest eigenvalue.
-  Vec4 q = N.jacobiSvd<Eigen::ComputeFullU>().matrixU().col(0);
+  Vec4 q = N.jacobiSvd(Eigen::ComputeFullU).matrixU().col(0);
 
   // Retrieve the 3x3 rotation matrix.
   Vec4 qq = q.array() * q.array();
@@ -246,7 +246,7 @@ void EuclideanResectionAnsarDaniilidis(c
   }
 
   int num_lambda = num_points + 1;  // Dimension of the null space of M.
-  Mat V = M.jacobiSvd<Eigen::ComputeFullV>().matrixV().block(
+  Mat V = M.jacobiSvd(Eigen::ComputeFullV).matrixV().block(
       0, num_m_rows, num_m_columns, num_lambda);
 
   // TODO(vess): The number of constraint equations in K (num_k_rows) must be
@@ -303,7 +303,7 @@ void EuclideanResectionAnsarDaniilidis(c
     }
   }
   Vec L_sq =
-      K.jacobiSvd<Eigen::ComputeFullV>().matrixV().col(num_k_columns - 1);
+      K.jacobiSvd(Eigen::ComputeFullV).matrixV().col(num_k_columns - 1);
 
   // Pivot on the largest element for numerical stability. Afterwards recover
   // the sign of the lambda solution.
