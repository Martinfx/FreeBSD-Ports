--- src/IECore/RunTimeTyped.cpp.orig	2026-05-30 11:26:24 UTC
+++ src/IECore/RunTimeTyped.cpp
@@ -118,7 +118,7 @@ void RunTimeTyped::registerType( TypeId derivedTypeId,
 		{
 			if ( baseTypeId != lb->second )
 			{
-				msg( Msg::Warning, "RunTimeTyped", "Duplicate registration of base type id for '{}' - {} and {}", derivedTypeName, lb->second, baseTypeId );
+				msg( Msg::Warning, "RunTimeTyped", "Duplicate registration of base type id for '{}' - {} and {}", derivedTypeName, static_cast<int>(lb->second), static_cast<int>(baseTypeId) );
 			}
 		}
 		else
@@ -140,7 +140,7 @@ void RunTimeTyped::registerType( TypeId derivedTypeId,
 		{
 			if ( std::string( derivedTypeName ) != lb->second )
 			{
-				msg( Msg::Warning, "RunTimeTyped", "Duplicate registration of type name for type id {} - '{}' and '{}'", derivedTypeId, lb->second, derivedTypeName );
+				msg( Msg::Warning, "RunTimeTyped", "Duplicate registration of type name for type id {} - '{}' and '{}'", static_cast<int>(derivedTypeId), lb->second, derivedTypeName );
 			}
 		}
 		else
@@ -159,7 +159,7 @@ void RunTimeTyped::registerType( TypeId derivedTypeId,
 		{
 			if ( derivedTypeId != lb->second )
 			{
-				msg( Msg::Warning, "RunTimeTyped", "Duplicate registration of type id for type name '{}' - {} and {}", derivedTypeName, lb->second, derivedTypeId );
+				msg( Msg::Warning, "RunTimeTyped", "Duplicate registration of type id for type name '{}' - {} and {}", derivedTypeName, static_cast<int>(lb->second), static_cast<int>(derivedTypeId) );
 			}
 		}
 		else
