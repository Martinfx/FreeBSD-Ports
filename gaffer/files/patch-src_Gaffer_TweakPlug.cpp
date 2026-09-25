--- src/Gaffer/TweakPlug.cpp.orig	2026-09-24 19:41:12 UTC
+++ src/Gaffer/TweakPlug.cpp
@@ -142,7 +142,7 @@ T applyNumericTweak(
 					)
 				);
 			default:
-				throw IECore::Exception( fmt::format( "Not a valid tweak mode: {}.", mode ) );
+				throw IECore::Exception( fmt::format( "Not a valid tweak mode: {}.", static_cast<int>( mode ) ) );
 		}
 	}
 	else
