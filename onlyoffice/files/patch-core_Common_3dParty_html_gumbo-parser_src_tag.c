--- core/Common/3dParty/html/gumbo-parser/src/tag.c.orig	2026-09-28 06:09:54 UTC
+++ core/Common/3dParty/html/gumbo-parser/src/tag.c
@@ -57,7 +57,7 @@ void gumbo_tag_from_original_text(GumboS
     // strnchr is apparently not a standard C library function, so I loop
     // explicitly looking for whitespace or other illegal tag characters.
     for (const char* c = text->data; c != text->data + text->length; ++c) {
-      if (isspace(*c) || *c == '/') {
+      if (isspace((unsigned char)*c) || *c == '/') {
         text->length = c - text->data;
         break;
       }
