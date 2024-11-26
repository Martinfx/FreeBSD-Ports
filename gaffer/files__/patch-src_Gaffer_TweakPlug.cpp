--- src/Gaffer/TweakPlug.cpp.orig	2025-03-04 09:57:44 UTC
+++ src/Gaffer/TweakPlug.cpp
@@ -139,7 +139,7 @@ T applyNumericTweak(
 					)
 				);
 			default:
-				throw IECore::Exception( fmt::format( "Not a valid tweak mode: {}.", mode ) );
+				throw IECore::Exception( fmt::format( "Not a valid tweak mode: {}.",TweakPlug::modeToString(mode) ) );
 		}
 	}
 	else
