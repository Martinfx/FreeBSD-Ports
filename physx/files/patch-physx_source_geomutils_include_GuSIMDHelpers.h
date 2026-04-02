--- physx/source/geomutils/include/GuSIMDHelpers.h.orig	2022-11-09 12:26:46 UTC
+++ physx/source/geomutils/include/GuSIMDHelpers.h
@@ -72,7 +72,7 @@ namespace Gu
 			const QuatV qV = V4LoadU(&q.x);
 			Vec3V column0V, column1V, column2V;
 			QuatGetMat33V(qV, column0V, column1V, column2V);
-#if defined(PX_SIMD_DISABLED) || PX_ANDROID || (PX_LINUX && (PX_ARM || PX_A64)) || (PX_UWP && (PX_ARM || PX_A64))
+#if defined(PX_SIMD_DISABLED) || PX_ANDROID || ((PX_LINUX || PX_FREEBSD) && (PX_ARM || PX_A64)) || (PX_UWP && (PX_ARM || PX_A64))
 			V3StoreU(column0V, column0);
 			V3StoreU(column1V, column1);
 			V3StoreU(column2V, column2);
