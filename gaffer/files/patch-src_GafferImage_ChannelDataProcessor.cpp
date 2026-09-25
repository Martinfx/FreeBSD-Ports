--- src/GafferImage/ChannelDataProcessor.cpp.orig	2026-09-25 06:15:48 UTC
+++ src/GafferImage/ChannelDataProcessor.cpp
@@ -202,8 +202,9 @@ IECore::ConstFloatVectorDataPtr ChannelD
 		}
 
 		int size = alphaData->readable().size();
-		const float *A = &alphaData->readable().front();
-		float *O = &outData->writable().front();
+		// `data()` rather than `&front()`, because deep tiles may have no samples.
+		const float *A = alphaData->readable().data();
+		float *O = outData->writable().data();
 		for( int j = 0; j < size; j++ )
 		{
 			if( *A != 0 )
@@ -219,12 +220,12 @@ IECore::ConstFloatVectorDataPtr ChannelD
 	if( unpremult && postAlphaData )
 	{
 		int size = postAlphaData->readable().size();
-		const float *A = &postAlphaData->readable().front();
-		float *O = &outData->writable().front();
+		const float *A = postAlphaData->readable().data();
+		float *O = outData->writable().data();
 
 		if( repremultByProcessedAlpha )
 		{
-			const float *preA = &alphaData->readable().front();
+			const float *preA = alphaData->readable().data();
 			for( int j = 0; j < size; j++ )
 			{
 				if( ! ( *A == 0 && *preA == 0 ) )
