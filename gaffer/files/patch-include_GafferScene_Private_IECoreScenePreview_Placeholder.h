--- include/GafferScene/Private/IECoreScenePreview/Placeholder.h.orig	2025-10-29 20:19:51 UTC
+++ include/GafferScene/Private/IECoreScenePreview/Placeholder.h
@@ -47,6 +47,8 @@ namespace IECoreScenePreview
 namespace IECoreScenePreview
 {
 
+class Renderer;
+
 /// A renderable placeholder for geometry that hasn't been expanded yet.
 class GAFFERSCENE_API Placeholder : public IECoreScene::VisibleRenderable
 {
@@ -73,7 +75,7 @@ class GAFFERSCENE_API Placeholder : public IECoreScene
 
 		Imath::Box3f bound() const override;
 #if CORTEX_COMPATIBILITY_VERSION < MAKE_CORTEX_COMPATIBILITY_VERSION( 10, 6 )
-		void render( IECoreScene::Renderer *renderer ) const override {};
+		void render( Renderer *renderer ) const {};
 #endif
 
 	private :
