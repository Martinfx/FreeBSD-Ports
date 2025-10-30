--- include/GafferScene/Private/IECoreScenePreview/Procedural.h.orig	2025-10-29 20:06:01 UTC
+++ include/GafferScene/Private/IECoreScenePreview/Procedural.h
@@ -61,9 +61,9 @@ class GAFFERSCENE_API Procedural : public IECoreScene:
 
 		IE_CORE_DECLAREEXTENSIONOBJECT( Procedural, IECoreScenePreview::PreviewProceduralTypeId, IECoreScene::VisibleRenderable );
 
-#if CORTEX_COMPATIBILITY_VERSION < MAKE_CORTEX_COMPATIBILITY_VERSION( 10, 6 )
-		void render( IECoreScene::Renderer *renderer ) const final {};
-#endif
+/*#if CORTEX_COMPATIBILITY_VERSION < MAKE_CORTEX_COMPATIBILITY_VERSION( 10, 6 )
+		void render( Renderer *renderer ) const {};
+#endif*/
 		/// Must be implemented by derived classes.
 		virtual void render( Renderer *renderer ) const = 0;
 
