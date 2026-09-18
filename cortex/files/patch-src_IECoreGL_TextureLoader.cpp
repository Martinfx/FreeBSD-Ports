--- src/IECoreGL/TextureLoader.cpp.orig	2026-09-10 21:49:58 UTC
+++ src/IECoreGL/TextureLoader.cpp
@@ -187,7 +187,7 @@
 
 		chanRoiFull.chbegin = chan;
 		chanRoiFull.chend = chan + 1;
-		if( !imageBuf.get_pixels( chanRoiFull, OIIO::TypeDesc::FLOAT, &(*dst)->writable()[0] ) )
+		if( !imageBuf.get_pixels( chanRoiFull, OIIO::TypeDesc::FLOAT, (*dst)->writable().data() ) )
 		{
 			IECore::msg(
 				IECore::Msg::Error, "IECoreGL::TextureLoader::load",
