--- core/OOXML/Binary/Presentation/Converter.cpp.orig	2026-11-05 00:00:00 UTC
+++ core/OOXML/Binary/Presentation/Converter.cpp
@@ -249,7 +249,7 @@
 			// check note
 			size_t pPointerN = (size_t)(slide->Note.operator ->());
 			LONG nNoteIndex = -1;
-			if (NULL != pPointerN)
+			if (0 != pPointerN)
 			{
 				std::map<size_t, LONG>::const_iterator pSearchN = pCommon->notes.find(pPointerN);
 				if (pSearchN == pCommon->notes.end())
