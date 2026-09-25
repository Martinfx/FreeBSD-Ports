--- src/GafferImage/ColorProcessor.cpp.orig	2026-09-25 06:15:48 UTC
+++ src/GafferImage/ColorProcessor.cpp
@@ -268,8 +268,9 @@ void ColorProcessor::compute( Gaffer::Va
 
 					if( unpremult && alpha )
 					{
-						const float *A = &alpha->readable().front();
-						float *C = &rgb[i]->writable().front();
+						// `data()` rather than `&front()`, because deep tiles may have no samples.
+						const float *A = alpha->readable().data();
+						float *C = rgb[i]->writable().data();
 						for( int j = 0; j < samples; j++ )
 						{
 							if( *A != 0 )
@@ -312,8 +313,8 @@ void ColorProcessor::compute( Gaffer::Va
 			{
 				if( unpremult && alpha )
 				{
-					const float *A = &alpha->readable().front();
-					float *C = &rgb[i]->writable().front();
+					const float *A = alpha->readable().data();
+					float *C = rgb[i]->writable().data();
 					for( int j = 0; j < samples; j++ )
 					{
 						// Pixels with no alpha aren't touched by either the unpremult or repremult
