--- src/GafferImageUI/ImageGadget.cpp.orig	2025-10-10 20:24:55 UTC
+++ src/GafferImageUI/ImageGadget.cpp
@@ -1378,7 +1378,7 @@ void ImageGadget::Tile::resetActive()
 	m_active = false;
 }
 
-const IECoreGL::Texture *ImageGadget::Tile::texture( bool &active )
+IECoreGL::Texture *ImageGadget::Tile::texture( bool &active ) const
 {
 	const auto now = std::chrono::steady_clock::now();
 	Mutex::scoped_lock lock( m_mutex );
@@ -1390,7 +1390,7 @@ const IECoreGL::Texture *ImageGadget::Tile::texture( b
 	}
 
 	ConstFloatVectorDataPtr channelDataToConvert = m_channelDataToConvert;
-	m_channelDataToConvert = nullptr;
+	
 	lock.release(); // Don't hold lock while doing expensive conversion
 
 	if( channelDataToConvert )
@@ -1401,7 +1401,7 @@ const IECoreGL::Texture *ImageGadget::Tile::texture( b
 		{
 			GLuint texture;
 			glGenTextures( 1, &texture );
-			m_texture = new Texture( texture ); // Lock not needed, because this is only touched on the UI thread.
+			m_texture = new Texture(texture); // Lock not needed, because this is only touched on the UI thread.
 			Texture::ScopedBinding binding( *m_texture );
 
 			if( m_loadAsID )
