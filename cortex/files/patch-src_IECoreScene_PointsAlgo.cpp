--- src/IECoreScene/PointsAlgo.cpp.orig	2026-05-30 12:37:59 UTC
+++ src/IECoreScene/PointsAlgo.cpp
@@ -302,7 +302,7 @@ PointsPrimitivePtr deletePoints( const PointsPrimitive
 	if( pointsToDelete.interpolation != PrimitiveVariable::Vertex )
 	{
 		throw InvalidArgumentException(
-			fmt::format( "PointsAlgo::deletePoints requires a Vertex [Int|Bool|Float]VectorData primitiveVariable. {} interpolation found", pointsToDelete.interpolation )
+			fmt::format( "PointsAlgo::deletePoints requires a Vertex [Int|Bool|Float]VectorData primitiveVariable. {} interpolation found", static_cast<int>(pointsToDelete.interpolation) )
 		);
 	}
 
