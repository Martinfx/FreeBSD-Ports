--- src/IECoreGL/PointsPrimitive.cpp.orig	2026-09-10 21:49:58 UTC
+++ src/IECoreGL/PointsPrimitive.cpp
@@ -395,7 +395,7 @@
 	if ( t == IECore::TypedData< std::vector< T > >::staticTypeId() )
 	{
 		stride = 1;
-		return &(static_cast< const IECore::TypedData< std::vector<T> > * >( data )->readable()[0]);
+		return static_cast< const IECore::TypedData< std::vector<T> > * >( data )->readable().data();
 	}
 	return defaultValue;
 }
