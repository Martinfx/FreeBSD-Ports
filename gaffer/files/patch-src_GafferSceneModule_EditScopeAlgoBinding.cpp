--- src/GafferSceneModule/EditScopeAlgoBinding.cpp.orig	2026-09-24 19:41:12 UTC
+++ src/GafferSceneModule/EditScopeAlgoBinding.cpp
@@ -282,8 +282,12 @@ bool renameRenderPassWrapper( Gaffer::Ed
 
 object renameRenderPassNonEditableReasonWrapper( Gaffer::EditScope &scope, const std::string &newName )
 {
-	IECorePython::ScopedGILRelease gilRelease;
-	std::optional<std::string> result = EditScopeAlgo::renameRenderPassNonEditableReason( &scope, newName );
+	std::optional<std::string> result;
+	{
+		IECorePython::ScopedGILRelease gilRelease;
+		result = EditScopeAlgo::renameRenderPassNonEditableReason( &scope, newName );
+	}
+	// The GIL must be held to create the Python object for the result.
 	return result ? object( result.value() ) : object();
 }
 
