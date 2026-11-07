--- core/OOXML/XlsxFormat/Worksheets/SheetData.cpp.orig	2026-11-05 00:00:00 UTC
+++ core/OOXML/XlsxFormat/Worksheets/SheetData.cpp
@@ -92,6 +92,8 @@
 
 #include <boost/make_unique.hpp>
 
+#include <cfloat>
+
 #ifndef MININT32
 #define MAXUINT32   ((uint32_t)~((uint32_t)0))
 #define MAXINT32    ((int32_t)(MAXUINT32 >> 1))
