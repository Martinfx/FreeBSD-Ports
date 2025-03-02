--- src/Gaffer/TweakPlug.cpp.orig	2025-03-02 07:34:01 UTC
+++ src/Gaffer/TweakPlug.cpp
@@ -138,7 +138,7 @@ T applyNumericTweak(
 					)
 				);
 			default:
-				throw IECore::Exception( fmt::format( "Not a valid tweak mode: {}.", mode ) );
+				throw IECore::Exception( fmt::format( "Not a valid tweak mode: {}.",TweakPlug::modeToString(mode) ) );
 		}
 	}
 	else
