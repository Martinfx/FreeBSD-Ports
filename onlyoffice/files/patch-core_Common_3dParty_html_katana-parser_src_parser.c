--- core/Common/3dParty/html/katana-parser/src/parser.c.orig	2026-09-28 06:09:54 UTC
+++ core/Common/3dParty/html/katana-parser/src/parser.c
@@ -39,7 +39,7 @@
 //#define assert(x)
 
 #define breakpoint
-#define KATANA_PARSER_STRING(literal) (KatanaParserString){ literal, sizeof(literal) - 1 }
+#define KATANA_PARSER_STRING(literal) { literal, sizeof(literal) - 1 }
 
 
 typedef void (*KatanaArrayDeallocator)(KatanaParser* parser, void* e);
@@ -1275,7 +1275,7 @@ void katanaerror(YYLTYPE* yyloc, void* s
            yyloc->last_line,
            yyloc->last_column,
            error,
-           katanaget_text(parser->scanner));
+           /*katanaget_text(parser->scanner)*/"error");
 
     YYSTYPE * s = katanaget_lval(parser->scanner);
 
@@ -1293,7 +1293,7 @@ void katanaerror(YYLTYPE* yyloc, void* s
     e->last_line = yyloc->last_line;
     e->last_column = yyloc->last_column;
     snprintf(e->message, KATANA_ERROR_MESSAGE_SIZE, "%s at %s", error,
-             katanaget_text(parser->scanner));
+             /*katanaget_text(parser->scanner)*/"error");
     katana_array_add(parser, e, &(parser->output->errors));
 }
 
