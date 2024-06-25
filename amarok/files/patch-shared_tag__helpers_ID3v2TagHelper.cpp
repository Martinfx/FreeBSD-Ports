--- shared/tag_helpers/ID3v2TagHelper.cpp.orig	2024-06-25 16:39:12 UTC
+++ shared/tag_helpers/ID3v2TagHelper.cpp
@@ -187,7 +187,7 @@ ID3v2TagHelper::setTags( const Meta::FieldHash &change
         QVariant value = changes.value( key );
         TagLib::ByteVector field( fieldName( key ).toCString() );
 
-        if( !field.isNull() && !field.isEmpty() )
+        if(!field.isEmpty() )
         {
             if( key == Meta::valHasCover )
                 continue;
