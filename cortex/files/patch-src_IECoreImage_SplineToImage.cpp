--- src/IECoreImage/SplineToImage.cpp.orig	2026-09-10 21:49:58 UTC
+++ src/IECoreImage/SplineToImage.cpp
@@ -127,16 +127,16 @@
 		if( YTraits::dimensions()==3 )
 		{
 			FloatVectorDataPtr channel = result->template createChannel<float>( "R" );
-			channels.push_back( &(channel->writable()[0]) );
+			channels.push_back( channel->writable().data() );
 			channel = result->template createChannel<float>( "G" );
-			channels.push_back( &(channel->writable()[0]) );
+			channels.push_back( channel->writable().data() );
 			channel = result->template createChannel<float>( "B" );
-			channels.push_back( &(channel->writable()[0]) );
+			channels.push_back( channel->writable().data() );
 		}
 		else if( YTraits::dimensions()==1 )
 		{
 			FloatVectorDataPtr channel = result->template createChannel<float>( "Y" );
-			channels.push_back( &(channel->writable()[0]) );
+			channels.push_back( channel->writable().data() );
 		}
 
 		XType splineWidth = boost::numeric::width( splineInterval );
