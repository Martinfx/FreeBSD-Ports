--- src/GafferImage/DeepMerge.cpp.orig	2026-09-25 06:15:48 UTC
+++ src/GafferImage/DeepMerge.cpp
@@ -260,7 +260,9 @@ void DeepMerge::compute( Gaffer::ValuePl
 
 	// Accumulate the output sample counts into a running offset
 	int accum = 0;
-	int *offsetPtr = &result[numInputs + 1];
+	// Note the use of `data()` : there may be no inputs, in which case `result` is
+	// empty, and `operator[]` aborts with a hardened C++ standard library.
+	int *offsetPtr = result.data() + numInputs + 1;
 	for( unsigned int o = 0; o < numInputs * ImagePlug::tilePixels(); o++ )
 	{
 		accum += *offsetPtr;
@@ -443,7 +445,8 @@ IECore::ConstFloatVectorDataPtr DeepMerg
 		{
 			channelDatas[j] = inP->channelDataPlug()->getValue();
 		}
-		channelPtrs[j] = &channelDatas[j]->readable()[0];
+		// `data()` rather than `&[0]`, because deep tiles may have no samples.
+		channelPtrs[j] = channelDatas[j]->readable().data();
 	}
 
 	// Now we can loop through just pasting in the samples from each input to each pixel
