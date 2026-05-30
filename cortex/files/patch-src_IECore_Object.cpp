--- src/IECore/Object.cpp.orig	2026-05-30 11:15:45 UTC
+++ src/IECore/Object.cpp
@@ -533,12 +533,12 @@ ObjectPtr Object::create( TypeId typeId )
 	TypeInformation::TypeIdsToCreatorsMap::const_iterator it = i->typeIdsToCreators.find( typeId );
 	if( it==i->typeIdsToCreators.end() )
 	{
-		throw Exception( fmt::format( "Type \"{}\" is not a registered Object type.", typeId ) );
+		throw Exception( fmt::format( "Type \"{}\" is not a registered Object type.", static_cast<int>(typeId) ) );
 	}
 
 	if( !it->second )
 	{
-		throw Exception( fmt::format( "Type \"{}\" is an abstract type.", typeId ) );
+		throw Exception( fmt::format( "Type \"{}\" is an abstract type.", static_cast<int>(typeId) ) );
 	}
 
 	return it->second();
