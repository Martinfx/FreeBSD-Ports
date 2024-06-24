--- shared/tag_helpers/ASFTagHelper.cpp.orig	2024-06-24 18:31:15 UTC
+++ shared/tag_helpers/ASFTagHelper.cpp
@@ -107,7 +107,7 @@ ASFTagHelper::setTags( const Meta::FieldHash &changes 
         QVariant value = changes.value( key );
         TagLib::String field = fieldName( key );
 
-        if( !field.isNull() && !field.isEmpty() )
+        if(!field.isEmpty() )
         {
             if( key == Meta::valHasCover )
                 continue;
