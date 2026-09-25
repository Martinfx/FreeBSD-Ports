--- src/GafferScene/RenderController.cpp.orig	2026-09-24 19:41:12 UTC
+++ src/GafferScene/RenderController.cpp
@@ -1646,7 +1646,7 @@ void RenderController::updateInternal( c
 					IECore::Msg::Warning, "RenderController",
 					fmt::format(
 						"{} attribute edit{} required geometry to be regenerated",
-						m_failedAttributeEdits, m_failedAttributeEdits > 1 ? "s" : ""
+						m_failedAttributeEdits.load(), m_failedAttributeEdits > 1 ? "s" : ""
 					)
 				);
 				m_failedAttributeEdits = 0;
