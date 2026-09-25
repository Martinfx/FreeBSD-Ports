--- include/GafferImage/DeepPixelAccessor.inl.orig	2026-09-25 06:42:21 UTC
+++ include/GafferImage/DeepPixelAccessor.inl
@@ -149,7 +149,8 @@ inline void DeepPixelAccessor::cachedDat
 
 	if( m_channelName.size() )
 	{
-		tileData = &m_dataCache[cacheIndex]->readable()[0];
+		// `data()` rather than `&[0]`, because deep tiles may have no samples.
+		tileData = m_dataCache[cacheIndex]->readable().data();
 	}
 	else
 	{
