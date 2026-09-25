--- src/GafferImage/Offset.cpp.orig	2026-09-25 06:15:48 UTC
+++ src/GafferImage/Offset.cpp
@@ -229,7 +229,8 @@ IECore::ConstFloatVectorDataPtr Offset::
 		outData->writable().resize( outSampleOffsetsData->readable().back() );
 	}
 
-	float *out = &outData->writable().front();
+	// `data()` rather than `&front()`, because deep tiles may have no samples.
+	float *out = outData->writable().data();
 
 	V2i inTileOrigin;
 	for( inTileOrigin.y = ImagePlug::tileOrigin( inBound.min ).y; inTileOrigin.y < inBound.max.y; inTileOrigin.y += ImagePlug::tileSize() )
@@ -238,7 +239,7 @@ IECore::ConstFloatVectorDataPtr Offset::
 		{
 			offsetScope.setTileOrigin( &inTileOrigin );
 			ConstFloatVectorDataPtr inData = inPlug()->channelDataPlug()->getValue();
-			const float *in = &inData->readable().front();
+			const float *in = inData->readable().data();
 
 			const Box2i inTileBound( inTileOrigin, inTileOrigin + V2i( ImagePlug::tileSize() ) );
 			const Box2i inRegion = BufferAlgo::intersection(
