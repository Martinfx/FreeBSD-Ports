--- contrib/IECoreUSD/src/IECoreUSD/PrimitiveAlgo.cpp.orig	2025-03-06 11:00:39 UTC
+++ contrib/IECoreUSD/src/IECoreUSD/PrimitiveAlgo.cpp
@@ -426,7 +426,10 @@ bool readPrimitiveVariables( const pxr::UsdSkelRoot &s
 	pxr::GfMatrix4d inverseBind = skinningQuery.GetGeomBindTransform( time ).GetInverse();
 	for( auto &p : points )
 	{
-		p = inverseBind.Transform( p );
+		GfVec3d transformed = inverseBind.Transform(p);
+		p = GfVec3f(static_cast<float>(transformed[0]),
+            		    static_cast<float>(transformed[1]),
+            		    static_cast<float>(transformed[2]));
 	}
 
 	Canceller::check( canceller );
