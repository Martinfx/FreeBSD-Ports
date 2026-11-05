--- core/OOXML/Binary/Sheets/Reader/ChartFromToBinary.cpp.orig	2026-11-05 00:00:00 UTC
+++ core/OOXML/Binary/Sheets/Reader/ChartFromToBinary.cpp
@@ -10123,7 +10123,7 @@
 			WriteCT_String(*oVal.m_gapDepth);
 			m_oBcw.WriteItemEnd(nCurPos);
 		}
-		if (NULL != oVal.m_shape.IsInit())
+		if (0 != oVal.m_shape.IsInit())
 		{
 			int nCurPos = m_oBcw.WriteItemStart(c_oserct_bar3dchartSHAPE);
 			WriteCT_Shape(*oVal.m_shape);
