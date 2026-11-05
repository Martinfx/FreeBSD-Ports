--- core/PdfFile/PdfEditor.cpp.orig	2026-11-05 00:00:00 UTC
+++ core/PdfFile/PdfEditor.cpp
@@ -3810,7 +3810,7 @@
 	}
 	int nPageIndex = m_pReader->GetPageIndex(nOriginIndex, &pPDFDocument, &pFontList, &nStartRefID);
 	if (nPageIndex < 0 || !pPDFDocument)
-		return NULL;
+		return 0;
 
 	if (m_nMode == Mode::WriteNew)
 	{
