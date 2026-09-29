--- core/Common/3dParty/html/katana-parser/src/tokenizer.c.orig	2026-09-28 06:09:54 UTC
+++ core/Common/3dParty/html/katana-parser/src/tokenizer.c
@@ -288,7 +288,7 @@ static char * katana_token_string(int to
 #endif // #if KATANA_FELX_DEBUG
 #endif // #ifdef KATANA_FELX_DEBUG
 
-inline bool katana_is_html_space(char c)
+static inline bool katana_is_html_space(char c)
 {
     return c <= ' ' && (c == ' ' || c == '\n' || c == '\t' || c == '\r' || c == '\f');
 }
