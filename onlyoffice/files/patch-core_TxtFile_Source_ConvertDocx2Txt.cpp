--- core/TxtFile/Source/ConvertDocx2Txt.cpp.orig	2026-11-05 00:00:00 UTC
+++ core/TxtFile/Source/ConvertDocx2Txt.cpp
@@ -152,7 +152,7 @@
 	const std::wstring Converter_Impl::m_letters = _T("abcdefghijklmnopqrstuvwxyz");
 
 	Converter_Impl::Converter_Impl()
-		:  Lists(NULL), NoteCount(0), listNumPrev(1)
+		:  Lists(0), NoteCount(0), listNumPrev(1)
 	{
 	}
 
