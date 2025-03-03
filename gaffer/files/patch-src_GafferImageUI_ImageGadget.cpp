--- src/GafferImageUI/ImageGadget.cpp.orig	2025-03-03 10:25:45 UTC
+++ src/GafferImageUI/ImageGadget.cpp
@@ -758,7 +758,7 @@ void ImageGadget::Tile::resetActive()
 	m_active = false;
 }
 
-const IECoreGL::Texture *ImageGadget::Tile::texture( bool &active )
+IECoreGL::Texture *ImageGadget::Tile::texture( bool &active ) const
 {
 	const auto now = std::chrono::steady_clock::now();
 	Mutex::scoped_lock lock( m_mutex );
@@ -770,7 +770,7 @@ const IECoreGL::Texture *ImageGadget::Tile::texture( b
 	}
 
 	ConstFloatVectorDataPtr channelDataToConvert = m_channelDataToConvert;
-	m_channelDataToConvert = nullptr;
+	
 	lock.release(); // Don't hold lock while doing expensive conversion
 
 	if( channelDataToConvert )
@@ -781,7 +781,7 @@ const IECoreGL::Texture *ImageGadget::Tile::texture( b
 		{
 			GLuint texture;
 			glGenTextures( 1, &texture );
-			m_texture = new Texture( texture ); // Lock not needed, because this is only touched on the UI thread.
+			m_texture = new Texture(texture); // Lock not needed, because this is only touched on the UI thread.
 			Texture::ScopedBinding binding( *m_texture );
 
 			glTexImage2D(
