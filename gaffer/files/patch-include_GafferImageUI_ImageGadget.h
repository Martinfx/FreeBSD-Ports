--- include/GafferImageUI/ImageGadget.h.orig	2025-03-03 10:27:42 UTC
+++ include/GafferImageUI/ImageGadget.h
@@ -294,17 +294,17 @@ class GAFFERIMAGEUI_API ImageGadget : public GafferUI:
 			void resetActive();
 
 			// Called from the UI thread.
-			const IECoreGL::Texture *texture( bool &active );
+			IECoreGL::Texture *texture( bool &active ) const;
 
 			private :
 
 				IECore::MurmurHash m_channelDataHash;
 				IECore::ConstFloatVectorDataPtr m_channelDataToConvert;
-				IECoreGL::TexturePtr m_texture;
+				mutable IECoreGL::TexturePtr m_texture;
 				bool m_active;
 				std::chrono::steady_clock::time_point m_activeStartTime;
 				using Mutex = tbb::spin_mutex;
-				Mutex m_mutex;
+				mutable Mutex m_mutex;
 
 		};
 
