--- src/GafferCycles/IECoreCyclesPreview/GeometryAlgo.cpp.orig	2026-09-24 19:41:12 UTC
+++ src/GafferCycles/IECoreCyclesPreview/GeometryAlgo.cpp
@@ -207,7 +207,13 @@ class VolumeLoader : public ccl::VDBImag
 		VolumeLoader( openvdb::GridBase::ConstPtr grid, const string &gridName, int precision_, float clipping )
 			:	VDBImageLoader( grid, gridName, clipping )
 		{
+#ifdef WITH_NANOVDB
 			precision = precision_;
+#else
+			// FreeBSD : graphics/cycles is built without NanoVDB, the only
+			// user of the precision (misc/openvdb does not install it).
+			(void)precision_;
+#endif
 		}
 
 };
