--- include/GafferImageUI/ImageGadget.h.orig	2025-03-03 10:27:42 UTC
+++ include/GafferImageUI/ImageGadget.h
@@ -294,7 +294,7 @@ class GAFFERIMAGEUI_API ImageGadget : public GafferUI:
 			void resetActive();
 
 			// Called from the UI thread.
-			const IECoreGL::Texture *texture( bool &active );
+			IECoreGL::Texture *texture( bool &active );
 
 			private :
 
