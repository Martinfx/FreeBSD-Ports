--- src/GafferImage/Mix.cpp.orig	2026-09-25 06:15:48 UTC
+++ src/GafferImage/Mix.cpp
@@ -515,10 +515,11 @@ IECore::ConstFloatVectorDataPtr Mix::com
 	FloatVectorDataPtr resultData = new FloatVectorData();
 	int resultSize = channelData[0] ? channelData[0]->readable().size() : ImagePlug::tilePixels();
 	resultData->writable().resize( resultSize, 0.0f );
-	float *R = &resultData->writable().front();
-	const float *A = channelData[0] ? &channelData[0]->readable().front() : nullptr;
-	const float *B = channelData[1] ? &channelData[1]->readable().front() : nullptr;
-	const float *M = maskData ? &maskData->readable().front() : nullptr;
+	// `data()` rather than `&front()`, because deep tiles may have no samples.
+	float *R = resultData->writable().data();
+	const float *A = channelData[0] ? channelData[0]->readable().data() : nullptr;
+	const float *B = channelData[1] ? channelData[1]->readable().data() : nullptr;
+	const float *M = maskData ? maskData->readable().data() : nullptr;
 
 	// For the common case where we're completely filled, we don't need to worry about
 	// the bounds, and can use a much simpler loop
