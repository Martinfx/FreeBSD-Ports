--- core/OOXML/XlsbFormat/Biff12_records/BeginPCDSCSet.h.orig	2026-11-05 00:00:00 UTC
+++ core/OOXML/XlsbFormat/Biff12_records/BeginPCDSCSet.h
@@ -40,6 +40,8 @@
 #include "../../../MsBinaryFile/XlsFile/Format/Logic/Biff_structures/BIFF12/RelID.h"
 #include "../../../MsBinaryFile/XlsFile/Format/Logic/Biff_structures/BIFF12/CellRangeRef.h"
 
+#include <array>
+
 namespace XLSB
 {
     // Logical representation of BrtBeginPCDSCSet record in BIFF12
