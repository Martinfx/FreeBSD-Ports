--- intern/slim/intern/slim.cpp.orig	2026-09-28 10:00:00 UTC
+++ intern/slim/intern/slim.cpp
@@ -208,8 +208,8 @@ static inline void polar_svd(const Eigen
                              Eigen::PlainObjectBase<DerivedV> &V)
 {
   using namespace std;
-  Eigen::JacobiSVD<DerivedA, Eigen::ComputeFullU | Eigen::ComputeFullV> svd;
-  svd.compute(A);
+  Eigen::JacobiSVD<DerivedA> svd;
+  svd.compute(A, Eigen::ComputeFullU | Eigen::ComputeFullV);
   U = svd.matrixU();
   V = svd.matrixV();
   S = svd.singularValues();
