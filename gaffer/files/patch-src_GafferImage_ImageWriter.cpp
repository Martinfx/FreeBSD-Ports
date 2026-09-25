--- src/GafferImage/ImageWriter.cpp.orig	2026-09-25 06:15:48 UTC
+++ src/GafferImage/ImageWriter.cpp
@@ -705,8 +705,9 @@ class DeepTileWriter
 					const int inOffsetPos = offset.y * ImagePlug::tileSize() + offset.x;
 
 					const int outStartIndex = ( outTileBnds.max.y - copyArea.max.y ) * outTileBnds.size().x + copyArea.min.x - outTileBnds.min.x;
+					// `data()` rather than `&[0]`, because deep tiles may have no samples.
 					copyDeepArea(
-						&sampleOffsets[0], &data->readable()[0], inOffsetPos, copyArea.size(),
+						&sampleOffsets[0], data->readable().data(), inOffsetPos, copyArea.size(),
 						m_tilesData[tileIndex], outStartIndex, outTileBnds.size().x, channelIndex
 					);
 				}
@@ -952,7 +953,7 @@ class DeepScanlineWriter
 			// Copy into the chunk the region of this tile that overlaps the process window ( which for
 			// deep is always the data window )
 			copyDeepArea(
-				&sampleOffsets[0], &data->readable()[0], inOffsetPos, copyArea.size(), m_deepData,
+				&sampleOffsets[0], data->readable().data(), inOffsetPos, copyArea.size(), m_deepData,
 				copyArea.min.x - m_processWindow.min.x, m_spec.width, channelIndex
 			);
 
