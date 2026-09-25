--- src/GafferImage/DeepState.cpp.orig	2026-09-25 06:15:48 UTC
+++ src/GafferImage/DeepState.cpp
@@ -747,7 +747,9 @@ IECore::IntVectorDataPtr computeSampleSo
 	{
 		if( offset > prevOffset )
 		{
-			std::sort( &result[prevOffset], &result[offset], compare );
+			// Iterators rather than `&result[offset]`, which is out of range for the
+			// last pixel, and aborts with a hardened C++ standard library.
+			std::sort( result.begin() + prevOffset, result.begin() + offset, compare );
 			prevOffset = offset;
 		}
 	}
