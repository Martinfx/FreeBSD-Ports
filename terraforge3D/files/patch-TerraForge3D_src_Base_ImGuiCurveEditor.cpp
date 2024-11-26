--- TerraForge3D/src/Base/ImGuiCurveEditor.cpp.orig	2024-11-26 21:09:40 UTC
+++ TerraForge3D/src/Base/ImGuiCurveEditor.cpp
@@ -605,7 +605,7 @@ int Curve(const char *label, const ImVec2 &size, const
 	ImRect bb(window->DC.CursorPos, window->DC.CursorPos + size);
 	ItemSize(bb);
 
-	if (!ItemAdd(bb, NULL))
+	if (!ItemAdd(bb, GetID("")))
 	{
 		return 0;
 	}
@@ -846,4 +846,4 @@ int Curve(const char *label, const ImVec2 &size, const
 	return modified;
 }
 
-}; // namespace ImGui
\ No newline at end of file
+}; // namespace ImGui
