--- core/Common/3dParty/html/katana-parser/src/parser.c.orig	2025-09-24 11:53:01 UTC
+++ core/Common/3dParty/html/katana-parser/src/parser.c
@@ -1293,7 +1293,7 @@ void katanaerror(YYLTYPE* yyloc, void* scanner, struct
     e->last_line = yyloc->last_line;
     e->last_column = yyloc->last_column;
     snprintf(e->message, KATANA_ERROR_MESSAGE_SIZE, "%s at %s", error,
-             katanaget_text(parser->scanner));
+             	katanaget_text(parser->scanner));
     katana_array_add(parser, e, &(parser->output->errors));
 }
 
