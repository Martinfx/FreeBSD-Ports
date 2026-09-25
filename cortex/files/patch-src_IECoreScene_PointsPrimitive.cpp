--- src/IECoreScene/PointsPrimitive.cpp.orig	2026-09-25 07:03:09 UTC
+++ src/IECoreScene/PointsPrimitive.cpp
@@ -146,7 +146,9 @@ Imath::Box3f PointsPrimitive::bound() co
 	const V3f *p = nullptr;
 	if( const V3fVectorData *pData = variableData<V3fVectorData>( "P" ) )
 	{
-		p = &pData->readable().front();
+		// Note the use of `data()` : P may be empty, and `front()` aborts with a
+		// hardened C++ standard library.
+		p = pData->readable().data();
 		count = min( count, pData->readable().size() );
 	}
 
@@ -166,7 +168,7 @@ Imath::Box3f PointsPrimitive::bound() co
 	size_t widthStep = 0;
 	if( const FloatVectorData *widthData = variableData<FloatVectorData>( "width" ) )
 	{
-		width = &widthData->readable().front();
+		width = widthData->readable().data();
 		widthStep = 1;
 		count = min( count, widthData->readable().size() );
 	}
@@ -184,7 +186,7 @@ Imath::Box3f PointsPrimitive::bound() co
 			}
 			else if( const FloatVectorData *aspectRatioData = variableData<FloatVectorData>( "patchaspectratio" ) )
 			{
-				aspectRatio = &aspectRatioData->readable().front();
+				aspectRatio = aspectRatioData->readable().data();
 				aspectRatioStep = 1;
 				count = min( count, aspectRatioData->readable().size() );
 			}
