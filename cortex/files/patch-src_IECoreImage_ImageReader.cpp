--- src/IECoreImage/ImageReader.cpp.orig	2026-09-10 21:49:58 UTC
+++ src/IECoreImage/ImageReader.cpp
@@ -410,7 +410,7 @@
 				0, 1, // z begin, z end
 				channelIndex, channelIndex + 1,
 				/* format */ dataType,
-				/* data */ &( data->writable()[0] )
+				/* data */ data->writable().data()
 			);
 
 			if( !status )
