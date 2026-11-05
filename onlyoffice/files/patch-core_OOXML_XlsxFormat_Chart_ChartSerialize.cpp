--- core/OOXML/XlsxFormat/Chart/ChartSerialize.cpp.orig	2026-11-05 00:00:00 UTC
+++ core/OOXML/XlsxFormat/Chart/ChartSerialize.cpp
@@ -1529,7 +1529,7 @@
 		{
 			writer.WriteString(L"<");
 			writer.WriteString(sNodeName);
-			if (NULL != m_l.IsInit())
+			if (0 != m_l.IsInit())
 			{
 				WritingStringAttrDouble(L"l", *m_l);
 			}
