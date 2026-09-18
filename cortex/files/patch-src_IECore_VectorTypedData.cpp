--- src/IECore/VectorTypedData.cpp.orig	2026-09-10 21:49:58 UTC
+++ src/IECore/VectorTypedData.cpp
@@ -71,7 +71,7 @@
 		{																										\
 			throw Exception( std::string( TNAME::staticTypeName() ) + " has no base type." );					\
 		}																										\
-		return reinterpret_cast< const TNAME::BaseType * >( &(this->readable()[0]) );							\
+		return reinterpret_cast< const TNAME::BaseType * >( this->readable().data() );							\
 	}																											\
 	template <>																									\
 	TNAME::BaseType * TNAME::baseWritable()																		\
@@ -80,7 +80,7 @@
 		{																										\
 			throw Exception( std::string( TNAME::staticTypeName() ) + " has no base type." );					\
 		}																										\
-		return reinterpret_cast< TNAME::BaseType * >( &(this->writable()[0]) );									\
+		return reinterpret_cast< TNAME::BaseType * >( this->writable().data() );									\
 	}																											\
 
 #define IE_CORE_DEFINEBASEVECTORTYPEDDATAIOSPECIALISATION( TNAME, N, FALLBACKNAME )								\
