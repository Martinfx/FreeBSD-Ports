--- src/GafferScene/PointInstancerCore.cpp.orig	2026-09-24 19:41:12 UTC
+++ src/GafferScene/PointInstancerCore.cpp
@@ -139,7 +139,8 @@ struct TypedContextVariableCreator : pub
 
 	string format( size_t pointIndex ) const override
 	{
-		return safeFormat( m_indexedView[pointIndex] );
+		// `static_cast` needed to avoid the `vector<bool>` fiasco.
+		return safeFormat( static_cast<T>( m_indexedView[pointIndex] ) );
 	}
 
 	private :
