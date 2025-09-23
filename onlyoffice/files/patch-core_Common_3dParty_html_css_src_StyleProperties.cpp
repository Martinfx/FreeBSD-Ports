--- core/Common/3dParty/html/css/src/StyleProperties.cpp.orig	2025-09-23 21:37:34 UTC
+++ core/Common/3dParty/html/css/src/StyleProperties.cpp
@@ -858,7 +858,7 @@ namespace NSCSS
 		}
 
 		m_enType = ColorEmpty;
-		m_unLevel    = NULL;
+		m_unLevel    = 0;
 		m_bImportant = false;
 	}
 
@@ -2928,7 +2928,7 @@ namespace NSCSS
 	void CEnum::Clear()
 	{
 		m_oValue     = INT_MAX;
-		m_unLevel    = NULL;
+		m_unLevel    = 0;
 		m_bImportant = false;
 	}
 
