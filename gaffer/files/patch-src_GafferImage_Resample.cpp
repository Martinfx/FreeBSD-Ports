--- src/GafferImage/Resample.cpp.orig	2026-09-25 07:03:08 UTC
+++ src/GafferImage/Resample.cpp
@@ -1950,7 +1950,10 @@ IECore::ConstFloatVectorDataPtr Resample
 				for( oP.x = tileBound.min.x; oP.x < tileBound.max.x; ++oP.x )
 				{
 					boost::span<const float> channelSamples = sampleOffsetsSampler.sample( *iPxIt, iPy );
-					memcpy( &result[outputSamplePosition], &channelSamples[0], channelSamples.size() * sizeof( float ) );
+					// `data()` rather than `&[]`, because pixels may have no samples, and
+					// `operator[]` at the end of `result` aborts with a hardened C++ standard
+					// library.
+					memcpy( result.data() + outputSamplePosition, channelSamples.data(), channelSamples.size() * sizeof( float ) );
 					outputSamplePosition += channelSamples.size();
 					++iPxIt;
 				}
