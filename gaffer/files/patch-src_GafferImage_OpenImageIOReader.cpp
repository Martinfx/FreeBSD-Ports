--- src/GafferImage/OpenImageIOReader.cpp.orig	2026-09-25 06:15:48 UTC
+++ src/GafferImage/OpenImageIOReader.cpp
@@ -1276,7 +1276,8 @@ class File
 								FloatVectorDataPtr tileAlloc = new IECore::FloatVectorData();
 								podVectorResizeUninitialized<float>( tileAlloc->writable(), totalSamples );
 
-								tileChannelPointers[ c * tileBatchNumTiles + i ] = &tileAlloc->writable()[0];
+								// `data()` rather than `&[0]`, because the tile may have no samples.
+								tileChannelPointers[ c * tileBatchNumTiles + i ] = tileAlloc->writable().data();
 								resultChannels->members()[ c * tileBatchNumTiles + i ] = std::move( tileAlloc );
 
 							}
