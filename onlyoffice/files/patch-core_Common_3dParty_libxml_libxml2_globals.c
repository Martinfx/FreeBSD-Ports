--- core/Common/3dParty/libxml/libxml2/globals.c.orig	2026-04-27 00:00:00 UTC
+++ core/Common/3dParty/libxml/libxml2/globals.c
@@ -216,7 +216,7 @@
  */
 
 static int xmlDoValidityCheckingDefaultValueThrDef = 0;
-static int xmlGetWarningsDefaultValueThrDef = 1;
+static int xmlGetWarningsDefaultValueThrDef = 0;
 static int xmlLoadExtDtdDefaultValueThrDef = 0;
 static int xmlPedanticParserDefaultValueThrDef = 0;
 static int xmlKeepBlanksDefaultValueThrDef = 1;
