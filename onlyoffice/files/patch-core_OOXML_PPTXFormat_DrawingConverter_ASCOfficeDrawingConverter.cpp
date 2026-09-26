--- core/OOXML/PPTXFormat/DrawingConverter/ASCOfficeDrawingConverter.cpp.orig	2025-09-24 09:41:03 UTC
+++ core/OOXML/PPTXFormat/DrawingConverter/ASCOfficeDrawingConverter.cpp
@@ -1965,11 +1965,11 @@ bool CDrawingConverter::ParceObject(const std::wstring
 {
 	XmlUtils::CXmlNode oMainNode;
 	if (!oMainNode.FromXmlString(strXml))
-		return NULL;
+		return 0;
 
 	std::vector<XmlUtils::CXmlNode> oNodes;
     if (!oMainNode.GetNodes(L"*", oNodes))
-		return NULL;
+		return 0;
 
 	m_pBinaryWriter->StartRecord(0);
 	m_pBinaryWriter->ClearCurShapePositionAndSizes();
