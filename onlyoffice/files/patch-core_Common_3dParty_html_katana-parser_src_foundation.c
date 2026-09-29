--- core/Common/3dParty/html/katana-parser/src/foundation.c.orig	2026-09-28 06:09:54 UTC
+++ core/Common/3dParty/html/katana-parser/src/foundation.c
@@ -52,6 +52,8 @@ void katana_string_init(struct KatanaInt
 void katana_string_append_characters(struct KatanaInternalParser* parser,
                                      const char* str, KatanaParserString* output)
 {
+    if (NULL == str)
+        return;
     size_t len = strlen(str);
     maybe_resize_string(parser, len, output);
     memcpy(output->data + output->length, str, len);
@@ -62,6 +64,8 @@ void katana_string_prepend_characters(st
                                       const char* str,
                                       KatanaParserString* output)
 {
+    if (NULL == str)
+        return;
     size_t len = strlen(str);
     size_t new_length = output->length + len;
     char* new_data = katana_parser_allocate(parser, new_length);
