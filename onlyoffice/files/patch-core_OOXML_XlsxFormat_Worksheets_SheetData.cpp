--- core/OOXML/XlsxFormat/Worksheets/SheetData.cpp.orig	2025-09-24 09:41:02 UTC
+++ core/OOXML/XlsxFormat/Worksheets/SheetData.cpp
@@ -76,6 +76,8 @@
 
 #include <boost/make_unique.hpp>
 
+#include <cfloat>
+
 #ifndef MININT32
 #define MAXUINT32   ((uint32_t)~((uint32_t)0))
 #define MAXINT32    ((int32_t)(MAXUINT32 >> 1))
