--- include/GafferScene/Private/IECoreScenePreview/Geometry.h.orig	2025-10-29 20:25:37 UTC
+++ include/GafferScene/Private/IECoreScenePreview/Geometry.h
@@ -44,7 +44,7 @@ namespace IECoreScenePreview
 
 namespace IECoreScenePreview
 {
-
+class Renderer;
 /// Class used to represent additional geometry types supported
 /// by specific renderers but not present in Cortex (think RiGeometry).
 class GAFFERSCENE_API Geometry : public IECoreScene::VisibleRenderable
@@ -68,7 +68,7 @@ class GAFFERSCENE_API Geometry : public IECoreScene::V
 		Imath::Box3f bound() const override;
 
 #if CORTEX_COMPATIBILITY_VERSION < MAKE_CORTEX_COMPATIBILITY_VERSION( 10, 6 )
-		void render( IECoreScene::Renderer *renderer ) const override {};
+		void render( Renderer *renderer ) const {};
 #endif
 
 	private:
