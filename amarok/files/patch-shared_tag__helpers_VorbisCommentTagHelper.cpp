--- shared/tag_helpers/VorbisCommentTagHelper.cpp.orig	2024-06-25 16:37:48 UTC
+++ shared/tag_helpers/VorbisCommentTagHelper.cpp
@@ -151,7 +151,7 @@ VorbisCommentTagHelper::setTags( const Meta::FieldHash
         QVariant value = changes.value( key );
         TagLib::String field = fieldName( key );
 
-        if( !field.isNull() && !field.isEmpty() )
+        if(!field.isEmpty() )
         {
             if( key == Meta::valHasCover )
                 continue;
