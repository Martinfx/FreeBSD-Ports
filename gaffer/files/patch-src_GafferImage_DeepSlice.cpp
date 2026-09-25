--- src/GafferImage/DeepSlice.cpp.orig	2026-09-25 06:15:48 UTC
+++ src/GafferImage/DeepSlice.cpp
@@ -393,7 +393,8 @@ void DeepSlice::compute( Gaffer::ValuePl
 	}
 
 	const std::vector<int> &sampleOffsets = sampleOffsetsData->readable();
-	const float *a = aData ? &aData->readable()[0] : nullptr;
+	// `data()` rather than `&[0]`, because deep tiles may have no samples.
+	const float *a = aData ? aData->readable().data() : nullptr;
 	const std::vector<float> &z = zData->readable();
 	const std::vector<float> &zBack = zBackData->readable();
 
@@ -874,7 +875,7 @@ IECore::ConstFloatVectorDataPtr DeepSlic
 		const float* alpha = nullptr;
 		if( alphaData )
 		{
-			alpha = &alphaData->readable()[0];
+			alpha = alphaData->readable().data();
 		}
 
 		int prevAccumCount = 0;
