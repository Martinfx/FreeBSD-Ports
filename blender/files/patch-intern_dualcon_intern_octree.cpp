--- intern/dualcon/intern/octree.cpp.orig	2026-09-28 10:00:00 UTC
+++ intern/dualcon/intern/octree.cpp
@@ -2183,8 +2183,7 @@ void Octree::countIntersection(Node *nod
 /* from http://eigen.tuxfamily.org/bz/show_bug.cgi?id=257 */
 static void pseudoInverse(const Eigen::Matrix3f &a, Eigen::Matrix3f &result, float tolerance)
 {
-  const int Options = Eigen::ComputeFullU | Eigen::ComputeFullV;
-  Eigen::JacobiSVD<Eigen::Matrix3f, Options> svd = a.jacobiSvd<Options>();
+  Eigen::JacobiSVD<Eigen::Matrix3f> svd = a.jacobiSvd(Eigen::ComputeFullU | Eigen::ComputeFullV);
 
   result = svd.matrixV() *
            Eigen::Vector3f((svd.singularValues().array().abs() > tolerance)
