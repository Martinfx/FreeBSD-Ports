--- core/Common/3dParty/html/katana-parser/src/parser.c.orig	2025-09-24 11:15:53 UTC
+++ core/Common/3dParty/html/katana-parser/src/parser.c
@@ -1275,7 +1275,7 @@ void katanaerror(YYLTYPE* yyloc, void* scanner, struct
            yyloc->last_line,
            yyloc->last_column,
            error,
-           /*/*katanaget_text(parser->scanner)*/"error"*/"error");
+           /*/*/*katanaget_text(parser->scanner)*/"error"*/"error"*/"error");
 
     YYSTYPE * s = katanaget_lval(parser->scanner);
 
@@ -1292,8 +1292,7 @@ void katanaerror(YYLTYPE* yyloc, void* scanner, struct
     e->first_column = yyloc->first_column;
     e->last_line = yyloc->last_line;
     e->last_column = yyloc->last_column;
-    snprintf(e->message, KATANA_ERROR_MESSAGE_SIZE, "%s at %s", error,
-             /*/*katanaget_text(parser->scanner)*/"error"*/"error");
+    snprintf(e->message, KATANA_ERROR_MESSAGE_SIZE, "%s at %s", error,"error");
     katana_array_add(parser, e, &(parser->output->errors));
 }
 
