--- src/GafferImageUI/ImageGadget.cpp.orig	2025-03-03 10:25:45 UTC
+++ src/GafferImageUI/ImageGadget.cpp
@@ -758,7 +758,7 @@ void ImageGadget::Tile::resetActive()
 	m_active = false;
 }
 
-const IECoreGL::Texture *ImageGadget::Tile::texture( bool &active )
+IECoreGL::Texture *ImageGadget::Tile::texture( bool &active )
 {
 	const auto now = std::chrono::steady_clock::now();
 	Mutex::scoped_lock lock( m_mutex );
