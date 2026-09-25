--- src/GafferScene/PointInstancerAlgo.cpp.orig	2026-09-25 06:15:48 UTC
+++ src/GafferScene/PointInstancerAlgo.cpp
@@ -482,7 +482,8 @@ IECoreScene::PointInstancerPtr Private::
 
 	PointInstancer::VisibilityQuery visibilityQuery( *instancer );
 
-	vector<size_t> pointOffsets; pointOffsets.reserve( prototypeIndex.size() );
+	// Sized rather than just reserved, because we assign by index below.
+	vector<size_t> pointOffsets( prototypeIndex.size() );
 	size_t numFlattenedPoints = 0;
 	const size_t hiddenPointOffset = std::numeric_limits<size_t>::max(); // Sentinel to indicate a point has been hidden.
 	for( size_t pointIndex = 0; pointIndex < prototypeIndex.size(); ++pointIndex )
