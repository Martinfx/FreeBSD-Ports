--- src/IECoreImage/MedianCutSampler.cpp.orig	2026-09-10 21:49:58 UTC
+++ src/IECoreImage/MedianCutSampler.cpp
@@ -238,7 +238,7 @@
 		float radiansPerPixel = M_PI / (dataWindow.size().y + 1);
 		float angle = ( M_PI - radiansPerPixel ) / 2.0f;
 
-		float *p = &(luminance->writable()[0]);
+		float *p = luminance->writable().data();
 
 		for( int y=dataWindow.min.y; y<=dataWindow.max.y; y++ )
 		{
@@ -274,8 +274,8 @@
 
 	dataWindow.max -= dataWindow.min;
 	dataWindow.min -= dataWindow.min; // let's start indexing from 0 shall we?
-	Array2D array( &(luminance->writable()[0]), extents[dataWindow.size().x+1][dataWindow.size().y+1], fortran_storage_order() );
-	Array2D summedArray( &(summedLuminance->writable()[0]), extents[dataWindow.size().x+1][dataWindow.size().y+1], fortran_storage_order() );
+	Array2D array( luminance->writable().data(), extents[dataWindow.size().x+1][dataWindow.size().y+1], fortran_storage_order() );
+	Array2D summedArray( summedLuminance->writable().data(), extents[dataWindow.size().x+1][dataWindow.size().y+1], fortran_storage_order() );
 	medianCut( array, summedArray, projection, dataWindow, areas->writable(), centroids->writable(), 0, subdivisionDepthParameter()->getNumericValue() );
 
 	return result;
