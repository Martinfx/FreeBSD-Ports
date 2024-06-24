--- shared/tag_helpers/APETagHelper.cpp.orig    2024-06-24 08:42:20 UTC
+++ shared/tag_helpers/APETagHelper.cpp
@@ -84,7 +84,7 @@ APETagHelper::setTags( const Meta::FieldHash &changes 
         QVariant value = changes.value( key );
         TagLib::String field = fieldName( key );
 
-        if( !field.isNull() && !field.isEmpty() )
+        if(!field.isEmpty() )
         {
             if( key == Meta::valRating )
                 m_tag->addValue( field, Qt4QStringToTString( QString::number( value.toFloat() / 10.0 ) ) );
 
