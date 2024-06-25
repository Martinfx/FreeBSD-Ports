--- shared/tag_helpers/MP4TagHelper.cpp.orig	2024-06-25 16:34:09 UTC
+++ shared/tag_helpers/MP4TagHelper.cpp
@@ -106,7 +106,7 @@ MP4TagHelper::setTags( const Meta::FieldHash &changes 
         QVariant value = changes.value( key );
         TagLib::String field = fieldName( key );
 
-        if( !field.isNull() && !field.isEmpty() )
+        if(!field.isEmpty() )
         {
             // http://gitorious.org/~jefferai/xdg-specs/jefferais-xdg-specs/blobs/mediaspecs/specifications/FMPSpecs/specification.txt sais that mp4 tags should be saved as strings
             if( key == Meta::valHasCover )
