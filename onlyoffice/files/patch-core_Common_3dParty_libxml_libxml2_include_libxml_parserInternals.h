--- core/Common/3dParty/libxml/libxml2/include/libxml/parserInternals.h.orig	2026-04-27 00:00:00 UTC
+++ core/Common/3dParty/libxml/libxml2/include/libxml/parserInternals.h
@@ -47,7 +47,7 @@
  * use XML_PARSE_HUGE option to override it.
  * Introduced in 2.9.0
  */
-#define XML_MAX_TEXT_LENGTH 10000000
+#define XML_MAX_TEXT_LENGTH 15000000
 
 /**
  * Maximum size allowed when XML_PARSE_HUGE is set.
@@ -78,7 +78,7 @@
  * behaviour on "unfriendly' content
  * Introduced in 2.9.0
  */
-#define XML_MAX_LOOKUP_LIMIT 10000000
+#define XML_MAX_LOOKUP_LIMIT 15000000
 
 /**
  * Identifiers can be longer, but this will be more costly
