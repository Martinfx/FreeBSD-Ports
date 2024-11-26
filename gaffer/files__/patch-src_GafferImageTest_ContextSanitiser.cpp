--- src/GafferImageTest/ContextSanitiser.cpp.orig	2025-03-03 12:58:23 UTC
+++ src/GafferImageTest/ContextSanitiser.cpp
@@ -54,6 +54,7 @@ ContextSanitiser::ContextSanitiser()
 {
 }
 
+/*
 void ContextSanitiser::processStarted( const Gaffer::Process *process )
 {
 	if( const ImagePlug *image = process->plug()->parent<ImagePlug>() )
@@ -124,4 +125,4 @@ void ContextSanitiser::warn( const Gaffer::Process &pr
 			message
 		);
 	}
-}
+}*/
